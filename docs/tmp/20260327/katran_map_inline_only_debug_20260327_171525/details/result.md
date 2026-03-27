# Corpus Batch REJIT Results

- Generated: 2026-03-27T17:15:25.848104+00:00
- Corpus manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`
- Corpus build report: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.latest.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Benchmark profile: `ablation_map_inline_only`
- Benchmark config: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/benchmark_config.yaml`
- Objects: 1
- Programs: 1
- Compile pairs: 1
- Measured pairs: 1
- REJIT applied programs: 1
- Code-size ratio geomean (baseline/rejit): 1.061x
- Exec-time ratio geomean (baseline/rejit): 0.716x
- Build availability: 563 objects (429 built, 134 staged)
- Guest kernel: `7.0.0-rc2+`

## By Repo

| Repo | Programs | Compile Pairs | Measured Pairs | Applied | Code Ratio | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| katran | 1 | 1 | 1 | 1 | 1.061x | 0.716x |

## By Object

| Object | Programs | Compile | REJIT Compile | Status | Error |
| --- | --- | --- | --- | --- | --- |
| katran:balancer.bpf.o | 1 | 99530645 | 91636134 | ok |  |

## Per-Program Results

| Program | Repo | Type | Compile Passes | Run Passes | Baseline JIT | REJIT JIT | Code Ratio | Baseline ns | REJIT ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| katran:balancer.bpf.o:balancer_ingress | katran | xdp | map_inline | map_inline | 13645 | 12864 | 1.061x | 2177 | 3039 | 0.716x |  |
