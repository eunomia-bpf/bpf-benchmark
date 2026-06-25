# tracee/monitor source-opt attempt: defer-sys-exit-ret-read

- Time: 2026-06-25 06:21:13
- App: `tracee/monitor`
- Status: accepted-for-analysis
- Source files: `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: `sys_exit_init()` can defer reading `ctx->args[1]` until after
  syscall id sanity checking, avoiding a return-value read on mismatch and
  early-return paths.
- Expected hot path: raw syscall exit initialization.
- Correctness argument: the return value is only used to assign `sys->ret`
  after `sys->id == id` is confirmed. Reading the same raw tracepoint argument
  at that assignment preserves the value while keeping the existing compat id
  translation, sanity check, tail-call targets, maps, and event ABI unchanged.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_132825_862375`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Follow-up: compare raw workload payload externally against the clean-source
  baseline.
