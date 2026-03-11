# Kernel JIT cleanup patches

Date: 2026-03-11

Vendor kernel commit: `8c66cec7cbab4c05858655f8ea15cbc5c222b4ce` (`bpf, x86: shrink common JIT memory encodings`)

## What changed

Implemented:

- `arch/x86/net/bpf_jit_comp.c:1586-1604`
  - `emit_insn_suffix()` now emits the zero-displacement ModR/M form for `off == 0` when the base encoding does not require an explicit displacement.
  - `rbp` / `r13` are still forced through the displacement form, since their base encoding cannot use plain `mod=00`.
  - Effect: common `[base + 0]` load/store forms lose one byte.

- `arch/x86/net/bpf_jit_comp.c:1856-1879`
  - Added a direct `mov qword ptr [base + off], imm32` fast path for `emit_store_stack_imm64()` when the 64-bit value is exactly sign-extended from 32 bits and non-zero.
  - Zero still uses the existing `xor reg, reg` plus store sequence, which is already shorter than a direct qword-imm store in this path.
  - Full 64-bit immediates still fall back to the existing register materialization path.

Considered but intentionally not changed:

- Prologue NOP window
  - The first `X86_PATCH_SIZE` bytes are the live text-poke slot used by `bpf_arch_text_poke()`.
  - The extra `nop3` keeps `X86_TAIL_CALL_OFFSET` fixed for tail-call entry jumps.
  - Changing either would break current patching/layout assumptions.

- `div/mod` save/restore cleanup
  - The emitter already avoids some moves when the destination is `rax` or `rdx`.
  - Further save/restore removal would require register liveness the x86 JIT does not currently track at this point.

- `movbe` endian fusion
  - Safe use would need a cross-instruction load+endian peephole, not just a local `BPF_END` change.
  - No conservative local implementation was obvious in this file.

## Build status

Kernel build command:

```bash
cd vendor/linux-framework && make -j$(nproc) bzImage
```

Result: success.

Tail of build output:

```text
OBJCOPY arch/x86/boot/vmlinux.bin
AS      arch/x86/boot/header.o
LD      arch/x86/boot/setup.elf
OBJCOPY arch/x86/boot/setup.bin
BUILD   arch/x86/boot/bzImage
Kernel: arch/x86/boot/bzImage is ready  (#14)
```

## VM verification

Smoke test image:

- patched image: `vendor/linux-framework/arch/x86/boot/bzImage`

Command used:

```bash
sudo env PATH=/home/yunwei37/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin \
  PYTHONPATH=/home/yunwei37/.local/lib/python3.12/site-packages \
  python3 -m virtme_ng.run --run vendor/linux-framework/arch/x86/boot/bzImage \
    --cwd /home/yunwei37/workspace/bpf-benchmark \
    --disable-monitor --cpus 2 --mem 4G \
    --exec 'PATH=/usr/local/sbin:$PATH micro/build/runner/micro_exec run-kernel \
      --program micro/programs/simple.bpf.o \
      --input micro/generated-inputs/simple.mem \
      --io-mode staged \
      --kernel-input-size 64 \
      --repeat 5'
```

Notes:

- The task-provided `micro_exec` CLI was slightly stale in this tree:
  - use `--program` instead of `--prog`;
  - `--warmup` is not supported by the current `micro_exec`.
- `virtme-ng` printed a `modules.order not found` warning, but the VM booted and the benchmark ran successfully.

Verification result:

- `simple.bpf.o`
  - `result = 12345678`
  - `retval = 2`
  - `exec_ns = 220`
  - `jited_prog_len = 173`

## Quick before/after comparison

Baseline image:

- `/tmp/task83-bzImage-before`

Patched image:

- `vendor/linux-framework/arch/x86/boot/bzImage`

Benchmark command shape (same for both kernels):

```bash
micro/build/runner/micro_exec run-kernel --program <prog> --input <input> \
  --io-mode staged --kernel-input-size 1032 --repeat 200
```

Results:

| Benchmark | Before `exec_ns` | After `exec_ns` | Before native bytes | After native bytes | Reading |
| --- | ---: | ---: | ---: | ---: | --- |
| `load_byte_recompose` | 294 | 235 | 422 | 418 | Smaller JIT image; quick-run exec improved |
| `stride_load_16` | 395 | 282 | 517 | 514 | Smaller JIT image; quick-run exec improved |
| `struct_field_cluster` | 79 | 92 | 450 | 445 | Smaller JIT image; exec moved slightly the other way in a noisy short run |

Interpretation:

- The code-size effect is consistent across all three memory-heavy benchmarks.
- The execution-time numbers are only quick smoke measurements, not a rigorous statistical run.
- The shortest benchmark (`struct_field_cluster`) is especially sensitive to timer noise; the stable signal here is the reduced JIT code size.
