# Corpus Runnability Report

- Generated: 2026-03-11T04:26:10.570229+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Packet repeat: 20
- Tracing repeat: 3
- Recompile mode: `v5`
- BPF objects scanned: 3
- Programs discovered: 5
- Loadable programs: 5
- Programs with directive sites: 5
- Packet-test-run candidates: 5
- Packet baseline-runnable programs: 5
- Packet paired baseline/recompile programs: 5
- Tracing attach+trigger candidates: 0
- Tracing programs with positive run_cnt delta: 0
- Truly runnable programs: 5
- Truly runnable objects: 3
- Packet speedup geomean: 0.942x

## Strategy Summary

| Strategy | Programs |
| --- | --- |
| packet_test_run | 5 |

## Directive Totals

| Metric | Value |
| --- | --- |
| CMOV sites | 9 |
| WIDE sites | 12 |
| ROTATE sites | 0 |
| LEA sites | 0 |
| Tracing avg ns/run min | n/a |
| Tracing avg ns/run max | n/a |

## By Program Type

| Prog Type | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | Primary Strategy |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| sched_cls | 3 | 3 | 3 | 3 | 3 | 3 | 0 | packet_test_run |
| xdp | 2 | 2 | 2 | 2 | 2 | 2 | 0 | packet_test_run |

## By Source

| Source | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 3 | 5 | 5 | 5 | 5 | 5 | 0 | 5 |

## Object Inventory

| Object | Source | Programs | Loadable | Site Programs | Sites | Packet Candidates | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable | Top Strategies |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o | linux-selftests | 2 | 2 | 2 | 10 | 2 | 2 | 2 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o | linux-selftests | 2 | 2 | 2 | 10 | 2 | 2 | 2 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o | linux-selftests | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 0 | yes | packet_test_run |

## Packet Paired Measurements

| Program | Type | Section | Baseline ns | Recompile ns | Speedup | Correct | Sites | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_tc | sched_cls | tc | 29 | 18 | 1.611x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | xdp | 39 | 40 | 0.975x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_tc | sched_cls | tc | 33 | 36 | 0.917x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | xdp | 43 | 50 | 0.860x | match | 5 | 2 | 3 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_change_tail.bpf.o:change_tail | sched_cls | tc/ingress | 33 | 55 | 0.600x | match | 1 | 1 | 0 | 0 | 0 |

## Notes

- Program type comes from `micro_exec list-programs`, which now surfaces libbpf-inferred `prog_type` and `expected_attach_type` per program.
- Packet-backed measurements use `bpf_prog_test_run_opts()` and the existing `micro_exec run-kernel` path.
- Tracing measurements use real load + attach + trigger, then read `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- Directive counts prefer the live recompile probe. When that fails but the program still loads, the report falls back to `dump-xlated` plus `bpf-jit-scanner scan --xlated --v5`.
- `syscall` programs are counted separately because the kernel has a synthetic test-run path, but this report does not treat that as a real attached workload benchmark.
