# Six applications on image 8f6ff5891 and the micro suite (2026-11-20)

Image `bpf-benchmark/kprog:current` built from 8f6ff5891 (source agreement by the whole BTF function name, CO-RE slots
skipped, inline kernel reads with the helper's address rule). Frozen entry `kprog/perf/one-image/Makefile`, CPUs 0-7.
Ratios are native/eBPF from `kprog/results/flag-tuning-20261117/may29_ratio.py`. Raw run directories are under
`corpus/results/` and `micro/results/`; logs under `/workspaces/kprog-raw/coordinator/six-app-names-20261119T231151Z/`.

## Throughput, stats off, 3 x 180 s per app (rotate)

| App | Ratio | Samples | Replaced | Run |
|---|---|---|---|---|
| Tracee | 1.864x | 1.891 / 1.864 / 1.886 | 169 | x86_kvm_corpus_20261120_015438_841006 |
| Cilium | 1.013x | 1.024 / 1.030 / 0.987 | 28 of 135 | x86_kvm_corpus_20261120_010219_662231 |
| OTel | 0.999x | 0.969 / 0.999 / 1.029 | 14 | x86_kvm_corpus_20261120_000921_188142 |
| Katran | 0.988x | 0.982 / 0.981 / 1.019 | 1 | x86_kvm_corpus_20261120_022206_247083 |
| BCC | 0.968x | 1.055 / 0.966 / 0.954 | 25 | x86_kvm_corpus_20261120_003544_445224 |
| Tetragon | 0.874x | 1.730 / 0.716 / 0.631 | 288 | x86_kvm_corpus_20261120_012812_716421 |

Cilium's 107 per-endpoint programs, compiled by the agent with other constants, stay on eBPF. Tetragon's samples spread
too far to separate the arms.

## Per call, stats on, 3 x 60 s per app (rotate STATS=1 WORKLOAD_DURATION=60)

| App | Per call | Throughput | Run |
|---|---|---|---|
| Tracee | 2.015x (396.6 / 196.8 ns) | 1.726x | x86_kvm_corpus_20261120_033105_125412 |
| Tetragon | 1.145x (920.2 / 803.5 ns) | 1.140x | x86_kvm_corpus_20261120_032024_286235 |
| Cilium | 1.061x (821.1 / 774.2 ns) | 1.042x | x86_kvm_corpus_20261120_031013_631126 |
| BCC | 1.040x (110.5 / 106.3 ns) | 1.023x | x86_kvm_corpus_20261120_025930_173466 |
| OTel | 0.948x (3454.7 / 3646.0 ns) | 0.985x | x86_kvm_corpus_20261120_024823_728004 |
| Katran | 0.926x (184.2 / 198.9 ns) | 0.910x | x86_kvm_corpus_20261120_034205_104865 |

Per-call geomean 1.14x.

## Micro suite, program bodies (micro_pure_jit.yaml, 29 benchmarks, 3 samples, 100000 inner repeats)

Run `micro/results/x86_kvm_micro_20261120_035132_968628`, on the one kernel and image (the one-image OVERRIDES,
`-o runtime-kernel-image`). Geomean over 29: kernel JIT / in-kernel native execution time 1.461x; kernel JIT / user-space
native 1.728x; in-kernel native code bytes / JIT bytes 0.537.
