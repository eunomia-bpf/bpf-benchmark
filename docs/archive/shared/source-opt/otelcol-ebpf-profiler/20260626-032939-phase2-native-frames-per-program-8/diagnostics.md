# Diagnostics

Candidate change:

```c
-#define NATIVE_FRAMES_PER_PROGRAM 4
+#define NATIVE_FRAMES_PER_PROGRAM 8
```

Instruction-count comparison from the OTEL eBPF build logs:

| Program | Clean | Patched | Delta |
| --- | ---: | ---: | ---: |
| `kprobe/unwind_native` | 6972 | 13433 | +6461 |
| `perf_event/unwind_native` | 6972 | 13433 | +6461 |
| `perf_event/native_tracer_entry` | 1322 | 1322 | 0 |
| total `tracer.ebpf.amd64` | 123833 | 136755 | +12922 |

Interpretation:

- The patch trades fewer tail-call iterations for a much larger native unwinder body.
- The formal workload did not improve: mean `language_ops_total=19526940261`, `-0.60%` vs clean baseline.
- This suggests the bottleneck is not the default 4-frame tail-call chunking under this workload, or the larger instruction footprint offsets any tail-call savings.
- Do not stack this patch. Next OTEL attempts should avoid larger unroll/body-size changes and look at native unwind map lookup/data preparation or profiler metadata paths with stronger hot-path evidence.

