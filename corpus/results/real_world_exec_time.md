# Real-World Execution-Time Validation

- Generated at: `2026-03-07T23:16:03.430438+00:00`
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
| Geomean exec ratio (llvmbpf/kernel) | 0.694x |

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
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 16.5 | 76.5 | 0.216x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 51.0 | 0.235x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.0 | 49.5 | 0.242x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.0 | 49.0 | 0.245x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.5 | 49.0 | 0.255x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 49.5 | 0.263x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 16.0 | 58.5 | 0.274x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 12.0 | 43.5 | 0.276x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 58.0 | 0.293x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 57.5 | 0.296x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 12.5 | 39.5 | 0.316x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_to_host` | `tc` | 15.5 | 48.5 | 0.320x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 52.5 | 0.324x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 13.0 | 40.0 | 0.325x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 12.0 | 35.0 | 0.343x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.0 | 34.5 | 0.348x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 48.0 | 0.354x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 13.0 | 36.0 | 0.361x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 27.0 | 72.0 | 0.375x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_host` | `tc` | 24.5 | 63.5 | 0.386x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 15.0 | 38.0 | 0.395x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.0 | 30.0 | 0.400x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_to_host` | `tc` | 26.0 | 63.0 | 0.413x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 26.0 | 60.5 | 0.430x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 26.5 | 61.0 | 0.434x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 37.0 | 0.459x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 17.0 | 36.0 | 0.472x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_host` | `tc` | 38.0 | 80.0 | 0.475x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_to_host` | `tc` | 16.0 | 31.5 | 0.508x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 24.0 | 47.0 | 0.511x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 22.5 | 0.533x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_to_host` | `tc` | 26.5 | 49.0 | 0.541x |
| bcf/cilium | `clang-15_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 20.0 | 0.550x |
| bcf/cilium | `clang-16_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 20.0 | 0.550x |
| bcf/cilium | `clang-18_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 20.0 | 0.550x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 20.0 | 36.0 | 0.556x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.0 | 21.0 | 0.571x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.5 | 23.0 | 0.587x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_host` | `tc` | 33.5 | 56.5 | 0.593x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.5 | 21.0 | 0.595x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 12.5 | 21.0 | 0.595x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 12.0 | 20.0 | 0.600x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.0 | 20.0 | 0.600x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 38.0 | 62.5 | 0.608x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_host` | `tc` | 22.5 | 36.5 | 0.616x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 13.0 | 21.0 | 0.619x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 21.5 | 34.5 | 0.623x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 12.5 | 20.0 | 0.625x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 13.0 | 20.5 | 0.634x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 40.5 | 62.0 | 0.653x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_host` | `tc` | 34.0 | 51.0 | 0.667x |
| bcf/cilium | `clang-19_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 13.5 | 20.0 | 0.675x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 16.0 | 0.750x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 17.0 | 22.0 | 0.773x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 15.0 | 0.800x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 17.0 | 21.0 | 0.810x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_host` | `tc` | 30.0 | 36.0 | 0.833x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 33.0 | 39.5 | 0.835x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 26.0 | 30.5 | 0.852x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 12.0 | 14.0 | 0.857x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 32.0 | 37.0 | 0.865x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 32.0 | 36.0 | 0.889x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 44.5 | 49.5 | 0.899x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 19.5 | 21.0 | 0.929x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 22.0 | 22.0 | 1.000x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 21.0 | 21.0 | 1.000x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_host` | `tc` | 35.0 | 35.0 | 1.000x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 15.0 | 15.0 | 1.000x |
| libbpf-bootstrap | `examples/c/sockfilter.bpf.c` | `socket_handler` | `socket` | 11.0 | 11.0 | 1.000x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_to_host` | `tc` | 21.5 | 21.0 | 1.024x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 20.5 | 20.0 | 1.025x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 16.0 | 15.0 | 1.067x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 46.0 | 42.5 | 1.082x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 29.5 | 27.0 | 1.093x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 26.0 | 22.5 | 1.156x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 25.5 | 22.0 | 1.159x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_host` | `tc` | 41.0 | 35.0 | 1.171x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 68.0 | 58.0 | 1.172x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 31.0 | 25.0 | 1.240x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 44.5 | 35.5 | 1.254x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_to_host` | `tc` | 27.0 | 21.0 | 1.286x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 30.5 | 23.0 | 1.326x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 20.0 | 15.0 | 1.333x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 53.0 | 39.0 | 1.359x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_to_host` | `tc` | 29.0 | 21.0 | 1.381x |
| bcf/cilium | `clang-20_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 15.0 | 10.5 | 1.429x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_to_host` | `tc` | 32.0 | 21.0 | 1.524x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 30.5 | 20.0 | 1.525x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 73.0 | 43.0 | 1.698x |
| bcf/cilium | `clang-14_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 6.0 | 1.833x |
| bcf/cilium | `clang-21_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 11.0 | 6.0 | 1.833x |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 11.0 | 5.0 | 2.200x |
| bcf/cilium | `clang-17_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 13.5 | 6.0 | 2.250x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 72.5 | 22.0 | 3.295x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 68.5 | 20.0 | 3.425x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 70.0 | 20.0 | 3.500x |

## Notes

- Inputs come from the subset of programs that already compiled successfully on both runtimes in `real_world_code_size.json`.
- Each median is computed across separate `micro_exec` invocations; each invocation uses packet mode with `--repeat 1000` and no input file.
- Kernel runs are attempted first; if `run-kernel` fails, the program is recorded as unsupported for exec-time comparison and llvmbpf is marked `skipped`.
- `--program-name` uses the libbpf program name stored in the code-size results; section names are reported alongside the measurements.
