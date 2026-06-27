# Diagnostics

Candidate change:

- In `get_stack_delta()`, add a `numDeltas == 1` path that reuses the first `bpf_map_lookup_elem(inner_map, &idx)` result when `page_offset >= delta->addrLow`.
- For `page_offset < delta->addrLow`, fall back to the previous-page lookup path by clearing `delta` and letting the existing `idx--` lookup run.

Instruction-count comparison from the OTEL eBPF build logs:

| Program | Clean | Patched | Delta |
| --- | ---: | ---: | ---: |
| `kprobe/unwind_native` | 6972 | 6987 | +15 |
| `perf_event/unwind_native` | 6972 | 6987 | +15 |
| `perf_event/native_tracer_entry` | 1322 | 1322 | 0 |
| total `tracer.ebpf.amd64` | 123833 | 123863 | +30 |

Interpretation:

- The patch directly targets a repeated map lookup in the per-frame native unwind path, but only helps when stack-delta pages with exactly one delta are common.
- The formal workload did not improve: mean `language_ops_total=19575112832`, `-0.35%` vs clean baseline.
- This suggests the workload either does not spend enough time in the single-delta-page reuse case or the added branch/code size offsets the saved lookup.
- Do not stack this patch. The remaining OTEL attempt should use stronger evidence from actual hot language paths or switch back to an app with proven positive headroom.

