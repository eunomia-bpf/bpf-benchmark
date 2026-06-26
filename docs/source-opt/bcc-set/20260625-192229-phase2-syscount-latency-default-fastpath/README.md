# bcc/set source-opt attempt: phase2-tcpconnect-fexit-stack

- Time: 2026-06-25 19:22
- App: `bcc/set`
- Status: planned
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: keep the positive `capable` fexit + `syscount` early-return base
  and also convert `tcpconnect` from kprobe/kretprobe plus a temporary
  `sockets` map into direct `fexit/tcp_v4_connect` and
  `fexit/tcp_v6_connect` handlers. This should reduce overhead on socket
  connect churn by removing one map update, lookup, and delete per traced
  connect attempt.
- Expected hot path: `stress_ng_bcc_hook_hot` includes `sockfd`, and BCC set
  always starts `tcpconnect`; if the workload drives active TCP connects, the
  fexit rewrite should show up in workload throughput.
- Correctness argument: fexit receives the original `struct sock *sk` argument
  and function return value, so the return-side code can apply the same
  pid/uid/port/count/event rules without the temporary map. Failed connects
  still produce no event, matching the existing kretprobe path.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: TBD
- Follow-up: run the formal single-app corpus command and keep this stacked
  patch only if the app loads and throughput improves.
