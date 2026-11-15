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

The full control is RUNNING, PID858016, 3x180 seconds per arm, stats1,
CPUs0–7, 8vCPU/64GiB, host80GiB AS, timingEX and imageSH. It uses the same
canonical STATE path, sole current image/kernel/base, with no other guest.
Raw: /workspaces/kprog-raw/perf/20261115-per-call-aa/full. Read terminal app
status and actual program facts before reporting the full per-call drift.
No completed per-call A/A result is claimed here.

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
counter. Reproduce on completion with:

```
python3 kprog/results/perf_20261113/per-call-aa/analyze.py --run <full artifact_run_dir> --output /workspaces/kprog-raw/perf/20261115-per-call-aa/full/analysis.json
```
