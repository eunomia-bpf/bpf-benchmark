# Diagnostics

## Selection

The candidate targeted `collect_trace()` in `support/ebpf/tracemgmt.h`.
The goal was to move `bpf_get_current_comm()` and `bpf_get_stackid()` below the
unmapped-PID check so a metadata-only `report_pid()` path could return before
running those helpers.

## Instruction counts

Counts are from the built `tracer.ebpf.amd64` object around the candidate patch.

| Build | Total insns | `perf_event/native_tracer_entry` | `uprobe/custom__generic` | `kprobe/finish_task_switch` | `uprobe/generic` |
| --- | ---: | ---: | ---: | ---: | ---: |
| clean/current-before | 123833 | 1322 | 1253 | 1267 | 1231 |
| rejected duplicated-helper draft | 124210 | 1472 | 1329 | 1344 | 1305 |
| accepted formal patch | 123792 | 1238 | 1265 | 1285 | 1244 |

The first draft duplicated helper calls across branches and increased code size,
so it was rejected before a formal run. The formal patch reduced
`native_tracer_entry` by 84 instructions and total object instructions by 41,
but the workload result was `-0.83%` versus baseline.

## Artifacts

- `diagnostic-build-duplicated-helpers.log`
- `ebpf-build.log`
- `native_tracer_entry.objdump.txt`
- `unwind_stop.objdump.txt`

