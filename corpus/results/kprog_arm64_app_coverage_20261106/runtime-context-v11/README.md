# Complete six-application ARM QEMU runtime v11

The unchanged two-start corpus protocol completed for all six applications
using the matched kernel/modules, private frozen image/runtimev11 and
prebuilt generation-bound proof requirement. The driver exits0; application
outcomes below are authoritative. QEMU throughput/timing is functional only.

| Application | Baseline counter rows | Native counter rows | App status |
| --- | ---: | ---: | --- |
| bcc/set | 23 | 0 | error |
| cilium/agent | 62 | 0 | error |
| katran | 1 | 1 | ok |
| otelcol-ebpf-profiler/profiling | 12 | 0 | error |
| tetragon/observer | 287 | 0 | error |
| tracee/monitor | 151 | 0 | error |

The counts are resident BPF counter rows from the actual application phases,
not totals inferred from a staged artifact directory. No native workload was
recorded for the five error applications. Every934 startup load attempts is
retained, including feature probes, retries,30failed original load attempts
and11unfinished requests. No failed program is excluded from the goal.

Concrete failures: BCC startup proof rejections; OTel missing exact simulator
artifact; Cilium dynamic-configuration cil_xdp_entry proof absent; Tetragon
startup loader failures; Tracee startup failure (raw native-loader/app error
logs retained). Katran has1resident baseline and1native counter row, both
workload phases finish, and bound native replacement is recorded. All raw
workload commands/stdout/stderr and per-program work/time counters are in the
JSON files and complete run archive. This is not six-application completion.

BCC is superseded by ../bcc-runtime-v14, which fixes context-load admission
while retaining its remaining errors. The previous standalone1136-artifact
census remains historical and must not be used as an actual app-loaded
program denominator. The image's Spark launcher and matching-kernel package
were built; ARM hardware execution/performance remains pending.
