# tracee/monitor phase3 attempt: hot syscall arg serializer

Status: completed-not-stacked

Base:

- Stacks `phase3/20260626-090841-phase3-prctl-fentry`.

Change:

- Add missing eBPF syscall id macros for workload-relevant x86 and arm64
  syscalls.
- Add a hot syscall fast path in `save_args_to_submit_buf()` for `setuid`,
  `setgid`, `kill`, `tkill`, `tgkill`, `eventfd`, `eventfd2`, `signalfd`,
  `signalfd4`, and `futex`.
- Keep argument indexes, encoded sizes, pointer-vs-value behavior, and return
  value handling unchanged. Non-hot events still use the original generic loop.

Rationale:

- Attempt 2 showed `prctl` is a tiny contributor. The dominant stressors are
  `sigfd`, `futex`, `cap`, `eventfd`, and `kill`.
- These syscall events currently pay the generic argument serializer cost:
  decode field type, lookup `type_size_table`, compute masks, branch through
  type handling, then save. For known hot syscall layouts we can directly emit
  the same `save_to_submit_buf()` calls.

Risk:

- `sys_exit_submit` code size grows from `0x4fc8` in the attempt 2 base to
  `0x60a0` in this candidate. If I-cache/verifier layout dominates, this may
  regress despite removing dynamic type dispatch on hot syscalls.

Result:

- Formal run passed correctness with `post_rejit=null` and
  `rejit_result.mode="skip_rejit_all"`.
- `stress_ng_sum_bogo_ops_s` samples: `458895, 456475, 457398`; mean=457589.
- This is -0.71% vs the clean baseline mean 460865 and -1.55% vs the current
  tracee phase3 base mean 464810, so the patch is not selected for stacking.
- Likely cause: the direct hot syscall serializer removed dynamic dispatch for
  selected events, but expanded `sys_exit_submit` enough to hurt instruction
  cache/layout more than it helped.

Artifacts:

- `source.diff`: complete source patch for this attempt.
- `build.log`: tracee x86 rebuild log before the benchmark.
- `restore-build.log`: tracee x86 rebuild log after reversing the patch.
- `candidate-symbols.txt`: symbols from the optimized BPF object.
- `candidate-hotpath-objdump.txt`: disassembly for the touched hot sections.
- `run-command.sh`: exact formal benchmark command.
- `result-paths.txt`: formal result path.
- `correctness.md`: correctness gate and raw workload samples.
