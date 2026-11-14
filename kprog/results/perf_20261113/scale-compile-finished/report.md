# Completed scale compiler batch

All 16 cases in the original 100/1K/10K/100K × scalar/pointer ×
direct/indirect batch now have terminal compiler outcomes. Eight 100/1K
cases compiled. Both 10K scalar compilers ended with signal9: direct wall
7030.056s / peak83234848KiB; indirect wall6938.867s / peak82620896KiB.
The signal's cause beyond the observed status remains unestablished.
Both 10K pointer and all four 100K cases failed preprocessing with
`ran out of source locations`. `cases.json` retains every outcome, native
instruction count, expanded bytes when available, compiler command and
per-stage wall/user/system/RSS observations.

The first guest verifier attempt failed before case loading because the
case-file glob also included resource sidecar JSON lacking `name`.
0659b4ee4 selects actual direct/indirect case records; two targeted tests
check that failed cases are retained and malformed actual records still
raise. 8dcdc41f8 updates the existing Make target to the sole kernel,
shared image lock and bounded 2vCPU/8GiB guest on18–19.

A subsequent attempt recorded all eight failed compiler outcomes and then
stopped because the host/guest root lacked `trace-cmd`. The existing memory
trace analysis was retained; Ubuntu package3.2-1ubuntu2 and dependencies
were installed on the host (install log retained), without rebuilding the
base or image. `resume-queue.json` records the fresh verifier-only attempt
using the same eight compiled B objects. No compiler batch was repeated.
Its verifier/execution and memory-trace results remain to be collected.

This harness uses single-translation-unit preprocessing, whereas production
uses chunked preprocessing and known-helper specialization. Its frontend
limits do not establish production capacity without a matched production
replay. The full V3 scale goal remains open. Raw data stays under
`/workspaces/kprog-raw/perf/20261114-scale-current/retry3`.
