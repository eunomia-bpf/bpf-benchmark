# bcc/set source-opt attempt: phase3-syscount-default-filter-fastpath

- Time: 2026-06-26 07:05
- App: `bcc/set`
- Status: accepted-for-analysis; selected as current bcc/set phase3 base
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: stack the phase3 attempt 1 base and tune `syscount -L` for the
  runner's default no-filter mode without changing generic syscount behavior.
- Expected hot path: `stress_ng_bcc_hook_hot` is syscall-heavy, and `syscount`
  observes every syscall enter/exit while `-L` is enabled.
- Correctness argument: the patch only changes control-flow layout and a
  no-filter enter fast path. The same start/data maps, syscall keys, latency
  accounting, filters, and output records remain present.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_141358_076518`
- Performance: `stress_ng_sum_bogo_ops_s` mean=733113, samples
  `733995, 732654, 732689`; +3.19% vs clean baseline and +0.29% vs
  bcc/set phase3 attempt 1.
- Follow-up: stackable but still low leverage. Continue bcc/set attempts 3-5,
  with emphasis on `capable` event-path cost or syscall map-update cost.
