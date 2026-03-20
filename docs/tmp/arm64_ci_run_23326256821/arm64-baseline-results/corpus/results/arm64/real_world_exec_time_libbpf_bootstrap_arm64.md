# Real-World Execution-Time Validation

- Generated at: `2026-03-20T02:19:52.553968+00:00`
- Input: `/home/runner/work/bpf-benchmark/bpf-benchmark/corpus/results/arm64/real_world_code_size_libbpf_bootstrap_arm64.json`
- Runner: `/home/runner/work/bpf-benchmark/bpf-benchmark/micro/build/runner/micro_exec`
- Iterations per program: `5`
- Repeat count per invocation: `200`
- I/O mode: `packet`

## Summary

| Metric | Value |
| --- | ---: |
| Programs paired in code-size input | 24 |
| Kernel `BPF_PROG_TEST_RUN` succeeded | 1 |
| llvmbpf runs completed | 1 |
| Programs with both runtimes ok | 1 |
| Geomean exec ratio (llvmbpf/kernel) | 0.146x |

## Runtime Status

| Runtime | ok | error | timeout | skipped |
| --- | ---: | ---: | ---: | ---: |
| kernel | 1 | 23 | 0 | 0 |
| llvmbpf | 1 | 0 | 0 | 23 |

## kernel Failures

| Error summary | Count |
| --- | ---: |
| io-mode packet requires an XDP or skb packet context | 23 |

## Program-Level Results

| Repo | Artifact | Program | Section | llvmbpf median ns | kernel median ns | L/K ratio |
| --- | --- | --- | --- | ---: | ---: | ---: |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 39.0 | 267.0 | 0.146x |

## Notes

- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.latest.json`.
- Each median is computed across separate `micro_exec` invocations; each invocation uses packet mode with a generated valid raw packet input from `/home/runner/work/bpf-benchmark/bpf-benchmark/corpus/results/arm64/valid_packet.bin`.
- Kernel runs are attempted first; if `run-kernel` fails, the program is recorded as unsupported for exec-time comparison and llvmbpf is marked `skipped`.
- `--program-name` uses the libbpf program name stored in the code-size results; section names are reported alongside the measurements.
