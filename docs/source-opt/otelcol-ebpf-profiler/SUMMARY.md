# otelcol-ebpf-profiler/profiling source-opt summary

- App: `otelcol-ebpf-profiler/profiling`
- Source root: `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/`
- Workload: `otel_mixed_workload`
- Status: phase2-complete

## Baseline

| Run | Result | Primary metric | Samples |
| --- | --- | ---: | --- |
| baseline | `corpus/results/x86_kvm_corpus_20260625_184535_486633` | language_ops_total mean=19644780415 | `19476891866, 19704797451, 19752651928` |

## Attempts

| Attempt | Status | Result | Primary metric | vs baseline | Notes |
| --- | --- | --- | ---: | ---: | --- |
| pre-1 | rejected-correctness | `corpus/results/x86_kvm_corpus_20260625_190706_743922` | language_ops_total mean=19631015807; samples `19482699802, 19832870505, 19577477114` | -0.07% | provenance fail: edited source was not proven to regenerate/load embedded eBPF artifact |
| 1 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260625_192715_058308` | language_ops_total mean=19644068683; samples `19898566747, 19709048452, 19324590849` | -0.00% | valid rebuild/load path, flat throughput; do not stack |
| 2 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260625_194845_959410` | language_ops_total mean=19358366012; samples `19402588695, 19278089079, 19394420261` | -1.46% | correctness passed, but repeated per-CPU lookup removal slowed this workload; do not stack |
| 3 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260625_201102_658698` | language_ops_total mean=19634728466; samples `19889012769, 19180704492, 19834468137` | -0.05% | correctness passed, but direct `send_trace()` size calculation was flat/slightly lower; do not stack |
| 4 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260625_203203_222972` | language_ops_total mean=19611239252; samples `19226116826, 20279757143, 19327843786` | -0.17% | correctness passed, but larger native unwinder body did not improve throughput; do not stack |
| 5 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260625_205249_386525` | language_ops_total mean=19480337627; samples `19345351817, 19739934685, 19355726380` | -0.84% | correctness passed, but lazy custom-label clearing regressed throughput; do not stack |

## Phase 2 Attempts

| Attempt | Status | Result | Primary metric | vs baseline | Notes |
| --- | --- | --- | ---: | ---: | --- |
| phase2-1 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_095211_287090` | language_ops_total mean=19481366793; samples `19676128056, 19509969254, 19258003069` | -0.83% | deferring `comm`/kernel stack helper work on the unmapped-PID path reduced `native_tracer_entry` instructions but did not improve workload throughput; do not stack |
| phase2-2 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_101543_422474` | language_ops_total mean=19582008878; samples `19879363031, 19331939856, 19534723746` | -0.32% | early drop of empty-stack error-only traces preserved correctness but did not improve throughput; do not stack |
| phase2-3 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_103605_569628` | language_ops_total mean=19526940261; samples `19705666680, 19244754469, 19630399634` | -0.60% | raising `NATIVE_FRAMES_PER_PROGRAM` to 8 doubled `unwind_native` body and reduced tail-call recursion, but did not improve throughput; do not stack |
| phase2-4 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_110000_678727` | language_ops_total mean=19575112832; samples `19658284979, 19486494323, 19580559194` | -0.35% | single-delta stack page lookup reuse kept instruction growth small but did not improve throughput; do not stack |
| phase2-5 | rejected-no-signal | `corpus/results/x86_kvm_corpus_20260626_112227_995529` | language_ops_total mean=19508075671; samples `19462147885, 19814623616, 19247455513` | -0.70% | batching PHP successful-frame metric updates cut `unwind_php` from 6899 to 3358 instructions but did not improve workload throughput; do not stack |

## Notes

- Use `SKIP_REJIT=all`; `post_rejit` must stay `null`.
- Tail-called profiler programs may report `run_cnt=0`; performance is tracked through raw app-side workload throughput.
- Attempts may stack on the best previous source patch when the earlier result improves throughput and keeps the correctness gate passing.
- Baseline gate passed: app `status=ok`, `error=""`, three composite workload samples, all 33 components returned 0, `post_rejit=null`, `rejit_result.mode=skip_rejit_all`.
- For otel, a source edit under `support/ebpf/` must be followed by an explicit eBPF artifact rebuild before the formal `make corpus` run, otherwise the collector may reuse the previous embedded `tracer.ebpf.amd64`.
- Phase2 completed with no positive OTEL throughput signal; keep the clean source as the next base.
