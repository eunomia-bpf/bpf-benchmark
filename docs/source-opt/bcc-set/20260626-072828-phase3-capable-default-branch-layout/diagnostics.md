# Diagnostics

Current base: bcc/set phase3 attempt 2,
`docs/source-opt/bcc-set/20260626-070554-phase3-syscount-default-filter-fastpath/source.diff`.

Candidate change: keep the phase3 attempt 2 stacked base and add default-cold
branch layout hints to `capable.bpf.c`: cgroup filter, self pid, target pid,
unique mode, cgroup uniqueness, and stack collection are cold under the runner's
default `capable` invocation. The patch also moves `struct key_t i_key` into
the stack branch to shorten its lifetime.

Object comparison:

| Object | Base | Candidate | Notes |
| --- | --- | --- | --- |
| `capable.bpf.o` | fexit `0x4c0`, insn_lines=133 | fexit `0x4b0`, insn_lines=131 | slightly smaller default-layout program |
| `syscount.bpf.o` | phase3 attempt 2 base | unchanged | stacked base |
| `tcpconnect.bpf.o` | phase3 attempt 2 base | unchanged | stacked base |
| `runqlat.bpf.o` | unchanged | unchanged | not part of source.diff |

Formal result:

- Result: `corpus/results/x86_kvm_corpus_20260626_143534_405266`
- Metric: `stress_ng_sum_bogo_ops_s`
- Samples: `725965, 726577, 729010`
- Mean: `727184`
- Clean baseline mean: `710465`
- Phase3 attempt 2 mean: `733113`
- vs clean baseline: `+2.35%`
- vs phase3 attempt 2: `-0.81%`

Decision: completed-not-stacked. The patch passes correctness and shrinks the
object, but it regresses against the current bcc/set phase3 base.
