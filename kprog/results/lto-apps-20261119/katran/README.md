# Katran in the main-configuration recipe (2026-11-19 19:00 UTC, source 1fd6c957a)

Run x86_kvm_corpus_20261119_190039_078110, recipe kprog/results/lto-apps-20261119/Makefile (APP=katran,
3 x 180 s per arm, stats on), started directly with flock and make. Image a0b2bbb7d (every app calls helpers by name).

- Coverage: 1 program; B generated, stock verifier rejected it (`math between fp pointer and register with
  unbounded min value`, B instruction 4145 `r2 -= r1`), so the program ran direct native (the 11-16 rule).
  This measures direct native for Katran. omp's verified run at 17:46 (verified-hot-20261117) passed stock with
  an earlier source; the rejection is the pointer-difference class perf is working on.
- Per call (ns/inv, eBPF -> native): 187.8 -> 173.3, 1.084x.
- Throughput: 1.039x (samples 1.217 / 1.042 / 1.018; the first eBPF sample is low), workload errors 27 937.
- Installed native 8 594 B against JIT 13 641 B (0.63x).

Raw: /workspaces/kprog-raw/coordinator/lto-katran-20261119T185858Z (service archive with the verifier log).
