# tetragon/observer source-opt summary

- App: `tetragon/observer`
- Status: phase2-in-progress
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
- [x] Root `docs/source-opt/README.md` performance table updated through phase2 attempt 2.
- [ ] Five phase2 attempts recorded.
- [ ] Root `docs/source-opt/README.md` performance table updated through phase2 attempt 5.
