# x86 frozen-entry rotate on image 3b5fa4b40 (2026-11-20 22:17 to 2026-11-21 02:26 UTC)

Image `bpf-benchmark/kprog:current` sha256:ba86ac5d (built 2026-11-20 16:53 from 3b5fa4b40), frozen entry
`kprog/perf/one-image/Makefile rotate` with its defaults only (3 x 180 s per app, STATS 0 then 1, CPUs 0-7).
Ratios are native/eBPF from `kprog/results/flag-tuning-20261117/may29_ratio.py`. Logs:
`/workspaces/kprog-raw/coordinator/rotate-3b5fa4b40-20261120T210836Z/`.

## Per call, stats on

| App | Per call | ns eBPF / native | Programs with counts | Throughput, same run | Run |
|---|---|---|---|---|---|
| Tracee | 2.036x | 365.0 / 179.3 | 41/167, 41/167 | 1.659x | x86_kvm_corpus_20261121_013353_459359 |
| Tetragon | 1.248x | 743.8 / 596.0 | 21/287, 24/287 | 1.093x | x86_kvm_corpus_20261121_010702_796774 |
| BCC | 1.144x | 119.9 / 104.8 | 16/25, 15/25 | 1.251x | x86_kvm_corpus_20261121_001342_075406 |
| Katran | 1.017x | 179.7 / 176.7 | 1/1, 1/1 | 1.004x | x86_kvm_corpus_20261121_020118_444610 |
| Cilium | 1.012x | 726.7 / 718.4 | 2/53, 2/53 | 0.992x | x86_kvm_corpus_20261121_004030_795317 |
| OTel | 0.936x | 3259.9 / 3482.5 | 2/13, 2/13 | 0.961x | x86_kvm_corpus_20261120_234746_882172 |

Geomean per call over the six: 1.187x (image 8f6ff5891: 1.143x). Without Tracee: 1.066x.

## Throughput, stats off

| App | Throughput | Samples | 05-29 floor | Run |
|---|---|---|---|---|
| Tetragon | 3.291x | 3.288 / 3.291 / 3.265 | 1.009x | x86_kvm_corpus_20261120_222740_505433 |
| Tracee | 1.884x | 1.895 / 1.817 / 1.900 | 0.948x | x86_kvm_corpus_20261120_225422_198013 |
| Katran | 0.962x | 0.924 / 0.964 / 0.984 | 1.113x | x86_kvm_corpus_20261120_232145_135785 |
| OTel | rerun queued | | 1.849x | |
| BCC | rerun queued | | 0.985x | |
| Cilium | rerun queued | | 1.319x | |

- Tetragon: per call is 1.248x in the stats-on run of the same image, and BPF takes about half of the eBPF arm's
  CPU there (2168 s of 8 vCPU x 540 s), which bounds throughput near 1.11x. The stats-off eBPF arm ran 113k ops/s against 324k in the stats-on
  run, so the excess comes from the arms doing different work. Earlier images read 2.009x, 0.874x
  (1.730 / 0.716 / 0.631) and 2.995x on this workload. Tetragon tuning reads the per-call ratio.
- Katran 0.962x is below its 05-29 floor of 1.113x. That floor exceeds the bound its 5-9% BPF share allows (about
  1.10x, todo 1127). OTel's 1.849x floor came from a path whose unrolling did no work
  (`perf-history-review-20261120/README.md`: unroll attempts 913,099,438 to 0).
- OTel, BCC and Cilium stats off exited 255 at VM start, 22:17-22:25: omp SIGKILLed two QEMUs it took for its own
  (COORDINATION 22:26:28Z). The rerun with the same image and entry defaults (ORDER names the three apps) is queued
  behind the timing lock: `/workspaces/kprog-raw/coordinator/rerun3-3b5fa4b40-20261121T064913Z/`.
