# Timing Fix Report (2026-03-19)

## Scope

Task: fix two timing-accuracy issues in the benchmark runners without changing JSON output or CLI shape.

Files changed:

- `micro/runner/src/llvmbpf_runner.cpp`
- `micro/runner/src/kernel_runner.cpp`

Kernel code was inspected but not modified.

## Fix 1: `run-llvmbpf` batch timing

### Problem

`run-llvmbpf` measured each `vm.exec()` call separately inside the repeat loop and summed the per-call deltas. For ultra-short programs, the `rdtsc` / loop overhead dominated the measurement.

### Change

The runner now times the entire repeat batch once:

- take one timer start before the repeat loop
- execute `vm.exec()` `repeat` times
- take one timer end after the loop
- compute `exec_ns` and `exec_cycles` as per-execution averages by dividing the batch total by `repeat`

Result capture semantics are unchanged:

- `retval` still comes from the last `vm.exec()`
- `result` still comes from the last execution's output buffer or result map
- JSON fields are unchanged

## Fix 2: context-mode kernel repeat

### Problem

`run-kernel` forced `io_mode=context` to `repeat=0/1`, which disabled kernel-side batching even when the kernel `test_run` implementation supported it.

### Kernel support check

Inspection of `vendor/linux-framework/net/bpf/test_run.c` shows:

- generic `bpf_test_run()` supports `repeat > 1`
- `bpf_prog_test_run_sk_lookup()` supports `repeat > 1`
- `bpf_prog_test_run_nf()` supports `repeat > 1`
- `bpf_prog_test_run_raw_tp()` rejects non-zero `repeat`
- `bpf_prog_test_run_syscall()` rejects non-zero `repeat`
- tracing / struct-ops test-run paths do not use `repeat` for the timed execution path

### Change

`run-kernel` now enables kernel repeat for context-mode programs only when the vendored kernel path actually supports batching:

- enabled for `BPF_PROG_TYPE_SK_LOOKUP`
- enabled for `BPF_PROG_TYPE_NETFILTER`
- left at `repeat=0` for other context-mode program types

This preserves compatibility on unsupported paths while restoring kernel-side batching on the supported context-mode cases.

## Verification

### Build

Command:

```bash
make -C micro micro_exec
```

Result: success.

### Smoke

Command:

```bash
make vm-micro-smoke
```

Result: pass.

Observed VM smoke medians:

- `simple`: `kernel 10 ns`, `kernel-recompile 12 ns`
- `load_byte_recompose`: `kernel 189 ns`, `kernel-recompile 234 ns`
- `cmov_dense`: `kernel 29 ns`, `kernel-recompile 23 ns`

### Direct timing comparison: `simple` llvmbpf before vs after

Command shape:

```bash
micro_exec run-llvmbpf \
  --program micro/programs/simple.bpf.o \
  --io-mode staged \
  --input-size 64 \
  --repeat 10000
```

Before patch (`HEAD` binary rebuilt in a temporary directory):

- `exec_ns: 11`
- `wall_exec_ns: 25`

After patch:

- `exec_ns: 4`
- `wall_exec_ns: 5`

Patched runner repeatability check, 5 consecutive host runs:

```text
[4, 4, 4, 4, 4]
```

Direct VM kernel comparison for the same benchmark and repeat count:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --rwdir ... -- \
  bash -lc 'cd ... && sudo -n micro/build/runner/micro_exec run-kernel \
    --program micro/programs/simple.bpf.o \
    --program-name simple_xdp \
    --io-mode staged \
    --input-size 64 \
    --repeat 10000'
```

Observed VM kernel result:

- `exec_ns: 4`

So the patched llvmbpf timing for this ultra-short benchmark moved from `11 ns` to `4 ns`, matching the corresponding high-repeat kernel sample.

### Direct context-mode repeat comparison: `sk_lookup`

Test program:

- object: `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o`
- program: `padding_ctx_access_bpf_sk_lookup`
- mode: `--io-mode context`
- input: synthetic `struct bpf_sk_lookup`

Command shape:

```bash
micro_exec run-kernel \
  --program corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_ctx.bpf.o \
  --program-name padding_ctx_access_bpf_sk_lookup \
  --io-mode context \
  --memory <ctx.bin> \
  --input-size 72 \
  --repeat 10000
```

Before patch (`HEAD` binary rebuilt in a temporary directory):

- `exec_ns: 402-405`
- `wall_exec_ns: 67406-168761`
- `prog_run_wall_ns: 67486-168865`

Interpretation: the old runner forced the context path to a single kernel test-run, so the sample was dominated by one syscall-sized measurement even though `--repeat 10000` was requested.

After patch:

- `exec_ns: 2`
- `wall_exec_ns: 3`
- `prog_run_wall_ns: 31249`

Interpretation: the patched runner preserved the requested repeat on the kernel `sk_lookup` path, and the total syscall wall time now reflects one batched 10k-run sample instead of one forced single-run sample.

## Outcome

The requested fixes are implemented:

- llvmbpf timing now uses one batch timer per measured sample
- supported context-mode kernel paths now keep kernel-side repeat batching
- JSON output format is unchanged
- CLI is unchanged
- no kernel code was modified
