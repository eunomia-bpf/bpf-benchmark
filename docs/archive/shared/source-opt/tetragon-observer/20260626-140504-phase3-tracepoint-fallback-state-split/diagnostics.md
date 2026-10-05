# Diagnostics

- Current base: phase3 attempt 2 `20260626-132055-phase3-tracepoint-no-selector-config-flag`, mean `400249`.
- Candidate change: split the tracepoint entry state initialization into no-selector fast-path-required fields and selector-fallback-only fields.
- Object inspected: `vendor/build/.tetragon-bpf/x86/objs/bpf_generic_tracepoint_v61.o`.
- Key section: `tracepoint/generic_tracepoint` size `0x6600`.
- Key symbol sizes:
  - `generic_tracepoint_event`: `0x6600`
  - `generic_tracepoint_process_event`: `0x67c8`
  - `generic_tracepoint_filter`: `0x72d0`
- Size delta: `generic_tracepoint_event` shrank by `0xb8` bytes versus phase3 attempt 2 (`0x66b8`) but is `0x8` bytes larger than phase3 attempt 3 (`0x65f8`).
- Performance observation: despite the smaller tracepoint entry program, workload mean regressed by `3.25%` versus attempt 2, so this change is not selected for stacking.
- Disk check before run: `/` had about `109G` available; no Docker image cleanup was needed.
- Disk check after run: `/` had about `108G` available. Docker reported images `62.18GB`, containers `29.73GB`, and build cache `84.6GB`; no cleanup was needed.
