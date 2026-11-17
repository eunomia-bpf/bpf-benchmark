# Joined clock-batch observations before batch 2

Read at 2026-11-17T13:26Z from the coordinator's
`kprog/results/ktime-leaf-20261117/summary.txt` and persistent
`/workspaces/kprog-raw/ktime-leaf-20261117/hostload.log`.
Image `cb4bd4d8` predates batch-2 UID/GID, kernel-string loop and Cilium
switches. It joins the clock leaf with current-task BTF/jiffies,
user/compat strings and the tail-frame correction. These observations do
not isolate any one of those changes. The batch finished at 13:08:55Z.

| App / retained run | eBPF / native ns per invocation | Ratio eBPF/native | Throughput sample ratios native/eBPF | Installed native / JIT bytes |
|---|---:|---:|---|---:|
| BCC `123339_157340` | 154.0 / 127.8 | 1.205 | 0.962 / 1.787 / 1.352 | 13248 / 7965 |
| Katran `124541_839520` | 196.6 / 318.9 | 0.616 | 0.560 / 0.863 / 0.591 | 9783 / 13641 |
| Tracee `125801_473832` | 634.2 / 348.2 | 1.822 | 0.996 / 3.485 / 1.536 | 1805760 / 2068918 |

Run directory prefix for each row:
`corpus/results/x86_kvm_corpus_20261117_`. These are the coordinator's
stats-on subset runs, not the frozen stats-off 3x180 floor comparison.
Per-call selection is 15/25 records per BCC arm, 1/1 for Katran and
41/167 for Tracee. No PMU body/helper/map split accompanies this table.

BCC's native sched_switch and sched_wakeup counts are 2.083 and 2.082
times eBPF. Its aggregate weighted ratio does not isolate faster execution
of the same program mix. Tracee's median active count ratio is 1.538
(24 of 24 classified active programs follow it); that does not establish
an unchanged invocation mixture across all 41 selected records. Katran
has one active program with native/eBPF count ratio 0.664. Keep those
counts beside the timings instead of turning the aggregate into an
equal-work or target-achievement claim. None reaches the half-size target.

Katran is slower in each sample of this particular run. Before/after
host load averages are 14.90/40.46; the log's `ps %CPU` values are lifetime
averages, not a recording of CPU use inside each sample. They cannot prove
the host was quiet during measurement. Conversely, load averages alone
do not identify contention as the cause. The existing quiet repeat keeps
the raw result and checks the behavior without changing the benchmark.
Its app-side aggregate error counter is 957071407; the table does not
attribute that counter to a BPF load or execution failure.

The new clock source emits one 341-byte shared host fixture per calling
program, versus an external kernel call previously. Installed code grew
in these timed objects; that alone does not identify where the extra
per-call time was spent. If the repeat retains Katran's slowdown, split
its program/clock/map cost against the preceding same-app stats-on run
before crediting or blaming the clock leaf. Retain the joined-change
provenance and invocation counts. Omp owns the image and repeat schedule;
this readout introduces no new run admission requirement.
