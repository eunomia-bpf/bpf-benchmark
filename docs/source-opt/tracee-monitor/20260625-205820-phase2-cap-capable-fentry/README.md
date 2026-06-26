# tracee/monitor source-opt attempt: phase2-cap-capable-fentry

- Time: 2026-06-25 20:58
- App: `tracee/monitor`
- Status: rejected-correctness
- Source file:
  - `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: convert the high-rate `cap_capable` probe from kprobe to fentry.
  The tracee workload includes the `cap` stressor, so reducing the hook
  mechanism cost on this path should have a larger effect than the first-round
  field-read micro changes.
- Expected hot path: `stress_ng_tracee_syscall_hot` runs `cap`, `set`,
  `sigfd`, `eventfd`, `kill`, `futex`, and `prctl`; `cap` should repeatedly
  enter Tracee's `trace_cap_capable` program.
- Intended correctness argument: fentry observes the same `cap_capable()` function entry
  and provides typed `cap` and `cap_opt` arguments. The program keeps the same
  event id, scope filtering, `CAP_OPT_NOAUDIT` guard, argument payload, and
  perf-event submit behavior.
- Build command: `make -C vendor tracee-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_040613_380312`
- Result: no performance sample; Tracee failed to load the modified BPF object.
- Failure reason: after conversion to fentry, the program still returned the
  `events_perf_submit()` helper result. The verifier rejected the tracing
  program because `R0` at exit was an unknown scalar instead of the required 0.
- Follow-up: rerun the same fentry direction with the submit result discarded
  and an explicit `return 0`.
