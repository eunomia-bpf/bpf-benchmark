# bcc/set source-opt attempt: phase3-tcpconnect-default-fastpath

- Time: 2026-06-26 06:40
- App: `bcc/set`
- Status: accepted-for-analysis; selected as current bcc/set phase3 base
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: keep the phase2 best base (`capable` fexit, raw-tracepoint
  `syscount`, `tcpconnect` fexit) and improve the default `tcpconnect` layout
  by marking rarely enabled filter/count branches as unlikely.
- Expected hot path: `stress_ng_bcc_hook_hot` runs the default `tcpconnect`
  command with no pid/uid/port filters and no count mode. The hot path is
  successful connect tracing, so filter/count branches should stay cold.
- Correctness argument: the patch only adds branch prediction hints to existing
  conditions. All filter, count, source-port, IPv4, IPv6, and event output paths
  remain intact.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_135003_717963`
- Performance: `stress_ng_sum_bogo_ops_s` mean=730977, samples
  `730828, 727856, 734246`; +2.89% vs clean baseline and +0.18% vs
  bcc/set phase2 best.
- Follow-up: stackable but low leverage. Next attempts should target
  higher-throughput bcc hooks (`capable`, `syscount`) rather than more
  `tcpconnect` branch-hint tuning.
