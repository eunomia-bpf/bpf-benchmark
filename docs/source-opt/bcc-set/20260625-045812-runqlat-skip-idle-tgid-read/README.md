# bcc/set source-opt attempt: runqlat-skip-idle-tgid-read

- Time: 2026-06-25 04:58:12
- App: `bcc/set`
- Status: accepted-for-analysis
- Source files: `vendor/repos/bcc/libbpf-tools/runqlat.bpf.c`
- Hypothesis: `runqlat` can skip reading `prev->tgid` when `prev->pid == 0`
  in the `sched_switch` path, because `trace_enqueue()` already returns
  immediately for pid 0 before using tgid.
- Expected hot path: `runqlat` `sched_switch` handler through
  `handle_switch()`.
- Correctness argument: the old path called `trace_enqueue(tgid, pid)` and
  `trace_enqueue()` returned before map updates when `pid == 0`. The new path
  performs the same early return in the caller for that case. For nonzero pid,
  it still calls `trace_enqueue()` with the same pid and lazily read tgid.
  Maps, histogram layout, filters, attach points, and output ABI are unchanged.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_120517_651286`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; three
  workload samples returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Follow-up: compare raw workload payload externally against the clean-source
  baseline.
