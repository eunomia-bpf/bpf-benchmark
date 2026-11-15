# OTel whole-app terminal result

2026-11-15. Existing run 605029/QEMU 609811 ended at 02:49 UTC.
Make/service wrapper exit status is zero; the application result is **error**:
post-arm shim socket request failed with connection refused. Baseline
measurement completed; no complete paired native measurement is claimed.
Run: `corpus/results/x86_kvm_corpus_20261114_200608_049958`.

The retained service journal has five requests: source 21 → native 27,
28 → 34, and main 35 → 41 installed. Sources 42 and 45, both
`perf_unwind_hotspot`, failed stock verification before checked native
compilation. Request 5's first stack write is `*(u64 *)(r10 -576) = r0`;
the verifier reports `invalid write to stack R10 off=-576 size=8` after two
instructions. Main installation remains a partial success, not whole-app
acceptance. Request 5 verifier output and metadata accompany this report;
the complete service archive and all five nested request archives remain raw.

The stopped run's scratch docker disk is a rebuildable image copy; its cleanup
is recorded in cleanup-log.md. Measurements, original service archive, logs
and command records remain under
`/workspaces/kprog-raw/perf/20261114-otel-whole-word-checked`.
