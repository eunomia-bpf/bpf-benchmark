# Correctness

Command:

```sh
SKIP_REJIT=all BPFREJIT_CORPUS_APPS='tracee/monitor' BPFREJIT_CORPUS_BPF_STATS=0 SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 BPFREJIT_CORPUS_APP_TIMEOUT=3600 BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 TIMEOUT=7200 KEEP_WORKDIRS=1 make corpus
```

Result:

- Suite exit status: 0.
- App result: `corpus/results/x86_kvm_corpus_20260626_161621_526914/details/apps/tracee__monitor.json`
- App `status=ok`, `error=""`.
- `post_rejit` is `null`.
- `rejit_result.mode="skip_rejit_all"`.
- Baseline workload sample count: 3.
- Workload returncodes: `[0]`.
- Workload durations: `180.024947926`, `180.030141135`,
  `180.029667849` seconds.

Performance payload:

- `stress_ng_sum_bogo_ops_s` samples: `462950, 465355, 466125`.
- Mean: `464810`.
- Docs-side comparison: `+0.86%` vs clean baseline `460865`; `+0.53%`
  vs phase2 best `462359`.

Restore gate:

- Reversed this attempt's `source.diff` with `patch -R`.
- `make -C vendor tracee-x86` passed after restore.
- `vendor/repos/tracee` status and diff were empty after restore.
- Disk after run: `/dev/nvme0n1p2 915G 750G 119G 87% /`.
- Docker after run: images 47 / 50.86GB, containers 26 / 29.73GB,
  build cache 73.28GB. No cleanup was required.

