# bcc/set baseline

Status: accepted

Clean-source baseline for `bcc/set`, using the documented source-opt command.
No bcc source files are modified for this run.

Expected runner behavior:

- Starts the real libbpf-tools binaries for `capable`, `biosnoop`, `vfsstat`,
  `opensnoop`, `syscount`, `tcpconnect`, `tcplife`, and `runqlat`.
- Runs `stress_ng_bcc_hook_hot`.
- Uses `SKIP_REJIT=all`, so `post_rejit` should be `null` and
  `rejit_result.mode` should be `skip_rejit_all`.

Result:

- Run directory: `corpus/results/x86_kvm_corpus_20260625_102432_554290`
- Suite result: `status=ok`, `samples=3`, `warmups=1`,
  `workload_seconds=180.0`, `skip_rejit=true`, `bpf_stats=false`,
  `kinsn_modules={}`.
- App result: `app=bcc/set`, `runner=bcc_set`,
  `selected_workload=stress_ng_bcc_hook_hot`, `status=ok`, `error=""`.
- Workload samples: 3 baseline workloads, returncodes `[0, 0, 0]`.
- ReJIT state: `post_rejit=null`,
  `rejit_result={"mode":"skip_rejit_all","status":"skipped"}`.
- Source state: `vendor/repos/bcc` clean after baseline.
- Disk after run: `/dev/nvme0n1p2 915G 695G 175G 80% /`.
