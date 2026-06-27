# Diagnostics

## Change

Batch successful PHP frame metric updates inside `walk_php_stack()`:

- Count `metricID_UnwindPHPFrames` locally as `php_frames`.
- Preserve immediate `increment_metric()` calls for error metrics.
- Write the successful-frame metric once at `finish`.
- Keep `unwinder_mark_done()` behavior for end/error cases.

This was selected after the previous OTEL run showed PHP as the largest mixed-workload contributor.

## Static build signal

Before restore, optimized `tracer.ebpf.amd64` instruction counts:

| Program | Clean | Optimized | Delta |
| --- | ---: | ---: | ---: |
| `kprobe/unwind_php` | 6899 | 3358 | -3541 |
| `perf_event/unwind_php` | 6899 | 3358 | -3541 |
| total | 123833 | 116751 | -7082 |

After `patch -R` and clean eBPF rebuild, counts returned to:

- `kprobe/unwind_php`: 6899
- `perf_event/unwind_php`: 6899
- total: 123833

## Runtime result

Correctness passed, but `language_ops_total` mean was 19508075671 vs clean baseline 19644780415 (`-0.70%`). Static instruction reduction did not translate into workload throughput improvement, likely because PHP unwinder instruction count was not the dominant limiter for the app-level mixed workload.

Decision: rejected-no-signal; do not stack.

