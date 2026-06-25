# tetragon/observer baseline

- Source state: clean `vendor/repos/tetragon` source tree.
- Mode: `SKIP_REJIT=all`; expected `post_rejit=null` and `rejit_result.mode="skip_rejit_all"`.
- Workload: `stress_ng_tetragon_policy_hot`.
- Result path: `corpus/results/x86_kvm_corpus_20260625_163302_015551`.
- Correctness gate: suite `status=ok`; app `status=ok`; app `error=""`; workload returncodes `0,0,0`; `post_rejit=null`; `rejit_result.mode="skip_rejit_all"`.
- Performance: stress-ng real-time bogo ops/s sample sums `362190, 355981, 357871`; mean `358681`.
