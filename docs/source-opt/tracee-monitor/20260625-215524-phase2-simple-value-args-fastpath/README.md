# tracee/monitor source-opt attempt: phase2-simple-value-args-fastpath

- Time: 2026-06-25 21:55
- App: `tracee/monitor`
- Status: rejected-correctness
- Source file:
  - `vendor/repos/tracee/pkg/ebpf/c/common/buffer.h`
- Hypothesis: most stress-ng Tracee syscall events carry only simple value
  arguments (`INT`, `UINT`, `LONG`, `ULONG`, `POINTER`). A simple-value fast
  path in `save_args_to_submit_buf()` avoids the generic type table, mask, and
  pointer/special-type switch on the hot syscall-exit submit path.
- Expected hot path: `stress_ng_tracee_syscall_hot` drives `set`, `kill`,
  `eventfd`, `sigfd`, and `prctl` syscall events through
  `sys_exit_submit() -> save_args_to_submit_buf()`.
- Correctness argument: the fast path preserves argument indexes, byte sizes,
  and `save_to_submit_buf()` calls for simple value types. Any event containing
  strings, sockaddr, timespec, bytes, arrays, or unknown types falls back to the
  original generic path.
- Build command: `make -C vendor tracee-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_050351_616916`
- Result: Tracee failed during BPF load. The verifier rejected
  `sys_exit_submit` with `invalid access to map value` while proving the
  fallback `type_size_table[type]` lookup after the new simple-value check.
- Follow-up: do not keep this patch. A future attempt should avoid global
  helper restructuring and use a narrower verifier-obvious syscall-id
  specialization if continuing on Tracee.
