Katran sample decay, 2026-11-16

Coordinator 21:19 requests the sample-by-sample slowdown after the shared-hash
comparison. The current image remains 6641a7e1. This directory analyzes retained
raw results only; it launches no guest and changes no frozen file or setting.

The default Make target analyzes C's stats-off run 192946_405839, committed in
15d1fda7d. Pass RUN=<stats-on run directory> CASE=stats-on when C's ongoing
round reaches Katran. Each thread's packetgen packets, pps, errors, kernel
duration, wrapper duration and return code remain separate in the report.
Packetgen errors do not establish the number of BPF drops.

Counter scope is a material limit: runner/libs/rejit.py:462-484 has one
measure_start before the sample loop and one measure_finish after it.
Consequently the frozen three-sample result contains one aggregate BPF delta
per arm and three workload records. It does not contain three per-call times.
BCC run 202317_937563's shim log independently shows one start/finish pair
covering the full approximately 541-second arm. A throughput curve cannot be
converted to per-sample BPF ns/call without additional counter observations.
The analysis retains the aggregate per-call value when stats are enabled and
reports the missing sample times explicitly. No new collection or gate is added.

Stats-off result, run 192946_405839

| Worker | JIT sample 1 | JIT sample 2 | JIT sample 3 | Native sample 1 | Native sample 2 | Native sample 3 |
|---|---:|---:|---:|---:|---:|---:|
| 0 | 537420 | 947725 | 935808 | 669008 | 784120 | 602560 |
| 1 | 474129 | 351340 | 258669 | 558930 | 529538 | 538766 |
| 2 | 523417 | 846011 | 821358 | 825331 | 711764 | 499452 |
| 3 | 556232 | 821997 | 888751 | 826852 | 629003 | 633561 |
| Total pps | 2091198 | 2967073 | 2904586 | 2880121 | 2654425 | 2274339 |

Native workers 2 and 3 lose 519170 of the total 605782 pps between the first
and third samples, about 85.7% of the decline. Worker 1 loses 3.6%, while
worker 2 loses 39.5%. The JIT arm also has a sharply declining worker 1
(45.4%) alongside three rising workers. Per-worker execution or queue/cache
state therefore deserves attention in the next stats-on comparison. This
pattern alone does not identify scheduling, cache behavior or a code defect.

All packetgen kernel intervals span 179.895–180.005 seconds. The native
reported-error counts are 336148672/352860124/279585127; errors per reported
packet are 0.649/0.739/0.683. The error fraction is not a monotonic explanation
of the PPS series, and these counts cannot be renamed BPF drops. Stats are off,
so per-call time is unmeasured. stats-off.json retains every component and
the arm metadata. C's current round is on Tracee stats-on at this checkpoint;
Katran stats-on follows. No additional timing run has been started.
