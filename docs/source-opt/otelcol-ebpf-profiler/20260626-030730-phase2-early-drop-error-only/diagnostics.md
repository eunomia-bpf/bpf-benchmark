# Diagnostics

## Selection

The candidate targeted `unwind_stop()` in `support/ebpf/interpreter_dispatcher.ebpf.c`.
The old path pushed an error frame and ran APM/Go-label logic before dropping
single-error traces when `filter_error_frames` was enabled. The patch moved the
empty-stack error-only drop ahead of those operations.

## Instruction counts

Counts are from `tracer.ebpf.amd64`.

| Build | Total insns | `kprobe/unwind_stop` | `perf_event/unwind_stop` | `perf_event/native_tracer_entry` |
| --- | ---: | ---: | ---: | ---: |
| clean/current-before | 123833 | 1631 | 1631 | 1322 |
| formal patch | 123833 | 1631 | 1631 | 1322 |
| restored clean | 123833 | 1631 | 1631 | 1322 |

The patch did not change aggregate instruction count; it only changed which
work runs before the existing error-only drop. The formal result was `-0.32%`
versus baseline, so this path is not a useful source-opt direction for OTEL.

