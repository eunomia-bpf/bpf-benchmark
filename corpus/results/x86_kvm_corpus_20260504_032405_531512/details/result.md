# Corpus Benchmark

```json
{
  "daemon": "/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon",
  "generated_at": "2026-05-04T04:04:45.862662+00:00",
  "kop_modules": {
    "captured_at": "2026-05-04T03:24:05.561224+00:00",
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
      "invoked_at": "2026-05-04T03:24:05.561161+00:00",
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
        "captured_at": "2026-05-04T03:24:05.561153+00:00",
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
      "captured_at": "2026-05-04T03:24:05.547951+00:00",
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
      "baseline_avg_ns_per_run": 1024.926168224299,
      "baseline_run_cnt_delta": 1070,
      "baseline_run_time_ns_delta": 1096671,
      "post_rejit_avg_ns_per_run": 949.6367041198502,
      "post_rejit_run_cnt_delta": 1068,
      "post_rejit_run_time_ns_delta": 1014212,
      "program": "event_exit_acct_process",
      "program_id": 19,
      "ratio": 0.9265415730043374,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1354.4653098982424,
      "baseline_run_cnt_delta": 1081,
      "baseline_run_time_ns_delta": 1464177,
      "post_rejit_avg_ns_per_run": 1523.125,
      "post_rejit_run_cnt_delta": 1080,
      "post_rejit_run_time_ns_delta": 1644975,
      "program": "event_wake_up_new_task",
      "program_id": 20,
      "ratio": 1.1245212327471337,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7311.190476190476,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 153535,
      "post_rejit_avg_ns_per_run": 9565.666666666666,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 200879,
      "program": "event_execve",
      "program_id": 22,
      "ratio": 1.3083596574071057,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 684.2857142857143,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 14370,
      "post_rejit_avg_ns_per_run": 792.8095238095239,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 16649,
      "program": "tg_kp_bprm_committing_creds",
      "program_id": 24,
      "ratio": 1.1585942936673626,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 590.561496616691,
      "baseline_run_cnt_delta": 7537,
      "baseline_run_time_ns_delta": 4451062,
      "post_rejit_avg_ns_per_run": 445.4327503974563,
      "post_rejit_run_cnt_delta": 6290,
      "post_rejit_run_time_ns_delta": 2801772,
      "program": "generic_kprobe_event",
      "program_id": 52,
      "ratio": 0.7542529490143314,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 193.8012471805758,
      "baseline_run_cnt_delta": 7537,
      "baseline_run_time_ns_delta": 1460680,
      "post_rejit_avg_ns_per_run": 57.58028616852146,
      "post_rejit_run_cnt_delta": 6290,
      "post_rejit_run_time_ns_delta": 362180,
      "program": "generic_retkprobe_event",
      "program_id": 58,
      "ratio": 0.2971099877126724,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 942.0356644981413,
      "baseline_run_cnt_delta": 8608,
      "baseline_run_time_ns_delta": 8109043,
      "post_rejit_avg_ns_per_run": 865.9998406628425,
      "post_rejit_run_cnt_delta": 6276,
      "post_rejit_run_time_ns_delta": 5435015,
      "program": "generic_kprobe_event",
      "program_id": 63,
      "ratio": 0.9192856208094776,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 591.1775242138782,
      "baseline_run_cnt_delta": 7537,
      "baseline_run_time_ns_delta": 4455705,
      "post_rejit_avg_ns_per_run": 449.56931637519875,
      "post_rejit_run_cnt_delta": 6290,
      "post_rejit_run_time_ns_delta": 2827791,
      "program": "generic_kprobe_event",
      "program_id": 75,
      "ratio": 0.7604641549473928,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 194.84264296139048,
      "baseline_run_cnt_delta": 7537,
      "baseline_run_time_ns_delta": 1468529,
      "post_rejit_avg_ns_per_run": 54.30985691573927,
      "post_rejit_run_cnt_delta": 6290,
      "post_rejit_run_time_ns_delta": 341609,
      "program": "generic_retkprobe_event",
      "program_id": 84,
      "ratio": 0.2787370161392297,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 996.0295074349442,
      "baseline_run_cnt_delta": 8608,
      "baseline_run_time_ns_delta": 8573822,
      "post_rejit_avg_ns_per_run": 955.2115997450605,
      "post_rejit_run_cnt_delta": 6276,
      "post_rejit_run_time_ns_delta": 5994908,
      "program": "generic_kprobe_event",
      "program_id": 85,
      "ratio": 0.9590193790593602,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 446.4850597758592,
      "baseline_run_cnt_delta": 66833,
      "baseline_run_time_ns_delta": 29839936,
      "post_rejit_avg_ns_per_run": 405.0675986701901,
      "post_rejit_run_cnt_delta": 70386,
      "post_rejit_run_time_ns_delta": 28511088,
      "program": "generic_kprobe_event",
      "program_id": 97,
      "ratio": 0.9072366248347454,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 460.7988182043109,
      "baseline_run_cnt_delta": 68709,
      "baseline_run_time_ns_delta": 31661026,
      "post_rejit_avg_ns_per_run": 403.3455731902892,
      "post_rejit_run_cnt_delta": 72332,
      "post_rejit_run_time_ns_delta": 29174792,
      "program": "generic_kprobe_event",
      "program_id": 101,
      "ratio": 0.8753181589355816,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 206.24914583894147,
      "baseline_run_cnt_delta": 48293,
      "baseline_run_time_ns_delta": 9960390,
      "post_rejit_avg_ns_per_run": 220.49055496380672,
      "post_rejit_run_cnt_delta": 46003,
      "post_rejit_run_time_ns_delta": 10143227,
      "program": "generic_kprobe_event",
      "program_id": 125,
      "ratio": 1.0690495423238564,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 622.0354873433105,
      "baseline_run_cnt_delta": 57598,
      "baseline_run_time_ns_delta": 35828000,
      "post_rejit_avg_ns_per_run": 755.613609128328,
      "post_rejit_run_cnt_delta": 57579,
      "post_rejit_run_time_ns_delta": 43507476,
      "program": "generic_kprobe_event",
      "program_id": 133,
      "ratio": 1.214743570910278,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 45.253810896211675,
      "baseline_run_cnt_delta": 57598,
      "baseline_run_time_ns_delta": 2606529,
      "post_rejit_avg_ns_per_run": 49.142847218604004,
      "post_rejit_run_cnt_delta": 57579,
      "post_rejit_run_time_ns_delta": 2829596,
      "program": "generic_retkprobe_event",
      "program_id": 137,
      "ratio": 1.085938316472655,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3680.2106003752347,
      "baseline_run_cnt_delta": 4264,
      "baseline_run_time_ns_delta": 15692418,
      "post_rejit_avg_ns_per_run": 4043.193461819956,
      "post_rejit_run_cnt_delta": 4099,
      "post_rejit_run_time_ns_delta": 16573050,
      "program": "generic_kprobe_event",
      "program_id": 144,
      "ratio": 1.0986310026409118,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 71.18363039399625,
      "baseline_run_cnt_delta": 4264,
      "baseline_run_time_ns_delta": 303527,
      "post_rejit_avg_ns_per_run": 82.84435228104415,
      "post_rejit_run_cnt_delta": 4099,
      "post_rejit_run_time_ns_delta": 339579,
      "program": "generic_retkprobe_event",
      "program_id": 145,
      "ratio": 1.163811845820544,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 6378.428571428572,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 133947,
      "post_rejit_avg_ns_per_run": 6982.619047619048,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 146635,
      "program": "generic_kprobe_event",
      "program_id": 199,
      "ratio": 1.0947240326397754,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 588.8095972804718,
      "baseline_run_cnt_delta": 6294033,
      "baseline_run_time_ns_delta": 3705987036,
      "post_rejit_avg_ns_per_run": 586.1414995180361,
      "post_rejit_run_cnt_delta": 6195484,
      "post_rejit_run_time_ns_delta": 3631430282,
      "program": "generic_tracepoint_event",
      "program_id": 203,
      "ratio": 0.9954686578229043,
      "runner": "tetragon",
      "type": "tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4623.238095238095,
      "baseline_run_cnt_delta": 21,
      "baseline_run_time_ns_delta": 97088,
      "post_rejit_avg_ns_per_run": 5714.619047619048,
      "post_rejit_run_cnt_delta": 21,
      "post_rejit_run_time_ns_delta": 120007,
      "program": "generic_rawtp_event",
      "program_id": 214,
      "ratio": 1.2360641891891893,
      "runner": "tetragon",
      "type": "raw_tracepoint",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 727.0680459770115,
      "baseline_run_cnt_delta": 2175,
      "baseline_run_time_ns_delta": 1581373,
      "post_rejit_avg_ns_per_run": 490.95982142857144,
      "post_rejit_run_cnt_delta": 1120,
      "post_rejit_run_time_ns_delta": 549875,
      "program": "generic_kprobe_event",
      "program_id": 218,
      "ratio": 0.6752597974084185,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4576.2771618625275,
      "baseline_run_cnt_delta": 1804,
      "baseline_run_time_ns_delta": 8255604,
      "post_rejit_avg_ns_per_run": 5588.470620842572,
      "post_rejit_run_cnt_delta": 1804,
      "post_rejit_run_time_ns_delta": 10081601,
      "program": "generic_kprobe_event",
      "program_id": 224,
      "ratio": 1.2211827263032482,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 614.2000796072708,
      "baseline_run_cnt_delta": 7537,
      "baseline_run_time_ns_delta": 4629226,
      "post_rejit_avg_ns_per_run": 463.1683624801272,
      "post_rejit_run_cnt_delta": 6290,
      "post_rejit_run_time_ns_delta": 2913329,
      "program": "generic_kprobe_event",
      "program_id": 241,
      "ratio": 0.7541001342368505,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 196.43067533501394,
      "baseline_run_cnt_delta": 7537,
      "baseline_run_time_ns_delta": 1480498,
      "post_rejit_avg_ns_per_run": 57.61399046104928,
      "post_rejit_run_cnt_delta": 6290,
      "post_rejit_run_time_ns_delta": 362392,
      "program": "generic_retkprobe_event",
      "program_id": 244,
      "ratio": 0.293304446277488,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 1005.7565055762082,
      "baseline_run_cnt_delta": 8608,
      "baseline_run_time_ns_delta": 8657552,
      "post_rejit_avg_ns_per_run": 955.8183556405354,
      "post_rejit_run_cnt_delta": 6276,
      "post_rejit_run_time_ns_delta": 5998716,
      "program": "generic_kprobe_event",
      "program_id": 253,
      "ratio": 0.9503476739560708,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2545.375,
      "baseline_run_cnt_delta": 8,
      "baseline_run_time_ns_delta": 20363,
      "post_rejit_avg_ns_per_run": 2710.25,
      "post_rejit_run_cnt_delta": 8,
      "post_rejit_run_time_ns_delta": 21682,
      "program": "generic_kprobe_event",
      "program_id": 258,
      "ratio": 1.0647743456268723,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 3987.6666666666665,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 11963,
      "post_rejit_avg_ns_per_run": 5334.0,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 16002,
      "program": "generic_kprobe_event",
      "program_id": 264,
      "ratio": 1.3376243417203044,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4390.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 4390,
      "post_rejit_avg_ns_per_run": 4296.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 4296,
      "program": "generic_kprobe_event",
      "program_id": 269,
      "ratio": 0.9785876993166287,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 2495.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 2495,
      "post_rejit_avg_ns_per_run": 1935.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 1935,
      "program": "generic_retkprobe_event",
      "program_id": 278,
      "ratio": 0.7755511022044088,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 7977.0,
      "baseline_run_cnt_delta": 1,
      "baseline_run_time_ns_delta": 7977,
      "post_rejit_avg_ns_per_run": 7314.0,
      "post_rejit_run_cnt_delta": 1,
      "post_rejit_run_time_ns_delta": 7314,
      "program": "generic_kprobe_event",
      "program_id": 281,
      "ratio": 0.9168860473862355,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 4061.3333333333335,
      "baseline_run_cnt_delta": 3,
      "baseline_run_time_ns_delta": 12184,
      "post_rejit_avg_ns_per_run": 5132.666666666667,
      "post_rejit_run_cnt_delta": 3,
      "post_rejit_run_time_ns_delta": 15398,
      "program": "generic_kprobe_event",
      "program_id": 289,
      "ratio": 1.2637885751805646,
      "runner": "tetragon",
      "type": "kprobe",
      "workload": "stress_ng_os_io_network"
    },
    {
      "app": "tetragon/observer",
      "baseline_avg_ns_per_run": 667.5905088062623,
      "baseline_run_cnt_delta": 102200,
      "baseline_run_time_ns_delta": 68227750,
      "post_rejit_avg_ns_per_run": 618.0186105675147,
      "post_rejit_run_cnt_delta": 102200,
      "post_rejit_run_time_ns_delta": 63161502,
      "program": "generic_kprobe_event",
      "program_id": 296,
      "ratio": 0.9257450524163554,
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
          "19": {
            "avg_ns_per_run": 1024.926168224299,
            "bytes_jited": 1012,
            "bytes_xlated": 1792,
            "id": 19,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1070,
            "run_time_ns_delta": 1096671,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 1354.4653098982424,
            "bytes_jited": 7335,
            "bytes_xlated": 11312,
            "id": 20,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1081,
            "run_time_ns_delta": 1464177,
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
            "avg_ns_per_run": 7311.190476190476,
            "bytes_jited": 11213,
            "bytes_xlated": 20272,
            "id": 22,
            "name": "event_execve",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 153535,
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
            "avg_ns_per_run": 684.2857142857143,
            "bytes_jited": 1533,
            "bytes_xlated": 2560,
            "id": 24,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 14370,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 28,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 29,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 30,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 31,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 32,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 33,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 34,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 35,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 37,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 38,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 39,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 40,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 41,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "42": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 42,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 43,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 44,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 45,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 46,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 48,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 49,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 50,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 51,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "avg_ns_per_run": 590.561496616691,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 52,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7537,
            "run_time_ns_delta": 4451062,
            "type": "kprobe"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 53,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 54,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 55,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 56,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 57,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": 193.8012471805758,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 58,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7537,
            "run_time_ns_delta": 1460680,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 59,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 61,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 62,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "avg_ns_per_run": 942.0356644981413,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 63,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8608,
            "run_time_ns_delta": 8109043,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 64,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 67,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 68,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 69,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 71,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 72,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 73,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 74,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": 591.1775242138782,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 75,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7537,
            "run_time_ns_delta": 4455705,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 76,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 81,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 82,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 83,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": 194.84264296139048,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 84,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7537,
            "run_time_ns_delta": 1468529,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": 996.0295074349442,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 85,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8608,
            "run_time_ns_delta": 8573822,
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 88,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "89": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 89,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 90,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 91,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 92,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 93,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 94,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 95,
            "name": "generic_kprobe_output",
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
            "avg_ns_per_run": 446.4850597758592,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 97,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 66833,
            "run_time_ns_delta": 29839936,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 98,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 99,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 100,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": 460.7988182043109,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 101,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 68709,
            "run_time_ns_delta": 31661026,
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
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 106,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 107,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 108,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 113,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 114,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 115,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 116,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 117,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 118,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 119,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 120,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 122,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 123,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 124,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": 206.24914583894147,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 125,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 48293,
            "run_time_ns_delta": 9960390,
            "type": "kprobe"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 126,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 127,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 128,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 129,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 622.0354873433105,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 133,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57598,
            "run_time_ns_delta": 35828000,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 134,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 135,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 136,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": 45.253810896211675,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 137,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57598,
            "run_time_ns_delta": 2606529,
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
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 139,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 140,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 143,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": 3680.2106003752347,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 144,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4264,
            "run_time_ns_delta": 15692418,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": 71.18363039399625,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 145,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4264,
            "run_time_ns_delta": 303527,
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 147,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 148,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 149,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 150,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 151,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 152,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 153,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": 5318.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 154,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 5318,
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 156,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": 444.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 157,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 444,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 158,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 161,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 162,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 163,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 164,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 166,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 171,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 172,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 173,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 174,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 175,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 176,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 177,
            "name": "generic_kprobe_event",
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
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 179,
            "name": "generic_retkprobe_output",
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
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 181,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 182,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 183,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 184,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 185,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 186,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 188,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 189,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 191,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 192,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 194,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 195,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 196,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 197,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 6378.428571428572,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 199,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 133947,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 200,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 201,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 202,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": 588.8095972804718,
            "bytes_jited": 10899,
            "bytes_xlated": 19392,
            "id": 203,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6294033,
            "run_time_ns_delta": 3705987036,
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
            "bytes_jited": 14876,
            "bytes_xlated": 25720,
            "id": 205,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 11087,
            "bytes_xlated": 17992,
            "id": 206,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 207,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 4754,
            "bytes_xlated": 8504,
            "id": 208,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 741,
            "bytes_xlated": 1176,
            "id": 210,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 211,
            "name": "generic_rawtp_process_filter",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 213,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "214": {
            "avg_ns_per_run": 4623.238095238095,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 214,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 97088,
            "type": "raw_tracepoint"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 17059,
            "bytes_xlated": 29456,
            "id": 215,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 216,
            "name": "generic_kprobe_actions",
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
            "avg_ns_per_run": 727.0680459770115,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 218,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 2175,
            "run_time_ns_delta": 1581373,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 219,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 220,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 221,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 222,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 223,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": 4576.2771618625275,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 224,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1804,
            "run_time_ns_delta": 8255604,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 225,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 226,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 227,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 228,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 229,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 230,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 231,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 232,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 234,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 237,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 238,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 239,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 240,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": 614.2000796072708,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 241,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 7537,
            "run_time_ns_delta": 4629226,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 242,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 243,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": 196.43067533501394,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 244,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 7537,
            "run_time_ns_delta": 1480498,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 245,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 246,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 247,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 248,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 249,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 252,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 1005.7565055762082,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 253,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8608,
            "run_time_ns_delta": 8657552,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 254,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 256,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 257,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": 2545.375,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 258,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 20363,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 259,
            "name": "generic_kprobe_setup_event",
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
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 261,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 262,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 263,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": 3987.6666666666665,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 264,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 11963,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 265,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 266,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 268,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": 4390.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 269,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4390,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 270,
            "name": "generic_kprobe_setup_event",
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
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 272,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 274,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 275,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 3770,
            "bytes_xlated": 6688,
            "id": 277,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": 2495.0,
            "bytes_jited": 14043,
            "bytes_xlated": 24744,
            "id": 278,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 2495,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 799,
            "bytes_xlated": 1360,
            "id": 279,
            "name": "generic_retkprobe_output",
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
            "avg_ns_per_run": 7977.0,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 281,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 7977,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 282,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 283,
            "name": "generic_kprobe_process_filter",
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
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 285,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 286,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 287,
            "name": "generic_kprobe_process_event",
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
            "avg_ns_per_run": 4061.3333333333335,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 289,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 12184,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 290,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 291,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 292,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 293,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 294,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 4893,
            "bytes_xlated": 8752,
            "id": 295,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": 667.5905088062623,
            "bytes_jited": 1722,
            "bytes_xlated": 3056,
            "id": 296,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102200,
            "run_time_ns_delta": 68227750,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 297,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 298,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 1877,
            "bytes_xlated": 3160,
            "id": 299,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 300,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 17149,
            "bytes_xlated": 29456,
            "id": 301,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 1313,
            "bytes_xlated": 2240,
            "id": 302,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 11080,
            "bytes_xlated": 17992,
            "id": 304,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 305,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "duration_s": 3.752028510999992,
            "ops_per_sec": 2987.7171687622135,
            "ops_total": 11210.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [4118]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4118] sockdiag           1012      0.00      0.00      0.00   2712227.25     1813620.07\nstress-ng: info:  [4118] skipped: 0\nstress-ng: info:  [4118] passed: 1: sockdiag (1)\nstress-ng: info:  [4118] failed: 0\nstress-ng: info:  [4118] metrics untrustworthy: 0\nstress-ng: info:  [4118] successful run completed in 0.00 secs\nstress-ng: info:  [4120] setting to a 1 secs run per stressor\nstress-ng: info:  [4120] dispatching hogs: 1 sockfd\nstress-ng: info:  [4120] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4120] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4120]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4120] sockfd              200      0.00      0.00      0.00    140842.98       83507.31\nstress-ng: info:  [4120] skipped: 0\nstress-ng: info:  [4120] passed: 1: sockfd (1)\nstress-ng: info:  [4120] failed: 0\nstress-ng: info:  [4120] metrics untrustworthy: 0\nstress-ng: info:  [4120] successful run completed in 0.00 secs\nstress-ng: info:  [4123] setting to a 1 secs run per stressor\nstress-ng: info:  [4123] dispatching hogs: 1 sockpair\nstress-ng: info:  [4123] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4123] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4123]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4123] sockpair            500      0.04      0.00      0.05     11206.99        9702.71\nstress-ng: info:  [4123] skipped: 0\nstress-ng: info:  [4123] passed: 1: sockpair (1)\nstress-ng: info:  [4123] failed: 0\nstress-ng: info:  [4123] metrics untrustworthy: 0\nstress-ng: info:  [4123] successful run completed in 0.05 secs\nstress-ng: info:  [4127] setting to a 1 secs run per stressor\nstress-ng: info:  [4127] dispatching hogs: 1 udp-flood\nstress-ng: info:  [4127] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [4127] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [4127]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [4127] udp-flood          1000      0.00      0.00      0.00    211940.58      201531.64\nstress-ng: info:  [4127] skipped: 0\nstress-ng: info:  [4127] passed: 1: udp-flood (1)\nstress-ng: info:  [4127] failed: 0\nstress-ng: info:  [4127] metrics untrustworthy: 0\nstress-ng: info:  [4127] successful run completed in 0.01 secs"
          }
        ]
      },
      "error": "prog 21: prog 21 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff88c715005400\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff88c6c73c5000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...; prog 22: prog 22 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff88c715005400\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff88c70072fc00\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff88c70072fc00\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff88c70072fc00\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...; prog 33: prog 33 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 40: prog 40 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 47: prog 47 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 54: prog 54 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 56: prog 56 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 61: prog 61 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 73: prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 77: prog 77 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 82: prog 82 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 91: prog 91 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 93: prog 93 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 105: prog 105 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 111: prog 111 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 119: prog 119 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 123: prog 123 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 131: prog 131 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 135: prog 135 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 141: prog 141 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 146: prog 146 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 153: prog 153 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 156: prog 156 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 166: prog 166 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 167: prog 167 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 175: prog 175 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 181: prog 181 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 183: prog 183 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 190: prog 190 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 196: prog 196 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 207: prog 207 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 212: prog 212 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 221: prog 221 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 229: prog 229 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 235: prog 235 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 240: prog 240 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 245: prog 245 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 252: prog 252 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 255: prog 255 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 268: prog 268 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 275: prog 275 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 276: prog 276 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 285: prog 285 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 292: prog 292 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 298: prog 298 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 305: prog 305 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
      "post_rejit": {
        "bpf": {
          "19": {
            "avg_ns_per_run": 949.6367041198502,
            "bytes_jited": 1029,
            "bytes_xlated": 1872,
            "id": 19,
            "name": "event_exit_acct_process",
            "run_cnt_delta": 1068,
            "run_time_ns_delta": 1014212,
            "type": "kprobe"
          },
          "20": {
            "avg_ns_per_run": 1523.125,
            "bytes_jited": 7049,
            "bytes_xlated": 11032,
            "id": 20,
            "name": "event_wake_up_new_task",
            "run_cnt_delta": 1080,
            "run_time_ns_delta": 1644975,
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
            "avg_ns_per_run": 9565.666666666666,
            "bytes_jited": 11204,
            "bytes_xlated": 20272,
            "id": 22,
            "name": "event_execve",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 200879,
            "type": "tracepoint"
          },
          "23": {
            "avg_ns_per_run": null,
            "bytes_jited": 1394,
            "bytes_xlated": 2416,
            "id": 23,
            "name": "execve_rate",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "24": {
            "avg_ns_per_run": 792.8095238095239,
            "bytes_jited": 1541,
            "bytes_xlated": 2592,
            "id": 24,
            "name": "tg_kp_bprm_committing_creds",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 16649,
            "type": "kprobe"
          },
          "25": {
            "avg_ns_per_run": null,
            "bytes_jited": 133,
            "bytes_xlated": 224,
            "id": 25,
            "name": "execve_map_update",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "socket_filter"
          },
          "28": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 28,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "29": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 29,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "30": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 30,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "31": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 31,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "32": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 32,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "33": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 33,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "34": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 34,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "35": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 35,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "36": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 36,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "37": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 37,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "38": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 38,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "39": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 39,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "40": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 40,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "41": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 41,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "42": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 42,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "43": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 43,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "44": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 44,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "45": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 45,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "46": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 46,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 48,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "49": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 49,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "50": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 50,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "51": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 51,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "52": {
            "avg_ns_per_run": 445.4327503974563,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 52,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6290,
            "run_time_ns_delta": 2801772,
            "type": "kprobe"
          },
          "53": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 53,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "54": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 54,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "55": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 55,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "56": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 56,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "57": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 57,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "58": {
            "avg_ns_per_run": 57.58028616852146,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 58,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6290,
            "run_time_ns_delta": 362180,
            "type": "kprobe"
          },
          "59": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 59,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "60": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 60,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "61": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 61,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "62": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 62,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "63": {
            "avg_ns_per_run": 865.9998406628425,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 63,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6276,
            "run_time_ns_delta": 5435015,
            "type": "kprobe"
          },
          "64": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 64,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "65": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 65,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "66": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 66,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "67": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 67,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "68": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 68,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "69": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 69,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "70": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 70,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "71": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 71,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "72": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 72,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "73": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 73,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "74": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 74,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "75": {
            "avg_ns_per_run": 449.56931637519875,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 75,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6290,
            "run_time_ns_delta": 2827791,
            "type": "kprobe"
          },
          "76": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 76,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
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
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 78,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "79": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 79,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "80": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 80,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "81": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 81,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "82": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 82,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "83": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 83,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "84": {
            "avg_ns_per_run": 54.30985691573927,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 84,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6290,
            "run_time_ns_delta": 341609,
            "type": "kprobe"
          },
          "85": {
            "avg_ns_per_run": 955.2115997450605,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 85,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6276,
            "run_time_ns_delta": 5994908,
            "type": "kprobe"
          },
          "86": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 86,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "87": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 87,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "88": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 88,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "89": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 89,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "90": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 90,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "91": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 91,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "92": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 92,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "93": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 93,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "94": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 94,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "95": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 95,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "96": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 96,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "97": {
            "avg_ns_per_run": 405.0675986701901,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 97,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 70386,
            "run_time_ns_delta": 28511088,
            "type": "kprobe"
          },
          "98": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 98,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "99": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 99,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "100": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 100,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "101": {
            "avg_ns_per_run": 403.3455731902892,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 101,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 72332,
            "run_time_ns_delta": 29174792,
            "type": "kprobe"
          },
          "102": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 102,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "103": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 103,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "104": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
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
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 106,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "107": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 107,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "108": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 108,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "109": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 109,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "110": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 110,
            "name": "generic_kprobe_output",
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
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 112,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "113": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 113,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "114": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 114,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "115": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 115,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "116": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 116,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "117": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 117,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "118": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 118,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "119": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 119,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "120": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 120,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "121": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 121,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "122": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 122,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "123": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 123,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "124": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 124,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "125": {
            "avg_ns_per_run": 220.49055496380672,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 125,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 46003,
            "run_time_ns_delta": 10143227,
            "type": "kprobe"
          },
          "126": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 126,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "127": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 127,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "128": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 128,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "129": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 129,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "130": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
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
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 132,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "133": {
            "avg_ns_per_run": 755.613609128328,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 133,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 57579,
            "run_time_ns_delta": 43507476,
            "type": "kprobe"
          },
          "134": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 134,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "135": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 135,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "136": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 136,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "137": {
            "avg_ns_per_run": 49.142847218604004,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 137,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 57579,
            "run_time_ns_delta": 2829596,
            "type": "kprobe"
          },
          "138": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 138,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "139": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 139,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "140": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 140,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 142,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "143": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 143,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "144": {
            "avg_ns_per_run": 4043.193461819956,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 144,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 4099,
            "run_time_ns_delta": 16573050,
            "type": "kprobe"
          },
          "145": {
            "avg_ns_per_run": 82.84435228104415,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 145,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 4099,
            "run_time_ns_delta": 339579,
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
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 147,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "148": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 148,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "149": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 149,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "150": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 150,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "151": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 151,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "152": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 152,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "153": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 153,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "154": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 154,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "155": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 155,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "156": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 156,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "157": {
            "avg_ns_per_run": null,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 157,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "158": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 158,
            "name": "generic_retkprobe_actions",
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
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 160,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "161": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 161,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "162": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 162,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "163": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 163,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "164": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 164,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "165": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 165,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "166": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 166,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 168,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "169": {
            "avg_ns_per_run": null,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
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
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 171,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "172": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 172,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "173": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 173,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "174": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 174,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "175": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 175,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "176": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 176,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "177": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 177,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "178": {
            "avg_ns_per_run": null,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 178,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "179": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 179,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "180": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 180,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "181": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 181,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "182": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 182,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "183": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 183,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "184": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 184,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "185": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 185,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "186": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 186,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "187": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 187,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "188": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 188,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "189": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 189,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 191,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "192": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 192,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "193": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 193,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "194": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 194,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "195": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 195,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "196": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 196,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "197": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 197,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "198": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 198,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "199": {
            "avg_ns_per_run": 6982.619047619048,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 199,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 146635,
            "type": "kprobe"
          },
          "200": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 200,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "201": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 201,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "202": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 202,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "203": {
            "avg_ns_per_run": 586.1414995180361,
            "bytes_jited": 10878,
            "bytes_xlated": 19560,
            "id": 203,
            "name": "generic_tracepoint_event",
            "run_cnt_delta": 6195484,
            "run_time_ns_delta": 3631430282,
            "type": "tracepoint"
          },
          "204": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 204,
            "name": "generic_tracepoint_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "205": {
            "avg_ns_per_run": null,
            "bytes_jited": 14811,
            "bytes_xlated": 25712,
            "id": 205,
            "name": "generic_tracepoint_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "206": {
            "avg_ns_per_run": null,
            "bytes_jited": 11046,
            "bytes_xlated": 18008,
            "id": 206,
            "name": "generic_tracepoint_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "207": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 207,
            "name": "generic_tracepoint_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "208": {
            "avg_ns_per_run": null,
            "bytes_jited": 4673,
            "bytes_xlated": 8456,
            "id": 208,
            "name": "generic_tracepoint_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "tracepoint"
          },
          "209": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 209,
            "name": "generic_rawtp_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "210": {
            "avg_ns_per_run": null,
            "bytes_jited": 721,
            "bytes_xlated": 1152,
            "id": 210,
            "name": "generic_rawtp_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "211": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 211,
            "name": "generic_rawtp_process_filter",
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
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 213,
            "name": "generic_rawtp_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "214": {
            "avg_ns_per_run": 5714.619047619048,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 214,
            "name": "generic_rawtp_event",
            "run_cnt_delta": 21,
            "run_time_ns_delta": 120007,
            "type": "raw_tracepoint"
          },
          "215": {
            "avg_ns_per_run": null,
            "bytes_jited": 16984,
            "bytes_xlated": 29472,
            "id": 215,
            "name": "generic_rawtp_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "raw_tracepoint"
          },
          "216": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 216,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "217": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 217,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "218": {
            "avg_ns_per_run": 490.95982142857144,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 218,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1120,
            "run_time_ns_delta": 549875,
            "type": "kprobe"
          },
          "219": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 219,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "220": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 220,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "221": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 221,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "222": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 222,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "223": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 223,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "224": {
            "avg_ns_per_run": 5588.470620842572,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 224,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1804,
            "run_time_ns_delta": 10081601,
            "type": "kprobe"
          },
          "225": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 225,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "226": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 226,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "227": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 227,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "228": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 228,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "229": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 229,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "230": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 230,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "231": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 231,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "232": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 232,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "233": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 233,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "234": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 234,
            "name": "generic_kprobe_actions",
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
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 236,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "237": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 237,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "238": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 238,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "239": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 239,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "240": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 240,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "241": {
            "avg_ns_per_run": 463.1683624801272,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 241,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6290,
            "run_time_ns_delta": 2913329,
            "type": "kprobe"
          },
          "242": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 242,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "243": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 243,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "244": {
            "avg_ns_per_run": 57.61399046104928,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 244,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 6290,
            "run_time_ns_delta": 362392,
            "type": "kprobe"
          },
          "245": {
            "avg_ns_per_run": null,
            "bytes_jited": 10581,
            "bytes_xlated": 17344,
            "id": 245,
            "name": "generic_retkprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "246": {
            "avg_ns_per_run": null,
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 246,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "247": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 247,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "248": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 248,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "249": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 249,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "250": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 250,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "251": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 251,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "252": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 252,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "253": {
            "avg_ns_per_run": 955.8183556405354,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 253,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 6276,
            "run_time_ns_delta": 5998716,
            "type": "kprobe"
          },
          "254": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 254,
            "name": "generic_kprobe_process_event",
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
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 256,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "257": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 257,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "258": {
            "avg_ns_per_run": 2710.25,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 258,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 8,
            "run_time_ns_delta": 21682,
            "type": "kprobe"
          },
          "259": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 259,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "260": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 260,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "261": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 261,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "262": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 262,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "263": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 263,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "264": {
            "avg_ns_per_run": 5334.0,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 264,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 16002,
            "type": "kprobe"
          },
          "265": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 265,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "266": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 266,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "267": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 267,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "268": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 268,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "269": {
            "avg_ns_per_run": 4296.0,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 269,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 4296,
            "type": "kprobe"
          },
          "270": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 270,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "271": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 271,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "272": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 272,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "273": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 273,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "274": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 274,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "275": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 275,
            "name": "generic_kprobe_filter_arg",
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
            "bytes_jited": 3737,
            "bytes_xlated": 6664,
            "id": 277,
            "name": "generic_retkprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "278": {
            "avg_ns_per_run": 1935.0,
            "bytes_jited": 13985,
            "bytes_xlated": 24784,
            "id": 278,
            "name": "generic_retkprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 1935,
            "type": "kprobe"
          },
          "279": {
            "avg_ns_per_run": null,
            "bytes_jited": 807,
            "bytes_xlated": 1392,
            "id": 279,
            "name": "generic_retkprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "280": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 280,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "281": {
            "avg_ns_per_run": 7314.0,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 281,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 1,
            "run_time_ns_delta": 7314,
            "type": "kprobe"
          },
          "282": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 282,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "283": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 283,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "284": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 284,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "285": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 285,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "286": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 286,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "287": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 287,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "288": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 288,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "289": {
            "avg_ns_per_run": 5132.666666666667,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 289,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 3,
            "run_time_ns_delta": 15398,
            "type": "kprobe"
          },
          "290": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 290,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "291": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 291,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "292": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 292,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "293": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 293,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "294": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 294,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "295": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 295,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "296": {
            "avg_ns_per_run": 618.0186105675147,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 296,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 102200,
            "run_time_ns_delta": 63161502,
            "type": "kprobe"
          },
          "297": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 297,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "298": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 298,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "299": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 299,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "300": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 300,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "301": {
            "avg_ns_per_run": null,
            "bytes_jited": 17074,
            "bytes_xlated": 29472,
            "id": 301,
            "name": "generic_kprobe_process_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "302": {
            "avg_ns_per_run": null,
            "bytes_jited": 1280,
            "bytes_xlated": 2200,
            "id": 302,
            "name": "generic_kprobe_setup_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "303": {
            "avg_ns_per_run": null,
            "bytes_jited": 4815,
            "bytes_xlated": 8720,
            "id": 303,
            "name": "generic_kprobe_actions",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "304": {
            "avg_ns_per_run": null,
            "bytes_jited": 11039,
            "bytes_xlated": 18008,
            "id": 304,
            "name": "generic_kprobe_process_filter",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "305": {
            "avg_ns_per_run": null,
            "bytes_jited": 10676,
            "bytes_xlated": 17544,
            "id": 305,
            "name": "generic_kprobe_filter_arg",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "306": {
            "avg_ns_per_run": null,
            "bytes_jited": 1826,
            "bytes_xlated": 3104,
            "id": 306,
            "name": "generic_kprobe_output",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          },
          "307": {
            "avg_ns_per_run": null,
            "bytes_jited": 1716,
            "bytes_xlated": 3064,
            "id": 307,
            "name": "generic_kprobe_event",
            "run_cnt_delta": 0,
            "run_time_ns_delta": 0,
            "type": "kprobe"
          }
        },
        "workloads": [
          {
            "duration_s": 3.7467443089999506,
            "ops_per_sec": 3028.229060826512,
            "ops_total": 11346.0,
            "stderr": "",
            "stdout": "stress-ng: metrc: [9275]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9275] sockdiag           1026      0.00      0.00      0.00    657502.81      398137.37\nstress-ng: info:  [9275] skipped: 0\nstress-ng: info:  [9275] passed: 1: sockdiag (1)\nstress-ng: info:  [9275] failed: 0\nstress-ng: info:  [9275] metrics untrustworthy: 0\nstress-ng: info:  [9275] successful run completed in 0.00 secs\nstress-ng: info:  [9277] setting to a 1 secs run per stressor\nstress-ng: info:  [9277] dispatching hogs: 1 sockfd\nstress-ng: info:  [9277] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9277] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9277]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9277] sockfd              200      0.00      0.00      0.00    122372.11       59224.16\nstress-ng: info:  [9277] skipped: 0\nstress-ng: info:  [9277] passed: 1: sockfd (1)\nstress-ng: info:  [9277] failed: 0\nstress-ng: info:  [9277] metrics untrustworthy: 0\nstress-ng: info:  [9277] successful run completed in 0.00 secs\nstress-ng: info:  [9280] setting to a 1 secs run per stressor\nstress-ng: info:  [9280] dispatching hogs: 1 sockpair\nstress-ng: info:  [9280] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9280] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9280]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9280] sockpair            500      0.05      0.01      0.04     11034.33       10094.48\nstress-ng: info:  [9280] skipped: 0\nstress-ng: info:  [9280] passed: 1: sockpair (1)\nstress-ng: info:  [9280] failed: 0\nstress-ng: info:  [9280] metrics untrustworthy: 0\nstress-ng: info:  [9280] successful run completed in 0.05 secs\nstress-ng: info:  [9284] setting to a 1 secs run per stressor\nstress-ng: info:  [9284] dispatching hogs: 1 udp-flood\nstress-ng: info:  [9284] note: /proc/sys/kernel/sched_autogroup_enabled is 1 and this can impact scheduling throughput for processes not attached to a tty. Setting this to 0 may improve performance metrics\nstress-ng: metrc: [9284] stressor       bogo ops real time  usr time  sys time   bogo ops/s     bogo ops/s\nstress-ng: metrc: [9284]                           (secs)    (secs)    (secs)   (real time) (usr+sys time)\nstress-ng: metrc: [9284] udp-flood          1000      0.00      0.00      0.00    218567.17      205803.66\nstress-ng: info:  [9284] skipped: 0\nstress-ng: info:  [9284] passed: 1: udp-flood (1)\nstress-ng: info:  [9284] failed: 0\nstress-ng: info:  [9284] metrics untrustworthy: 0\nstress-ng: info:  [9284] successful run completed in 0.01 secs"
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
        "error": "prog 21: prog 21 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff88c715005400\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff88c6c73c5000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...; prog 22: prog 22 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff88c715005400\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff88c70072fc00\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff88c70072fc00\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff88c70072fc00\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...; prog 33: prog 33 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 40: prog 40 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 47: prog 47 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 54: prog 54 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 56: prog 56 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 61: prog 61 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 73: prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 77: prog 77 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 82: prog 82 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 91: prog 91 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 93: prog 93 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 105: prog 105 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 111: prog 111 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 119: prog 119 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 123: prog 123 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 131: prog 131 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 135: prog 135 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 141: prog 141 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 146: prog 146 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 153: prog 153 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 156: prog 156 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 166: prog 166 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 167: prog 167 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 175: prog 175 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 181: prog 181 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 183: prog 183 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 190: prog 190 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 196: prog 196 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 207: prog 207 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 212: prog 212 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 221: prog 221 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 229: prog 229 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 235: prog 235 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 240: prog 240 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 245: prog 245 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 252: prog 252 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 255: prog 255 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 268: prog 268 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 275: prog 275 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 276: prog 276 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...; prog 285: prog 285 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 292: prog 292 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 298: prog 298 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...; prog 305: prog 305 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
        "error_programs": [
          {
            "applied": false,
            "changed": false,
            "error": "prog 21 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @844\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (b7) r7 = 0\n      2: ......67.. (63) *(u32 *)(r10 -88) = r7\n      3: ......67.. (bf) r2 = r10\n      4: ..2...67.. (07) r2 += -88\n      5: ..2...67.. (18) r1 = 0xffff88c715005400\n      7: .12...67.. (85) call bpf_map_lookup_elem#1\n      8: 0.....67.. (15) if r0 == 0x0 goto pc+821\n      9: 0.....67.. (7b) *(u64 *)(r10 -120) = r6\n     10: 0......7.. (bf) r8 = r0\n     11: 0......78. (bf) r6 = r0\n     12: ......678. (85) call bpf_get_current_task#35\n     13: 0.....678. (b7) r1 = 2680\n     14: 01....678. (0f) r0 += r1\n     15: 0.....678. (bf) r1 = r10\n     16: 01....678. (07) r1 += -72\n     17: 01....678. (b7) r2 = 8\n     18: 012...678. (bf) r3 = r0\n     19: .123..678. (85) call bpf_probe_read#4\n     20: ......678. (b7) r1 = 1448\n     21: .1....678. (79) r3 = *(u64 *)(r10 -72)\n     22: .1.3..678. (0f) r3 += r1\n     23: ...3..678. (bf) r1 = r10\n     24: .1.3..678. (07) r1 += -64\n     25: .1.3..678. (b7) r2 = 8\n     26: .123..678. (85) call bpf_probe_read#4\n     27: ......678. (79) r9 = *(u64 *)(r10 -64)\n     28: ......6789 (63) *(u32 *)(r10 -84) = r7\n     29: ......6.89 (bf) r2 = r10\n     30: ..2...6.89 (07) r2 += -84\n     31: ..2...6.89 (18) r1 = 0xffff88c6c73c5000\n     33: .12...6.89 (85) call bpf_map_lookup_elem#1\n     34: 0.....6.89 (7b) *(u64 *)(r10 -104) = r6\n     35: 0.....6.89 (07) r6 += 5808\n     36: 0.....6.89 (7b) *(u64 *)(r10 -112) = r6\n     37: 0.......89 (bf) r2 = r8\n     38: 0.2.....89 (7b) *(u64 *)(r10 -96) = r8\n     39: 0.2......9 (bf) r8 = r0\n     40: ..2.....89 (55) if r8 != 0x0 goto pc+1\n     41: .......... (05) goto pc+254\n     42: ..2.....89 (b7) r1 = 64\n     43: .12.....89 (0f) r9 += r1\n     44: ..2.....89 (b7) r1 = 4096\n     45: .12.....89 (63) *(u32 *)(r2 +6192) = r1\n     46: ........89 (85) call bpf_get_current_task#35\n     47: 0.......89 (b7) r1 = 3408\n     48: 01......89 (0f) r0 += r1\n     49: 0.......89 (bf) r1 = r10\n     50: 01......89 (07) r1 += -80\n     51: 01......89 (b7) r2 = 8\n     52: 012.....89 (bf) r3 = r0\n     53: .123....89 (85) call bpf_probe_read#4\n     54: ........89 (b7) r1 = 8\n     55: .1......89 (7b) *(u64 *)(r10 -128) = r9\n     56: .1......89 (0f) r9 += r1\n     57: ........89 (79) r7 = *(u64 *)(r10 -80)\n     58: .......789 (bf) r1 = r10\n     59: .1.....789 (07) r1 += -72\n     60: .1.....789 (b7) r2 = 8\n     61: .12....789 (7b) *(u64 *)(r10 -136) = r9\n     62: .12....789 (bf) r3 = r9\n     63: .123...78. (85) call bpf_probe_read#4\n     64: .......78. (b7) r1 = 8\n     65: .1.....78. (79) r6 = *(u64 *)(r10 -72)\n     66: .1....678. (bf) r3 = r6\n     67: .1.3..678. (0f) r3 += r1\n     68: ...3..678. (b7) r1 = 8\n     69: .1.3..678. (0f) r3 += r1\n     70: ...3..678. (bf) r1 = r10\n     71: .1.3..678. (07) r1 += -64\n     72: .1.3..678. (b7) r2 = 8\n     73: .123..678. (85) call bpf_probe_read#4\n     74: ......678. (79) r3 = *(u64 *)(r10 -96)\n     75: ...3..678. (bf) r9 = r8\n     76: ...3..6789 (07) r9 += 4096\n     77: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     78: .1.3..6789 (55) if r1 != 0x0 goto pc+41\n     79: ......6789 (b7) r1 = 24\n     80: .1....6789 (bf) r3 = r6\n     81: .1.3..6789 (0f) r3 += r1\n     82: ...3..6789 (bf) r1 = r10\n     83: .1.3..6789 (07) r1 += -64\n     84: .1.3..6789 (b7) r2 = 8\n     85: .123..6789 (85) call bpf_probe_read#4\n     86: ......6789 (79) r3 = *(u64 *)(r10 -96)\n     87: ...3..6789 (79) r1 = *(u64 *)(r10 -64)\n     88: .1.3..6789 (1d) if r1 == r6 goto pc+31\n     89: ...3...789 (61) r1 = *(u32 *)(r3 +6192)\n     90: .1.3...789 (bf) r2 = r1\n     91: .123...789 (07) r2 += -10\n     92: .123...789 (63) *(u32 *)(r3 +6192) = r2\n     93: .123...789 (67) r1 <<= 32\n     94: .123...789 (c7) r1 s>>= 32\n     95: .123...789 (65) if r1 s> 0x9 goto pc+5\n     96: ..23.....9 (18) r1 = 0xffffffdc\n     98: .123.....9 (63) *(u32 *)(r3 +6196) = r1\n     99: ..2......9 (bf) r7 = r9\n    100: ..2....7.. (05) goto pc+93\n    101: ...3...78. (b7) r1 = 41\n    102: .1.3...78. (73) *(u8 *)(r8 +4095) = r1\n    103: ...3...78. (b7) r1 = 116\n    104: .1.3...78. (73) *(u8 *)(r8 +4092) = r1\n    105: ...3\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 21
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 22 pass prefetch failed after 11 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)\nverifier log summary:\nfunc#0 @0\nfunc#1 @1724\nfunc#2 @1840\nfunc#3 @2033\nfunc#4 @2208\nfunc#5 @2277\nfunc#6 @2300\nfunc#7 @2370\nLive regs before insn:\n      0: .1........ (bf) r6 = r1\n      1: ......6... (85) call bpf_get_current_task#35\n      2: 0.....6... (bf) r9 = r0\n      3: ......6..9 (7b) *(u64 *)(r10 -128) = r6\n      4: ......6..9 (61) r6 = *(u32 *)(r6 +8)\n      5: ......6..9 (b7) r1 = 0\n      6: .1....6..9 (63) *(u32 *)(r10 -120) = r1\n      7: ......6..9 (bf) r2 = r10\n      8: ..2...6..9 (07) r2 += -120\n      9: ..2...6..9 (18) r1 = 0xffff88c715005400\n     11: .12...6..9 (85) call bpf_map_lookup_elem#1\n     12: 0.....6..9 (bf) r7 = r0\n     13: ......67.9 (15) if r7 == 0x0 goto pc+1689\n     14: ......67.9 (7b) *(u64 *)(r10 -144) = r6\n     15: .......7.9 (85) call bpf_get_current_pid_tgid#14\n     16: 0......7.9 (bf) r6 = r0\n     17: ......67.9 (85) call bpf_get_current_task#35\n     18: 0.....67.9 (7b) *(u64 *)(r10 -96) = r0\n     19: 0.....67.9 (b7) r8 = 2816\n     20: 0.....6789 (0f) r0 += r8\n     21: 0.....6789 (bf) r1 = r10\n     22: 01....6789 (07) r1 += -96\n     23: 01....6789 (b7) r2 = 8\n     24: 012...6789 (bf) r3 = r0\n     25: .123..6789 (85) call bpf_probe_read_kernel#113\n     26: ......6789 (7b) *(u64 *)(r10 -160) = r6\n     27: ......6789 (7b) *(u64 *)(r10 -152) = r6\n     28: .......789 (79) r3 = *(u64 *)(r10 -96)\n     29: ...3...789 (7b) *(u64 *)(r10 -136) = r9\n     30: ...3...789 (15) if r3 == 0x0 goto pc+162\n     31: ...3...789 (b7) r1 = 2804\n     32: .1.3...789 (0f) r3 += r1\n     33: ...3...789 (bf) r1 = r10\n     34: .1.3...789 (07) r1 += -8\n     35: .1.3...789 (b7) r2 = 4\n     36: .123...789 (85) call bpf_probe_read_kernel#113\n     37: .......789 (61) r1 = *(u32 *)(r10 -8)\n     38: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     39: .......789 (bf) r2 = r10\n     40: ..2....789 (07) r2 += -112\n     41: ..2....789 (18) r1 = 0xffff88c70072fc00\n     43: .12....789 (85) call bpf_map_lookup_elem#1\n     44: 0......789 (bf) r6 = r0\n     45: ......6789 (15) if r6 == 0x0 goto pc+3\n     46: ......6789 (05) goto pc+0\n     47: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     48: .1....6789 (55) if r1 != 0x0 goto pc+81\n     49: .......789 (b7) r1 = 2816\n     50: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     51: .1.3...789 (0f) r3 += r1\n     52: ...3...789 (bf) r1 = r10\n     53: .1.3...789 (07) r1 += -96\n     54: .1.3...789 (b7) r2 = 8\n     55: .123...789 (85) call bpf_probe_read_kernel#113\n     56: .......789 (79) r3 = *(u64 *)(r10 -96)\n     57: ...3...789 (15) if r3 == 0x0 goto pc+135\n     58: ...3...789 (b7) r1 = 2804\n     59: .1.3...789 (0f) r3 += r1\n     60: ...3...789 (bf) r1 = r10\n     61: .1.3...789 (07) r1 += -8\n     62: .1.3...789 (b7) r2 = 4\n     63: .123...789 (85) call bpf_probe_read_kernel#113\n     64: .......789 (61) r1 = *(u32 *)(r10 -8)\n     65: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     66: .......789 (bf) r2 = r10\n     67: ..2....789 (07) r2 += -112\n     68: ..2....789 (18) r1 = 0xffff88c70072fc00\n     70: .12....789 (85) call bpf_map_lookup_elem#1\n     71: 0......789 (bf) r6 = r0\n     72: ......6789 (15) if r6 == 0x0 goto pc+3\n     73: ......6789 (05) goto pc+0\n     74: ......6789 (79) r1 = *(u64 *)(r6 +8)\n     75: .1....6789 (55) if r1 != 0x0 goto pc+54\n     76: .......789 (b7) r1 = 2816\n     77: .1.....789 (79) r3 = *(u64 *)(r10 -96)\n     78: .1.3...789 (0f) r3 += r1\n     79: ...3...789 (bf) r1 = r10\n     80: .1.3...789 (07) r1 += -96\n     81: .1.3...789 (b7) r2 = 8\n     82: .123...789 (85) call bpf_probe_read_kernel#113\n     83: .......789 (79) r3 = *(u64 *)(r10 -96)\n     84: ...3...789 (15) if r3 == 0x0 goto pc+108\n     85: ...3...789 (b7) r1 = 2804\n     86: .1.3...789 (0f) r3 += r1\n     87: ...3...789 (bf) r1 = r10\n     88: .1.3...789 (07) r1 += -8\n     89: .1.3...789 (b7) r2 = 4\n     90: .123...789 (85) call bpf_probe_read_kernel#113\n     91: .......789 (61) r1 = *(u32 *)(r10 -8)\n     92: .1.....789 (63) *(u32 *)(r10 -112) = r1\n     93: .......789 (bf) r2 = r10\n     94: ..2....789 (07) r2 += -112\n     95: ..2....789 (18) r1 = 0xffff88c70072fc00\n     97: .12....789 (85) call bpf_map_lookup_elem#1\n     98: 0......789 (bf) r6 = r0\n\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 22
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 33 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 33
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 40 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 40
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 47 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 47
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 54 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 54
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 56 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 56
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 61 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 61
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 73 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 73
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
            "error": "prog 82 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 82
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 91 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 91
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 93 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 93
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 105 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 105
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 111 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 111
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 119 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 119
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 123 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 123
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 131 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 131
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 135 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 135
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 141 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 141
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 146 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 146
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 153 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 153
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 156 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 156
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 166 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 166
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 167 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 167
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 175 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 175
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 181 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 181
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 183 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 183
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 190 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 190
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 196 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 196
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 207 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 207
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 212 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 212
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 221 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 221
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 229 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 229
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 235 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 235
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 240 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 240
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 245 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 245
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 252 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 252
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 255 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 255
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 268 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 268
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 275 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 275
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 276 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs=r1 stack= before 1881: (07) r1 += 1\nmark_precise: frame2: regs=r1 stack= before 1880: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs=r1 stack= before 1879: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs=r1 stack= before 1878: (0f) r2 += r1\nmark_precise: frame2: regs=r1 stack= before 1877: (bf) r2 = r0\nmark_precise: frame2: regs=r1 stack= before 1876: (0f) r3 += r2\nmark_precise: frame2: regs=r1 stack= before 1875: (bf) r3 = r7\nmark_precise: frame2: regs=r1 stack= before 1874: (57) r2 &= 4095\nmark_precise: frame2: regs=r1 stack= before 1873: (bf) r2 = r6\nmark_precise: frame2: regs=r1 stack= before 1872: (07) r6 += -1\nmark_precise: frame2: regs=r1 stack= before 1871: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs=r1 stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=P31 R2=map_value(map=string_postfix_,ks=4,vs=132,off=30) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=Pscalar(smin=smin32=-27,smax=smax32=99,umax=0xffffffffffffffe5) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off=(0x0; 0x7ff)) R8=map_ptr(ks=132,vs=1) R9=0 R10=fp0 fp-8=mmmm0\nmark_precise: frame1: parent state regs= stack=:  frame1: R6=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) R10=fp0\nmark_precise: frame0: parent state regs= stack=:  R6=P20 R7=map_value(map=process_call_he,ks=4,vs=25608) R8=map_value(map=filter_map,ks=4,vs=4096) R9=scalar(smin=umin=8,smax=umax=0x100000023,var_off=(0x0; 0x1ffffffff)) R10=fp0 fp-24=0000???? fp-32=P1 fp-40=map_value(map=filter_map,ks=4,vs=4096,smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff)) fp-48=ctx() fp-56=Pscalar(smin=0,smax=umax=0xffffffff,var_off=(0x0; 0xffffffff)) fp-64=scalar(smin=smin32=0,smax=umax=smax32=umax32=1023,var_off=(0x0; 0x3ff))\n1879: frame2: R1=38 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38)\n1879: (71) r3 = *(u8 *)(r3 +0)        ; frame2: R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1880: (73) *(u8 *)(r2 +0) = r3        ; frame2: R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff))\n1881: (07) r1 += 1                    ; frame2: R1=39\n1882: (55) if r6 != 0x0 goto pc-12    ; frame2: R6=0\nframe 0: propagating r6,fp-32,fp-56\nmark_precise: frame2: last_idx 1883 first_idx 1882 subseq_idx -1 \nmark_precise: frame2: regs= stack= before 1882: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: parent state regs= stack=:  frame2: R0=map_value(map=string_postfix_,ks=4,vs=132) R1=39 R2=map_value(map=string_postfix_,ks=4,vs=132,off=38) R3=scalar(smin=smin32=0,smax=umax=smax32=umax32=255,var_off=(0x0; 0xff)) R6=scalar(smin=smin32=-35,smax=smax32=91,umax=0xffffffffffffffdd) R7=map_value(map=process_call_he,ks=4,vs=25608,off=148,smin=smin32=0,smax=umax=smax32=umax32=2047,var_off\n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 276
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 285 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 285
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 292 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 292
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 298 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 298
          },
          {
            "applied": false,
            "changed": false,
            "error": "prog 305 pass wide_mem failed after 0 committed passes: kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)\nverifier log summary:\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 == 0x83 goto pc+11\nmark_precise: frame2: regs= stack= before 1907: (55) if r6 != 0x0 goto pc-12\nmark_precise: frame2: regs= stack= before 1906: (07) r1 += 1\nmark_precise: frame2: regs= stack= before 1905: (73) *(u8 *)(r2 +0) = r3\nmark_precise: frame2: regs= stack= before 1904: (71) r3 = *(u8 *)(r3 +0)\nmark_precise: frame2: regs= stack= before 1903: (0f) r2 += r1\nmark_precise: frame2: regs= stack= before 1902: (bf) r2 = r0\nmark_precise: frame2: regs= stack= before 1901: (0f) r3 += r2\nmark_precise: frame2: regs= stack= before 1900: (bf) r3 = r7\nmark_precise: frame2: regs= stack= before 1899: (57) r2 &= 4095\nmark_precise: frame2: regs= stack= before 1898: (bf) r2 = r6\nmark_precise: frame2: regs= stack= before 1897: (07) r6 += -1\nmark_precise: frame2: regs= stack= before 1896: (15) if r1 \n... verifier log truncated ...",
            "exit_code": 1,
            "prog_id": 305
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
      "status": "error"
    }
  ],
  "samples": 1,
  "status": "error",
  "suite_name": "macro_apps",
  "summary": {
    "losses": 14,
    "per_program_geomean": 0.8918233883342972,
    "program_count": 32,
    "wins": 18
  },
  "workload_seconds": 1.0
}
```
