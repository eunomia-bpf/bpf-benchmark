# Diagnostics

- Candidate base: phase2 attempt 1, `20260626-004351-phase2-tracepoint-nop-arg-fastpath`.
- New change:
  - In `filter_args()`, return accept immediately when `!e->sel.active[SELECTORS_ACTIVE]`.
  - Only active-selector events perform `map_lookup_elem(&filter_map, &e->idx)` before arg-filter evaluation.
- Policy basis: `runner/assets/tetragon_policies/raw_syscalls.yaml` has no configured selectors, so the raw-syscalls hot path should take the no-selector accept branch in the args phase.
- Build sanity: local Tetragon BPF build completed with clang-18 before the formal run.
- Patched object symbol observations before the formal run:
  - `bpf_generic_tracepoint_v511.o` `generic_tracepoint_event`: `0x6250`.
  - `bpf_generic_tracepoint_v511.o` `generic_tracepoint_arg`: `0x77b8`.
  - `bpf_generic_tracepoint_v53.o` `generic_tracepoint_event`: `0x6250`.
  - `bpf_generic_tracepoint_v53.o` `generic_tracepoint_arg`: `0x68b8`.
  - `bpf_generic_tracepoint_v61.o` `generic_tracepoint_event`: `0x6250`.
  - `bpf_generic_tracepoint_v61.o` `generic_tracepoint_arg`: `0x0b68`.
  - `bpf_generic_kprobe_v511.o` `generic_kprobe_event`: `0x0650`.
  - `bpf_generic_rawtp_v511.o` `generic_rawtp_event`: `0x0650`.
- Result: correctness passed, but workload throughput was `390359`, below phase2 attempt 1's `391151`. This patch is not selected for stacking.
