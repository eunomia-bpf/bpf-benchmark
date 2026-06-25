# tracee/monitor source-opt attempt: cache-sys-enter-compat

- Time: 2026-06-25 06:00:03
- App: `tracee/monitor`
- Status: accepted-for-analysis
- Source files: `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
- Hypothesis: `sys_enter_init()` can compute compat mode once and reuse it for
  both x86 syscall argument selection and syscall id translation, avoiding a
  duplicate task compat-state read on the x86 hot path.
- Expected hot path: raw syscall enter initialization.
- Correctness argument: on x86, `is_compat(task)` calls `is_x86_compat(task)`,
  so the cached value is identical to the previous argument-selection predicate.
  The preprocessor guard keeps non-x86 argument extraction on the previous
  generic path while still using `is_compat(task)` for syscall id translation.
  The patch does not change maps, event fields, attach points, or tail-call
  keys.
- Build command: covered by the documented single-app `make corpus` run.
- Run command: see `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_130746_945964`
- Result gate: suite `status=ok`; app `status=ok`; `error=""`; 3 workload
  samples all returned 0; `post_rejit=null`;
  `rejit_result.mode="skip_rejit_all"`.
- Follow-up: compare raw workload payload externally against the clean-source
  baseline.
