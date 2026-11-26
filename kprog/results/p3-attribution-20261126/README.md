# P3 attribution: Tetragon and OTel, 2026-11-26

Coordinator assignment 10:21Z: establish whether P3 causes the Tetragon and
OTel short-check native time, fix the evidence-supported cause within the
design, and record kernel memset weight from Tetragon and Tracee profiles.
The full x86 timing run stays frozen.

The first collection uses image fb53150e89ea unchanged. It runs the frozen
check target for Tetragon three times, then OTel three times (one 10 s sample,
stats on each time), followed by host PMU profiles of Tetragon and Tracee.
The first Tetragon case is also the smoke case and contributes to its three
runs. Expected collection time is about 35–50 minutes including startup.
Each job records its command, exit status and raw paths; a heartbeat records
progress during long jobs. Every result is retained and published as it ends.

Profiles reuse profile-host.sh with EVENT=cpu_core/cycles/ and PERIOD=1000000,
call chains, eight guest CPUs and 32 GiB guest memory; the existing profile's
60 s workload and stats-off protocol is unchanged. A 40 GiB outer address-space
limit bounds each profile job. Module text symbols join the phase snapshots,
so the P3 routines are resolved after their module loads. Host monotonic/realtime
offset is captured for phase alignment. Existing staging captures move to
prior-staging rather than being deleted. Timing EX then image SH serializes
guests against other lanes; the separate compile pool retains its own limits.

The analysis compares per-program counts/time as well as aggregate ns/call,
and PMU samples in P3 routines, the kernel hash lookup family, program bodies,
memset and other kernel work. `memset-calls-20261126` receives the observed
memset weight with the denominator and attribution limits. Implementation
changes wait for this evidence; workload/framework definitions stay fixed.

The first collection's six diagnostic launches returned an immediate Make
path error: its relative entry path was resolved from this result directory.
No application ran in those six attempts; their logs and summaries are kept.
The absolute entry path fixes this wrapper error. The independent Tetragon and
Tracee profiles continue, then retry-checks.sh runs the required three
Tetragon and three OTel checks. A launcher failure now stops dependent check
launches while retaining their error; it does not discard measurements or
block independent profiles.
