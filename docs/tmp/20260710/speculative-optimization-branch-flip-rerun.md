# Speculative Optimization Branch-Flip Rerun Log

Date: 2026-07-10

This note indexes the current profile-guided `branch_flip` artifacts and keeps
the interpretation outside the benchmark framework. All ratios below are
post-hoc analysis over raw per-app corpus JSON files with the documented
`min(baseline_runs, post_rejit_runs) >= 100` filter. A ratio below 1.0 means
post-ReJIT was faster.

## Artifacts

- Real per-site PMU profile root:
  `corpus/results/branch_profile_root_20260703_040500_pgohold`
- Raw PMU profile captures:
  `corpus/results/branch_profile_raw_20260702_195718`
  `corpus/results/branch_profile_raw_20260703_033844_pgohold`
  `corpus/results/branch_profile_raw_20260703_034310_pgohold`
- Historical complete branch_flip-only run:
  `corpus/results/x86_docker_corpus_20260701_213659_735606`
- Historical complete branch_flip + map_inline run:
  `corpus/results/x86_docker_corpus_20260701_223045_655842`
- Latest partial six-app branch_flip rerun:
  `corpus/results/x86_docker_corpus_20260704_043453_163431`
- Tracee-only completion used to fill the missing app:
  `corpus/results/x86_docker_corpus_20260704_185159_405412`
- Later katran/tracee repro attempt:
  `corpus/results/x86_docker_corpus_20260709_211125_030456`

`20260704_043453` and `20260709_211125` still have
`metadata.status=running` because the host Docker runner exited before suite
finalization. They are not active runs. The app payloads already written under
`20260704_043453/details/apps/` are usable as raw per-app data for the first
five applications; `20260704_185159` provides the completed Tracee payload.

## Performance Snapshot

| Dataset | Retained | Geomean post/base | Speedup | W/L/T | Notes |
| --- | ---: | ---: | ---: | ---: | --- |
| `20260701_213659_735606` branch_flip only | 85 | 0.948732 | 1.054039 | 57/28/0 | Complete six-app run |
| `20260701_223045_655842` branch_flip,map_inline | 81 | 0.961137 | 1.040434 | 59/22/0 | Complete six-app run |
| `20260704_043453` first five apps only | 42 | 1.021610 | 0.978847 | 22/20/0 | No Tracee payload in this suite |
| `20260704_185159` Tracee only | 62 | 1.179119 | 0.848090 | 22/40/0 | Completed Tracee rerun |
| `20260704_043453` + `20260704_185159` stitched six-app view | 104 | 1.112780 | 0.898651 | 44/60/0 | App-level stitch, not one atomic suite artifact |

Per-app breakdown for the stitched latest view:

| App | Retained | Geomean post/base | Speedup | W/L/T |
| --- | ---: | ---: | ---: | --- |
| `bcc/set` | 18 | 0.950739 | 1.051814 | 12/6/0 |
| `cilium/agent` | 2 | 0.926406 | 1.079440 | 2/0/0 |
| `katran` | 1 | 1.015257 | 0.984973 | 0/1/0 |
| `otelcol-ebpf-profiler/profiling` | 2 | 0.998445 | 1.001557 | 1/1/0 |
| `tetragon/observer` | 19 | 1.107971 | 0.902550 | 7/12/0 |
| `tracee/monitor` | 62 | 1.179119 | 0.848090 | 22/40/0 |

## Interpretation

The July 1 complete branch_flip-only result is positive, but the July 4 rerun
does not reproduce that result. The latest stitched view is negative overall,
mainly because Tracee and Tetragon regress. This should not be reported as a
stable speedup claim.

The next optimization step should be conservative gating inside `bpfopt
branch_flip`: only annotate high-confidence sites from real PMU profiles and
leave low-count, near-50/50, low-miss-rate, or profile-unstable sites unchanged.
Missing profile data must remain a hard error; unreliable but present profile
data should become a no-op at that site rather than a fallback heuristic.
