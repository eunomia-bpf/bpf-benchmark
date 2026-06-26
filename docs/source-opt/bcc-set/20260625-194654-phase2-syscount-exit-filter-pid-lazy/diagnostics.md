# Diagnostics

Patch shape:

- Stacks phase2 attempt 1: `capable` is one `fexit/cap_capable` program and
  `syscount` keeps the interrupt-id fast return before `bpf_get_current_pid_tgid()`.
- Changes `syscount` section names from `tracepoint/raw_syscalls/sys_enter` and
  `tracepoint/raw_syscalls/sys_exit` to `raw_tracepoint/sys_enter` and
  `raw_tracepoint/sys_exit`.
- Keeps the existing `syscount.c` skeleton attach path unchanged; the real
  `syscount` binary still loads and attaches its own BPF programs.

Build artifact checked:

- `vendor/build/.bcc-libbpf/x86/output/capable.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/syscount.bpf.o`

Object diagnostics after build:

| Object | Program sections | Instruction lines |
| --- | --- | ---: |
| `capable.bpf.o` | `fexit/cap_capable` size `0x4c0`; `.maps` size `0x88` | 133 |
| `syscount.bpf.o` | `raw_tracepoint/sys_enter` size `0xf8`; `raw_tracepoint/sys_exit` size `0x3c8`; `.maps` size `0x60` | 134 |

Expected performance mechanism:

- Raw tracepoints avoid the formatted tracepoint context used by
  `tracepoint/raw_syscalls/*`.
- The BPF instruction count is slightly higher than phase2 attempt 1
  (`syscount` 134 vs 129 instruction lines), so the expected win must come from
  lower hook/context overhead, not from smaller BPF bytecode.

Observed performance:

- Correctness gate passed.
- `stress_ng_sum_bogo_ops_s` mean=724628, samples
  `727466, 720947, 725471`, +1.99% vs clean baseline.
- This beats phase2 attempt 1 by +0.89%, so the raw-tracepoint `syscount`
  rewrite is selected as the next stacked base.
