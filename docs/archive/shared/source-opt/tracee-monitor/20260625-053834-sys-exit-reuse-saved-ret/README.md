# tracee/monitor source-opt attempt: sys-exit-reuse-saved-ret

- Time: 2026-06-25 05:38:34
- App: `tracee/monitor`
- Status: accepted-for-analysis
- Source files: `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: `sys_exit_submit()` can reuse `sys->ret`, which was written by
  `sys_exit_init()` immediately before the tail call, instead of reading the
  raw tracepoint return value from `ctx->args[1]` a second time.
- Expected hot path: syscall exit submit tail call.
- Correctness argument: `sys_exit_submit()` is reached through the
  `sys_exit_init()` tail call after syscall id sanity checking and
  `sys->ret = ctx->args[1]`. Reusing `sys->ret` preserves the submitted return
  value and does not change maps, event field ordering, attach points, or
  tail-call keys.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_124558_225233`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Follow-up: compare raw workload payload externally against the clean-source
  baseline.
