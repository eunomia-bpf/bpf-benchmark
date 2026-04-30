# Corpus Batch REJIT Results

- Generated: 2026-03-27T05:33:03.656805+00:00
- Corpus manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`
- Corpus build report: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.latest.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec`
- Daemon: `/home/yunwei37/workspace/bpf-benchmark/daemon/target/release/bpfrejit-daemon`
- Requested mode: `strict-vm`
- Effective mode: `vm`
- Benchmark profile: `dev`
- Benchmark config: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/benchmark_config.yaml`
- Objects: 2
- Programs: 2
- Compile pairs: 2
- Measured pairs: 1
- REJIT applied programs: 0
- Code-size ratio geomean (baseline/rejit): 1.000x
- Exec-time ratio geomean (baseline/rejit): 1.012x
- Build availability: 565 objects (429 built, 136 staged)
- Guest kernel: `7.0.0-rc2+`

## By Repo

| Repo | Programs | Compile Pairs | Measured Pairs | Applied | Code Ratio | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| tetragon | 2 | 2 | 1 | 0 | 1.000x | 1.012x |

## By Object

| Object | Programs | Compile | REJIT Compile | Status | Error |
| --- | --- | --- | --- | --- | --- |
| tetragon:bpf_execve_event.bpf.o | 1 | 330902249 | 311717100 | ok |  |
| tetragon:bpf_fork.bpf.o | 1 | 259711532 | 233293353 | ok |  |

## Per-Program Results

| Program | Repo | Type | Compile Passes | Run Passes | Baseline JIT | REJIT JIT | Code Ratio | Baseline ns | REJIT ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tetragon:bpf_execve_event.bpf.o:event_execve | tetragon | tracepoint | - | - | 18289 | 18289 | 1.000x | n/a | n/a | n/a |  |
| tetragon:bpf_fork.bpf.o:event_wake_up_new_task | tetragon | kprobe | - | - | 6820 | 6820 | 1.000x | 83 | 82 | 1.012x |  |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_program__attach failed: Invalid argument | 2 |
