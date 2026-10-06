# bcc/set source-opt attempt: phase2-syscount-raw-tracepoint

- Time: 2026-06-25 19:46
- App: `bcc/set`
- Status: accepted-for-analysis; selected as the next stacked base
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
- Hypothesis: keep the positive `capable` fexit + `syscount` interrupt
  fast-return base and switch `syscount` from formatted syscall tracepoints to
  raw tracepoints. The workload is syscall-heavy and `syscount -L` attaches both
  enter and exit hooks, so reducing tracepoint dispatch/context overhead may
  improve throughput even if the BPF instruction count is slightly larger.
- Expected hot path: `stress_ng_bcc_hook_hot` runs `syscall`, `cap`, `set`, and
  `sockfd`; `syscount` observes every syscall enter/exit while latency mode is
  active.
- Correctness argument: `raw_tracepoint/sys_enter` provides the syscall id in
  `ctx->args[1]`, but `syscount` enter only needs the current tid and timestamp.
  `raw_tracepoint/sys_exit` provides `pt_regs *` in `ctx->args[0]` and return
  value in `ctx->args[1]`; on x86 the syscall id is read from `regs->orig_ax`,
  matching Tracee's existing raw syscall pattern. Map layouts and user-visible
  syscount output remain unchanged.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_025631_917158`
- Performance: `stress_ng_sum_bogo_ops_s` mean=724628, samples
  `727466, 720947, 725471`, +1.99% vs clean baseline and +0.89% vs phase2
  attempt 1.
- Follow-up: keep this raw-tracepoint `syscount` patch as the next stacked
  base. The next attempt should look for a larger `capable` event-path win, as
  `cap` remains the dominant stressor contribution.
