# Diagnostics

## Base

- Base source: clean OTEL source. Previous OTEL attempts had no positive throughput signal, so none were stacked.
- Candidate: add `OPTI_UNLIKELY(x)` as `__builtin_expect(!!(x), 0)` and apply it to native unwinder / trace collection error branches.

## Instruction Counts

`tracer.ebpf.amd64` candidate build:

| Program | Candidate | Clean after restore | Delta |
| --- | ---: | ---: | ---: |
| `kprobe/unwind_native` | 6960 | 6972 | -12 |
| `perf_event/unwind_native` | 6960 | 6972 | -12 |
| `perf_event/native_tracer_entry` | 1326 | 1322 | +4 |
| `uprobe/custom__generic` | 1278 | 1253 | +25 |
| `kprobe/finish_task_switch` | 1294 | 1267 | +27 |
| `uprobe/generic` | 1256 | 1231 | +25 |
| Total | 123898 | 123833 | +65 |

## Interpretation

The native unwinder body shrank slightly, but global artifact size grew and the workload regressed. This suggests the workload bottleneck is not solved by cold-branch hinting in native unwind error paths. The next attempt should target real helper/map/event work or a narrower high-frequency path instead of more branch hints.
