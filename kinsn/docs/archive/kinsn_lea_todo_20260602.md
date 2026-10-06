# kinsn LEA TODO, 2026-06-02

This is a local follow-up checklist for the x86 KVM LEA policy work. It is a
planning note only; benchmark framework code must continue to record raw data
only.

- [x] Enable x86 LEA in the bpfopt policy path.
- [x] Remove the wrapper-side LLVM kinsn selector/profitability gate.
- [x] Preserve workload methodology: use `make corpus`, keep
  `WORKLOAD_DURATION=30`, and change only pass/app selection knobs.
- [x] Add exact-hash no-op policy entries for load/runtime-unsafe Tracee LEA
  variants while leaving other Tracee LEA programs enabled.
- [x] Run x86 KVM LEA smoke for OTEL, Tetragon, and Tracee.
- [x] Run full six-app x86 KVM LEA corpus:
  `corpus/results/x86_kvm_corpus_20260602_141656_778399`.
- [x] Generate post-hoc summary and figure:
  `docs/tmp/kinsn_eval_20260602_summary.md` and
  `docs/figures/eval-kinsn-lea-corpus-20260602.png`.
- [ ] Investigate OTEL's LEA BPF-counter regression
  (`native_tracer_e` `1.152x` post/baseline cost) without changing workload.
- [ ] Investigate Tracee's raw `vfs_write_magic` BPF counter outlier and decide
  whether it is a kernel stats artifact, pairing ambiguity, or real slowdown.
- [ ] Improve post-hoc affected-population analysis for tail-called programs:
  callers with applied descendants should be classified as affected.
- [ ] After LEA-specific cleanup, run the combined x86 kinsn pass set with the
  same workload methodology and compare apply/performance against LEA-only and
  previous `kinsn-6`.
