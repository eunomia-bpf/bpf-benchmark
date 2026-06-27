# tetragon/observer source-opt summary

- App: `tetragon/observer`
- Status: phase3-complete
- Start date: 2026-06-25
- Source tree at start: `vendor/repos/tetragon` had no local diff.
- Baseline: `corpus/results/x86_kvm_corpus_20260625_163302_015551`

| Item | Status | Result | Notes |
| --- | --- | --- | --- |
| baseline | complete | `corpus/results/x86_kvm_corpus_20260625_163302_015551` | clean source, `SKIP_REJIT=all`; stress_ng_sum_bogo_ops_s mean=358681 |
| attempt 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_165241_915913` | sparse selector active clear; stress_ng_sum_bogo_ops_s mean=356619 (-0.57% vs baseline) |
| attempt 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_171339_967034` | filter_args active fastpath; stress_ng_sum_bogo_ops_s mean=355810 (-0.80% vs baseline) |
| attempt 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_173550_665242` | lazy namespace/capability selector state; stress_ng_sum_bogo_ops_s mean=387898 (+8.15% vs baseline) |
| attempt 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_175958_060141` | lazy ns/cap selector state plus conditional namespace for caps and sparse active clear; stress_ng_sum_bogo_ops_s mean=386271 (+7.69% vs baseline) |
| attempt 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260625_182312_224669` | attempt 3 plus skip empty namespace-section loop; stress_ng_sum_bogo_ops_s mean=389565 (+8.61% vs baseline, +0.43% vs attempt 3); current tetragon best |
| phase2 attempt 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_075102_935489` | first-round best plus tracepoint `nop_ty` arg fast path and conditional capability namespace load; stress_ng_sum_bogo_ops_s mean=391151 (+9.05% vs baseline, +0.41% vs first-round best); current tetragon phase2 best |
| phase2 attempt 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_081407_505208` | phase2 attempt 1 plus deferred selector-specific active clear; stress_ng_sum_bogo_ops_s mean=390959 (+9.00% vs baseline, -0.05% vs phase2 attempt 1); not selected as next base |
| phase2 attempt 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_083643_226335` | phase2 attempt 1 plus args-stage no-selector fast path before `filter_map` lookup; stress_ng_sum_bogo_ops_s mean=390359 (+8.83% vs baseline, -0.20% vs phase2 attempt 1); not selected as next base |
| phase2 attempt 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_085918_851913` | phase2 attempt 1 plus tracepoint-entry no-selector filter bypass; stress_ng_sum_bogo_ops_s mean=388975 (+8.45% vs baseline, -0.56% vs phase2 attempt 1); not selected as next base |
| phase2 attempt 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_092152_089522` | phase2 attempt 1 plus curr-only tracepoint no-selector bypass; stress_ng_sum_bogo_ops_s mean=391962 (+9.28% vs baseline, +0.21% vs phase2 attempt 1); selected as tetragon phase2 best but below 10% target |
| phase3 attempt 1 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_200430_726187` | phase2 best plus tracepoint no-selector sparse active clear; stress_ng_sum_bogo_ops_s mean=393050 (+9.58% vs baseline, +0.28% vs phase2 best); selected as current tetragon phase3 base but still below 10% target |
| phase3 attempt 2 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_202805_644441` | phase3 attempt 1 plus load-time no-selector `event_config.flags` bit to remove per-event `filter_map` lookup; stress_ng_sum_bogo_ops_s mean=400249 (+11.59% vs baseline, +1.83% vs phase3 attempt 1); selected as current tetragon phase3 base and reaches 10% target |
| phase3 attempt 3 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_205027_125596` | phase3 attempt 2 plus deferred `sel.pass=false` and duplicate `common.op` store removal; stress_ng_sum_bogo_ops_s mean=392557 (+9.44% vs baseline, -1.92% vs attempt 2); not selected for stacking |
| phase3 attempt 4 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_211133_416524` | phase3 attempt 2 plus no-selector fast-path/fallback state split; stress_ng_sum_bogo_ops_s mean=387226 (+7.96% vs baseline, -3.25% vs attempt 2); not selected for stacking |
| phase3 attempt 5 | accepted-for-analysis | `corpus/results/x86_kvm_corpus_20260626_213400_944958` | phase3 attempt 2 plus process-stage `event_config` pointer reuse in `generic_read_arg()`; stress_ng_sum_bogo_ops_s mean=398133 (+11.00% vs baseline, -0.53% vs attempt 2); not selected for stacking |

## Completion Gates

- [x] Clean-source baseline result recorded.
- [x] Five source-only attempts recorded.
- [x] Every accepted attempt has `source.diff`, command, result path, and correctness notes.
- [x] App source restored after every attempt.
- [x] Root `docs/source-opt/README.md` performance table updated through attempt 5.

## Phase2 Gates

- [x] Phase2 attempt 1 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase2 attempt 1.
- [x] Phase2 attempt 2 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase2 attempt 2.
- [x] Phase2 attempt 3 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase2 attempt 3.
- [x] Phase2 attempt 4 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase2 attempt 4.
- [x] Phase2 attempt 5 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase2 attempt 5.
- [x] Five phase2 attempts recorded.
- [x] Root `docs/source-opt/README.md` performance table updated through phase2 attempt 5.

## Phase3 Gates

- [x] Phase3 attempt 1 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase3 attempt 1.
- [x] Phase3 attempt 2 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase3 attempt 2.
- [x] Phase3 attempt 3 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase3 attempt 3.
- [x] Phase3 attempt 4 recorded with `source.diff`, command, result path, diagnostics, and correctness notes.
- [x] App source restored after phase3 attempt 4.
- [x] Phase3 attempt 5 recorded.
- [x] App source restored after phase3 attempt 5.
- [x] Five phase3 attempts recorded.
- [x] Root `docs/source-opt/README.md` performance table updated through phase3 attempt 5.
