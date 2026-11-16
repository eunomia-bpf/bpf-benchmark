# BCC scheduling volume investigation

The 06:04 run has extra scheduler events; the newer 13:18 run does not.
All 25 program records per arm are retained, with colliding names grouped by
type/name and their IDs kept. No run is discarded.

| Run | Scheduler switches, eBPF → native | Ratio | sockfd transfers, eBPF → native | sockfd CPU seconds, eBPF → native |
|---|---:|---:|---:|---:|
| 060435_731340 | 70,242,816 → 176,296,084 | 2.5098 | 77,563,540 → 106,860,971 | 503.63 → 737.29 |
| 131847_109569 | 54,485,576 → 47,023,142 | 0.8630 | 70,867,237 → 69,368,698 | 450.60 → 439.14 |

In the older run, switch counts divided by sockfd transfers rise from 0.906
to 1.650; in the newer run they fall from 0.769 to 0.678. These are diagnostic
ratios of aggregate counters, not counts attributed to a specific process.
The older native syscall sample also reports 7,334 bogo operations against
514 in its other samples; every sample remains in analysis.json.

The sole image's dpkg status identifies stress-ng 0.17.06-1build1. In the
[matching upstream implementation](https://github.com/ColinIanKing/stress-ng/blob/V0.17.06/stress-sockfd.c),
stress_socket_server opens /dev/zero and sends its descriptor via sendmsg
before incrementing its bogo count (lines 286–311). The client uses blocking
recvmsg and later closes the received descriptors (lines 113, 187–204).
This socket pair is therefore a concrete source of wakeups, opens and switches.
The retained counts and CPU time make it the leading producer to trace;
they do not prove how many historical switches belong to it, or why its
blocking/scheduling regime changed. An always-present 2.51x multiplier is
not supported by the newer run.

Next: capture guest-wide ctxt plus per-task voluntary/involuntary switches,
process identities and CPU placement during both arms, with the frozen entry,
three 180-second samples, current image, and an independent diagnostic collector.
No workload, benchmark source, result schema or admission rule changes.

Reproduce analysis with make -r -f kprog/test/katran-accounting.mk
bcc-scheduler-analysis OUTPUT=/workspaces/kprog-raw/perf/20261116-bcc-scheduler-analysis.
The image package status is read directly from the existing tar, without
running another image or making another source/build copy.
