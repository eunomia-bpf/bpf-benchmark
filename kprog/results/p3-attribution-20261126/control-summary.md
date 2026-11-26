# Generic-helper control, 2026-11-26

The control completed with controller0, all six app checks ok/error empty,
288 Tetragon and14 OTel native replacements per check and no native-load
failures. Module evidence confirms the same .text with renamed symbols for
the control, and the normal module rebuilt identically afterward. The image,
P objects and frozen1x10s stats-on workload were unchanged.

| treatment / app | eBPF ns/call, in run order | native ns/call, in run order |
|---|---|---|
| P3 / tetragon | 1374.3 / 1147.7 / 1111.2 | 1242.1 / 856.9 / 1647.4 |
| P3 / otel | 3998.5 / 3683.5 / 3612.3 | 3720.0 / 3907.9 / 3479.6 |
| generic / tetragon | 1839.4 / 1616.7 / 3136.0 | 2359.5 / 4095.6 / 1085.1 |
| generic / otel | 3847.0 / 3492.8 / 3756.9 | 3897.9 / 3938.4 / 4635.3 |

Tetragon generic_tracepoint remains slow with the kernel helper: native
5446.9/9465.8/2428.7 ns/call. It accounts for98.53%/98.94%/96.99% of retained
native BPF time. The generic control does not remove the slow tracepoint,
and disabling P3 does not consistently improve either app. This is evidence
against assigning the large observed regression to the specialized hash call.
The checks ran sequentially, their eBPF phases and realized call mix vary,
and there is substantial temporal spread. They establish neither a precise
causal speedup nor that the two slow programs have been fixed.

The workload-only profile agrees on the localization: Tetragon P3 hash is
0.254% of guest-kernel cycle samples versus83.15% in the resilient BPF lock
slow path (baseline75.66%). Without real guest callchain frames the lock
caller cannot be named. The Tetragon/Tracee memset weights and conditional
bounds are in ../memset-calls-20261126/README.md. The raw PMU files remain in
their committed archives; the uncompressed copies were removed only after
the coordinator-requested size/SHA256 comparison passed for each member.

The operator retained the C hash mechanism and replaced the app census by
the general1..512 rule. No per-program loader selection or extra production
configuration was added. The historical generic-control recipe is an
experimental control, not an installed selection policy. First complete
the512-size image and six-app functional check; then continue the common
header/flags/linker investigation for generic_tracepoint/native_tracer_entry.
Full timing remains frozen.
