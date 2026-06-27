# tracee/monitor phase3 attempt: prctl fentry

Status: accepted-for-analysis; selected as current tracee phase3 base

Base:

- Stacks `phase2/20260625-210832-cap-capable-fentry-return0`.

Change:

- Convert `trace_security_task_prctl` from `kprobe/security_task_prctl` with
  `PT_REGS_PARM*()` reads to `fentry/security_task_prctl` with typed arguments.
- Keep the same event id, filter path, argument payload order, PR_SET_VMA /
  PR_SET_MM / PR_SET_SECUREBITS handling, and return 0 after
  `events_perf_submit(&p)`.

Rationale:

- The tracee workload includes a hot `prctl` stressor.  Previous small
  syscall-path edits mostly measured noise.  This attempt changes the attach
  and argument-read mechanism for a workload-relevant probe while preserving
  app-visible event semantics.

Artifacts:

- `source.diff`: complete source patch for this attempt.
- `build.log`: tracee x86 rebuild log before the benchmark.
- `candidate-symbols.txt`: symbols from the optimized BPF object.
- `candidate-hotpath-objdump.txt`: disassembly for the touched fentry sections.
- `run-command.sh`: exact formal benchmark command.
- `run.log`: formal benchmark log.
- `restore-build.log`: clean-source tracee rebuild log after reversing the patch.

Result:

- Result path: `corpus/results/x86_kvm_corpus_20260626_161621_526914`
- Correctness gate: passed. App `status=ok`, `error=""`, 3 workload samples
  returned 0, `post_rejit=null`, and `rejit_result.mode="skip_rejit_all"`.
- Primary metric: `stress_ng_sum_bogo_ops_s mean=464810`, samples
  `462950, 465355, 466125`.
- Docs-side comparison: `+0.86%` vs clean baseline mean `460865`, `+0.53%`
  vs phase2 best mean `462359`.

Decision:

- Stack for the next tracee attempt because this is the best tracee result so
  far and passed the real loader/workload gate.
- Do not keep optimizing prctl specifically: per-stressor output shows prctl is
  only about `350-374` bogo ops/s of the total, while `sigfd`, `futex`, and
  `cap` dominate this workload.
