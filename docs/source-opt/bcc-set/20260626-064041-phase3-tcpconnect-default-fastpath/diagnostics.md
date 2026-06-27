# Diagnostics

Current base: bcc/set phase2 best,
`docs/source-opt/bcc-set/20260625-203413-phase2-raw-syscount-tcpconnect-fexit/source.diff`.

Candidate change: keep the phase2 stacked base and add `__builtin_expect(..., 0)`
to default-cold `tcpconnect` branches inside `exit_tcp_connect()`: pid filter,
failed-connect return, uid filter, source-port read, destination-port filter,
and count mode.

Object comparison:

| Object | Base | Candidate | Notes |
| --- | --- | --- | --- |
| `capable.bpf.o` | `fexit/cap_capable` size `0x4c0`, insn_lines=144 | same | unchanged phase2 base |
| `syscount.bpf.o` | raw enter `0xf8`, raw exit `0x3c8`, insn_lines=151 | same | unchanged phase2 base |
| `tcpconnect.bpf.o` | v4 `0x580`, v6 `0x598`, insn_lines=349 | v4 `0x568`, v6 `0x598`, insn_lines=347 | candidate slightly shrinks the default path |
| `runqlat.bpf.o` | insn_lines=426 | same | unchanged |

An earlier duplicated default-fast-path variant was rejected before formal run
because it grew `tcpconnect` to 508 instruction lines and expanded both fexit
sections. The formal candidate keeps the same attach points and semantics while
nudging clang's branch layout for the benchmark default configuration.

Formal result:

- Result: `corpus/results/x86_kvm_corpus_20260626_135003_717963`
- Metric: `stress_ng_sum_bogo_ops_s`
- Samples: `730828, 727856, 734246`
- Mean: `730977`
- Clean baseline mean: `710465`
- Phase2 best mean: `729628`
- vs clean baseline: `+2.89%`
- vs phase2 best: `+0.18%`

Decision: accepted-for-analysis and stackable as the current bcc/set phase3
base because it passes correctness and is a small positive delta over phase2
best. The gain is tiny, so the next bcc/set attempts should move away from
tcpconnect branch hints and inspect higher-leverage `capable` and `syscount`
hot-path costs.
