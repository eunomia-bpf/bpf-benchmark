# Kernel Interface Simplify 2026-03-19

## Scope

This round only simplified the recompile interface surface. It did not change the recompile feature set or relax the safety model.

## Kernel Changes

### 1. Removed `recompile_count`

- Deleted `recompile_count` from:
  - `vendor/linux-framework/include/uapi/linux/bpf.h`
  - `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
  - `vendor/linux-framework/include/linux/bpf.h`
- Removed the export in `vendor/linux-framework/kernel/bpf/syscall.c`
- Removed the increment path in `vendor/linux-framework/kernel/bpf/jit_directives.c`
- Removed bpftool display in `vendor/linux-framework/tools/bpf/bpftool/prog.c`

### 2. Removed `BPF_F_RECOMPILE_ROLLBACK`

- Deleted the UAPI flag definition from `vendor/linux-framework/include/uapi/linux/bpf.h`
- Deleted the matching tools-copy flag from `vendor/linux-framework/tools/include/uapi/linux/bpf.h`
- `BPF_PROG_JIT_RECOMPILE` now requires `attr.jit_recompile.flags == 0`
- On recompile failure, the kernel now always restores both:
  - the pre-recompile JIT image
  - the pre-recompile policy pointer

### 3. Simplified recompile `log_level` semantics to bool

- Kept the wire field width as `__u32` for layout compatibility, but documented it as:
  - `0`: disabled
  - non-zero: enabled
- Removed the internal multi-level state from `struct bpf_jit_recompile_log`
- The logging path now only distinguishes presence vs absence of logging
- Updated the kernel selftest helper to pass `bool log_enabled`

## DSL / Dead-Code Check

### Kernel side

- Re-checked the old “2-insn COND_SELECT dead path” concern from the earlier deep review.
- Current tree still accepts `site_len == 2` in `bpf_jit_parse_cond_select_shape()`, so that x86 emitter path is still reachable and is not dead after the DSL deletions.
- In the touched recompile interface paths, no additional DSL-removal leftovers were found beyond:
  - `recompile_count`
  - `BPF_F_RECOMPILE_ROLLBACK`
  - the unused multi-level recompile log state

### User-space `_driver_impl_*` files

Cross-check used `rg` on each `_driver_impl` filename/module stem, excluding `vendor/`, `docs/tmp/`, and archived result trees.

- No `_driver_impl_*.py` file was found to be orphaned.
- Active callers observed:
  - `micro/_driver_impl_run_micro.py`: `micro/driver.py`
  - `micro/_driver_impl_run_rigorous.py`: `micro/driver.py`
  - `micro/_driver_impl_run_rigorous_framework_vm.py`: `micro/driver.py`
  - `corpus/_driver_impl_run_corpus_perf.py`: `micro/driver.py`, `corpus/run_corpus_runnability.py`, `corpus/_driver_impl_run_corpus_tracing_exec.py`
  - `corpus/_driver_impl_run_corpus_tracing.py`: `micro/driver.py`, `corpus/run_corpus_runnability.py`, `corpus/_driver_impl_run_corpus_tracing_exec.py`
  - `corpus/_driver_impl_run_corpus_tracing_exec.py`: `micro/driver.py`, `corpus/_driver_impl_run_tracing_corpus_vm.py`
  - `corpus/_driver_impl_run_tracing_corpus_vm.py`: `micro/driver.py`
  - `corpus/_driver_impl_run_corpus_v5_framework.py`: `micro/driver.py`
  - `corpus/_driver_impl_run_corpus_v5_vm_batch.py`: `micro/driver.py`, `corpus/auto_tune.py`
  - `corpus/_driver_impl_run_macro_corpus.py`: `micro/driver.py`
  - `corpus/_driver_impl_run_production_corpus_v5_framework.py`: `micro/driver.py`

### `micro/orchestrator/` dead code

Removed two actually orphaned exported helpers:

- `micro/orchestrator/commands.py`
  - removed `maybe_prepend_taskset()`
- `micro/orchestrator/environment.py`
  - removed `resolve_path()`

Reason:

- repo-wide `rg` found no callers outside their own definition and `__all__`
- `vm-micro-smoke` still passed after removal

## Validation

Executed with the repo virtualenv activated via:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
```

### 1. Kernel build

```bash
cd vendor/linux-framework && make -j$(nproc) bzImage
```

Result:

- PASS
- built `arch/x86/boot/bzImage`

### 2. VM selftest

```bash
cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest
```

Result:

- PASS
- `PASS all 19 test(s)`
- Count changed from the earlier 20-test version because the two `recompile_count` assertions were removed/reworked with the interface deletion

### 3. VM micro smoke

```bash
cd /home/yunwei37/workspace/bpf-benchmark && make vm-micro-smoke
```

Result:

- PASS
- exercised both `kernel` and `kernel-recompile` runtimes
- output written to `micro/results/dev/vm_micro_smoke.json`

### 4. Scanner tests

- Not run
- Reason: no scanner source or tests changed in this round

