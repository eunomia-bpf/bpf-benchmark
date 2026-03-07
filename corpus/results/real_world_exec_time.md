# Real-World Execution-Time Validation

- Generated at: `2026-03-07T21:58:34.716025+00:00`
- Input: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/real_world_code_size.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Iterations per program: `5`
- Repeat count per invocation: `1000`
- I/O mode: `packet`

## Summary

| Metric | Value |
| --- | ---: |
| Programs paired in code-size input | 105 |
| Kernel `BPF_PROG_TEST_RUN` succeeded | 46 |
| llvmbpf runs completed | 44 |
| Programs with both runtimes ok | 44 |
| Geomean exec ratio (llvmbpf/kernel) | 0.753x |

## Runtime Status

| Runtime | ok | error | timeout | skipped |
| --- | ---: | ---: | ---: | ---: |
| kernel | 46 | 59 | 0 | 0 |
| llvmbpf | 44 | 2 | 0 | 59 |

## kernel Failures

| Error summary | Count |
| --- | ---: |
| bpf_prog_test_run_opts failed: Unknown error 524 | 58 |
| bpf_prog_test_run_opts failed: Bad address | 1 |

## llvmbpf Failures

| Error summary | Count |
| --- | ---: |
| unknown error | 2 |

## Program-Level Results

| Repo | Artifact | Program | Section | llvmbpf median ns | kernel median ns | L/K ratio |
| --- | --- | --- | --- | ---: | ---: | ---: |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 48.0 | 0.271x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 41.0 | 0.317x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 41.0 | 0.317x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 41.0 | 0.317x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 36.0 | 0.361x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 28.0 | 75.0 | 0.373x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 28.0 | 0.464x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.0 | 22.0 | 0.545x |
| bcf/cilium | `clang-20_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 20.0 | 0.550x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 37.0 | 64.0 | 0.578x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 20.0 | 0.600x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 19.0 | 0.632x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 24.0 | 37.0 | 0.649x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 20.0 | 0.650x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 20.0 | 0.650x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 25.0 | 36.0 | 0.694x |
| libbpf-bootstrap | `examples/c/sockfilter.bpf.c` | `socket_handler` | `socket` | 11.0 | 15.0 | 0.733x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 32.0 | 38.0 | 0.842x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 14.0 | 0.857x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 14.0 | 0.857x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 14.0 | 0.857x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 14.0 | 0.857x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 14.0 | 0.857x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 35.0 | 38.0 | 0.921x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 37.0 | 36.0 | 1.028x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 37.0 | 36.0 | 1.028x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 28.0 | 21.0 | 1.333x |
| bcf/cilium | `clang-15_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 7.0 | 1.571x |
| bcf/cilium | `clang-14_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 13.0 | 8.0 | 1.625x |
| bcf/cilium | `clang-16_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 6.0 | 1.833x |
| bcf/cilium | `clang-17_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 6.0 | 1.833x |
| bcf/cilium | `clang-18_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 6.0 | 1.833x |
| bcf/cilium | `clang-21_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 6.0 | 1.833x |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 11.0 | 5.0 | 2.200x |
| bcf/cilium | `clang-19_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 15.0 | 6.0 | 2.500x |

## Notes

- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.json`.
- Each median is computed across separate `micro_exec` invocations; each invocation uses packet mode with `--repeat 1000` and no input file.
- Kernel runs are attempted first; if `run-kernel` fails, the program is recorded as unsupported for exec-time comparison and llvmbpf is marked `skipped`.
- `--program-name` uses the libbpf program name stored in the code-size results; section names are reported alongside the measurements.
