# katran source-opt summary

App: `katran`

Status: phase3-in-progress

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

Phase2 attempts:

| Attempt | Status | Result path | Primary metric | vs baseline | Notes |
| --- | --- | --- | ---: | ---: | --- |
| 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_235638_664542` | pktgen_total_pps mean=3305186; samples `3299495, 3294334, 3321729` | +7.97% | `udp-flow-migration-require-dst`; positive signal, stack future katran phase2 attempts |
| 2 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_002120_778242` | pktgen_total_pps mean=3288342; samples `3267504, 3316271, 3281251` | +7.42% | `lru-miss-proto-compare`; correctness passed, but -0.51% vs phase2 attempt 1, so do not stack |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_004646_185930` | pktgen_total_pps mean=3348905; samples `3390361, 3336180, 3320175` | +9.40% | `cache-vip-metadata`; correctness passed, +1.32% vs phase2 attempt 1, stack as current katran best base |
| 4 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_011245_701549` | pktgen_total_pps mean=3275764; samples `3272779, 3268211, 3286301` | +7.01% | `cache-vip-plus-lru-proto-compare`; correctness passed, but -2.18% vs phase2 attempt 3, so do not stack |
| 5 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_013906_982440` | pktgen_total_pps mean=3301431; samples `3317221, 3295753, 3291320` | +7.85% | `nonnull-lru-map`; correctness passed, but -1.42% vs phase2 attempt 3, so do not stack |

Phase3 attempts:

| Attempt | Status | Result path | Primary metric | vs baseline | Notes |
| --- | --- | --- | ---: | ---: | --- |
| 1 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_114838_879478` | pktgen_total_pps mean=3338745; samples `3337569, 3357814, 3320853` | +9.07% | `phase3-thoff-parser-reuse`; correctness passed and static xdp size shrank to `0x4760`, but result was -0.30% vs phase2 best, so do not stack |
| 2 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_121345_246104` | pktgen_total_pps mean=3320793; samples `3276898, 3371790, 3313690` | +8.48% | `phase3-quic-v0-cid-fast-reject`; correctness passed, but result was -0.84% vs phase2 best, so do not stack; next attempt should target conn-rate/LRU/stats overhead |
| 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_123820_861697` | pktgen_total_pps mean=3349874; samples `3379459, 3355767, 3314396` | +9.43% | `phase3-unlikely-hot-map-misses`; correctness passed, +0.03% vs phase2 best, stack as current katran best base even though static xdp size grew to `0x4858` |
| 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_130130_983141` | pktgen_total_pps mean=3414266; samples `3406881, 3418862, 3417054` | +11.53% | `phase3-vip-flag-branch-layout`; correctness passed, +1.92% vs phase3 attempt 3 and clears the 10% target; stack as current katran best base despite static xdp size growing to `0x4890` |
| 5 | completed-not-stacked | `corpus/results/x86_kvm_corpus_20260626_132449_671728` | pktgen_total_pps mean=3277602; samples `3275164, 3299603, 3258040` | +7.07% | `phase3-quic-hot-branch-layout`; correctness passed, but regressed -4.00% vs phase3 attempt 4, so do not stack parser fallback hints |

Completion gate:

- [x] Clean-source baseline result recorded.
- [x] Five independent source optimization attempts recorded.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] katran source tree returned to attempt-start state after each attempt.
