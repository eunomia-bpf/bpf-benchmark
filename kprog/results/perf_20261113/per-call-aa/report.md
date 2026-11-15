# Counter-enabled Katran A/A

Counter collection is restored using existing modes, with 65504dc71 forwarding
NATIVE_LOADER_MODE through the one-image Make target (default post). For A/A,
SKIP_REJIT_MODE=norejit keeps the shim's measure_start/measure_finish while
NATIVE_LOADER_MODE=0 leaves both application starts on eBPF. The prior all
mode explicitly returned bpf={}. Frozen runner, workload, image, kernel and
base were unchanged. The narrow C-owned target change was announced in
COORDINATION before editing and handed back to C after the commit.

Actual smoke: x86_kvm_corpus_20261115_071929_236167, Make0/appOK, one 1-second
sample per arm. Both records are xdp/balancer_ingres, 23840 translated bytes,
13641 JIT bytes. First ID9: 3255312 invocations / 374721099 ns. Later ID15:
3145190 invocations / 371055791 ns. Actual docker environment has norejit,
native-loader0 and stats1; both shim logs and all raw counters are retained.
This verifies collection; the short run is not a performance number or proof
of byte identity from sizes alone.

The full control completed at 07:47:31Z, Make exit0, app and both phases ok.
Run x86_kvm_corpus_20261115_072225_798807. The two records remain
xdp/balancer_ingres, 23840 translated bytes and13641 JIT bytes (IDs9/15).

| Arm | Calls | BPF runtime ns | ns/call | Sample pps |
|---|---:|---:|---:|---|
| First | 1490195922 | 231120984285 | 155.094361 | 3137697,2678373,2397974 |
| Later | 1270627649 | 245900414986 | 193.526731 | 2034304,2503305,2435964 |

The per-call factor, first ns/call divided by later ns/call, is **0.801410536x**:
the later eBPF arm cost24.78% more per invocation. Later/first throughput is
**0.848981695x using means**, **0.909493935x using medians**. All per-thread
pktgen sent/error counters remain in the raw data. No native code was loaded.
This is a completed same-configured-program A/A, not a native speedup.

The sole guest held timingEX/imageSH on0–7, 8vCPU/64GiB, host80GiB AS.
Bounded host Rust/Clang/source checks ran outside0–7 during this control;
that activity is recorded, so the whole host is not described as idle.
There is no evidence here that identifies the cause of the drift. The earlier
shim-disabled control drifted upward, while this counter-enabled control
drifted downward; together they do not establish one fixed directional or
transportable correction factor. Neither run is discarded. Keep each app's
own A/A and matching reducer visible, per the coordinator's analysis rule,
and treat cross-run quotients as retrospective analysis rather than causal
native effects. Per-call counters are available now, but also exhibit drift.

Raw: /workspaces/kprog-raw/perf/20261115-per-call-aa/full. The timing/image
locks are released. Existing Make removed the guest Docker disk; ended image
archive/module copies were removed after checking holders. Logs, protocol,
metadata, app counters and both shim logs are retained. Each of the other
five apps still needs its own isolated A/A before freeze.

Earlier throughput control (72fb8a71a): mean later/first 1.172592626x;
median later/first 1.178142764x. The analyzer reproduces historical C4
median throughput 1.075982064x and raw per-call1.186663754x. Applying the
coordinator's stated mean A/A factor gives C4 0.917609441x; using the
same median reducer on both gives 0.913286655x. Neither supports a
Katran throughput gain. These are retrospective quotients across different
runs, not a measured native slowdown or a recovered causal correction. Keep
the raw values and their reducer visible. Future throughput comparisons use
their own app's A/A with the same reducer. Per-program counters remain the
primary metric, and each of the six apps still needs its isolated A/A before
freeze. The paper is unchanged.

Analysis script preserves all recorded programs, including zero-run and
unmatched/ambiguous shapes. It reports program facts and per-program time as
well as total time/count for the complete measured window; warmup precedes
the shim start. It introduces no program filter, validity gate or fabricated
counter. Reproduce the completed analysis with:

```
python3 kprog/results/perf_20261113/per-call-aa/analyze.py --run corpus/results/x86_kvm_corpus_20261115_072225_798807 --output /workspaces/kprog-raw/perf/20261115-per-call-aa/full/analysis.json
```
