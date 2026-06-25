# katran source-opt summary

App: `katran`

Status: complete

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
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_084248_406394` | `udp-parse-first`; source restored |
| 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_090323_284447` | `icmp-protocol-refresh`; source restored |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_092311_749645` | `calc-offset-fastpath`; source restored |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_094328_513110` | `quic-connid-no-null-check`; source restored |
| 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_100305_598103` | `stable-rt-header-early-return`; source restored |

Completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] katran source tree returned to attempt-start state after each attempt.
