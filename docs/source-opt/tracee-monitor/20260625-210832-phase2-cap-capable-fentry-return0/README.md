# tracee/monitor source-opt attempt: phase2-cap-capable-fentry-return0

- Time: 2026-06-25 21:08
- App: `tracee/monitor`
- Status: planned
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
- Result path: TBD
- Follow-up: if this loads and improves throughput, keep fentry as the tracee
  phase2 base; otherwise pivot to reducing work in the hot event-submit path.
