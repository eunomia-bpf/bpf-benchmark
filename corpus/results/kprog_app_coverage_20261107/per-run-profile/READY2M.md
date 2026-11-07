# Upstream-ready fixed-input follow-up, CPU0

Baseline `run-baseline-20261107T055424Z` and compiler tables `run-tables-20261107T055854Z` each completed12 windows with2,000,000 fixed inputs/window. Both use the same frozen image/kernel pairing and a single vCPU on hostCPU0, with no other guest on0-7 during the windows. `perf-ready2m-raw.tar.gz` retains full raw logs, work counters, JIT bytes, kernel symbols, map snapshots and sampling data. Host five-event counters are guest-only but include userspace, syscall, libbpf, reset/copy and measurement-boundary work. They are not BPF-body PMU counts. The BPF runtime counters below are separately measured by the kernel.

## Actual program runtime

| Image option | App/path | JIT ns/run | Native ns/run |
|---|---|---:|---:|
| baseline | Katran LRU bypass |106.718|100.042|
| baseline | Katran nominal warm LRU |79.311|107.564|
| tables | Katran LRU bypass |108.123|98.029|
| tables | Katran nominal warm LRU |80.223|104.363|
| baseline | Tetragon generic_kprobe_event for fixed open/close |217.625|222.440|
| tables | Tetragon generic_kprobe_event for fixed open/close |225.575|229.318|

`ready2m-counters.csv` gives exact values, actual IDs/counts and all five per-input perf counters. Each row is one window, not an estimated mean or a compiler-option speedup claim. Katran actual run-count deltas are2,000,000 or2,000,001; the extra attached-interface invocation is retained. Every explicit packet returns XDP_TX3,84 output bytes and FNV647f2ff540c87b52ba, with per-window byte equality checked by the helper. Across arms the captured comparison is action/size/hash.

## Katran work mismatch isolates the next correctness question

Flags0 and100 warmup inputs do not produce the same cache path in native and JIT. `ready2m-cache-work.csv` records the unchanged app's map-counter deltas. In the baseline nominal-warm stat window, JIT has0 LRU misses while native has2,000,000; the non-SYN TCP-miss counter has the same0/2,000,000 split. Both route all2M packets through fallback-cache selection and update the VIP packet/byte counters equally. The warm-LRU difference therefore includes repeated hashing/new-connection work on native. It cannot establish the overhead of an equivalent cache-hit path. Tables preserve the defect. Raw connection-rate values/timestamps are retained; native timestamps advance/reset, so a stuck clock is not established.

The unchanged fixed input is TCP ACK to VIP10.100.1.1:8080. Source first looks up `pckt.flow` in the cache; a miss routes via consistent hashing and may update the cache unless bypass, flood or RST rules prevent it. Existing map-lowering OFF is used only as a same-image counterfactual to isolate this observed behavior. A separate100-packet functional diagnostic captures fallback-cache keys/values; CPU12-15 durations are not comparative timing evidence. The functional diagnostic completed: JIT and native-OFF each miss once in100 inputs, native-ON misses100 times; all three caches contain the same40-byte key and16-byte value(pos1). Lowering therefore causes the divergent lookup behavior despite correct retained insertion. Exact lowered-call root cause is still under investigation. No app input, policy, upstream source or common framework has changed.

## Tetragon readiness and cost

The script waits for upstream `Listening for events...`, emitted after policy loading and event-reader setup. This replaces the pilot's premature start with the full289-program JIT inventory. All118 native replacements complete with0 loader failures and the same symbol cohort. Measured hot entry ID145 executes2,000,875 times on JIT; native ID496/baseline or500/tables executes2,001,190 times. Other generic entries' raw deltas, including background/metadata activity, remain present. Exactly2M successful opens and2M closes of `/dev/null` complete per arm. These are unbound native-path diagnostics, not six-app generation-bound acceptance.

Baseline guest ROI per input is14,031.05 cycles/38,806.64 instructions/9.667 branch misses JIT and14,576.51/39,618.69/9.585 native. iTLB misses are2.794/2.997 and L1 instruction-cache misses174.848/186.631. Counters include all active policies and app/measurement work. Sampling identifies2,365/2,413 samples in `copy_from_kernel_nofault`,996/1,033 in `bpf_probe_read_compat`,454/477 in `__bpf_ringbuf_reserve`, and substantial other tracepoint/tail-chain programs. The hot entry's loaded code has116/91 JIT/native samples versus28,208/29,244 total samples. Native code is2047B versus1879B JIT. Kernel reads, event machinery and other policy code dominate the inclusive ROI; this does not assign the4.8ns difference to one helper or instruction. Tables do not improve observed target runtime. `ready2m-profiles.json` retains complete histograms and exact primary-code spans, avoiding attribution from truncated names alone.

## Reproduce and provenance

Use the private result Makefile's `perf-profile-build`, `perf-profile`, `perf-tables-profile`, and `perf-no-lowering-profile` targets. Image sources/commands are in `README.md` and `table-candidate-inputs.tar.gz`. Analyze the specific completed RUN_DIRECTORY using `analyze.py`, then run `ready2m-report.py` for these frozen observations. The analyzer requires collector completion and all reported windows; it no longer accepts an empty directory selected by a queued job's shared pointer. That premature empty OFF summary is retained. Measured raw data is unchanged. Archived guest snapshots identify the executing workload script; the existing tool-hash record identifies the pre-map-sampling helper. Current diagnostic helper/source hashes are recorded separately.
