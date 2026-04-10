# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-10T02:31:57.074282+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Baseline

- Application throughput mean: `1132.0067411584414` ops/s
- Events/s mean: `941.2224150721299`
- Agent CPU mean: `47.364530998385085`%
- BPF avg ns mean: `2820.0076199797268`

- exec_storm: ops/s=1132.0067411584414, events/s=941.2224150721299, agent_cpu=47.364530998385085, bpf_avg_ns=2820.0076199797268

## Per-Program

- execve_rate (tracepoint): sites=7, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=144, stock_avg_ns=2820.0076199797268, rejit_avg_ns=6011.8763646575635, speedup=0.469072790078968

## Post-ReJIT

- Application throughput mean: `1128.232975860286` ops/s
- Events/s mean: `940.8932575114015`
- Agent CPU mean: `41.948033628384295`%
- BPF avg ns mean: `6011.8763646575635`

- exec_storm: ops/s=1128.232975860286, events/s=940.8932575114015, agent_cpu=41.948033628384295, bpf_avg_ns=6011.8763646575635

## Comparison

- exec_storm: baseline_ops/s=1132.0067411584414, post_ops/s=1128.232975860286, app_delta=-0.3333695075255097%, baseline_cpu=47.364530998385085, post_cpu=41.948033628384295, cpu_delta=-11.435766924801744%

## Limitations

- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.

