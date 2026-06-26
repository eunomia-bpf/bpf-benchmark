# Diagnostics

Patch shape:

- Stacks phase2 attempt 1: `capable` is one `fexit/cap_capable` program and
  `syscount` keeps the interrupt-id fast return before `bpf_get_current_pid_tgid()`.
- Adds `tcpconnect` fexit conversion: removes the `sockets` temporary hash map,
  removes `kprobe/tcp_{v4,v6}_connect`, and replaces
  `kretprobe/tcp_{v4,v6}_connect` with `fexit/tcp_{v4,v6}_connect`.

Build artifact checked:

- `vendor/build/.bcc-libbpf/x86/output/capable.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/syscount.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/tcpconnect.bpf.o`

Object diagnostics after build:

| Object | Program sections | Instruction lines |
| --- | --- | ---: |
| `capable.bpf.o` | `fexit/cap_capable` size `0x4c0`; `.maps` size `0x88` | 133 |
| `syscount.bpf.o` | `sys_enter` size `0xf8`; `sys_exit` size `0x3a0`; `.maps` size `0x60` | 129 |
| `tcpconnect.bpf.o` | `fexit/tcp_v4_connect` size `0x580`; `fexit/tcp_v6_connect` size `0x598`; `.maps` size `0x58` | 327 |

Expected performance mechanism:

- The old `tcpconnect` path stored `sk` in a hash map on function entry and
  looked it up/deleted it on return. The fexit rewrite avoids that map handoff.
- The patch keeps all tcpconnect output maps and event payloads unchanged.
  UID filtering is still supported, but `bpf_get_current_uid_gid()` is only
  called when `filter_uid` is configured.

Observed performance:

- Correctness gate passed.
- `stress_ng_sum_bogo_ops_s` mean=717722, samples
  `716964, 718507, 717694`, +1.02% vs clean baseline.
- This is slightly below phase2 attempt 1 (mean=718235, +1.09%), so the
  `tcpconnect` fexit rewrite is not selected as the next stacked base.
