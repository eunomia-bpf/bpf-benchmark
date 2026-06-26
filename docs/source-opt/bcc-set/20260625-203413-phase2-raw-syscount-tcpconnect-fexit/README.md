# bcc/set source-opt attempt: phase2-raw-syscount-tcpconnect-fexit

- Time: 2026-06-25 20:34
- App: `bcc/set`
- Status: accepted-for-analysis; selected as bcc/set phase2 best
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: keep the best phase2 attempt 3 base (`capable` fexit plus
  raw-tracepoint `syscount`) and retest the independent `tcpconnect` fexit
  rewrite on top of it. The `tcpconnect` change removes the private `sockets`
  map used to hand off `struct sock *` from kprobe entry to kretprobe exit.
- Expected hot path: `stress_ng_bcc_hook_hot` is dominated by syscall and
  capability stressors, but it also includes `sockfd`, and bcc/set always keeps
  `tcpconnect` resident. If `sockfd` drives active connects in this environment,
  the fexit rewrite can reduce hook cost without changing user-visible output.
- Correctness argument: `tcpconnect` still handles IPv4 and IPv6 connects,
  failed-return filtering, pid/uid/port filters, count mode, and perf-event
  output. The removed `sockets` map was private temporary state only.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_034309_094312`
- Performance: `stress_ng_sum_bogo_ops_s` mean=729628, samples
  `729898, 726762, 732224`; +2.70% vs clean baseline and +0.69% vs
  phase2 attempt 3.
- Follow-up: this is the best bcc/set phase2 source-only result so far. The
  next app can start from a different hot path because bcc/set has completed
  its five phase2 attempts.
