# Diagnostics

Pre-run status:

- `vendor/repos/tracee` was clean after attempt 4 restore.
- Applied attempt 2 full `source.diff` as the base.
- `make -C vendor tracee-x86` passed after converting `commit_creds` to fentry.

Instruction / symbol-size observation:

- Attempt 2 base `sys_exit_submit`: `0x4fc8`.
- Candidate `sys_exit_submit`: `0x4fc8` unchanged.
- Attempt 2 base `trace_commit_creds`: `kprobe/commit_creds`, size `0x45f0`.
- Candidate `trace_commit_creds`: `fentry/commit_creds`, size `0x4648`
  (`+0x58` bytes).
- `trace_cap_capable` stayed `0x3520`.
- `trace_security_task_prctl` stayed `0x12870`.

Decision rule:

- Stack only if the formal run improves over attempt 2 mean `464810`.
- If the result is flat or lower, keep attempt 2 as the tracee phase3 base and
  stop this tracee phase3 batch at 5 attempts.

Post-run observation:

- Formal samples were `460381, 463013, 462406`; mean=461933.
- The candidate improved by 0.23% vs clean baseline, but regressed by 0.62% vs
  attempt 2. The narrow fentry conversion is correct but does not add useful
  throughput on top of the current tracee base.
