# Katran C4 packet accounting

Source `x86_kvm_corpus_20261114_012718_572545`, status `ok`, stats on, three180-second samples. No workload or runner change; this is retrospective analysis.

| counter | eBPF | native |
| --- | ---: | ---: |
| successful pktgen sends | 1,859,479,230 | 2,007,058,276 |
| pktgen transmit errors | 1,759,520,106 | 1,733,015,373 |
| send attempts = sends + errors | 3,618,999,336 | 3,740,073,649 |
| XDP invocations | 1,859,479,231 | 2,007,058,277 |
| XDP minus successful sends | 1 | 1 |
| error fraction of attempts | 48.6190% | 46.3364% |
| median reported successful pps | 3,450,538 | 3,712,717 |
| BPF ns/invocation | 122.3517 | 103.1056 |

The frozen throughput ratio is **1.075982x**; per-call speedup is **1.186664x**. Successful sends and XDP invocations differ by one in each arm. The capture cannot identify that one invocation or its exact boundary.

In the sole kernel, net/core/pktgen.c:3654 increments sofar only for NETDEV_TX_OK. NET_XMIT_DROP/NET_XMIT_CN increment errors separately. Therefore errors are additional failed attempts, not a subset of pkts-sofar. Subtracting errors from successful sends would invent a forwarded-packet count. The earlier94.6%/86.3% figures were errors per successful send; the attempt error fractions above use the correct denominator.

The veth transmit path enqueues before receive-side XDP. A full XDP receive ring returns NETDEV_TX_BUSY; the no-qdisc transmit branch can turn it into NET_XMIT_DROP. The receive path separately records XDP_DROP in xdp_drops. The retained C4 result has pktgen errors and program run counters, but no XDP action-drop/ethtool snapshots. These errors cannot be called XDP return-action drops, and neither accepted sends nor runs establish forwarded application packets.

For the actual median samples (baseline index2, native index1), recomputing rates from every thread's original usec gives:

- attempted-send rate ratio: 1.058540700x;
- successful-admission fraction ratio: 1.016477003x;
- product: 1.075982278x, versus 1.075982064x using pktgen's integer pps.

Thus more attempts and a higher successful fraction account for the observed packet-rate ratio. Aggregate counts decompose similarly, but their ratio is not the frozen median metric. This accounting does not determine how much of either factor was caused by native code.

Using 8.8644% as a hypothetical serial-work fraction and the C4 per-call speedup yields 1.014141x. That model is not a bound on this asynchronous, queue-limited multicore packet path: profile share is across the capture's CPUs, not a measured fraction of the limiting queue/CPU, and failed sends do not execute BPF. It also comes from a different run. Do not restore the withdrawn45% inference.

The profile's start/stop log spans 124.0s baseline and 121.0s native, while its one workload sample is configured60s. Its global sample share must retain that capture-window scope; it is not a direct C4 critical-path fraction.

There is also a counter-window mismatch: profile details/result.json records one warmup and one measured60-second sample. corpus/driver.py emits measurement_start before measure_app_phase; runner/libs/rejit.py:440 runs warmups before the shim measure_start. The profile observer brackets the outer event, so its samples include warmup while run_cnt_delta excludes warmup. The table below is the literal raw quotient, not a matched-window per-call cost. No exact matching invocation denominator can be recovered from the retained C4/profile counter deltas.

| full-capture samples per million measured-only runs (window mismatch) | eBPF | native |
| --- | ---: | ---: |
| program_text | 73.174 | 71.620 |
| clock | 69.034 | 62.873 |
| map_lookup | 51.348 | 20.787 |

The raw profile JSON labels baseline208420472 invocations and native217104606, with JIT sizes13641/10196 respectively. The earlier217.1M/208.4M prose reverses those denominators. The corrected table does not support the quoted native-body6% slowdown or unchanged normalized clock samples. These are sampled observations from a different run, not a causal attribution of C4's per-call gain.

The program-text bucket includes logic moved into the program by helper inlining; it is not an isolated measurement of unchanged application-body code generation. The clock helper still calls the same implementation; reducing its wrapper remains a candidate rather than a predicted saving of the entire clock sample share.

Next in the authorized order: after the remaining OTel app, use C's existing producer switches for the18:40 target-CPU/CMOV/sibling-call configuration and every LTO piece, then subset-time Katran. After that baseline, bind the clock helper directly to the same ktime_get_mono_fast_ns implementation. No new timing or improvement is claimed here.

Source f64a1698e/b161e5508/be28ce768; make -f kprog/test/katran-accounting.mk analyze. This publication uses warmup-corrected-v3; initial and corrected-v2 reports/raw inputs are retained in the persistent raw tree. No benchmark or profile result was discarded.
