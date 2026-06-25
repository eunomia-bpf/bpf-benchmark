# bcc/set source-opt attempt: syscount-interrupt-fast-return

- Time: 2026-06-25 04:37:50
- App: `bcc/set`
- Status: accepted-for-analysis
- Source files: `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
- Hypothesis: `syscount` can handle the `args->id == -1` interrupt case before
  calling `bpf_get_current_pid_tgid()`, avoiding a helper call on a path that
  already returns immediately.
- Expected hot path: `sys_exit` tracepoint handler.
- Correctness argument: the same `args->id == -1` case returns 0 before any map
  update or event-visible state change in both versions. Moving the guard
  earlier only avoids computing pid/tgid for a path that does not use it. Maps,
  counters, filters, and attach points are unchanged.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_114437_519205`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; three
  workload samples returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Follow-up: compare raw workload payload externally against the clean-source
  baseline.
