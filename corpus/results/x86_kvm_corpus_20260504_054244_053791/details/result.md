# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T06:04:12.926077+00:00",
  "kop_modules": {
    "captured_at": "2026-05-04T05:42:44.080894+00:00",
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
      "invoked_at": "2026-05-04T05:42:44.080829+00:00",
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
        "captured_at": "2026-05-04T05:42:44.080821+00:00",
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
      "captured_at": "2026-05-04T05:42:44.068947+00:00",
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
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1115.9495327102804,
      "baseline_run_cnt_delta": 1070,
      "baseline_run_time_ns_delta": 1194066,
      "post_rejit_avg_ns_per_run": 1097.6058052434457,
      "post_rejit_run_cnt_delta": 1068,
      "post_rejit_run_time_ns_delta": 1172243,
      "program": "event_exit_acct_process",
      "program_id": 18,
      "ratio": 0.9835622248774246,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1542.3703703703704,
      "baseline_run_cnt_delta": 1080,
      "baseline_run_time_ns_delta": 1665760,
      "post_rejit_avg_ns_per_run": 1273.474025974026,
      "post_rejit_run_cnt_delta": 1078,
      "post_rejit_run_time_ns_delta": 1372805,
      "program": "event_wake_up_new_task",
      "program_id": 20,
      "ratio": 0.8256603280496279,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 8608.285714285714,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 180774,
      "post_rejit_avg_ns_per_run": 6835.761904761905,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 143551,
      "program": "event_execve",
      "program_id": 22,
      "ratio": 0.7940909644085986,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 666.3809523809524,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 13994,
      "post_rejit_avg_ns_per_run": 567.6666666666666,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 11921,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 24,
      "ratio": 0.8518650850364441,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 569.0954741098213,
      "baseline_run_cnt_delta": 7667,
      "baseline_run_time_ns_delta": 4363255,
      "post_rejit_avg_ns_per_run": 411.44176334106726,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 2659971,
      "program": "generic_kprobe_event",
      "program_id": 50,
      "ratio": 0.722974934890572,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 212.42637276640147,
      "baseline_run_cnt_delta": 7667,
      "baseline_run_time_ns_delta": 1628673,
      "post_rejit_avg_ns_per_run": 50.94555297757154,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 329363,
      "program": "generic_retkprobe_event",
      "program_id": 57,
      "ratio": 0.23982687419699408,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 943.4925954793453,
      "baseline_run_cnt_delta": 8981,
      "baseline_run_time_ns_delta": 8473507,
      "post_rejit_avg_ns_per_run": 933.3896365042536,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 6034364,
      "program": "generic_kprobe_event",
      "program_id": 65,
      "ratio": 0.9892919573258985,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 579.1242989435242,
      "baseline_run_cnt_delta": 7667,
      "baseline_run_time_ns_delta": 4440146,
      "post_rejit_avg_ns_per_run": 416.8957463263728,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 2695231,
      "program": "generic_kprobe_event",
      "program_id": 77,
      "ratio": 0.7198726544317011,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 229.967131863832,
      "baseline_run_cnt_delta": 7667,
      "baseline_run_time_ns_delta": 1763158,
      "post_rejit_avg_ns_per_run": 52.46883217324053,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 339211,
      "program": "generic_retkprobe_event",
      "program_id": 82,
      "ratio": 0.22815796217482218,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1006.3212770707747,
      "baseline_run_cnt_delta": 8958,
      "baseline_run_time_ns_delta": 9014626,
      "post_rejit_avg_ns_per_run": 1015.8935808197989,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 6567752,
      "program": "generic_kprobe_event",
      "program_id": 90,
      "ratio": 1.0095121746574687,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 520.1692341351041,
      "baseline_run_cnt_delta": 77703,
      "baseline_run_time_ns_delta": 40418710,
      "post_rejit_avg_ns_per_run": 412.5905837281984,
      "post_rejit_run_cnt_delta": 59514,
      "post_rejit_run_time_ns_delta": 24554916,
      "program": "generic_kprobe_event",
      "program_id": 97,
      "ratio": 0.7931852878885101,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 526.1043976047303,
      "baseline_run_cnt_delta": 79657,
      "baseline_run_time_ns_delta": 41907898,
      "post_rejit_avg_ns_per_run": 423.4104352360312,
      "post_rejit_run_cnt_delta": 61369,
      "post_rejit_run_time_ns_delta": 25984275,
      "program": "generic_kprobe_event",
      "program_id": 100,
      "ratio": 0.8048030717168525,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 220.8694481553797,
      "baseline_run_cnt_delta": 48655,
      "baseline_run_time_ns_delta": 10746403,
      "post_rejit_avg_ns_per_run": 194.25890891654498,
      "post_rejit_run_cnt_delta": 45881,
      "post_rejit_run_time_ns_delta": 8912793,
      "program": "generic_kprobe_event",
      "program_id": 122,
      "ratio": 0.8795191482521637,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 662.244088057964,
      "baseline_run_cnt_delta": 57553,
      "baseline_run_time_ns_delta": 38114134,
      "post_rejit_avg_ns_per_run": 630.6097268973175,
      "post_rejit_run_cnt_delta": 57634,
      "post_rejit_run_time_ns_delta": 36344561,
      "program": "generic_kprobe_event",
      "program_id": 133,
      "ratio": 0.9522315687960092,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 51.44809132451827,
      "baseline_run_cnt_delta": 57553,
      "baseline_run_time_ns_delta": 2960992,
      "post_rejit_avg_ns_per_run": 46.25306242842766,
      "post_rejit_run_cnt_delta": 57634,
      "post_rejit_run_time_ns_delta": 2665749,
      "program": "generic_retkprobe_event",
      "program_id": 137,
      "ratio": 0.899023875087571,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3152.0396341463415,
      "baseline_run_cnt_delta": 4264,
      "baseline_run_time_ns_delta": 13440297,
      "post_rejit_avg_ns_per_run": 2627.4403513051966,
      "post_rejit_run_cnt_delta": 4099,
      "post_rejit_run_time_ns_delta": 10769878,
      "program": "generic_kprobe_event",
      "program_id": 144,
      "ratio": 0.8335683101322358,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 78.86280487804878,
      "baseline_run_cnt_delta": 4264,
      "baseline_run_time_ns_delta": 336271,
      "post_rejit_avg_ns_per_run": 67.79995120761161,
      "post_rejit_run_cnt_delta": 4099,
      "post_rejit_run_time_ns_delta": 277912,
      "program": "generic_retkprobe_event",
      "program_id": 148,
      "ratio": 0.8597202611859361,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6671.9047619047615,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 140110,
      "post_rejit_avg_ns_per_run": 5667.428571428572,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 119016,
      "program": "generic_kprobe_event",
      "program_id": 198,
      "ratio": 0.8494468631789309,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 588.7943853635925,
      "baseline_run_cnt_delta": 6454808,
      "baseline_run_time_ns_delta": 3800554709,
      "post_rejit_avg_ns_per_run": 589.5806516584423,
      "post_rejit_run_cnt_delta": 7318343,
      "post_rejit_run_time_ns_delta": 4314753435,
      "program": "generic_tracepoint_event",
      "program_id": 208,
      "ratio": 1.0013353834791823,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6411.238095238095,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 134636,
      "post_rejit_avg_ns_per_run": 5238.476190476191,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 110008,
      "program": "generic_rawtp_event",
      "program_id": 215,
      "ratio": 0.8170771561840816,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 827.6938097216452,
      "baseline_run_cnt_delta": 2407,
      "baseline_run_time_ns_delta": 1992259,
      "post_rejit_avg_ns_per_run": 430.04968383017166,
      "post_rejit_run_cnt_delta": 1107,
      "post_rejit_run_time_ns_delta": 476065,
      "program": "generic_kprobe_event",
      "program_id": 219,
      "ratio": 0.5195758126725608,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 5215.731152993348,
      "baseline_run_cnt_delta": 1804,
      "baseline_run_time_ns_delta": 9409179,
      "post_rejit_avg_ns_per_run": 4352.315410199557,
      "post_rejit_run_cnt_delta": 1804,
      "post_rejit_run_time_ns_delta": 7851577,
      "program": "generic_kprobe_event",
      "program_id": 228,
      "ratio": 0.8344593082988432,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 596.9250032607277,
      "baseline_run_cnt_delta": 7667,
      "baseline_run_time_ns_delta": 4576624,
      "post_rejit_avg_ns_per_run": 424.7622583139985,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 2746088,
      "program": "generic_kprobe_event",
      "program_id": 243,
      "ratio": 0.7115839611236201,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 219.36389722185993,
      "baseline_run_cnt_delta": 7667,
      "baseline_run_time_ns_delta": 1681863,
      "post_rejit_avg_ns_per_run": 48.67703016241299,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 314697,
      "program": "generic_retkprobe_event",
      "program_id": 246,
      "ratio": 0.22190082679458456,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1036.4140433132395,
      "baseline_run_cnt_delta": 8958,
      "baseline_run_time_ns_delta": 9284197,
      "post_rejit_avg_ns_per_run": 1016.4702242846095,
      "post_rejit_run_cnt_delta": 6465,
      "post_rejit_run_time_ns_delta": 6571480,
      "program": "generic_kprobe_event",
      "program_id": 254,
      "ratio": 0.9807569000465557,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2023.5555555555557,
      "baseline_run_cnt_delta": 9,
      "baseline_run_time_ns_delta": 18212,
      "post_rejit_avg_ns_per_run": 3388.25,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 27106,
      "program": "generic_kprobe_event",
      "program_id": 256,
      "ratio": 1.674404238963321,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3393.6666666666665,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 10181,
      "post_rejit_avg_ns_per_run": 5802.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 17406,
      "program": "generic_kprobe_event",
      "program_id": 264,
      "ratio": 1.7096552401532268,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3265.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 3265,
      "post_rejit_avg_ns_per_run": 9655.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 9655,
      "program": "generic_kprobe_event",
      "program_id": 272,
      "ratio": 2.9571209800918834,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1984.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 1984,
      "post_rejit_avg_ns_per_run": 6432.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 6432,
      "program": "generic_retkprobe_event",
      "program_id": 278,
      "ratio": 3.2419354838709675,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7092.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 7092,
      "post_rejit_avg_ns_per_run": 13991.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 13991,
      "program": "generic_kprobe_event",
      "program_id": 285,
      "ratio": 1.9727862380146644,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3979.0,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 11937,
      "post_rejit_avg_ns_per_run": 4039.6666666666665,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 12119,
      "program": "generic_kprobe_event",
      "program_id": 289,
      "ratio": 1.0152467119041635,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 643.0364481409002,
      "baseline_run_cnt_delta": 102200,
      "baseline_run_time_ns_delta": 65718325,
      "post_rejit_avg_ns_per_run": 605.4393150684931,
      "post_rejit_run_cnt_delta": 102200,
      "post_rejit_run_time_ns_delta": 61875898,
      "program": "generic_kprobe_event",
      "program_id": 296,
      "ratio": 0.9415318786655015,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    }
  ],
  "results": [
    {
      "app": "tetragon/observer",
      "baseline": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 1115.9495327102804,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 18,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1070,
            "run_time_ns_delta": 1194066,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 1542.3703703703704,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 20,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1080,
            "run_time_ns_delta": 1665760,
            "type": "kprobe"
          },
          "21": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 21,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "22": {
            "avg_ns_per_run": 8608.285714285714,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 22,
            "name": "event_execve",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 180774,
            "type": "tracepoint"
          },
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 1381,
            "bytes_xlated": 2352,
            "id": 23,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "24": {
            "avg_ns_per_run": 666.3809523809524,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 24,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 13994,
            "type": "kprobe"
          },
          "25": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 25,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "28": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 28,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 29,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 30,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 31,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 32,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 33,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 34,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 35,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 36,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 37,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 38,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 39,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 40,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 41,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "42": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 42,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 43,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 44,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 45,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 46,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 47,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 48,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 49,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": 569.0954741098213,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 50,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7667,
            "run_time_ns_delta": 4363255,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 52,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 53,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 54,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 55,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 56,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "avg_ns_per_run": 212.42637276640147,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 57,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7667,
            "run_time_ns_delta": 1628673,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 58,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 59,
            "name": "generic_retkprobe_output",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 61,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 63,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 64,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "avg_ns_per_run": 943.4925954793453,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 65,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8981,
            "run_time_ns_delta": 8473507,
            "type": "kprobe"
          },
          "66": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 66,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 67,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 68,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 69,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 70,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 71,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 72,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 73,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 74,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 75,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 76,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "77": {
            "avg_ns_per_run": 579.1242989435242,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 77,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7667,
            "run_time_ns_delta": 4440146,
            "type": "kprobe"
          },
          "78": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 78,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 79,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 80,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 81,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": 229.967131863832,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 82,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7667,
            "run_time_ns_delta": 1763158,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 83,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 84,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 85,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 86,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 87,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 1006.3212770707747,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 90,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8958,
            "run_time_ns_delta": 9014626,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 91,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 93,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 94,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 95,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": 520.1692341351041,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 97,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 77703,
            "run_time_ns_delta": 40418710,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 98,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 99,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": 526.1043976047303,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 100,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 79657,
            "run_time_ns_delta": 41907898,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 101,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 102,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 103,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 104,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 105,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 106,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 107,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 108,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 109,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 110,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "111": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 111,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 112,
            "name": "generic_kprobe_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 114,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 115,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 116,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 117,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 118,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 119,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 120,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 121,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "avg_ns_per_run": 220.8694481553797,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 122,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 48655,
            "run_time_ns_delta": 10746403,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 123,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 124,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 125,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 127,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 128,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 129,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 131,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 132,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "133": {
            "avg_ns_per_run": 662.244088057964,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 133,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57553,
            "run_time_ns_delta": 38114134,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 134,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 135,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 136,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": 51.44809132451827,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 137,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57553,
            "run_time_ns_delta": 2960992,
            "type": "kprobe"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 138,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 140,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 141,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 142,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 143,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": 3152.0396341463415,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 144,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4264,
            "run_time_ns_delta": 13440297,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 145,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 146,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 147,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": 78.86280487804878,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 148,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4264,
            "run_time_ns_delta": 336271,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": 6889.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 149,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 6889,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 150,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 151,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 152,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 153,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 154,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 155,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 156,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": 451.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 157,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 451,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 158,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 159,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 160,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 161,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 162,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 163,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 164,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 165,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 167,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 168,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "169": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 169,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "170": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 170,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "171": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 171,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 172,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 173,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 174,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 175,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 176,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 177,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 178,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "179": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 179,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "180": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 180,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 181,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 182,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 183,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 184,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 185,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 186,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 188,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 189,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 190,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 191,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 192,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 193,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 194,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 195,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 196,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 197,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": 6671.9047619047615,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 198,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 140110,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 199,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 200,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 201,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 202,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 203,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 204,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 205,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 206,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 207,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "208": {
            "avg_ns_per_run": 588.7943853635925,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 208,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6454808,
            "run_time_ns_delta": 3800554709,
            "type": "tracepoint"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 209,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 210,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 211,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 212,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 213,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 214,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "215": {
            "avg_ns_per_run": 6411.238095238095,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 215,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 134636,
            "type": "raw_tracepoint"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 216,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 217,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 218,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": 827.6938097216452,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 219,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2407,
            "run_time_ns_delta": 1992259,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 220,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 221,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 222,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 223,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 224,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 225,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 226,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 227,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": 5215.731152993348,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 228,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1804,
            "run_time_ns_delta": 9409179,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 229,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 230,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 231,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 233,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 234,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 235,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 236,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 238,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 239,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 240,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 241,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 242,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": 596.9250032607277,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 243,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7667,
            "run_time_ns_delta": 4576624,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 244,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 245,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": 219.36389722185993,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 246,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7667,
            "run_time_ns_delta": 1681863,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 247,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 248,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 249,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 250,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 251,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 252,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 1036.4140433132395,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 254,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8958,
            "run_time_ns_delta": 9284197,
            "type": "kprobe"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 255,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "avg_ns_per_run": 2023.5555555555557,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 256,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 9,
            "run_time_ns_delta": 18212,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 257,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 258,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 259,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 260,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 261,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 262,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 263,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": 3393.6666666666665,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 264,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 10181,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 265,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 266,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 267,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 268,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 269,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 270,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 271,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": 3265.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 272,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 3265,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 273,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 275,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 276,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 277,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": 1984.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 278,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1984,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 279,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 280,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 281,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 284,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": 7092.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 285,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 7092,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 286,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 287,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 288,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": 3979.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 289,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 11937,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 290,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 291,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 292,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 293,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 294,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 295,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": 643.0364481409002,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 296,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102200,
            "run_time_ns_delta": 65718325,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 297,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 298,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 299,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 300,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 301,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 302,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 303,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 304,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 305,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 306,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 307,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.9057251180000208,
            "ops_per_sec": 2879.618933797158,
            "ops_total": 11247.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4122]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4122] sockdiag           1012      0.00      0.00      0.00   1030501.49      515274.95\nstress-ng: info:  [4122] skipped: 0\nstress-ng: info:  [4122] passed: 1: sockdiag (1)\nstress-ng: info:  [4122] failed: 0\nstress-ng: info:  [4122] metrics untrustworthy: 0\nstress-ng: info:  [4122] successful run completed in 0.00 secs\nstress-ng: info:  [4124] setting to a 1 secs run per stressor\nstress-ng: info:  [4124] dispatching hogs: 1 sockfd\nstress-ng: info:  [4124] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4124] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4124]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4124] sockfd              200      0.00      0.00      0.00     96454.04       56132.47\nstress-ng: info:  [4124] skipped: 0\nstress-ng: info:  [4124] passed: 1: sockfd (1)\nstress-ng: info:  [4124] failed: 0\nstress-ng: info:  [4124] metrics untrustworthy: 0\nstress-ng: info:  [4124] successful run completed in 0.00 secs\nstress-ng: info:  [4127] setting to a 1 secs run per stressor\nstress-ng: info:  [4127] dispatching hogs: 1 sockpair\nstress-ng: info:  [4127] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4127] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4127]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4127] sockpair            500      0.04      0.00      0.05     11534.22       10241.07\nstress-ng: info:  [4127] skipped: 0\nstress-ng: info:  [4127] passed: 1: sockpair (1)\nstress-ng: info:  [4127] failed: 0\nstress-ng: info:  [4127] metrics untrustworthy: 0\nstress-ng: info:  [4127] successful run completed in 0.05 secs\nstress-ng: info:  [4131] setting to a 1 secs run per stressor\nstress-ng: info:  [4131] dispatching hogs: 1 udp-flood\nstress-ng: info:  [4131] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4131] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4131]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4131] udp-flood          1000      0.00      0.00      0.00    216536.09      204918.03\nstress-ng: info:  [4131] skipped: 0\nstress-ng: info:  [4131] passed: 1: udp-flood (1)\nstress-ng: info:  [4131] failed: 0\nstress-ng: info:  [4131] metrics untrustworthy: 0\nstress-ng: info:  [4131] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "",
      "post_rejit": {
        "bpf": {
          "18": {
            "avg_ns_per_run": 1097.6058052434457,
            "bytes_jited": 1029,
            "bytes_xlated": 1872,
            "id": 18,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1068,
            "run_time_ns_delta": 1172243,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 1273.474025974026,
            "bytes_jited": 7128,
            "bytes_xlated": 11152,
            "id": 20,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1078,
            "run_time_ns_delta": 1372805,
            "type": "kprobe"
          },
          "21": {
            "avg_ns_per_run": null,
            "bytes_jited": 4992,
            "bytes_xlated": 8064,
            "id": 21,
            "name": "execve_send",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "22": {
            "avg_ns_per_run": 6835.761904761905,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 22,
            "name": "event_execve",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 143551,
            "type": "tracepoint"
          },
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 1395,
            "bytes_xlated": 2416,
            "id": 23,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "24": {
            "avg_ns_per_run": 567.6666666666666,
            "bytes_jited": 1541,
            "bytes_xlated": 2592,
            "id": 24,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 11921,
            "type": "kprobe"
          },
          "25": {
            "avg_ns_per_run": null,
            "bytes_jited": 303,
            "bytes_xlated": 504,
            "id": 25,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "28": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 28,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 29,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 30,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 31,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 32,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 33,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 34,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 35,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 36,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 37,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 38,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 39,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 40,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 41,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "42": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 42,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 43,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 44,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 45,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 46,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "47": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 47,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "48": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 48,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 49,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": 411.44176334106726,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 50,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 2659971,
            "type": "kprobe"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 51,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 52,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 53,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 54,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 55,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 56,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "avg_ns_per_run": 50.94555297757154,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 57,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 329363,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 58,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 59,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 60,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 61,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 62,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 63,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 64,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "avg_ns_per_run": 933.3896365042536,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 65,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 6034364,
            "type": "kprobe"
          },
          "66": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 66,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 67,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 68,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 69,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 70,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 71,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 72,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 73,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 74,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 75,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 76,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "77": {
            "avg_ns_per_run": 416.8957463263728,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 77,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 2695231,
            "type": "kprobe"
          },
          "78": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 78,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 79,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 80,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 81,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": 52.46883217324053,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 82,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 339211,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 83,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 84,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 85,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 86,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 87,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
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
            "avg_ns_per_run": 1015.8935808197989,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 90,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 6567752,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 91,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 93,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 94,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 95,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 96,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "avg_ns_per_run": 412.5905837281984,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 97,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 59514,
            "run_time_ns_delta": 24554916,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 98,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 99,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": 423.4104352360312,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 100,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 61369,
            "run_time_ns_delta": 25984275,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 101,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 102,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 103,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 104,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "105": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 105,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "106": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 106,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 107,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 108,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 109,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 110,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "111": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 111,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "112": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 112,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 113,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 114,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 115,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 116,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 117,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 118,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 119,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 120,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 121,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "avg_ns_per_run": 194.25890891654498,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 122,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 45881,
            "run_time_ns_delta": 8912793,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 123,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 124,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 125,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 126,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 127,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 128,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 129,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 130,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "131": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 131,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "132": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 132,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "133": {
            "avg_ns_per_run": 630.6097268973175,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 133,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57634,
            "run_time_ns_delta": 36344561,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 134,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 135,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 136,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": 46.25306242842766,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 137,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57634,
            "run_time_ns_delta": 2665749,
            "type": "kprobe"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 138,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 139,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 140,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "141": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 141,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "142": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 142,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 143,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": 2627.4403513051966,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 144,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4099,
            "run_time_ns_delta": 10769878,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 145,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "146": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 146,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "147": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 147,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": 67.79995120761161,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 148,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4099,
            "run_time_ns_delta": 277912,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 149,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 150,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 151,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 152,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 153,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 154,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 155,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 156,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 157,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 158,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "159": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 159,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "160": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 160,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 161,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 162,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 163,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 164,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 165,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 166,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "167": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 167,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "168": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 168,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "169": {
            "avg_ns_per_run": null,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 169,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "170": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 170,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "171": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 171,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 172,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 173,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 174,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 175,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 176,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 177,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 178,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "179": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 179,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "180": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 180,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 181,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 182,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 183,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 184,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 185,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 186,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 187,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 188,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 189,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "190": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 190,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "191": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 191,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 192,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 193,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 194,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 195,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 196,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 197,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": 5667.428571428572,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 198,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 119016,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 199,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 200,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 201,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 202,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": null,
            "bytes_jited": 14893,
            "bytes_xlated": 25800,
            "id": 203,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 204,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 11118,
            "bytes_xlated": 18152,
            "id": 205,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 206,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 4781,
            "bytes_xlated": 8648,
            "id": 207,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "208": {
            "avg_ns_per_run": 589.5806516584423,
            "bytes_jited": 10963,
            "bytes_xlated": 19728,
            "id": 208,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 7318343,
            "run_time_ns_delta": 4314753435,
            "type": "tracepoint"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 209,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 210,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 17087,
            "bytes_xlated": 29584,
            "id": 211,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "212": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 212,
            "name": "generic_rawtp_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "213": {
            "avg_ns_per_run": null,
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 213,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "214": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 214,
            "name": "generic_rawtp_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "215": {
            "avg_ns_per_run": 5238.476190476191,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 215,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 110008,
            "type": "raw_tracepoint"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 216,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 217,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 218,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": 430.04968383017166,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 219,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1107,
            "run_time_ns_delta": 476065,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 220,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 221,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 222,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 223,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 224,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 225,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 226,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 227,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": 4352.315410199557,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 228,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1804,
            "run_time_ns_delta": 7851577,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 229,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 230,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 231,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 232,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 233,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 234,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "235": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 235,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "236": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 236,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 238,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 239,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 240,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 241,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 242,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": 424.7622583139985,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 243,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 2746088,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 244,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 245,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": 48.67703016241299,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 246,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 314697,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 247,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 248,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 249,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 250,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 251,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 252,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 253,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": 1016.4702242846095,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 254,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6465,
            "run_time_ns_delta": 6571480,
            "type": "kprobe"
          },
          "255": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 255,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "256": {
            "avg_ns_per_run": 3388.25,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 256,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 27106,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 257,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 258,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 259,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 260,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 261,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 262,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 263,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": 5802.0,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 264,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 17406,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 265,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 266,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 267,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 268,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 269,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 270,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 271,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": 9655.0,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 272,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 9655,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 273,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 275,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "276": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 276,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "277": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 277,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": 6432.0,
            "bytes_jited": 14078,
            "bytes_xlated": 24872,
            "id": 278,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 6432,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 3788,
            "bytes_xlated": 6784,
            "id": 279,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 280,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 281,
            "name": "generic_kprobe_process_filter",
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
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 283,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 284,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": 13991.0,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 285,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 13991,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 286,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 287,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 288,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": 4039.6666666666665,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 289,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 12119,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 290,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 291,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 292,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 293,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 294,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 295,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": 605.4393150684931,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 296,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102200,
            "run_time_ns_delta": 61875898,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 297,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 298,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 299,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 300,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 4923,
            "bytes_xlated": 8912,
            "id": 301,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 17177,
            "bytes_xlated": 29584,
            "id": 302,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 11111,
            "bytes_xlated": 18152,
            "id": 303,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 1324,
            "bytes_xlated": 2272,
            "id": 304,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 1730,
            "bytes_xlated": 3088,
            "id": 305,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 306,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1885,
            "bytes_xlated": 3192,
            "id": 307,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 4.668175824000173,
            "ops_per_sec": 2424.287436179392,
            "ops_total": 11317.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [7806]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7806] sockdiag           1025      0.00      0.00      0.00   2489381.35     1402188.78\nstress-ng: info:  [7806] skipped: 0\nstress-ng: info:  [7806] passed: 1: sockdiag (1)\nstress-ng: info:  [7806] failed: 0\nstress-ng: info:  [7806] metrics untrustworthy: 0\nstress-ng: info:  [7806] successful run completed in 0.00 secs\nstress-ng: info:  [7808] setting to a 1 secs run per stressor\nstress-ng: info:  [7808] dispatching hogs: 1 sockfd\nstress-ng: info:  [7808] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7808] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7808]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7808] sockfd              200      0.00      0.00      0.00    115117.44       70972.32\nstress-ng: info:  [7808] skipped: 0\nstress-ng: info:  [7808] passed: 1: sockfd (1)\nstress-ng: info:  [7808] failed: 0\nstress-ng: info:  [7808] metrics untrustworthy: 0\nstress-ng: info:  [7808] successful run completed in 0.00 secs\nstress-ng: info:  [7811] setting to a 1 secs run per stressor\nstress-ng: info:  [7811] dispatching hogs: 1 sockpair\nstress-ng: info:  [7811] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7811] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7811]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7811] sockpair            500      0.04      0.00      0.05     12114.14       10415.58\nstress-ng: info:  [7811] skipped: 0\nstress-ng: info:  [7811] passed: 1: sockpair (1)\nstress-ng: info:  [7811] failed: 0\nstress-ng: info:  [7811] metrics untrustworthy: 0\nstress-ng: info:  [7811] successful run completed in 0.04 secs\nstress-ng: info:  [7815] setting to a 1 secs run per stressor\nstress-ng: info:  [7815] dispatching hogs: 1 udp-flood\nstress-ng: info:  [7815] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [7815] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [7815]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [7815] udp-flood          1000      0.00      0.00      0.00    220497.53      206568.89\nstress-ng: info:  [7815] skipped: 0\nstress-ng: info:  [7815] passed: 1: udp-flood (1)\nstress-ng: info:  [7815] failed: 0\nstress-ng: info:  [7815] metrics untrustworthy: 0\nstress-ng: info:  [7815] successful run completed in 0.01 secs"
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
        "error": "prog 21: prog 21 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff894d8224f200\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff894d80f5bc00\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...; prog 22: prog 22 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff894d8224f200\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff894d86790400\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff894d86790400\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff894d86790400\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...; prog 28: prog 28 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 38: prog 38 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 47: prog 47 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 55: prog 55 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 58: prog 58 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 64: prog 64 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 71: prog 71 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 76: prog 76 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 81: prog 81 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 89: prog 89 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 92: prog 92 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 105: prog 105 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 108: prog 108 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 114: prog 114 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 125: prog 125 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 128: prog 128 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 134: prog 134 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 140: prog 140 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 146: prog 146 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 154: prog 154 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 158: prog 158 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 163: prog 163 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 167: prog 167 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 174: prog 174 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 179: prog 179 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 185: prog 185 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 190: prog 190 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 201: prog 201 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 206: prog 206 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 212: prog 212 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 222: prog 222 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 225: prog 225 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 235: prog 235 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 237: prog 237 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 244: prog 244 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 248: prog 248 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 258: prog 258 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 262: prog 262 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 274: prog 274 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 276: prog 276 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...; prog 282: prog 282 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 291: prog 291 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 295: prog 295 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...; prog 306: prog 306 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 21 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff894d8224f200\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff894d80f5bc00\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 21
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 22 pass prefetch failed after 5 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff894d8224f200\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff894d86790400\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff894d86790400\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff894d86790400\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 22
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 28 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 28
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 38 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 38
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 47 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 55 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 55
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 58 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 58
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 64 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 64
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 71 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 71
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 76 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 76
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 81 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 81
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 89 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 89
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 92 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 92
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 105 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 105
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 108 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 108
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 114 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 114
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 125 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 125
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 128 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 128
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 134 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 134
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 140 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 140
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 146 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 146
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 154 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 154
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 158 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 158
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 163 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 163
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 167 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 167
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 174 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 174
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 179 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 179
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 185 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 185
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
            "error": "prog 201 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 201
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 206 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 206
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 212 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 212
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 222 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 222
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
            "error": "prog 235 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 235
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 237 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 237
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 244 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 244
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 248 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 248
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 258 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 258
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
            "error": "prog 276 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\n+= -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2019: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2018: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2017: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2016: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2015: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2014: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2013: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 2012: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 2011: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 2010: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 2020: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2017: frame2: R1=90 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90)\n2017: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n2018: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=s\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 276
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 282 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 282
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 291 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 291
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 295 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 295
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 306 pass rotate failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nprecise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 2038: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 2037: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 2036: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 2035: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P87 R2=map_value(map=string_postfix_,ks=4,vs=132,off=86) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-83,smax=smax32=43,umax=0xffffffffffffffad) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x60000001e,var_off=(0x0; 0x7ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n2046: safe\n\nfrom 2045 to 2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=91 R2=map_value(map=string_postfix_,ks=4,vs=132,off=90) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(id=697,smin=smin32=-87,smax=smax32=39,umin=1,umax=0xffffffffffffffa9) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\n2034: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: last_idx 2034 first_idx 2045 subseq_idx -1 \nmark_precise: frame2: regs=r1 stack= before 2045: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 2044: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 2043: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 2042: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 2041: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 2040: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 2039: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 2038: (bf) r3 = r7\nma\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 306
          }
        ],
        "exit_code": 1,
        "program_counts": {
          "applied": 241,
          "not_applied": 46,
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
  "summary": {
    "losses": 8,
    "per_program_geomean": 0.8730858785307171,
    "program_count": 32,
    "wins": 24
  },
  "workload_seconds": 1.0
}
```
