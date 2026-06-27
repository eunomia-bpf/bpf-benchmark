# Diagnostics

Pre-run status:

- `vendor/repos/tracee` was clean after attempt 2 restore.
- Applied attempt 2 full `source.diff` as the base.
- `make -C vendor tracee-x86` passed after adding the hot syscall serializer.

Instruction / symbol-size observation:

- Attempt 2 base `sys_exit_submit`: `0x4fc8`.
- Candidate `sys_exit_submit`: `0x60a0`.
- `trace_cap_capable` stayed `0x3520`.
- `trace_security_task_prctl` stayed `0x12870`.

Decision rule:

- Stack only if the formal run improves over attempt 2 mean `464810`.
- If the result regresses, treat the code-size growth as the likely cause and
  pivot to a lower-code-size shared hot-path change.

Post-run observation:

- Formal samples were `458895, 456475, 457398`; mean=457589.
- The candidate regressed by 1.55% vs attempt 2, so the code-size risk
  materialized. Do not continue with large `sys_exit_submit` specialization for
  tracee unless a later diagnosis proves a narrower hot path.
