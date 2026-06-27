# bcc/set source-opt attempt: phase3-tcpconnect-default-event-fastpath

- Time: 2026-06-26 08:16
- App: `bcc/set`
- Status: completed-not-stacked
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: stack the phase3 attempt 4 task-storage `syscount` base and add
  a default-event fast path to `tcpconnect` for the runner's no-filter,
  no-count, no-source-port mode.
- Expected hot path: `stress_ng_bcc_hook_hot` includes `sockfd`; if it drives
  enough successful TCP connects, skipping default-cold option branches may
  improve throughput.
- Correctness argument: the generic path remains for pid/uid/port/source-port
  filtering and count mode. The default path emits the same event payload as
  the existing no-filter event path.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_152354_967827`
- Primary metric: `stress_ng_sum_bogo_ops_s` mean=`789683`, samples
  `790657, 788288, 790104`; `+11.15%` vs clean baseline but `-0.59%` vs
  phase3 attempt 4.
- Decision: correctness passed, but do not stack this attempt because it
  regressed against the current bcc/set best. Keep phase3 attempt 4
  (`syscount` task storage) as the selected source-opt base.
- Restore: reversed `source.diff`, rebuilt with `make -C vendor bcc-x86`, and
  verified `vendor/repos/bcc` source diff/status are empty.
