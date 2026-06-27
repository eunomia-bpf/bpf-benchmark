# Diagnostics

- Current base: phase3 attempt 1 `20260626-125641-phase3-tracepoint-sparse-active-clear`, mean `393050`.
- Candidate change: add `EVENT_CONFIG_FLAG_NO_SELECTORS`, set it from `tp.selectors.Buffer()` in the tracepoint loader path, and use it in `generic_tracepoint_curr_no_selector_filter()` instead of looking up `filter_map` on every no-selector tracepoint event.
- Object inspected: `vendor/build/.tetragon-bpf/x86/objs/bpf_generic_tracepoint_v61.o`.
- Key section: `tracepoint/generic_tracepoint` size `0x66b8`.
- Key symbol sizes:
  - `generic_tracepoint_event`: `0x66b8`
  - `generic_tracepoint_process_event`: `0x67c8`
  - `generic_tracepoint_filter`: `0x72d0`
- Size delta: `generic_tracepoint_event` is `+0x8` bytes versus phase3 attempt 1 (`0x66b0`), but the hot no-selector path removes a per-event map lookup.
- Disk check before run: `/` had about `111G` available; no Docker image cleanup was needed.
- Disk check after run: `/` had about `110G` available; no Docker image cleanup was needed.
