# Diagnostics

- Candidate base: first-round `20260625-111613-lazy-ns-cap-skip-empty-namespace-loop`.
- New changes:
  - Skip `get_ctx_ul()` for tracepoint args whose configured type is `nop_ty`.
  - Load selector namespace/capability state lazily in `selector_process_filter()`.
  - For capability filters, load namespace only when `caps->ns != 0`.
- Policy basis: `runner/assets/tetragon_policies/raw_syscalls.yaml` configures only one `syscall64` argument for `raw_syscalls/sys_enter`; remaining tracepoint args are unused.
- Build sanity: local Tetragon BPF build completed with clang-18 before the formal run.
- Patched object symbol observations from the formal artifact:
  - `bpf_generic_tracepoint_v511.o` `generic_tracepoint_event`: `0x6250`.
  - `bpf_generic_tracepoint_v53.o` `generic_tracepoint_event`: `0x6250`.
  - `bpf_generic_tracepoint_v61.o` `generic_tracepoint_event`: `0x6250`.
  - `bpf_generic_kprobe_v511.o` `generic_kprobe_event`: `0x0650`.
  - `bpf_generic_rawtp_v511.o` `generic_rawtp_event`: `0x0650`.
- Comparison note: prior recorded first-round clean/base sizes were `generic_tracepoint_event=0x6878` for v511/v53/v61 and `generic_kprobe_event`/`generic_rawtp_event` around `0x0d30`, so this patch reduced the hot entry code rather than expanding it.
- Result: correctness passed and performance improved slightly over the first-round Tetragon best, but not enough to reach 10%.
