# Five-application single-round trial, 2026-09-19

This directory contains external post-hoc analysis. It is not imported or computed by the benchmark framework; the raw result files are unchanged.

Both batches completed with make exit code 0; all five applications report status ok. The protocol is the existing two-start load-time comparison on KVM x86, SAMPLES=1, WARMUPS=1, WORKLOAD_DURATION=30, BPF statistics disabled. This is a single-round measurement without confidence intervals. It is not a live replacement experiment. Workloads and launchers were not modified.

BCC and Tracee use context_specialize. Cilium, OTel and Tetragon use phase-stable map_inline. Exact make commands, source revision, runtime image identity, pass policy snapshots and complete console logs are in each run's provenance directory. Original per-application payloads, load-time plans, reports, shim logs and retained workdirs are in details.

Metrics: BCC/Tracee/Tetragon sum the raw stress-ng bogo operation counts and divide by the whole measured workload duration; this is a workload-specific aggregate, not a common unit across applications. Cilium sums the concurrent sender pktgen pps values. OTel reports the sum of the ten language-worker integer-loop operation rates, retaining each worker and language separately; its concurrent native CPU stressor is a separate metric. The earlier BCC +12.91% progress estimate summed per-stressor reported rates; the final whole-duration calculation is +10.41%.

Successful rewrite counts are cumulative over program load instances, not unique static program sites. Shim optimized records were paired with the actual subsequent BPF_PROG_LOAD return on the same pid/tid; fd >= 0 indicates successful loading, regardless of stale errno. Verifier acceptance and loading do not establish application semantics or stability assumptions.

Failures retained: OTel perf_unwind_dot has 141 rewritten sites in a rejected candidate (R1 unbounded memory access); these are excluded from the 1,078 successfully deployed sites. Tetragon has two optimizer failures (missing JSON string field name), plus 50 verifier-rejected candidates (unreachable insn), containing 178 rewritten sites that were not deployed; its 95 successfully deployed sites are separate. Cilium has ten original-bytecode preflight rejections, Tetragon two; these are recorded separately from optimized-candidate rejection. Application completion does not mean every optimization succeeded.

All measured changes, including OTel language regressions and the native CPU stressor slowdown, remain in analysis.json. OTel's aggregate language-loop change is +0.57%, while its native CPU stressor changes from 1,390.59 to 1,210.51 bogo ops/s (-12.95%). Tetragon's +157.41% is a single-round observation, not a demonstrated stable effect. A pre-existing unrelated host build was running during these trials; host contention was not controlled. No run is discarded for that caveat.

Reproduce the analysis with command.sh. Input paths are absolute artifact paths from this workspace.
