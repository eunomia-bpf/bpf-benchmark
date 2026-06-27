# Diagnostics

Current base: bcc/set phase3 attempt 2,
`docs/source-opt/bcc-set/20260626-070554-phase3-syscount-default-filter-fastpath/source.diff`.

Candidate change:

- Keep the stacked `capable` fexit, `tcpconnect` fexit, and raw-tracepoint
  `syscount` base.
- Change `syscount`'s private `start` map from `BPF_MAP_TYPE_HASH` keyed by tid
  to `BPF_MAP_TYPE_TASK_STORAGE`.
- Store the enter timestamp in task local storage and read it back on exit.

Object comparison against phase3 attempt 2:

| Object | Base | Candidate | Notes |
| --- | --- | --- | --- |
| `syscount.bpf.o` | enter `0x138`, exit `0x3c0`, insn_lines=140 | enter `0x178`, exit `0x3c8`, insn_lines=148 | larger code, different helper/map cost |
| `capable.bpf.o` | fexit `0x4c0`, insn_lines=133 | same | stacked base |
| `tcpconnect.bpf.o` | v4 `0x568`, v6 `0x598`, insn_lines=324 | same | stacked base |

Formal result:

- Result: `corpus/results/x86_kvm_corpus_20260626_150154_266900`
- Metric: `stress_ng_sum_bogo_ops_s`
- Samples: `794399, 794426, 794353`
- Mean: `794393`
- Clean baseline mean: `710465`
- Phase2 best mean: `729628`
- Phase3 attempt 2 mean: `733113`
- vs clean baseline: `+11.81%`
- vs phase2 best: `+8.88%`
- vs phase3 attempt 2: `+8.36%`

Decision: accepted-for-analysis and selected as the current bcc/set phase3
base. Although the BPF instruction count is larger, replacing the per-syscall
timestamp hash with task local storage is a higher-leverage runtime mechanism
for `syscount -L`.
