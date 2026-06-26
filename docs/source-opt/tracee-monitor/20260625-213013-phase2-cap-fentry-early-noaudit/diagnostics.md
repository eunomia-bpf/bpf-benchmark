# Diagnostics

Patch shape:

- Converts `trace_cap_capable` from kprobe to fentry with typed arguments.
- Moves the existing `CAP_OPT_NOAUDIT` drop before `init_program_data()`.
- Discards the `events_perf_submit()` helper return value and explicitly
  returns 0 for fentry verifier requirements.

Diffstat:

```text
pkg/ebpf/c/tracee.bpf.c | 17 ++++++++---------
1 file changed, 8 insertions(+), 9 deletions(-)
```

Build artifact checked:

- `vendor/build/.tracee-build/x86/dist/tracee.bpf.o`
- `vendor/build/x86/tracee/bin/tracee`

Object diagnostics after build:

| Object | Program section / symbol | Size |
| --- | --- | ---: |
| `tracee.bpf.o` | `fentry/cap_capable` / `trace_cap_capable` | `0x34f0` |

Expected performance mechanism:

- Calls that Tracee already drops due to `CAP_OPT_NOAUDIT` avoid
  `init_program_data()` and `evaluate_scope_filters()`.
- This targets event setup work, which dominated after the attach-only fentry
  attempt improved throughput by only +0.32%.

Observed performance:

| Metric | Value |
| --- | ---: |
| sample1 | 453679.61 |
| sample2 | 454458.88 |
| sample3 | 453650.59 |
| mean | 453929.69 |
| vs clean baseline 460865.35 | -1.50% |
| vs fentry-return0 mean 462358.83 | -1.82% |

Conclusion: the moved no-audit filter is correctness-preserving but not useful
for this workload. The next tracee attempt should not keep this patch; instead,
choose a hotter event path using raw program counters or workload coverage.
