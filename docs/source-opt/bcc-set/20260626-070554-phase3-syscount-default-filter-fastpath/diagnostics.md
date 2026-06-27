# Diagnostics

Current base: bcc/set phase3 attempt 1,
`docs/source-opt/bcc-set/20260626-064041-phase3-tcpconnect-default-fastpath/source.diff`.

Candidate change: keep the phase3 attempt 1 stacked base and tune
`syscount.bpf.c` for the default runner configuration (`syscount -L -i 1`).
The final candidate:

- Adds a small no-cgroup/no-pid fast path in `raw_tracepoint/sys_enter` to avoid
  computing the pid half of `bpf_get_current_pid_tgid()` when no pid filter is
  configured.
- Adds branch layout hints to `raw_tracepoint/sys_exit`: cgroup, interrupt,
  pid, failure, errno, and process grouping are cold; latency accounting is hot.
- Does not duplicate the data-map update path. An earlier variant duplicated
  the default latency exit path and grew `sys_exit` to `0x5a0`; it was rejected
  before formal run.

Object comparison:

| Object | Base | Candidate | Notes |
| --- | --- | --- | --- |
| `syscount.bpf.o` | enter `0xf8`, exit `0x3c8`, insn_lines=151 | enter `0x138`, exit `0x3c0`, insn_lines=140 | enter grows for the no-filter fast path; exit stays close to base |
| `capable.bpf.o` | phase3 attempt 1 base | unchanged | stacked base |
| `tcpconnect.bpf.o` | phase3 attempt 1 base | unchanged | stacked base |
| `runqlat.bpf.o` | unchanged | unchanged | not part of source.diff |

Formal result:

- Result: `corpus/results/x86_kvm_corpus_20260626_141358_076518`
- Metric: `stress_ng_sum_bogo_ops_s`
- Samples: `733995, 732654, 732689`
- Mean: `733113`
- Clean baseline mean: `710465`
- Phase2 best mean: `729628`
- Phase3 attempt 1 mean: `730977`
- vs clean baseline: `+3.19%`
- vs phase2 best: `+0.48%`
- vs phase3 attempt 1: `+0.29%`

Decision: accepted-for-analysis and stackable as the current bcc/set phase3
base. The gain is still small; next attempts should look for a larger
`capable` event-path reduction or a way to reduce syscall map-update cost
without changing output semantics.
