# Same-Image Paired Measurement Report (2026-03-19)

## Goal

Change `run-kernel --recompile` to measure stock and recompiled execution on the **same loaded program image**, and update the corpus VM batch driver to consume the paired JSON from a single `run-kernel` invocation.

## Implemented Changes

### 1. `micro_exec run-kernel`

Modified `micro/runner/src/kernel_runner.cpp` so that any non-`compile-only` recompile request now follows this sequence:

1. load once
2. stock warmup pass
3. stock timed pass
4. `BPF_PROG_JIT_RECOMPILE`
5. recompile warmup pass
6. recompile timed pass

The JSON output now includes:

- `exec_ns`: recompiled timed pass
- `stock_exec_ns`: stock timed pass on the same loaded image

When no recompile path is requested, `run-kernel` keeps the original single-measurement behavior and does not emit `stock_exec_ns`.

Also removed the dead `run-kernel-paired` path from:

- `micro/runner/src/main.cpp`
- `micro/runner/src/common.cpp`
- `micro/runner/include/micro_exec.hpp`
- `micro/runner/src/kernel_runner.cpp`

### 2. Corpus VM batch driver

Modified `corpus/_driver_impl_run_corpus_v5_vm_batch.py` so the exec lane no longer launches:

- one stock `run-kernel`
- one recompile `run-kernel`

Instead it launches only the recompile lane once, then synthesizes `baseline_run` from `v5_run.sample.stock_exec_ns`.

This preserves the existing corpus record shape while eliminating the separate stock load that was causing false regressions for non-applied programs.

## Verification

### Required

1. `source /home/yunwei37/workspace/.venv/bin/activate && make -C micro micro_exec`
   - Passed

2. `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro-smoke`
   - Passed

3. Manual paired-output check:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --rwdir . -- \
  bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && \
    sudo -n micro/build/runner/micro_exec run-kernel \
      --program micro/programs/load_byte_recompose.bpf.o \
      --program-name load_byte_recompose_xdp \
      --io-mode staged \
      --memory micro/generated-inputs/load_byte_recompose.mem \
      --btf-custom-path vendor/linux-framework/vmlinux \
      --repeat 10 \
      --recompile-v5 \
      --recompile-all'
```

Observed JSON included:

- `exec_ns: 109`
- `stock_exec_ns: 121`
- `recompile.requested: true`
- `recompile.applied: true`

### Extra sanity check

Ran a one-target corpus VM batch sanity pass:

```bash
python3 corpus/_driver_impl_run_corpus_v5_vm_batch.py \
  --skip-build \
  --kernel-image vendor/linux-framework/arch/x86/boot/bzImage \
  --runner micro/build/runner/micro_exec \
  --scanner scanner/build/bpf-jit-scanner \
  --blind-apply \
  --max-programs 1 \
  --repeat 10 \
  --timeout 120 \
  --output-json docs/tmp/corpus_vm_batch_same_image_sanity_20260319.json \
  --output-md docs/tmp/corpus_vm_batch_same_image_sanity_20260319.md
```

Result:

- `summary.measured_pairs = 1`
- `programs[0].baseline_run.sample.exec_ns = 107`
- `programs[0].v5_run.sample.exec_ns = 127`
- `programs[0].v5_run.sample.stock_exec_ns = 107`
- `programs[0].record_error = null`

This confirms the corpus driver is now deriving the stock baseline from the paired recompile JSON instead of a second stock load.
