# tetragon/observer source-opt attempt: phase2-tracepoint-nop-arg-fastpath

- Time: 2026-06-26 00:43:51
- App: `tetragon/observer`
- Status: accepted-for-analysis
- Source files:
  - `vendor/repos/tetragon/bpf/process/generic_calls.h`
  - `vendor/repos/tetragon/bpf/process/bpf_generic_tracepoint.c`
  - `vendor/repos/tetragon/bpf/process/pfilter.h`
- Hypothesis: the first-round best came from lazily materializing selector namespace/capability state. This attempt keeps that base, adds conditional namespace reads for capability selectors, and skips tracepoint `nop_ty` argument extraction so the raw-syscalls policy does not parse unused tracepoint args on every syscall.
- Expected hot path: `generic_tracepoint_event()` for `raw_syscalls/sys_enter`, plus `generic_start_process_filter()` / `selector_process_filter()` for kprobe and rawtp policies.
- Correctness argument: `nop_ty` previously returned 0 through `get_ctx_ul()`, so returning 0 before offset masking is equivalent. Namespace state is read before namespace consumers, and capability selectors read namespace only when their `ns` field requires it.
- Build command: included in `build.log`.
- Run command: included in `run-command.sh`.
- Result path: `corpus/results/x86_kvm_corpus_20260626_075102_935489`
- Performance: stress_ng_sum_bogo_ops_s samples `399794, 385719, 387940`; mean `391151`; baseline mean `358681`; `+9.05%` vs baseline; `+0.41%` vs first-round best.
- Follow-up: this is the current Tetragon best but still below the 10% target. Continue phase2 with narrower raw tracepoint/filter reductions rather than re-adding the sparse selector clear or `filter_args` patches that were negative alone.
