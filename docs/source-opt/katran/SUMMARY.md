# katran source-opt summary

App: `katran`

Status: in-progress

Start state:

- Started: 2026-06-25
- Initial worktree status: `M docs/source-opt/README.md`
- Initial disk: `/dev/nvme0n1p2 915G 683G 187G 79% /`
- Benchmark contract: single-app `make corpus`, `SKIP_REJIT=all`,
  `SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1`,
  `BPFREJIT_CORPUS_BPF_STATS=0`

Baseline:

- Status: accepted-for-analysis
- Result path: `corpus/results/x86_kvm_corpus_20260625_082123_391460`
- App result: `corpus/results/x86_kvm_corpus_20260625_082123_391460/details/apps/katran.json`
- Gate: suite/app `status=ok`, `error=""`, 3 workload samples returned 0,
  `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`

Attempts:

| Attempt | Status | Result path | Notes |
| --- | --- | --- | --- |
| 1 | planned | | |
| 2 | planned | | |
| 3 | planned | | |
| 4 | planned | | |
| 5 | planned | | |

Completion gate:

- [x] Clean-source baseline result recorded.
- [ ] Five independent source optimization attempts recorded.
- [ ] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [ ] katran source tree returned to attempt-start state after each attempt.
