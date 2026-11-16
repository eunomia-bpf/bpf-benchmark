2026-11-16T11:31:29Z

BCC stats-off run 105138_635552 completed app OK, 25 tracked programs in each
arm. Sum of the retained stress-ng real-time rates gives phase series:
eBPF 556323.46 / 578672.30 / 565756.07 and native 560216.04 / 518896.18 /
482902.35 ops/s; ratio of phase medians 0.917172979. Each sample is the frozen
180-second workload. All samples and raw workload metrics are retained.

The native decline is accompanied by falling accounted process CPU time:

| Native stressor | Wall ops/s, first → last | User+system s, first → last | CPU-normalized ops/s, first → last |
|---|---:|---:|---:|
| cap | 358235.21 → 317767.02 | 167.86 → 150.85 | 384136.68 → 379153.42 |
| set | 28007.16 → 25402.35 | 170.10 → 155.63 | 29638.07 → 29381.12 |
| sockfd | 173970.84 → 139730.17 | 172.99 → 136.74 | 181021.32 → 183943.10 |

Thus the large wall-rate loss is primarily associated with less accounted CPU
work per wall interval; these metrics do not show a similarly increasing CPU
cost per operation. Stress-ng CPU accounting is rounded and may include its
workers/children. This observation does not distinguish host vCPU scheduling,
guest contention, blocking or other work. Stats-off program counters contain
no per-program time, so the queued stats-1 BCC case is still needed to locate
BPF cost. No causal attribution or performance-target completion is claimed.

The retained shim log has 25 native replacements from boot second 831.373238
to 831.470017, one startup burst of 0.096779 seconds. It shows no continuing
native replacement accumulation across measured samples. That narrows one
possible growth mechanism without excluding map/app/kernel state growth.

Analysis entry: make -r -f kprog/test/katran-accounting.mk bcc-series
OUTPUT=/workspaces/kprog-raw/perf/20261116-bcc-series. Source is
bcc_series_analysis.py; analysis.json retains all parsed rows and arithmetic.
Core raw metadata/result/progress/app files are committed next to the run;
bulky shim details remain under corpus/results in this sole checkout.
