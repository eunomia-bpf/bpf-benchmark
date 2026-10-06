# bcc/set source-opt attempt: phase3-syscount-task-storage-start

- Time: 2026-06-26 07:52
- App: `bcc/set`
- Status: accepted-for-analysis; selected as current bcc/set phase3 base
- Source files:
  - `vendor/repos/bcc/libbpf-tools/capable.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/syscount.bpf.c`
  - `vendor/repos/bcc/libbpf-tools/tcpconnect.bpf.c`
- Hypothesis: stack the phase3 attempt 2 base and replace `syscount`'s
  private latency `start` hash map with task local storage. This may reduce
  per-syscall timestamp handoff cost without changing user-visible maps,
  payloads, filters, or output formatting.
- Expected hot path: `stress_ng_bcc_hook_hot` runs `syscount -L -i 1`, so every
  syscall enter stores a timestamp and every syscall exit reads it.
- Correctness argument: `start` is only an internal BPF-side latency scratch
  map; user space reads `data`, not `start`. The patch keeps the same `data`
  map ABI and latency/count update semantics.
- Build command: `make -C vendor bcc-x86`
- Run command: see `run-command.sh`
- Result path: `corpus/results/x86_kvm_corpus_20260626_150154_266900`
- Performance: `stress_ng_sum_bogo_ops_s` mean=794393, samples
  `794399, 794426, 794353`; +11.81% vs clean baseline and +8.36% vs bcc/set
  phase3 attempt 2.
- Follow-up: stackable. Attempt 5 should preserve the task-storage `syscount`
  base and look for another independent hot-path reduction; avoid reverting to
  hash-based `start`.
