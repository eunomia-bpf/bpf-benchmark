# tracee/monitor phase3 attempt: value args first

Status: completed-not-stacked

Base:

- Stacks `phase3/20260626-090841-phase3-prctl-fentry`.

Change:

- Reorder `save_args_to_submit_buf()` so value argument types set
  `arg = &args->args[i]` and jump to `save_arg` before testing
  `BITMASK_POINTER_TYPES`.
- Keep pointer/special handling unchanged for `STR_T`, `SOCKADDR_T`,
  `TIMESPEC_T`, and the default fallback path.

Rationale:

- Attempt 3 showed that per-syscall specialization expands `sys_exit_submit`
  too much and regresses throughput.
- The tracee workload is dominated by syscall events with integer/value
  arguments (`sigfd`, `futex`, `cap`, `eventfd`, `kill`). Handling value types
  first avoids the pointer-type branch for those common args without adding a
  syscall switch.

Risk:

- The compiler may turn the branch reorder into a neutral layout change, or
  the small code growth may still offset the saved branch.

Result:

- Formal run passed correctness with `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- `stress_ng_sum_bogo_ops_s` samples: `450246, 448766, 452111`; mean=450374.
- This is -2.28% vs the clean baseline mean 460865 and -3.11% vs the current
  tracee phase3 base mean 464810, so the patch is not selected for stacking.
- Although the code-size growth was small (`sys_exit_submit` `0x4fc8` to
  `0x5040`), the branch-layout change hurt all major stressors. Further tracee
  attempts should pivot away from `save_args_to_submit_buf()` layout tweaks.

Artifacts:

- `source.diff`: complete source patch for this attempt.
- `build.log`: tracee x86 rebuild log before the benchmark.
- `restore-build.log`: tracee x86 rebuild log after reversing the patch.
- `candidate-symbols.txt`: symbols from the optimized BPF object.
- `candidate-sections.txt`: section sizes from the optimized BPF object.
- `candidate-hotpath-objdump.txt`: disassembly for the touched hot sections.
- `run-command.sh`: exact formal benchmark command.
- `result-paths.txt`: formal result path.
- `correctness.md`: correctness gate and raw workload samples.
