# Diagnostics

Patch shape:

- Stacks phase2 attempt 3: `capable` is one `fexit/cap_capable` program and
  `syscount` uses `raw_tracepoint/sys_enter` plus `raw_tracepoint/sys_exit`.
- Adds `tcpconnect` fexit conversion: removes the `sockets` temporary hash map,
  removes the `kprobe/tcp_{v4,v6}_connect` entry programs, and replaces
  `kretprobe/tcp_{v4,v6}_connect` with `fexit/tcp_{v4,v6}_connect`.

Diffstat:

```text
libbpf-tools/capable.bpf.c    | 54 +++++++------------------------
libbpf-tools/syscount.bpf.c   | 38 +++++++++++++++-------
libbpf-tools/tcpconnect.bpf.c | 75 +++++++++++--------------------------------
3 files changed, 56 insertions(+), 111 deletions(-)
```

Build artifact checked:

- `vendor/build/.bcc-libbpf/x86/output/capable.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/syscount.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/tcpconnect.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/tcpconnect.skel.h`

Object diagnostics after build:

| Object | Program sections / symbols | Size or instruction lines |
| --- | --- | ---: |
| `capable.bpf.o` | `fexit/cap_capable` size `0x4c0`; `.maps` size `0x88` | 133 insns |
| `syscount.bpf.o` | `raw_tracepoint/sys_enter` size `0xf8`; `raw_tracepoint/sys_exit` size `0x3c8` | 134 insns |
| `tcpconnect.bpf.o` | `fexit/tcp_v4_connect` size `0x580`; `fexit/tcp_v6_connect` size `0x598`; `.maps` size `0x58` | 327 insns |

Expected performance mechanism:

- The old `tcpconnect` path stored `sk` in a hash map on function entry and
  looked it up/deleted it on return.
- The fexit rewrite receives the original `struct sock *sk` and return value in
  one program invocation, avoiding the private map handoff.
- This is a broader tool-level rewrite than the previous latency-only
  `syscount` specialization, but it can only help bcc/set if `sockfd` drives
  enough `tcpconnect` work during the formal workload.

Observed performance:

- Formal result:
  `corpus/results/x86_kvm_corpus_20260626_034309_094312/details/apps/bcc__set.json`
- `stress_ng_sum_bogo_ops_s` samples: `729898, 726762, 732224`
- Mean: `729628`
- Relative to clean baseline mean `710465`: `+2.70%`
- Relative to phase2 attempt 3 mean `724628`: `+0.69%`
- Interpretation: unlike the earlier attempt 2, the `tcpconnect` fexit rewrite
  composes positively with the raw-tracepoint `syscount` base. The improvement
  is still far below the 10% single-app target, but it is the best bcc/set
  stacked result after five phase2 attempts.
