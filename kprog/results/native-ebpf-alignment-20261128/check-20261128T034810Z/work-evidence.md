# Same-image six-app functional work evidence

All five remaining frozen1x10s/stats1 checks completed with process0/app status ok on the same6b88 image at04:07:45Z. OTel is reused from the completed033629 same-image check, not run again. No image, kernel, compiled P or benchmark setting changed between them. The table counts successful native install events, not distinct simultaneously live programs. It does not equate process completion with semantic equivalence.

| App | Native install events | Native failures | Active programs eBPF / native | App status |
|---|---:|---:|---:|---|
| OTel (033629 reused) | 14 | 0 | 2 / 2 | ok / ok |
| bcc/set | 25 | 0 | 17 / 17 | ok / ok |
| cilium/agent | 135 | 0 | 5 / 2 | ok / ok |
| tetragon/observer | 288 | 0 | 35 / 32 | ok / ok |
| tracee/monitor | 169 | 0 | 64 / 68 | ok / ok |
| katran | 1 | 0 | 1 / 1 | ok / ok |

The six apps total632 successful native install events and zero logged native failures. Every captured workload component returned0. All full per-program statistics and unmodified workload outputs remain in check-summary.json and the complete corpus archive; work-engagement.json is a compact index. Requested workload duration stays10s; actual component/stressor durations vary (including BCC's11s wrapper and Tracee's aggregate20s futex real-time metric) and are preserved, not normalized or overridden.

- OTel: real native attempt/frame counter growth, nonzero stacks and tails and installed prog-array targets on both arms are recorded in [binding-validation.md](../../x86-otel-perf-20261127/profile-20261128T033629Z/binding-validation.md). This specifically addresses the prior skipped-unwind defect.
- BCC: both arms have17 active hook programs; syscall, capability, VFS and scheduler hooks have nonzero counters, and all four syscall/cap/set/sockfd stressors report passed with zero failed/skipped. Worker outputs and per-program counts establish the same selected hook workload is exercised.
- Cilium: both have two hot endpoint entry programs with packet counts matching entries within11-12 extra calls; both directions report zero send errors, and slot7 resolves to their IPv4 tail targets. The apparent5-vs2 active-program difference consists of three baseline programs with one call each, as detailed in [cilium-work-alignment.md](cilium-work-alignment.md). Independent endpoint IP/MAC allocations are retained.
- Tetragon: all six eventfd/mmap/udp/sock/sockfd/sockpair stressors pass with zero failed/skipped. generic_tracepoint runs30380031 times on eBPF and29534096 on native. Active programs35/32 reflect the actual recorded workload; no count-based equality/exclusion rule is applied.
- Tracee: all seven cap/set/sigfd/eventfd/kill/futex/prctl stressors pass with zero failed/skipped. Entry/exit counters are26503059/26503094 on eBPF and47366177/47366201 on native; hooks and workload engagement are present on both sides. Active programs64/68 are retained, not declared a failure or omitted.
- Katran: the single balancer counter exactly equals the sum of the four reported pktgen sent-packet counts in each arm. The same64-byte/65535-flow/UDP8080 workload and all four component return codes are retained. Send errors are present in both arms; see below.

Katran totals: eBPF sent24000485 packets, reported26900978 send errors; native sent25379137 packets, reported26843839 send errors. These errors are NOT zero and their cause is not established by this run. No throughput/latency acceptance or packet-delivery claim follows from this functional check.

This establishes captured workload and hook engagement for all six applications, not full path equivalence or equality of every event/packet. Read-only snapshots contain all map metadata but only the first8 array entries up to64KiB. In particular Tetragon tg_stats_map and Tracee event_data_map are larger per-CPU values and were not read; ring-buffer consumer/output contents, hash contents, later prog-array slots and dynamic helper/lock invocation counts remain unobserved. Tetragon/Tracee emitted-event equivalence is not proved by active-program counters. Those limits remain explicit in the alignment audit; no fabricated zero-error row, new runtime guard, repeated check or benchmark change is introduced to make them disappear.

Complete remaining-five-app preservation finished0 at04:07:50Z:3338 original files, all SHA/size/fileset and archive contents verified; two zstd parts total85,642,915 bytes (48,000,000 +37,642,915). Publication is followed by Git-blob and every-file verification before removing the redundant terminal RAW copy. OTel's separate committed archive remains retained. Next is the both-architecture per-program load/verifier/JIT alignment audit and known ARM frozen-global omission, not performance tuning.
