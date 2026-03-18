# Real-World Execution-Time Validation

- Generated at: `2026-03-07T21:53:04.116017+00:00`
- Input: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/real_world_code_size.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Iterations per program: `1`
- Repeat count per invocation: `1000`
- I/O mode: `packet`

## Summary

| Metric | Value |
| --- | ---: |
| Programs paired in code-size input | 1 |
| Kernel `BPF_PROG_TEST_RUN` succeeded | 0 |
| llvmbpf runs completed | 0 |
| Programs with both runtimes ok | 0 |
| Geomean exec ratio (llvmbpf/kernel) | - |

## Runtime Status

| Runtime | ok | error | timeout | skipped |
| --- | ---: | ---: | ---: | ---: |
| kernel | 0 | 1 | 0 | 0 |
| llvmbpf | 0 | 0 | 0 | 1 |

## kernel Failures

| Error summary | Count |
| --- | ---: |
| bpf_prog_test_run_opts failed: Invalid argument | 1 |

## Notes

- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.json`.
- Each median is computed across separate `micro_exec` invocations; each invocation uses packet mode with `--repeat 1000` and no input file.
- Kernel runs are attempted first; if `run-kernel` fails, the program is recorded as unsupported for exec-time comparison and llvmbpf is marked `skipped`.
- `--program-name` uses the libbpf program name stored in the code-size results; section names are reported alongside the measurements.
