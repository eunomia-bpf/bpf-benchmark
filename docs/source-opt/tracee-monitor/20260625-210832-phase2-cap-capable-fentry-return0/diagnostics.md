# Diagnostics

Patch shape:

- Converts only `trace_cap_capable` from `SEC("kprobe/cap_capable")` with
  `BPF_KPROBE` argument extraction to `SEC("fentry/cap_capable")` with typed
  `BPF_PROG` arguments.
- Discards the `events_perf_submit()` helper return value and explicitly
  returns 0, satisfying fentry/tracing verifier requirements.
- Leaves filtering, `CAP_OPT_NOAUDIT`, payload layout, and submit behavior
  unchanged.

Diffstat:

```text
pkg/ebpf/c/tracee.bpf.c | 11 +++++------
1 file changed, 5 insertions(+), 6 deletions(-)
```

Build artifact checked:

- `vendor/build/.tracee-build/x86/dist/tracee.bpf.o`
- `vendor/build/x86/tracee/bin/tracee`

Object diagnostics after build:

| Object | Program section / symbol | Size |
| --- | --- | ---: |
| `tracee.bpf.o` | `fentry/cap_capable` / `trace_cap_capable` | `0x3520` |

Expected performance mechanism:

- kprobe dispatch is replaced with fentry dispatch for a workload-hot
  capability hook.
- The program body remains large; expected gain is from lower attach/dispatch
  overhead, not from reducing Tracee's generic event setup.
