# Corpus Batch REJIT Results

- Generated: 2026-03-27T14:14:13.867068+00:00
- Corpus manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`
- Corpus build report: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.latest.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Benchmark profile: `ablation_map_inline`
- Benchmark config: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/benchmark_config.yaml`
- Objects: 1
- Programs: 1
- Compile pairs: 1
- Measured pairs: 0
- REJIT applied programs: 1
- Code-size ratio geomean (baseline/rejit): 1.004x
- Exec-time ratio geomean (baseline/rejit): n/a
- Build availability: 565 objects (429 built, 136 staged)
- Guest kernel: `7.0.0-rc2+`

## By Repo

| Repo | Programs | Compile Pairs | Measured Pairs | Applied | Code Ratio | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| katran | 1 | 1 | 0 | 1 | 1.004x | n/a |

## By Object

| Object | Programs | Compile | REJIT Compile | Status | Error |
| --- | --- | --- | --- | --- | --- |
| katran:balancer.bpf.o | 1 | 242392831 | 103024675 | ok |  |

## Per-Program Results

| Program | Repo | Type | Compile Passes | Run Passes | Baseline JIT | REJIT JIT | Code Ratio | Baseline ns | REJIT ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| katran:balancer.bpf.o:balancer_ingress | katran | xdp | map_inline, wide_mem, endian_fusion | - | 13645 | 13584 | 1.004x | n/a | n/a | n/a |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_prog_test_run_opts failed: Invalid argument | 2 |
