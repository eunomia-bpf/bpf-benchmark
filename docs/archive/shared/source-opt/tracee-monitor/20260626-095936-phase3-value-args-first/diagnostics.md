# Diagnostics

Pre-run status:

- `vendor/repos/tracee` was clean after attempt 3 restore.
- Applied attempt 2 full `source.diff` as the base.
- `make -C vendor tracee-x86` passed after reordering value argument handling.

Instruction / symbol-size observation:

- Attempt 2 base `sys_exit_submit`: `0x4fc8`.
- Candidate `sys_exit_submit`: `0x5040` (`+0x78` bytes).
- `trace_cap_capable` stayed `0x3520`.
- `trace_security_task_prctl` stayed `0x12870`.

Decision rule:

- Stack only if the formal run improves over attempt 2 mean `464810`.
- If the result regresses or stays flat, treat this as another layout/noise
  result and pivot away from `save_args_to_submit_buf()` for tracee.

Post-run observation:

- Formal samples were `450246, 448766, 452111`; mean=450374.
- The candidate regressed by 3.11% vs attempt 2. Even a small value-arg branch
  reorder in `save_args_to_submit_buf()` can perturb `sys_exit_submit` enough
  to hurt the workload, so do not continue tracee phase3 with serializer
  layout-only changes.
