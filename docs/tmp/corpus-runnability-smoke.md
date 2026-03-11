# Corpus Runnability Report

- Generated: 2026-03-11T04:25:46.599529+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Corpus root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Packet repeat: 20
- Tracing repeat: 3
- Recompile mode: `v5`
- BPF objects scanned: 25
- Programs discovered: 20
- Loadable programs: 19
- Programs with directive sites: 0
- Packet-test-run candidates: 1
- Packet baseline-runnable programs: 1
- Packet paired baseline/recompile programs: 0
- Tracing attach+trigger candidates: 11
- Tracing programs with positive run_cnt delta: 10
- Truly runnable programs: 11
- Truly runnable objects: 7
- Packet speedup geomean: n/a

## Strategy Summary

| Strategy | Programs |
| --- | --- |
| iterator_custom_harness | 1 |
| lsm_custom_harness | 1 |
| packet_test_run | 1 |
| perf_event_custom | 1 |
| tracing_attach_trigger | 11 |
| user_tracing_custom_target | 5 |

## Directive Totals

| Metric | Value |
| --- | --- |
| CMOV sites | 0 |
| WIDE sites | 0 |
| ROTATE sites | 0 |
| LEA sites | 0 |
| Tracing avg ns/run min | 91.00 |
| Tracing avg ns/run max | 1926.00 |

## By Program Type

| Prog Type | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | Primary Strategy |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| kprobe | 4 | 9 | 9 | 0 | 0 | 0 | 3 | user_tracing_custom_target |
| tracepoint | 3 | 5 | 5 | 0 | 0 | 0 | 5 | tracing_attach_trigger |
| tracing | 2 | 3 | 3 | 0 | 0 | 0 | 2 | tracing_attach_trigger |
| lsm | 1 | 1 | 0 | 0 | 0 | 0 | 0 | lsm_custom_harness |
| perf_event | 1 | 1 | 1 | 0 | 0 | 0 | 0 | perf_event_custom |
| sched_cls | 1 | 1 | 1 | 0 | 1 | 0 | 0 | packet_test_run |

## By Source

| Source | Objects | Programs | Loadable | Sites | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| libbpf-bootstrap | 12 | 20 | 19 | 0 | 1 | 0 | 10 | 11 |

## Object Inventory

| Object | Source | Programs | Loadable | Site Programs | Sites | Packet Candidates | Packet Runnable | Packet Paired | Tracing +Runs | True Runnable | Top Strategies |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 1 | 1 | 0 | 0 | yes | packet_test_run |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 2 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o | libbpf-bootstrap | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/minimal.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | yes | tracing_attach_trigger |
| corpus/build/libbpf-bootstrap/examples/c/lsm.bpf.o | libbpf-bootstrap | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | no | lsm_custom_harness |
| corpus/build/libbpf-bootstrap/examples/c/profile.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | perf_event_custom |
| corpus/build/libbpf-bootstrap/examples/c/task_iter.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | iterator_custom_harness |
| corpus/build/libbpf-bootstrap/examples/c/uprobe.bpf.o | libbpf-bootstrap | 4 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |
| corpus/build/libbpf-bootstrap/examples/c/usdt.bpf.o | libbpf-bootstrap | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | no | user_tracing_custom_target |

## Tracing Measurements

| Program | Type | Section | Trigger | Runs | Run Time ns | Avg ns/run | Sites |
| --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o:entry_probe | kprobe | ksyscall/kill | signal | 3 | 273 | 91.00 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/minimal.bpf.o:handle_tp | tracepoint | tp/syscalls/sys_enter_write | write-devnull | 14 | 2876 | 205.43 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exit | tracepoint | tp/sched/sched_process_exit | execve | 3 | 2944 | 981.33 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o:handle_exec | tracepoint | tp/sched/sched_process_exec | execve | 3 | 3535 | 1178.33 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exec | tracepoint | tp/sched/sched_process_exec | execve | 3 | 4374 | 1458.00 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat | tracing | fentry/do_unlinkat | unlink | 3 | 4944 | 1648.00 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o:do_unlinkat_exit | kprobe | kretprobe/do_unlinkat | unlink | 3 | 5122 | 1707.33 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o:do_unlinkat | kprobe | kprobe/do_unlinkat | unlink | 3 | 5295 | 1765.00 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o:handle_exit | tracepoint | tp/sched/sched_process_exit | execve | 3 | 5427 | 1809.00 | 0 |
| corpus/build/libbpf-bootstrap/examples/c/fentry.bpf.o:do_unlinkat_exit | tracing | fexit/do_unlinkat | unlink | 3 | 5778 | 1926.00 | 0 |

## Top Load Failures

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Invalid argument (exit=1) | 1 |

## Notes

- Program type comes from `micro_exec list-programs`, which now surfaces libbpf-inferred `prog_type` and `expected_attach_type` per program.
- Packet-backed measurements use `bpf_prog_test_run_opts()` and the existing `micro_exec run-kernel` path.
- Tracing measurements use real load + attach + trigger, then read `run_cnt` and `run_time_ns` from `bpf_prog_info`.
- Directive counts prefer the live recompile probe. When that fails but the program still loads, the report falls back to `dump-xlated` plus `bpf-jit-scanner scan --xlated --v5`.
- `syscall` programs are counted separately because the kernel has a synthetic test-run path, but this report does not treat that as a real attached workload benchmark.
