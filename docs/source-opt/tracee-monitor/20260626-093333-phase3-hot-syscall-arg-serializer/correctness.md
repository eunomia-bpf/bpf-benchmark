# Correctness

Formal command:

```sh
SKIP_REJIT=all BPFREJIT_CORPUS_APPS='tracee/monitor' BPFREJIT_CORPUS_BPF_STATS=0 SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus
```

Result:

- Suite status: `ok`.
- App status: `ok`.
- App error: `""`.
- `post_rejit == null`: true.
- `rejit_result.mode`: `skip_rejit_all`.
- Baseline workload samples: 3.
- Workload returncodes: `0`.
- Workload durations: `180.02056778499997`, `180.029574482`,
  `180.02797145`.

Performance payload parsed from the three saved workload stdout blobs:

- `stress_ng_sum_bogo_ops_s` samples: `458895, 456475, 457398`.
- Mean: `457589`.
- vs clean-source baseline mean `460865`: `-0.71%`.
- vs current tracee phase3 base mean `464810`: `-1.55%`.

Decision:

- Correctness passed, but performance regressed. Do not stack this patch.
- Source was restored with `patch -R`, `make -C vendor tracee-x86` passed, and
  `vendor/repos/tracee` had empty `status --short` and empty diff for the
  touched files after restore.
