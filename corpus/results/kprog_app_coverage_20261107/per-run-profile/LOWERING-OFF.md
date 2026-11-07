# Same-image lowering-OFF counterfactual, CPU0

`run-no-lowering-20261107T060652Z` queued behind R's guest and then completed all12 windows on the same exclusive CPU0, one-vCPU matching frozen kernel/base image. Every stat/profile window executes2,000,000 fixed operations. All5 hardware PMU events are present; raw bytes, program counts, cache dumps, kernel symbols and perf samples are retained in `perf-no-lowering-raw.tar.gz`. `ready2m-counters.csv`, `ready2m-cache-work.csv` and `ready2m-profiles.json` also include this run.

| Path | JIT actual ns/run | Native actual ns/run | JIT/native cache misses during stat window |
|---|---:|---:|---|
| Katran bypass |105.745|105.469|2M /2M|
| Katran warm LRU |77.360|79.862|0 /0|
| Tetragon hot generic entry |220.442|221.497|not applicable|

Katran returns the same XDP_TX3/84-byte/FNV64 output across both arms and prior images. All explicit2M packets, VIP packet/byte counters and fallback-cache selection match; the observed extra attached-interface invocation remains in actual BPF counters. Native-OFF warm-LRU BPF count is2,000,001; Tetragon selected counts are2,000,875 JIT/2,001,190 native. Tetragon still waits for upstream event-reader readiness and loads the full app; no program filtering or cohort exclusion is added. Raw map keys/values and metadata/background deltas remain visible.

The prior ON baseline native warm-LRU path took107.564 ns/run with2M misses, compared with this OFF observation79.862 ns/run with0 misses. The unchanged input/native source and successful cache insertion isolate the discrepancy to lowering behavior; the27.7ns observation is not a pure lookup-overhead estimate because the repeated-miss path does different work. Correct warm-hit native-OFF is close to JIT, and disabling lowering does not recover a large Tetragon per-entry gain. These are individual windows, not a repeated-run compiler or application speedup claim.

Baseline ON bypass native100.042 vs OFF105.469 ns/run suggests that existing lowering removes some helper cost on that path. Guest ROI counters still include syscall/libbpf/copy/measurement work, and are separately reported rather than called BPF-only cycles. No claim is made that lowering itself has been repaired or that all six apps run generation-bound. Guest-local functional lookup tracing continues on CPUs12-15; no comparative timings from that CPU set are used.
