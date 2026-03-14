# Tracee E2E VM Summary

- Date: `2026-03-11`
- Kernel: `7.0.0-rc2-g2a6783cc77b6` from `vendor/linux-framework/arch/x86/boot/bzImage`
- Execution mode: `manual` inside `vng`
- Adjustment: ran with `--module-ops 0` because this framework kernel has modules disabled, so `modprobe dummy` cannot exercise `module_load`

## Recompile Outcome

- `BPF_PROG_JIT_RECOMPILE` succeeded on the framework kernel for all 5 selected Tracee programs.
- Applied directive sites: `17` total = `14 cmov` + `3 wide` + `0 rotate` + `0 lea`.
- Per-program accepted sites:
- `tracepoint__sched__sched_process_exec`: `4`
- `trace_security_file_open`: `5` (`2 cmov`, `3 wide`)
- `trace_security_socket_connect`: `3`
- `tracepoint__module__module_load`: `3`
- `lsm_file_open_test`: `2`

## Per-Program Results

| Workload | Program | Stock avg_ns | ReJIT avg_ns | Speedup |
| --- | --- | ---: | ---: | ---: |
| process-exec | `tracepoint__sched__sched_process_exec` | 4407.00 | 1628.00 | 2.71x |
| file-open | `lsm_file_open_test` | 152.23 | 138.30 | 1.10x |
| file-open | `trace_security_file_open` | 359.38 | 306.08 | 1.17x |
| network-connect | `trace_security_socket_connect` | 798.16 | 1202.94 | 0.66x |
| module-load | `tracepoint__module__module_load` | n/a | n/a | not exercised |

## Overall Assessment

- The framework kernel's v5 recompile path works end-to-end inside the VM: all requested Tracee programs accepted and applied their directives without syscall errors.
- Performance is mixed rather than uniformly positive. Median workload throughput improved by `1.05x`, but median event rate dropped to `0.89x` of stock and median BPF ns/run worsened by `1.51x`.
- The best win was `tracepoint__sched__sched_process_exec` at `2.71x` faster. The file-open programs improved modestly at `1.10x` to `1.17x`.
- `trace_security_socket_connect` regressed to `0.66x`, which dominates the overall slowdown signal in the aggregate metrics.
- The generated markdown result also notes that manual mode cannot isolate Tracee's high-level `open` event, so the file workload reports `security_file_open` and marks `open` unsupported.
- cgroup fallback checks also regressed under re-JIT: `cgroup_skb_ingress` `42 -> 69 ns`, `cgroup_skb_egress` `49 -> 58 ns`.
