# Tracee E2E Benchmark Results

- Generated: 2026-03-11T15:31:55.578895+00:00
- Mode selected: `manual`
- Tracee binary: `not available`
- Tracee object: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/tracee.bpf.o`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`

## Tooling

- bpftool: `/usr/local/sbin/bpftool`
- curl: `/usr/bin/curl`
- dd: `/usr/bin/dd`
- fio: `/usr/bin/fio`
- stress-ng: `/usr/bin/stress-ng`
- tracee: `missing`
- wrk: `missing`

## Variant Summary

### stock

- Recompile applied: `False`
- Workload ops/s median: `100.11808170326776`
- Event rate median: `1266.4841137391502`
- Avg BPF ns/run median: `1672.5845070422536`

- process-exec: ops/s=137.02585865615075 total_events/s=27.40517173123015 events={'execve': 1}
- file-open: ops/s=63.210304750384765 total_events/s=3455.4966596877002 events={'security_file_open': 164} unsupported=['open']
- network-connect: ops/s=176.44810251739932 total_events/s=2505.5630557470704 events={'connect': 71}
- module-load: ops/s=23.839385471579238 total_events/s=23.839385471579238 events={'module_load': 1}

### v5-all

- Recompile applied: `False`
- Recompile error: `Invalid argument`
- Workload ops/s median: `112.85899721236163`
- Event rate median: `912.8407693723011`
- Avg BPF ns/run median: `1457.235294117647`

- process-exec: ops/s=139.5828053324359 total_events/s=27.91656106648718 events={'execve': 1}
- file-open: ops/s=86.13518909228738 total_events/s=3990.9304279426487 events={'security_file_open': 139} unsupported=['open']
- network-connect: ops/s=176.2514683998152 total_events/s=1797.764977678115 events={'connect': 51}
- module-load: ops/s=25.556900837952004 total_events/s=25.556900837952004 events={'module_load': 1}

## Comparison

- Comparable: `False`
- Reason: `Invalid argument`

## cgroup_skb Fallback

- Repeat: `2`
- cgroup_skb_ingress: baseline_exec_ns=165 rejit_exec_ns=164 rejit_error=BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)
- cgroup_skb_egress: baseline_exec_ns=160 rejit_exec_ns=100 rejit_error=BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)

## Notes

- wrk is not installed; the connect workload uses a curl loop against a localhost HTTP server.
- Manual fallback does not isolate Tracee's high-level `open` user event from the monolithic object; the file workload reports `security_file_open` and marks `open` as unsupported.
