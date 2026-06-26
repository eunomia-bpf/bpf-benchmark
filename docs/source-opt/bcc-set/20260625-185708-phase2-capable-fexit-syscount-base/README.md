# bcc/set source-opt attempt: phase2-capable-fexit-syscount-base

- Time: 2026-06-25 18:57
- App: `bcc/set`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
- Hypothesis: keep the first-round positive `syscount` interrupt fast return and
  replace `capable`'s kprobe+kretprobe temporary map handoff with one
  `fexit/cap_capable` program. This preserves the same app-visible event
  payload and filters while removing per-call `start` map update, lookup, and
  delete work.
- Expected hot path: `bcc/set` runs multiple libbpf-tools under stress-ng.
  `capable` can fire on frequent capability checks; avoiding the entry probe
  and temporary map handoff should reduce BPF-side overhead without changing
  workload behavior.
- Correctness argument: `fexit/cap_capable` receives the original
  `cap_capable()` arguments and return value at function exit, so it can build
  the same `cap_event` fields that the old entry/return pair produced. The
  patch keeps the cgroup, pid, unique, kernel/user stack, and perf event paths.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_020646_300498`
- Performance: `stress_ng_sum_bogo_ops_s` mean `718235`, samples
  `719939, 713743, 721022`; `+1.09%` vs clean-source baseline `710465`.
- Follow-up: keep this as the current `bcc/set` stacked base candidate because
  it is correctness-clean and improves on both clean baseline and the
  first-round `syscount`-only result.
