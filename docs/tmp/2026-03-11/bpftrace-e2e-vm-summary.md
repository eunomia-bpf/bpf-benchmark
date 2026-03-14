# bpftrace E2E VM Summary

- Guest kernel: `7.0.0-rc2-g2a6783cc77b6`
- Result files: `docs/tmp/bpftrace-e2e-vm-results.json`, `docs/tmp/bpftrace-e2e-vm-results.md`
- Aggregate directive sites: 9 total (`cmov=9`, `wide=0`, `rotate=0`, `lea=0`)

## Outcome

- `--emit-elf` worked for 4/5 scripts in the VM. `exec_tracing` failed at emit time because `tracepoint:syscalls:sys_enter_execve` was not present in this guest kernel.
- Live attach worked for 4/5 scripts.
- Live `BPF_PROG_JIT_RECOMPILE` succeeded for 2/2 eligible scripts:
  - `open_latency`: accepted/applied 5 `cmov` sites on `do_sys_openat2`
  - `scheduler_latency`: accepted/applied 4 `cmov` sites on `sched_switch`
- Scripts with 0 candidate sites (`vfs_read_count`, `tcp_connect`) had no recompile attempt, so their ReJIT columns remain `n/a`.
- Overall geomean speedup across scripts with both stock and ReJIT measurements: `0.956x` (slower than stock).

## Per-Script

| Script | Sites | Stock ns | ReJIT ns | Speedup | Notes |
| --- | --- | --- | --- | --- | --- |
| `open_latency` | 5 | 118.48 | 125.12 | 0.947x | `--emit-elf` ok, live attach ok, recompile applied 5 `cmov` sites |
| `exec_tracing` | 0 | n/a | n/a | n/a | `--emit-elf` failed: `tracepoint not found: syscalls:sys_enter_execve` |
| `scheduler_latency` | 4 | 97.74 | 101.28 | 0.965x | `--emit-elf` ok, live attach ok, recompile applied 4 `cmov` sites |
| `vfs_read_count` | 0 | 50.91 | n/a | n/a | `--emit-elf` ok, live attach ok, no eligible recompile sites |
| `tcp_connect` | 0 | 413.57 | n/a | n/a | `--emit-elf` ok, live attach ok, no eligible recompile sites |

## Notes

- The artifact load-probe path was still 0/5 (`bpf_object__load failed: Invalid argument`), but that did not block the live bpftrace attach path used for the VM recompile experiment.
- The initial VM run found Ubuntu's kernel-tools wrapper instead of the real `bpftool`. Prepending `/usr/local/sbin` in the guest `PATH` fixed live program discovery.
