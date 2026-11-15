# Completed workload-throughput A/A control

Started 2026-11-15T06:21:35Z. PID 838173 is the timing-lock controller,
838174 the recorded Make launcher. Raw output:
`/workspaces/kprog-raw/perf/20261115-isolated-aa/job/make.log`.

The existing one-image corpus target runs Katran with `SKIP_REJIT_MODE=all`,
which disables the shim for both arms. The frozen driver still stops the
baseline application and starts the post application. Both arms therefore
use the image's same eBPF objects, with three 180-second samples, stats on,
CPUs 0–7, 8 vCPUs and 64 GiB guest memory. Host AS cap is 80 GiB. The job
holds timing EX and image SH; other functional guests finished before start.
No benchmark source, workload, timing script or image was changed for this
control. The coordinator explicitly requested it at 06:06:55.

Completed at 06:47:24Z, Make exit 0, app status ok, both measurements ok;
run `x86_kvm_corpus_20261115_062302_565500`. Mean pktgen throughput was
2,906,205.67 pps for the first arm and 3,407,795.33 pps for the later arm:
post/baseline **1.172593x**, a **17.26%** increase with the configured native
optimization disabled. Samples below use the sum of the four pktgen result
rates; the analyzer retains sent/error counters and per-thread measurements.

| Arm | Sample 1 pps | Sample 2 pps | Sample 3 pps |
|---|---:|---:|---:|

| baseline | 2,515,835 | 2,980,935 | 3,221,847 |
| post_rejit | 3,538,386 | 3,173,033 | 3,511,967 |

Despite `bpf_stats=true`, both arms have `bpf={}`. Actual program identities,
JIT bytes and per-invocation time are therefore **unobserved**, not equal or
zero. This is a same-configured-image workload-throughput control, not a
measured body/per-call A/A. Large pktgen error counts are retained in the raw
result. One chronological pair cannot separate workload evolution, scheduling
or other drift, or provide a correction factor for earlier native results.
No result is discarded and no admission threshold is introduced. The
per-call question remains open; this control is not a native speedup.

Reproduce the analysis with `python3 kprog/results/perf_20261113/isolated-aa/analyze.py`.
The existing Make target removed the ended guest Docker disk. All raw run
results and logs remain on persistent storage. The timing and image locks are
released. The frozen workload, runner and image were unchanged.
