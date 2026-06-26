# Diagnostics

- Candidate base: phase2 attempt 1, `20260626-004351-phase2-tracepoint-nop-arg-fastpath`.
- New change:
  - Entry programs clear only `sel.active[SELECTORS_ACTIVE]`.
  - Selector-specific active bits `0..MAX_SELECTORS` are cleared inside `generic_process_filter()` only when `selectors > 0` and `sel->curr == 0`.
- Policy basis: events with no configured selectors do not need per-selector active state. Events with selectors still clear the same active slots before the first selector pass, while later tail-call selector passes keep accumulated state.
- Build sanity: local Tetragon BPF build completed with clang-18 before the formal run.
- Patched object symbol observations before the formal run:
  - `bpf_generic_tracepoint_v511.o` `generic_tracepoint_event`: `0x6238`.
  - `bpf_generic_tracepoint_v53.o` `generic_tracepoint_event`: `0x6238`.
  - `bpf_generic_tracepoint_v61.o` `generic_tracepoint_event`: `0x6238`.
  - `bpf_generic_kprobe_v511.o` `generic_kprobe_event`: `0x0638`.
  - `bpf_generic_rawtp_v511.o` `generic_rawtp_event`: `0x0638`.
- Comparison note: phase2 attempt 1 recorded `generic_tracepoint_event=0x6250` and `generic_kprobe_event`/`generic_rawtp_event=0x0650`, so this patch reduced those entry symbols by `0x18` bytes.
- Result: correctness passed, but workload throughput was `390959`, slightly below phase2 attempt 1's `391151`. The smaller entry code did not produce a measurable improvement, so this patch is not selected for stacking.
