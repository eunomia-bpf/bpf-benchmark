# Diagnostics

Pre-run status:

- `vendor/repos/tracee` was clean before applying the attempt patch.
- The phase2 best patch applied cleanly.
- `make -C vendor tracee-x86` passed after adding the prctl fentry conversion.
- `candidate-symbols.txt` shows `trace_cap_capable` in `fentry/cap_capable`
  and `trace_security_task_prctl` in `fentry/security_task_prctl`.

Expected risk:

- Compile success does not prove that Tracee can attach this fentry program on
  the benchmark kernel.  If the real app loader rejects the fentry attach, this
  attempt should be recorded as a correctness failure and not stacked.

Post-run observations:

- Real app loader accepted `fentry/security_task_prctl`; the app completed with
  `status=ok`.
- The attempt improved the tracee primary metric to mean `464810`, the best
  tracee result so far.
- Per-stressor output shows `prctl` contributes only about `350-374` bogo ops/s
  per sample.  The next tracee attempt should pivot to hotter contributors:
  `sigfd`, `futex`, and `cap`, or to shared raw syscall tracing overhead.
