# Completed checked-app run with the earlier scalar packing policy

The job completed naturally at 2026-11-14 19:27:29 UTC. The outer make/VM
command returned zero; the application result reports `status=error` for
`x86_kvm_corpus_20261114_170807_121096`.

| Request | Source program | Service interval (UTC) | Result |
| --- | ---: | --- | --- |
| 1 | 21 | 17:08:36–17:08:47 | checked native installed, program 27 |
| 2 | 28 | 17:08:47–17:12:35 | checked native installed, program 34 |
| 3 | 35 | 17:12:35–18:19:57 | main proof rejected at tail-call context typing |
| 4 | 38 | 18:19:58–19:27:12 | main proof rejected at scalar/pointer subtraction |

Request 4 used the earlier pair-only four-byte spill layout. Its log shows
`R2 tried to subtract pointer from scalar` after 3,223 processed instructions.
`requests.jsonl`, the service summary and log, and request 4's commands, error
and full verifier output are retained alongside this report. The original
166 MiB service archive remains at
`/workspaces/kprog-raw/perf/20261114-static-helper-dispatch/checked-kernel/control/service.tar.gz`.
Both successful request archives were published with the earlier subset.

This run used the sole kernel, two vCPUs, 48 GiB, host CPUs 16–17 and a shared
image lock. Its original service instance predates frontend-IR reuse. The
corrected whole-word spill path has its own subsequent diagnostics. The
combined direct-P runtime results and equal-work work items retain their
existing scope.
