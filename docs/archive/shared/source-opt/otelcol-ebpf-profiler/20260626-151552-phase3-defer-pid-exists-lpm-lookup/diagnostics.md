# Diagnostics

## Base

- Base source: clean OTEL source. No previous OTEL attempt had a positive throughput signal, so none were stacked.
- Candidate: call `get_next_unwinder_after_native_frame()` before `pid_information_exists(pid)`, and only do the dummy PID LPM lookup when current-PC mapping resolution fails.

## Instruction Counts

`tracer.ebpf.amd64` candidate build:

| Program | Candidate | Clean after restore | Delta |
| --- | ---: | ---: | ---: |
| `uprobe/custom__generic` | 1249 | 1253 | -4 |
| `perf_event/native_tracer_entry` | 1318 | 1322 | -4 |
| `kprobe/finish_task_switch` | 1268 | 1267 | +1 |
| `uprobe/generic` | 1218 | 1231 | -13 |
| Total | 123813 | 123833 | -20 |

## Interpretation

The candidate reduces static instruction count and should remove one LPM lookup from successful known-PID samples. The workload still regressed by 0.83%, so the bottleneck is likely elsewhere or the extra error-path work/layout change offsets the expected map-lookup saving. Do not stack this patch.
