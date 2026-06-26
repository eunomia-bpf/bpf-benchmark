# bcc/set source-opt attempt: phase2-syscount-latency-specialized-exit

- Time: 2026-06-25 20:11
- App: `bcc/set`
- Status: accepted-for-analysis; not selected as next stacked base
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.c`
- Hypothesis: keep the phase2 attempt 3 raw-tracepoint base and specialize
  `syscount -L` by attaching a dedicated `sys_exit_latency` program. This
  preserves normal syscount count mode while removing runtime
  `measure_latency` branches from the hot latency exit path used by bcc/set.
- Expected hot path: `stress_ng_bcc_hook_hot` runs many syscalls and bcc/set
  starts `syscount -L -i 1`, so every syscall exit hits the latency-mode path.
- Correctness argument: non-latency mode still attaches `sys_exit`; latency mode
  attaches `sys_exit_latency` plus `sys_enter`. Both exit programs target
  `raw_tracepoint/sys_exit` and write the same `data` map schema. User-visible
  syscount output remains unchanged.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_031853_909472`
- Performance: `stress_ng_sum_bogo_ops_s` mean=715349, samples
  `713487, 715830, 716731`; +0.69% vs clean baseline but -1.28% vs
  phase2 attempt 3.
- Follow-up: do not stack this patch. It loaded correctly, but the specialized
  latency exit program did not improve over the raw-tracepoint base, so the next
  attempt should return to phase2 attempt 3 and target a broader hot path.
