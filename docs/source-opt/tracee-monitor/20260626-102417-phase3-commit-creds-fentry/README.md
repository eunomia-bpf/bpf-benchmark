# tracee/monitor phase3 attempt: commit_creds fentry

Status: completed-not-stacked

Base:

- Stacks `phase3/20260626-090841-phase3-prctl-fentry`.

Change:

- Convert `trace_commit_creds` from `kprobe/commit_creds` to typed
  `fentry/commit_creds`.
- Use the typed `struct cred *new_cred` argument directly instead of reading
  `PT_REGS_PARM1(ctx)`.
- Keep event id, scope filters, credential snapshot logic, payload layout, and
  submit path unchanged.

Rationale:

- Attempts 3 and 4 showed that changing the shared syscall argument serializer
  hurts the dominant `sys_exit_submit` hot path.
- This attempt tests a narrower hook-entry optimization, similar to the
  successful `cap_capable` and `security_task_prctl` fentry conversions, while
  avoiding serializer layout changes.

Risk:

- `commit_creds` may be too small a workload contributor for the saved argument
  load to offset fentry attach and code-layout changes.
- The symbol grew slightly, so the net instruction-cache effect may be neutral
  or negative.

Result:

- Formal run passed correctness with `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- `stress_ng_sum_bogo_ops_s` samples: `460381, 463013, 462406`; mean=461933.
- This is +0.23% vs the clean baseline mean 460865, but -0.62% vs the current
  tracee phase3 base mean 464810, so the patch is not selected for stacking.
- The result confirms that narrow fentry conversion is functionally safe here,
  but `commit_creds` is not hot enough in this workload to improve the current
  stacked tracee base.

Artifacts:

- `source.diff`: complete source patch for this attempt.
- `build.log`: tracee x86 rebuild log before the benchmark.
- `restore-build.log`: tracee x86 rebuild log after reversing the patch.
- `candidate-symbols.txt`: symbols from the optimized BPF object.
- `trace_commit_creds.objdump.txt`: disassembly for the touched BPF program.
- `run-command.sh`: exact formal benchmark command.
- `result-paths.txt`: formal result path.
- `correctness.md`: correctness gate and raw workload samples.
