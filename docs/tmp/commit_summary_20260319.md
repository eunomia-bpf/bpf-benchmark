# Commit Summary 2026-03-19

## Scope

- Main repo branch: `main`
- Main repo upstream: `origin/main`
- Kernel repo branch: `vendor/linux-framework` on `jit-directive-v5`
- Kernel push target: `origin/jit-directive-v5`
- Kernel commit created today: `9a0b29031`
- Kernel push result: `8c70a729d -> 9a0b29031`

## Kernel Diff Snapshot

- Command: `git -C vendor/linux-framework diff master --stat`
- Files changed vs `master`: 13
- Total delta vs `master`: `kernel: +5860/-193 = net +5667`

Kernel files grouped into the kernel commit:

- `arch/x86/net/bpf_jit_comp.c`
- `include/linux/bpf.h`
- `include/linux/bpf_jit_directives.h`
- `include/linux/filter.h`
- `include/trace/events/bpf.h`
- `include/uapi/linux/bpf.h`
- `kernel/bpf/core.c`
- `kernel/bpf/jit_directives.c`

Commit message:

- `bpf: Phase A-C kernel fixes + DSL removal + cleanup`

Covered themes:

- bug fixes
- perf optimization
- validator/emitter unification
- tracepoint removal
- stock choice removal
- DSL removal

## Main Repo Commit Groups

1. `Remove DSL from scanner and simplify blob format`
   - `scanner/**`
   - `tests/kernel/test_recompile.c`
   - `vendor/linux-framework` gitlink update
2. `Clean up userspace dead code and archive files`
   - `config/ablation/**`
   - `corpus/**` wrapper/archive/dead-code cleanup
   - `e2e/**` wrapper/dead-code cleanup
   - `micro/**` archive/dead-code cleanup
3. `Add kernel review and fix reports`
   - `docs/kernel-jit-optimization-plan.md`
   - `docs/tmp/*_20260319.md`
   - `docs/tmp/*_20260319.json`
   - this summary file

Explicitly excluded from commits:

- untracked `vendor/libbpf`
