# Real-World Execution-Time Validation

- Generated at: `2026-03-07T23:50:39.411451+00:00`
- Input: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/real_world_code_size_v2.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Iterations per program: `10`
- Repeat count per invocation: `1000`
- I/O mode: `packet`

## Summary

| Metric | Value |
| --- | ---: |
| Programs paired in code-size input | 162 |
| Kernel `BPF_PROG_TEST_RUN` succeeded | 100 |
| llvmbpf runs completed | 98 |
| Programs with both runtimes ok | 98 |
| Geomean exec ratio (llvmbpf/kernel) | 0.514x |

## Runtime Status

| Runtime | ok | error | timeout | skipped |
| --- | ---: | ---: | ---: | ---: |
| kernel | 100 | 62 | 0 | 0 |
| llvmbpf | 98 | 2 | 0 | 62 |

## kernel Failures

| Error summary | Count |
| --- | ---: |
| bpf_prog_test_run_opts failed: Unknown error 524 | 61 |
| bpf_prog_test_run_opts failed: Bad address | 1 |

## llvmbpf Failures

| Error summary | Count |
| --- | ---: |
| unknown error | 2 |

## Program-Level Results

| Repo | Artifact | Program | Section | llvmbpf median ns | kernel median ns | L/K ratio |
| --- | --- | --- | --- | ---: | ---: | ---: |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 11.0 | 120.0 | 0.092x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 55.5 | 0.234x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 55.0 | 0.236x |
| bcf/cilium | `clang-21_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 46.5 | 0.237x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 46.0 | 0.283x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 15.5 | 54.5 | 0.284x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 44.0 | 0.295x |
| bcf/cilium | `clang-15_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 37.0 | 0.297x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 18.5 | 61.5 | 0.301x |
| bcf/cilium | `clang-19_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 36.0 | 0.306x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 37.5 | 0.320x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 23.5 | 70.5 | 0.333x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.5 | 36.0 | 0.347x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 18.5 | 53.0 | 0.349x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 37.0 | 0.351x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 37.0 | 0.351x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 37.0 | 0.351x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 37.0 | 0.351x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 18.0 | 50.0 | 0.360x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_host` | `tc` | 16.0 | 44.0 | 0.364x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 19.5 | 53.5 | 0.364x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 30.5 | 0.393x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 30.0 | 0.400x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 21.0 | 52.5 | 0.400x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_to_host` | `tc` | 16.0 | 39.0 | 0.410x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 29.0 | 0.414x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 29.0 | 0.414x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 29.0 | 0.414x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 30.0 | 72.0 | 0.417x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_host` | `tc` | 16.5 | 39.0 | 0.423x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 23.0 | 53.0 | 0.434x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 24.0 | 53.0 | 0.453x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 26.5 | 0.453x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_host` | `tc` | 19.0 | 41.0 | 0.463x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 25.0 | 53.0 | 0.472x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_host` | `tc` | 19.0 | 40.0 | 0.475x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 25.5 | 52.5 | 0.486x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 26.5 | 54.0 | 0.491x |
| bcf/cilium | `clang-14_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 22.0 | 0.500x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_host` | `tc` | 19.5 | 39.0 | 0.500x |
| bcf/cilium | `clang-17_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 22.0 | 0.500x |
| bcf/cilium | `clang-18_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 22.0 | 0.500x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_host` | `tc` | 20.0 | 39.0 | 0.513x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 15.0 | 29.0 | 0.517x |
| bcf/cilium | `clang-16_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 21.0 | 0.524x |
| bcf/cilium | `clang-20_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 21.0 | 0.524x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 15.5 | 29.0 | 0.534x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 18.5 | 34.5 | 0.536x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 31.0 | 56.0 | 0.554x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 23.0 | 0.565x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_to_host` | `tc` | 27.0 | 47.0 | 0.574x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 22.0 | 0.591x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 22.0 | 0.591x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 22.0 | 0.591x |
| libbpf-bootstrap | `examples/c/sockfilter.bpf.c` | `socket_handler` | `socket` | 11.0 | 18.5 | 0.595x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.5 | 21.0 | 0.595x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 21.5 | 34.5 | 0.623x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.5 | 21.5 | 0.628x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 20.5 | 0.634x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 20.5 | 0.634x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_to_host` | `tc` | 20.0 | 29.5 | 0.678x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_to_host` | `tc` | 15.0 | 22.0 | 0.682x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 36.5 | 52.0 | 0.702x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_to_host` | `tc` | 15.5 | 22.0 | 0.705x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 26.0 | 36.0 | 0.722x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 20.0 | 27.0 | 0.741x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_to_host` | `tc` | 16.5 | 22.0 | 0.750x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_host` | `tc` | 29.5 | 39.0 | 0.756x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_to_host` | `tc` | 17.0 | 22.0 | 0.773x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_host` | `tc` | 31.0 | 39.0 | 0.795x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_to_host` | `tc` | 18.5 | 22.0 | 0.841x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 30.0 | 33.5 | 0.896x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 18.5 | 20.0 | 0.925x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 19.5 | 21.0 | 0.929x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 21.5 | 21.0 | 1.024x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 26.0 | 21.0 | 1.238x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 29.5 | 21.0 | 1.405x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 30.5 | 21.0 | 1.452x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 31.5 | 21.0 | 1.500x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 33.5 | 21.0 | 1.595x |

## Notes

- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.json`.
- Each median is computed across separate `micro_exec` invocations; each invocation uses packet mode with a generated valid raw packet input from `/home/yunwei37/workspace/bpf-benchmark/corpus/results/valid_packet.bin`.
- Kernel runs are attempted first; if `run-kernel` fails, the program is recorded as unsupported for exec-time comparison and llvmbpf is marked `skipped`.
- `--program-name` uses the libbpf program name stored in the code-size results; section names are reported alongside the measurements.
