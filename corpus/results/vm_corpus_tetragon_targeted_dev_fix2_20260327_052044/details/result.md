# Corpus Batch REJIT Results

- Generated: 2026-03-27T05:20:44.056869+00:00
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
- Compile pairs: 0
- Measured pairs: 0
- REJIT applied programs: 0
- Code-size ratio geomean (baseline/rejit): n/a
- Exec-time ratio geomean (baseline/rejit): n/a
- Build availability: 565 objects (429 built, 136 staged)
- Guest kernel: `7.0.0-rc2+`

## By Repo

| Repo | Programs | Compile Pairs | Measured Pairs | Applied | Code Ratio | Exec Ratio |
| --- | --- | --- | --- | --- | --- | --- |
| tetragon | 2 | 0 | 0 | 0 | n/a | n/a |

## By Object

| Object | Programs | Compile | REJIT Compile | Status | Error |
| --- | --- | --- | --- | --- | --- |
| tetragon:bpf_execve_event.bpf.o | 1 | 373647363 | 352204687 | ok |  |
| tetragon:bpf_fork.bpf.o | 1 | 249164086 | 256095956 | ok |  |

## Per-Program Results

| Program | Repo | Type | Compile Passes | Run Passes | Baseline JIT | REJIT JIT | Code Ratio | Baseline ns | REJIT ns | Exec Ratio | Note |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tetragon:bpf_execve_event.bpf.o:event_execve | tetragon | tracepoint | - | - | n/a | n/a | n/a | n/a | n/a | n/a | fixture value_size mismatch for map 'execve_msg_heap_map' |
| tetragon:bpf_fork.bpf.o:event_wake_up_new_task | tetragon | kprobe | - | - | n/a | n/a | n/a | n/a | n/a | n/a | fixture value size mismatch for map 'execve_val' |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| fixture value_size mismatch for map 'execve_msg_heap_map' | 4 |
| fixture value size mismatch for map 'execve_val' | 4 |
