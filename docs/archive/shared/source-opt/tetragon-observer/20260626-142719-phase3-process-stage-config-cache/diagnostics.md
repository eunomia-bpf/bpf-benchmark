# Diagnostics

- Current base: phase3 attempt 2 `20260626-132055-phase3-tracepoint-no-selector-config-flag`, mean `400249`.
- Candidate change: pass `struct msg_generic_kprobe *e` and `struct event_config *config` from `generic_process_event()` into `generic_read_arg()`, eliminating repeated `process_call_heap` and `config_map` lookups from the per-argument helper.
- Object inspected: `vendor/build/.tetragon-bpf/x86/objs/bpf_generic_tracepoint_v61.o`.
- Key section: `tracepoint/generic_tracepoint` size `0x66b8`.
- Key symbol sizes:
  - `generic_tracepoint_event`: `0x66b8`
  - `generic_tracepoint_process_event`: `0x66d0`
  - `generic_tracepoint_filter`: `0x72d0`
- Size delta: `generic_tracepoint_process_event` shrank by `0xf8` bytes versus phase3 attempt 2 (`0x67c8` to `0x66d0`), while `generic_tracepoint_event` stayed unchanged at `0x66b8`.
- Performance observation: the smaller process-stage program still regressed by `0.53%` versus attempt 2, so this change is not selected for stacking.
- Disk check before run: `/` had about `109G` available; no Docker image cleanup was needed.
- Disk check after run: `/` had about `108G` available. Docker reported images `63.26GB`, containers `29.73GB`, and build cache `85.66GB`; no cleanup was needed.
