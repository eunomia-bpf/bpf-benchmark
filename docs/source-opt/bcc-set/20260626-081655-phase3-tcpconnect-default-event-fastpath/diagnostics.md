# Diagnostics

Current base: bcc/set phase3 attempt 4,
`docs/source-opt/bcc-set/20260626-075220-phase3-syscount-key-width-cleanup/source.diff`.

Candidate change:

- Keep the task-storage `syscount` base.
- Add a default fast path in `tcpconnect` for `filter_pid == 0`,
  `filter_uid == -1`, `filter_ports_len == 0`, `source_port == false`, and
  `do_count == false`.
- The fast path returns immediately on failed connects, reads `dport`, and
  emits the same IPv4/IPv6 event payload as the generic event path.

Object comparison against phase3 attempt 4:

| Object | Base | Candidate | Notes |
| --- | --- | --- | --- |
| `tcpconnect.bpf.o` | v4 `0x568`, v6 `0x598`, insn_lines=324 | v4 `0x7b0`, v6 `0x6c8`, insn_lines=423 | larger due duplicated default event path |
| `syscount.bpf.o` | enter `0x178`, exit `0x3c8`, insn_lines=148 | same | stacked task-storage base |
| `capable.bpf.o` | fexit `0x4c0`, insn_lines=133 | same | stacked base |

Formal result:

- Result path: `corpus/results/x86_kvm_corpus_20260626_152354_967827`
- Correctness: passed (`status=ok`, `error=""`, 3 workload return codes are
  0, `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`).
- Primary metric: `stress_ng_sum_bogo_ops_s` mean=`789683`, samples
  `790657, 788288, 790104`.
- Comparison: `+11.15%` vs clean baseline, `+8.23%` vs phase2 best,
  `+7.72%` vs phase3 attempt 2, `-0.59%` vs phase3 attempt 4.
- Decision: completed-not-stacked. The duplicated default event path increased
  `tcpconnect` object size and did not improve the stacked attempt 4 base.
- Restore: `restore-build.log` and `restore-object.txt` record the clean-source
  artifact rebuilt after reversing this attempt's patch.
