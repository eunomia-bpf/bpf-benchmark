# Fixed-input perf pilot, CPU0

The baseline run is `run-baseline-20261107T051745Z`; compiler tables run is `run-tables-20261107T053251Z`. Both ran one vCPU pinned to hostCPU0 after R's guest released0-7. Host perf captured guest-only events on the exact QMP vCPU TID. No CPU8-11 timing is used. Complete raw files, JIT bytes, counters, source snapshots, commands and samples are in `perf-pilot-raw.tar.gz`; per-input Katran counters are also in `katran-pilot.csv`.

## Katran fixed VIP

Every row executes200,000 fresh TEST_RUN calls, each repeat1. All return XDP_TX3 and the same84-byte packet hash7f2ff540c87b52ba. Actual program run-count deltas are exactly200,000.

| Variant | Configuration | JIT ns/run | Native ns/run |
|---|---|---:|---:|
| baseline | LRU bypass |105.42|98.36|
| baseline | warm LRU |77.44|128.95|
| tables | LRU bypass |105.90|98.64|
| tables | warm LRU |77.60|146.19|

These are actual BPF run-time counters, not elapsed syscall time. The packet is TCP ACK, not SYN. “Warm LRU” means flags0 after100 warmup calls; map hit/miss deltas were not captured in this pilot, so actual cache-hit equivalence remains to be established in the follow-up. The source bypass flag is2. No compiler-option benefit is established by these single windows. The changed native blob is10239B versus10243B, and the actual loaded JIT is10257B versus10261B.

The baseline guest ROI has about15.41 branch misses/input native versus1.19 JIT with bypass, and19.61 versus1.16 with LRU enabled. These ROI counters include the syscall, packet reset/copy, libbpf wrapper and measurement boundary; they are **not BPF-only branch-miss counts**. Cycles/instructions/iTLB/icache values remain raw in the CSV. The combination of faster native bypass and slower native LRU narrows the next investigation to the LRU/helper path; it does not yet prove which individual call costs the difference.

Exact linked relocation targets, joined to the invocation's kernel symbols, show28 static call sites:8 bpf_ktime_get_ns,6 __htab_map_lookup_elem,4 generic bpf_map_lookup_elem,4 bpf_xdp_adjust_head,3 htab_lru_map_update_elem,2 array_of_map_lookup_elem and1 generic bpf_map_update_elem. These are static sites, not dynamic call counts. No tail-call map is present for this balancer. There are zero sampled IPs in the18-byte JIT prefix; only27 baseline/21 tables samples fall inside the native body in the bypass profile, so fine entry/body attribution is under-sampled. Large sample fractions lie in guest userspace and test-run/clock/copy code. More fixed operations and before/after map statistics are queued to resolve that limit.

## Tetragon startup work is visible

All200,000 open/close operations completed in each arm, and both variants ultimately recorded118 native replacements with0 loader failures and the same replacement-symbol counts. However, the program list captured just after runner.start had only82/84 JIT and115/114 native-side programs. Generic-kprobe deltas were hundreds rather than matching the fixed work, and profiles prominently contain stacksafe, verifier precision tracking and state-copy functions. Policies were still loading during the ROI. The raw counters describe this compound startup/work interval; they do not establish pure generic_kprobe ns/run or a native speedup.

Upstream `cmd/tetragon/main.go` loads the whole policy directory before calling Observer.StartReady; `pkg/observer/observer_linux.go` emits “Listening for events...” only after event-reader setup. The follow-up profile script waits for that actual upstream readiness message after the existing runner returns, then discovers full BTF identities/IDs. It changes no shared app runner, policy or corpus workload. It records readiness evidence, uses2M fixed operations and retains all program deltas. Both baseline and tables follow-ups are detached and serialized on the same exclusive0-7 protocol.
