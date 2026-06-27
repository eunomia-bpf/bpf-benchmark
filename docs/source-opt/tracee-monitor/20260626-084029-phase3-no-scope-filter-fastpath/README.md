# tracee/monitor source-opt attempt: phase3-no-scope-filter-fastpath

- Time: 2026-06-26 08:40
- App: `tracee/monitor`
- Status: completed-not-stacked
- Source files:
  - `vendor/repos/tracee/pkg/ebpf/c/tracee.bpf.c`
  - `vendor/repos/tracee/pkg/ebpf/c/common/filtering.h`
- Hypothesis: stack the phase2 best `cap_capable` fentry rewrite and add a
  general no-scope-filter fast path to `evaluate_scope_filters()`.
- Expected hot path: the tracee workload runs all-events mode without explicit
  scope filters, so frequent syscall/LSM events should avoid the full scope
  matcher when every filter-enabled bitmap is zero.
- Correctness argument: the fast path is guarded by real `policies_config`
  fields. If any scope/follow filter is enabled, it falls back to the original
  matcher. The no-filter path preserves the tracee-self exclusion and
  `enabled_policies` masking.
- Build command: `make -C vendor tracee-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_155038_747634`
- Primary metric: `stress_ng_sum_bogo_ops_s` mean=`462517`, samples
  `461582, 464345, 461625`; `+0.36%` vs clean baseline and `+0.03%` vs
  phase2 best.
- Decision: correctness passed, but do not stack this attempt. The measured
  gain over phase2 best is effectively flat while the object grew due
  `evaluate_scope_filters()` inlining.
- Restore: reversed `source.diff`, rebuilt with `make -C vendor tracee-x86`,
  and verified `vendor/repos/tracee` source diff/status are empty.
