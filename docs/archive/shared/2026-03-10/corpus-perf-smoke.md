# Corpus BPF Runtime Performance Results

- Generated: 2026-03-10T20:01:33.055732+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Dummy packet: `/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/corpus_dummy_packet_64.bin`
- Dummy context: `/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/corpus_dummy_context_64.bin`
- Corpus BPF objects discovered: 5
- Skipped non-BPF `.bpf.o` artifacts: 4
- Programs found: 4
- Loadable programs: 4
- Baseline-runnable programs: 4
- Recompile-runnable programs: 4
- Paired baseline/recompile measurements: 4
- Directive-bearing loadable programs: 0
- Directive-bearing paired programs: 0
- Correctness mismatches: 0
- Speedup geomean (baseline/recompile): 0.776x
- Speedup median (baseline/recompile): 0.934x

## Summary Statistics

| Metric | Value |
| --- | --- |
| CMOV sites | 0 |
| WIDE sites | 0 |
| ROTATE sites | 0 |
| LEA sites | 0 |
| Speedup min | 0.393x |
| Speedup max | 1.078x |

## Runnable Programs

| Program | Section | Baseline ns | Recompile ns | Speedup | Applied | Correct | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat | fentry/do_unlinkat | 1797 | 4572 | 0.393x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat_exit | fexit/do_unlinkat | 2133 | 2670 | 0.799x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/manual-test/fentry.gen.bpf.o:do_unlinkat | fentry/do_unlinkat | 2910 | 2722 | 1.069x | no | match | 0 | 0 | 0 | 0 |
| corpus/build/manual-test/fentry.gen.bpf.o:do_unlinkat_exit | fexit/do_unlinkat | 2012 | 1866 | 1.078x | no | match | 0 | 0 | 0 | 0 |

## Skipped Non-BPF Artifacts

| Path |
| --- |
| corpus/repos/libbpf-bootstrap/examples/c/.output/fentry.bpf.o |
| corpus/repos/libbpf-bootstrap/examples/c/.output/lsm.bpf.o |
| corpus/repos/libbpf-bootstrap/examples/c/.output/minimal.bpf.o |
| corpus/repos/libbpf-bootstrap/examples/c/.output/tc.bpf.o |

## Notes

- Discovery reuses `micro/directive_census.py` filtering, so only `EM_BPF` corpus objects are executed.
- Execution uses the existing `micro_exec run-kernel` path with `bpf_prog_test_run_opts` and scanner-backed `--recompile-all`.
- Non-runnable programs are expected in this corpus. The harness records load-only success separately from full runtime success.
- Packet programs use the synthetic 64-byte Ethernet/IPv4/TCP packet, while non-packet programs use `context` mode with empty or zero-filled `ctx_in`.

