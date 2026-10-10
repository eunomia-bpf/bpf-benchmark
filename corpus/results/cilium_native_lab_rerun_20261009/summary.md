# Interrupted Cilium native lab rerun, 2026-10-09

This record reconstructs the interrupted Codex run on lab's
`bpf-benchmark-dev` Workspace from `run.0.log`, supervisor evidence, and its
uncommitted result directory. **Status: interrupted.** Recording this result
ran no measurement, VM, or benchmark. Existing results and paper numbers are
unchanged. See [evidence/README.md](evidence/README.md),
[findings.md](findings.md), and [metadata.json](metadata.json).

## What ran and completed

Historical replay used candidate `9f3855f6fa1c` and kernel `8e116c79d104`;
these are the audit's leading paper-era candidates, not certified May 29
collection identities. The October 9 current-master image used
`9be2b6a199d4` and kernel `24cd6e63ce91`. Both guests reported
`7.0.0-rc2+`. Both builds used upstream Cilium `1.20.0-dev`, gitlink
`1b721c2964e7`; native compatibility/source patches, loader, and kernel differ.
Current native objects were reused from October 6, not freshly rebuilt.

On the Core Ultra 9 285K, four guest vCPUs were pinned
`0→host1, 1→host4, 2→host0, 3→host3`: pktgen used guest 0/1, application
container guest 2/3, QEMU emulator host 6/7. Affinity snapshots corroborate
this mapping. The early supervisor's six-vCPU proposal was superseded.
Guests had 24 GiB. Unchanged bidirectional 64-byte UDP traffic used random
ports/flows, one warmup and one 30-second sample per phase, versus three
180-second samples and default eight vCPUs/64 GiB in the old runs.
Endpoint addresses/MACs and map state changed after restart. Other Workspace
CPU use was sampled every two seconds; individual other pods reached about
1.04 CPU cores during measurement windows.

One guest ran at a time through `make corpus`. Historical replay completed
20 invocations/40 phases, 14:49:23–15:57:21 UTC: five JIT/native pairs and
five JIT/JIT restart controls **in each stats mode**, ordered per cycle as
stats-on treatment/control, then stats-off treatment/control. Four preceding
smoke attempts covered boot/selector/module/dump setup failures and one
completed 10-second comparison; they are separate from the scheduled series.
Current master completed one stats-on JIT/native pair, 15:57:24–16:01:03.
Its first stats-on restart control started at 16:01:03 and never finalized.
No current stats-off pair or control completed. Perf was installed and
profiling tooling prepared; **no completed perf-stat or perf-record output
was found**.

## Measured findings

Ratios are JIT/native ns/run and native/JIT generated PPS. Historical paired
medians were **6.110× ns/run** (range 5.921–7.652), **2.234× stats-on PPS**
(2.136–2.577), and **2.300× stats-off PPS** (2.254–2.410).
Stats-on arm medians were 1114.110→175.434 ns/run; their ratio, 6.351×,
differs from the median paired ratio. Stats-off medians were
1,046,645→2,407,456 PPS. JIT/JIT paired control medians were 0.967× ns/run
(0.936–1.022), 0.983× stats-on PPS (0.955–1.009), and 1.001× stats-off PPS
(0.977–1.042). Historical busy endpoint medians were
1121.088→177.550 and 1107.137→174.141 ns/run.

The single current pair measured **1198.543→237.110 ns/run (5.054801×)**
and **966,419→3,685,295 stats-on PPS (3.813351×)**. Native recorded
**110,502,719 reason-133 egress policy drops**; JIT recorded zero policy
drops, with 28,916,795 ingress and 28,916,798 egress reason-0 forwards.
Peer RX totals were 28,916,799 JIT versus two native packets. Historical
native median policy drops were 67,944,078 stats-on and 72,140,463 stats-off,
versus zero JIT drops; native peer RX was only one or two packets.

Program sets differed: historical shim timing rows were 53–62 JIT versus
27 native; current 56 versus 60. These are not complete kernel inventories:
current end snapshots contained 59 versus 198 programs, including retained
originals/native copies and observer/system programs. Historical native
retained only two endpoint TCX attachments, missing five host/netdev
attachments; current retained all seven. Both arms retained XDP.

**These are measurements of unequal forwarding/drop work, not valid
equivalent-forwarding speedups.** Generated PPS is not receiver goodput.
Attachment parity on current master did not restore delivery equivalence.
The old 2.357974× stats-off PPS and 1.863055× ns/run claims were not
established as reproducible speedups. Counters establish the path difference;
the native policy failure's root cause and cycle attribution remain unknown.

## Interruption and future rerun

The operator reports a host reboot about **16:04–16:05 UTC**. The log's last
write was 16:04:14.167738; the current control's second-arm start snapshot
finished at 16:03:51.413873, but its end files are truncated and host-load
gzip is damaged. No exit/result, retry, final summary, or commit followed.
The saved reboot checker never updated; exact reboot time/cause are unknown.

A future comparable rerun needs native policy/attachment behavior that
performs the same forwarding work, documented program/map/configuration
identity, fixed pinning, interleaved pairs/restart controls, separate stats-off
throughput, receiver/verdict counters, and separate completed profiling with
code-address attribution. Preserve all raw outcomes and contention caveats.
