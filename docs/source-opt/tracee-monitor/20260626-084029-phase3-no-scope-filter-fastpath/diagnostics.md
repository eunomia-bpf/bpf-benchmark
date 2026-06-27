# Diagnostics

Current base: tracee phase2 best,
`docs/source-opt/tracee-monitor/20260625-210832-phase2-cap-capable-fentry-return0/source.diff`.

Candidate change:

- Keep `trace_cap_capable` as `fentry/cap_capable` with explicit `return 0`.
- Add a no-scope-filter fast path in `evaluate_scope_filters()`.
- The guard ORs all scope/follow `*_filter_enabled` bitmaps. Only when the
  result is zero does it skip `match_scope_filters()`.

Object comparison against phase2 best base:

| Section | Base size | Candidate size | Base insn lines | Candidate insn lines | Notes |
| --- | ---: | ---: | ---: | ---: | --- |
| `raw_tracepoint/sys_enter_init` | `0x1218` | `0x1218` | 567 | 567 | unchanged |
| `raw_tracepoint/sys_enter_submit` | `0x7498` | `0x76f8` | 3687 | 3763 | no-filter guard inlined |
| `raw_tracepoint/sys_exit_init` | `0x0f10` | `0x0f10` | 471 | 471 | unchanged |
| `raw_tracepoint/sys_exit_submit` | `0x4fc8` | `0x51f0` | 2501 | 2570 | no-filter guard inlined |
| `fentry/cap_capable` | `0x3520` | `0x3638` | 1664 | 1699 | no-filter guard inlined |

Risk:

- The fast path increases code size because `evaluate_scope_filters()` is
  inlined into many event programs. It should only be kept if formal workload
  throughput improves enough to offset the extra instructions.

Formal result:

- Result path: `corpus/results/x86_kvm_corpus_20260626_155038_747634`
- Correctness: passed (`status=ok`, `error=""`, 3 workload return codes are
  0, `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`).
- Primary metric: `stress_ng_sum_bogo_ops_s` mean=`462517`, samples
  `461582, 464345, 461625`.
- Comparison: `+0.36%` vs clean baseline, `+0.03%` vs phase2 best.
- Decision: completed-not-stacked. The no-filter guard was correct but did not
  produce a meaningful throughput signal once inlining growth is included.
- Restore: `restore-build.log` and `restore-symbols.txt` record the clean-source
  artifact rebuilt after reversing this attempt's patch.
