# Corpus Tracing Runtime Results

- Generated: 2026-03-10T20:34:29.266496+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.json`
- Objects discovered: 1
- Programs found: 2
- Supported by harness: 2
- Measured programs: 2
- Programs with positive run_cnt delta: 2
- Zero-run programs: 0
- Attach failures: 0
- Skipped programs: 0
- Directive-bearing programs: 0
- Directive-bearing measured programs: 0

## Summary Statistics

| Metric | Value |
| --- | --- |
| Average ns/run min | 1356.60 |
| Average ns/run max | 1528.40 |

## Measured Programs

| Program | Section | Trigger | Runs | Run time ns | Avg ns/run | Recompile Applied | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat | fentry/do_unlinkat | unlink | 5 | 6783 | 1356.60 | no | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat_exit | fexit/do_unlinkat | unlink | 5 | 7642 | 1528.40 | no | 0 | 0 | 0 | 0 |

## Notes

- This harness measures tracing-style programs through load + attach + trigger, then reads `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- `--recompile-all` is probed separately through `micro_exec run-kernel --compile-only`; attached re-JIT plus re-measure is not implemented in this script yet.
- Programs with placeholder section targets such as `kprobe/dummy_*` are skipped because the attach target is supplied dynamically by their original user-space tool.

