# Tetragon End-to-End Benchmark Results

- Generated: 2026-03-11T15:41:58.693052+00:00
- Mode: `direct-objects`
- Smoke run: `False`
- Runner: `micro/build/runner/micro_exec`
- Scanner: `scanner/build/bpf-jit-scanner`
- bpftool: `/usr/local/sbin/bpftool`
- Tetragon binary: `not found`

## Preflight

| Check | Value |
| --- | --- |
| sudo -n true | yes |
| bpftool | /usr/local/sbin/bpftool |
| stress-ng | /bin/stress-ng |
| scanner | scanner/build/bpf-jit-scanner |
| micro_exec | micro/build/runner/micro_exec |
| execve object | corpus/build/tetragon/bpf_execve_event.bpf.o |
| kprobe object | corpus/build/tetragon/bpf_generic_kprobe.bpf.o |
| BTF | /sys/kernel/btf/vmlinux |
| kernel | 7.0.0-rc2-g2a6783cc77b6 |

## Summary

| Metric | Value |
| --- | --- |
| Targets | 3 |
| Stock OK | 0 |
| ReJIT OK | 0 |
| Comparable speedups | 0 |
| Best speedup | n/a |
| Worst speedup | n/a |

## Per-Program

| Program | Attach Target | Type | Sites | Stock Avg ns | ReJIT Avg ns | Speedup | Stock events/s | ReJIT events/s | Stock CPU ns | ReJIT CPU ns | Stock | ReJIT |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| event_execve | syscalls/sys_enter_execve | tracepoint | 37 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | failed | failed |
| generic_kprobe_event | security_file_open | kprobe | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | failed | failed |
| generic_kprobe_event | security_socket_connect | kprobe | 0 | n/a | n/a | n/a | n/a | n/a | n/a | n/a | failed | failed |

## Failures

| Program | Phase | Error |
| --- | --- | --- |
| event_execve | stock | event_execve attach failed: No such file or directory |
| event_execve | rejit | event_execve attach failed: No such file or directory |
| generic_kprobe_event | stock | bpf_object__load failed: Invalid argument |
| generic_kprobe_event | rejit | bpf_object__load failed: Invalid argument |
| generic_kprobe_event | stock | bpf_object__load failed: Invalid argument |
| generic_kprobe_event | rejit | bpf_object__load failed: Invalid argument |

## Notes

- Direct-object mode first probes `bpftool prog loadall ... autoattach`; when that cannot create links for the local Tetragon objects, the harness falls back to whole-object libbpf load plus explicit attach targets.
- Directive census uses `scanner/build/bpf-jit-scanner scan --v5` against loaded program FDs.
- Recompile uses `scanner/build/bpf-jit-scanner apply --v5`, so kernel support for `BPF_PROG_JIT_RECOMPILE` is required for comparable stock vs recompiled numbers.
- Programs that cannot be honestly attached are only sent through `micro_exec` `test_run` when their type is known to support that path; otherwise they are reported as skipped/failed instead of being misrepresented.
