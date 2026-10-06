# tracee/monitor source-opt attempt: phase2-cap-capable-fentry-return0

- Time: 2026-06-25 21:08
- App: `tracee/monitor`
- Status: accepted-for-analysis
- Source file:
  - `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: keep the `cap_capable` fentry conversion from the previous
  attempt, but satisfy tracing verifier return-value rules by discarding the
  `events_perf_submit()` helper result and returning 0.
- Expected hot path: `stress_ng_tracee_syscall_hot` includes the `cap` stressor,
  so `trace_cap_capable` should be exercised repeatedly.
- Correctness argument: event id, scope filtering, `CAP_OPT_NOAUDIT` filtering,
  argument payload, and perf-event submission are unchanged. The only semantic
  adjustment is that the tracing program returns 0 after submit, which matches
  fentry program requirements; the original kprobe return value was not part of
  Tracee's app-visible event ABI.
- Build command: `make -C vendor tracee-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_041555_482043`
- Result: `stress_ng_sum_bogo_ops_s mean=462359`, samples
  `466968, 460401, 459707`, +0.32% vs clean-source tracee baseline
  `460865`.
- Follow-up: this proves the fentry direction is load-correct and slightly
  positive, but the gain is too small for the 10% target. Next attempt should
  pivot to reducing work in the hot event-submit path.
