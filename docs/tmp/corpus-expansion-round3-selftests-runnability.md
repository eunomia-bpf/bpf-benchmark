# Corpus Runnability Report

- Generated: 2026-03-11T13:51:31.170484+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Packet repeat: 200
- Tracing repeat: 10
- Recompile mode: `v5`
- BPF objects scanned: 5
- Programs discovered: 14
- Loadable programs: 13
- Programs with directive sites: 6
- Packet-test-run candidates: 10
- Packet baseline-runnable programs: 10
- Packet paired baseline/recompile programs: 5
- Tracing attach+trigger candidates: 1
- Tracing programs with positive run_cnt delta: 0
- Truly runnable programs: 10
- Truly runnable objects: 4
- Packet speedup geomean: 1.023x

## Strategy Summary

| Strategy | Programs |
| --- | --- |
| packet_test_run | 10 |
| socket_custom_harness | 3 |
| tracing_attach_trigger | 1 |

## Directive Totals

| Metric | Value |
| --- | --- |
| CMOV sites | 5 |
| WIDE sites | 7 |
| ROTATE sites | 0 |
| LEA sites | 0 |
| Tracing avg ns/run min | n/a |
| Tracing avg ns/run max | n/a |

## By Program Type

| Prog Type | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | Primary Strategy |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| flow_dissector | 1 | 7 | 7 | 4 | 7 | 4 | 0 | packet_test_run |
| sk_reuseport | 2 | 3 | 3 | 1 | 0 | 0 | 0 | socket_custom_harness |
| cgroup_skb | 1 | 1 | 1 | 0 | 1 | 0 | 0 | packet_test_run |
| sched_cls | 1 | 1 | 1 | 1 | 1 | 1 | 0 | packet_test_run |
| tracing | 1 | 1 | 0 | 0 | 0 | 0 | 0 | tracing_attach_trigger |
| xdp | 1 | 1 | 1 | 0 | 1 | 0 | 0 | packet_test_run |

## By Source

| Source | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| linux-selftests | 5 | 14 | 13 | 6 | 10 | 5 | 0 | 10 |

## Object Inventory

| Object | Source | Programs | Loadable | Site Programs | Sites | Packet Candidates | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable | Top Strategies |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o | linux-selftests | 7 | 7 | 4 | 4 | 7 | 7 | 4 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o | linux-selftests | 3 | 3 | 2 | 8 | 1 | 1 | 1 | 0 | yes | socket_custom_harness, packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgroup_skb_sk_lookup_kern.bpf.o | linux-selftests | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_migrate_reuseport.bpf.o | linux-selftests | 2 | 2 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run, socket_custom_harness |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/trace_dummy_st_ops.bpf.o | linux-selftests | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | tracing_attach_trigger |

## Packet Paired Measurements

| Program | Type | Section | Baseline ns | Recompile ns | Speedup | Correct | Sites | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o:flow_dissector_0 | flow_dissector | flow_dissector | 91 | 79 | 1.152x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o:flow_dissector_1 | flow_dissector | flow_dissector | 80 | 80 | 1.000x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o:flow_dissector_2 | flow_dissector | flow_dissector | 79 | 78 | 1.013x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o:flow_dissector_3 | flow_dissector | flow_dissector | 78 | 73 | 1.068x | match | 1 | 1 | 0 | 0 | 0 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o:tc_main | sched_cls | tc | 18 | 20 | 0.900x | match | 1 | 1 | 0 | 0 | 0 |

## Directive-Bearing But Not Yet Runnable

| Program | Type | Section | Strategy | Sites | Reason |
| --- | --- | --- | --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o:reuse_accept | sk_reuseport | sk_reuseport | socket_custom_harness | 7 | requires socket lifecycle or listener setup beyond packet test_run |

## Top Load Failures

| Reason | Count |
| --- | --- |
| bpf_object__load failed: No such process (exit=1) | 1 |

## Notes

- Program type comes from `micro_exec list-programs`, which now surfaces libbpf-inferred `prog_type` and `expected_attach_type` per program.
- Packet-backed measurements use `bpf_prog_test_run_opts()` and the existing `micro_exec run-kernel` path.
- Tracing measurements use real load + attach + trigger, then read `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- Directive counts prefer the live recompile probe. When that fails but the program still loads, the report falls back to `dump-xlated` plus `bpf-jit-scanner scan --xlated --v5`.
- `syscall` programs are counted separately because the kernel has a synthetic test-run path, but this report does not treat that as a real attached workload benchmark.

