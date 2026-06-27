# Diagnostics

- Current base: phase3 attempt 2 `20260626-132055-phase3-tracepoint-no-selector-config-flag`, mean `400249`.
- Candidate change: remove the duplicate `common.op` assignment after `generic_process_init()` and defer `sel.pass=false` until after the no-selector fast path fails.
- Object inspected: `vendor/build/.tetragon-bpf/x86/objs/bpf_generic_tracepoint_v61.o`.
- Key section: `tracepoint/generic_tracepoint` size `0x65f8`.
- Key symbol sizes:
  - `generic_tracepoint_event`: `0x65f8`
  - `generic_tracepoint_process_event`: `0x67c8`
  - `generic_tracepoint_filter`: `0x72d0`
- Size delta: `generic_tracepoint_event` shrank by `0xc0` bytes versus phase3 attempt 2 (`0x66b8`).
- Performance observation: despite the smaller object and fewer hot-path stores, workload mean regressed by `1.92%` versus attempt 2, so this change is not selected for stacking.
- Disk check before run: `/` had about `110G` available; no Docker image cleanup was needed.
- Disk check after run: `/` had about `109G` available; no Docker image cleanup was needed.
