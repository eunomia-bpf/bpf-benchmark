# Tracee E2E Benchmark Results

- Generated: 2026-03-11T15:39:23.905356+00:00
- Mode selected: `manual`
- Tracee binary: `not available`
- Tracee object: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/tracee.bpf.o`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`

## Tooling

- bpftool: `/sbin/bpftool`
- curl: `/bin/curl`
- dd: `/bin/dd`
- fio: `/bin/fio`
- stress-ng: `/bin/stress-ng`
- tracee: `missing`
- wrk: `missing`

## Variant Summary

### stock

- Recompile applied: `False`
- Workload ops/s median: `40.39909579955766`
- Event rate median: `42.90753953670067`
- Avg BPF ns/run median: `798.1578947368421`

- process-exec: ops/s=183.3268793716519 total_events/s=7.333075174866076 events={'execve': 1}
- file-open: ops/s=40.39909579955766 total_events/s=3097.2640112994204 events={'security_file_open': 920} unsupported=['open']
- network-connect: ops/s=13.549749327379159 total_events/s=42.90753953670067 events={'connect': 38}

### v5-all

- Recompile applied: `True`
- Workload ops/s median: `42.510716349356464`
- Event rate median: `38.34207769680167`
- Avg BPF ns/run median: `1202.9444444444443`

- process-exec: ops/s=401.2435339604421 total_events/s=16.049741358417684 events={'execve': 1}
- file-open: ops/s=42.510716349356464 total_events/s=3244.9846813342106 events={'security_file_open': 916} unsupported=['open']
- network-connect: ops/s=12.780692565600557 total_events/s=38.34207769680167 events={'connect': 36}

## Comparison

- Event-rate speedup: `0.893597677956016`
- Workload-throughput speedup: `1.0522690052340709`
- Avg BPF ns/run ratio: `1.507150968970949`

## cgroup_skb Fallback

- Repeat: `8`
- cgroup_skb_ingress: baseline_exec_ns=42 rejit_exec_ns=69 rejit_error=
- cgroup_skb_egress: baseline_exec_ns=49 rejit_exec_ns=58 rejit_error=

## Notes

- wrk is not installed; the connect workload uses a curl loop against a localhost HTTP server.
- Manual fallback does not isolate Tracee's high-level `open` user event from the monolithic object; the file workload reports `security_file_open` and marks `open` as unsupported.
