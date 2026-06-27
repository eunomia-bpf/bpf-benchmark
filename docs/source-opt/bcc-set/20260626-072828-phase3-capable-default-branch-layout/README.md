# bcc/set source-opt attempt: phase3-capable-default-branch-layout

- Time: 2026-06-26 07:28
- App: `bcc/set`
- Status: completed-not-stacked
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: stack the phase3 attempt 2 base and improve `capable`'s default
  event path by marking non-default filter/unique/stack branches as cold.
- Expected hot path: the runner starts `capable` with no cgroup, pid, unique,
  or stack arguments, so most executions should build the event and perf-output
  it directly.
- Correctness argument: all branches and output fields remain present; the
  patch only changes branch layout hints and narrows the lifetime of a stack
  key object used only by stack collection.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_143534_405266`
- Performance: `stress_ng_sum_bogo_ops_s` mean=727184, samples
  `725965, 726577, 729010`; +2.35% vs clean baseline but -0.81% vs
  bcc/set phase3 attempt 2.
- Follow-up: do not stack. Avoid further pure branch hints in `capable`; the
  next attempts should target a different mechanism.
