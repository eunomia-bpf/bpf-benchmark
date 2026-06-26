# Diagnostics

Patch shape:

- Converts only `trace_cap_capable` from `SEC("kprobe/cap_capable")` with
  `BPF_KPROBE` argument extraction to `SEC("fentry/cap_capable")` with typed
  `BPF_PROG` arguments.
- Leaves filtering, `CAP_OPT_NOAUDIT`, payload layout, and submit behavior
  unchanged.

Diffstat:

```text
pkg/ebpf/c/tracee.bpf.c | 8 +++-----
1 file changed, 3 insertions(+), 5 deletions(-)
```

Build artifact checked:

- `vendor/build/.tracee-build/x86/dist/tracee.bpf.o`
- `vendor/build/x86/tracee/bin/tracee`

Object diagnostics after build:

| Object | Program section / symbol | Size |
| --- | --- | ---: |
| `tracee.bpf.o` | `fentry/cap_capable` / `trace_cap_capable` | `0x34e0` |

Expected performance mechanism:

- kprobe dispatch is replaced with fentry dispatch for a workload-hot
  capability hook.
- The BPF program body remains large because Tracee's generic event setup is
  unchanged; the expected win comes from lower attach/dispatch overhead rather
  than instruction-count reduction.

Observed result:

- No performance data. The modified object failed to load.
- Verifier failure: `At program exit the register R0 has unknown scalar value
  should have been in [0, 0]`.
- Root cause: fentry/tracing programs require `R0=0` on exit, while the original
  kprobe-style function returned the `events_perf_submit()` helper result.
