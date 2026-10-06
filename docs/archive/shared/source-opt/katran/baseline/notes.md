# katran clean-source baseline

Status: accepted-for-analysis

Purpose: record the clean-source workload payload for later source-only
optimization attempts. This run must use the real katran server and app loader,
with `SKIP_REJIT=all` so there is no shim, no kop module preload, and no
`post_rejit` phase.

Start checks:

- Worktree: `M docs/source-opt/README.md`
- Disk: `/dev/nvme0n1p2 915G 683G 187G 79% /`
- Residual benchmark process: none found.

Result:

- Result path: `corpus/results/x86_kvm_corpus_20260625_082123_391460`
- Suite result: `corpus/results/x86_kvm_corpus_20260625_082123_391460/details/result.json`
- App result: `corpus/results/x86_kvm_corpus_20260625_082123_391460/details/apps/katran.json`
- Status: accepted-for-analysis

Gate checks:

- Suite `status=ok`.
- App `status=ok`, `error=""`.
- `samples=3`, `warmups=1`, `workload_seconds=180.0`.
- `skip_rejit=true`, `bpf_stats=false`, `kop_modules={}`.
- `baseline.workloads` has 3 samples.
- Workload returncodes: `0, 0, 0`.
- `post_rejit=null`.
- `rejit_result.mode="skip_rejit_all"`, `status="skipped"`.

Disk after run:

- `/dev/nvme0n1p2 915G 686G 183G 79% /`
