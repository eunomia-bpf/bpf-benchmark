# Corpus Tracing Runtime Results

- Generated: 2026-03-10T20:34:28.738039+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.json`
- Objects discovered: 0
- Programs found: 0
- Supported by harness: 0
- Measured programs: 0
- Programs with positive run_cnt delta: 0
- Zero-run programs: 0
- Attach failures: 0
- Skipped programs: 0
- Directive-bearing programs: 0
- Directive-bearing measured programs: 0

## Summary Statistics

| Metric | Value |
| --- | --- |
| Average ns/run min | n/a |
| Average ns/run max | n/a |

## Notes

- This harness measures tracing-style programs through load + attach + trigger, then reads `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- `--recompile-all` is probed separately through `micro_exec run-kernel --compile-only`; attached re-JIT plus re-measure is not implemented in this script yet.
- Programs with placeholder section targets such as `kprobe/dummy_*` are skipped because the attach target is supplied dynamically by their original user-space tool.

