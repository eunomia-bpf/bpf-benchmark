# tracee/monitor source-opt attempt: phase2-cap-fentry-early-noaudit

- Time: 2026-06-25 21:30
- App: `tracee/monitor`
- Status: rejected-no-signal
- Source file:
  - `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: stack the load-correct `cap_capable` fentry conversion with an
  earlier `CAP_OPT_NOAUDIT` drop, so no-audit capability checks return before
  Tracee's generic event setup and scope filtering.
- Expected hot path: `stress_ng_tracee_syscall_hot` repeatedly exercises the
  `cap` stressor. If many `cap_capable()` calls carry `CAP_OPT_NOAUDIT`, this
  avoids `init_program_data()` map lookups, event reset, and task context work
  for events that Tracee already suppresses.
- Correctness argument: the original program never submits a `CAP_CAPABLE`
  event when `cap_opt & CAP_OPT_NOAUDIT` is true. Moving that drop earlier
  preserves submitted-event semantics, event id, argument payload, scope
  filtering for submitted events, and perf-event ABI. The fentry program returns
  0 explicitly.
- Build command: `make -C vendor tracee-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_043813_884875`
- Performance: `stress_ng_sum_bogo_ops_s mean=453930`, samples
  `453680, 454459, 453651`, -1.50% vs clean baseline and -1.82% vs the
  corrected fentry-return0 attempt.
- Follow-up: do not keep this as a stacked base. The early `CAP_OPT_NOAUDIT`
  filter is functionally valid, but it likely has insufficient coverage in the
  measured workload or changes code layout unfavorably.
