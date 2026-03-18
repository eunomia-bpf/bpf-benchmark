# Tracing Corpus Exec Driver Results

- Generated: 2026-03-11T21:55:58.830172+00:00
- Mode: `host`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.json`
- Objects discovered: 1
- Programs considered: 1
- Attached programs: 1
- Paired measurements: 1
- Paired measurements with applied v5 sites: 0
- Attach failures: 0
- Skipped programs: 0
- Zero-run programs: 0
- Speedup geomean (baseline/recompile): 0.949x
- Applied-only speedup geomean: n/a

## Summary Statistics

| Metric | Value |
| --- | --- |
| Inventory failures | 0 |
| Failure reason buckets | 0 |

## Paired Measurements

| Program | Section | Workload | Baseline ns | Recompile ns | Speedup | Applied | Sites | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/bcc/libbpf-tools/filelife.bpf.o:vfs_unlink | kprobe/vfs_unlink | unlink | 61.18 | 64.46 | 0.949x | no | 0 | 0 | 0 | 0 | 0 |

## Notes

- Each attached program is measured twice in one load session: baseline workload, then `scanner apply --all --v5`, then post-recompile workload.
- Average exec time is derived from `bpf_prog_info.run_time_ns / run_cnt` deltas around each workload phase.
- Programs that can be loaded but not matched to an attach target or workload are recorded with explicit skip reasons.

