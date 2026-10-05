# Kernel Selftest Expansion Report

Date: 2026-03-19

## Scope

Expanded `tests/kernel/test_recompile.c` coverage for the five previously uncovered canonical forms:

- `ADDR_CALC`
- `BITFIELD_EXTRACT`
- `ZERO_EXT_ELIDE`
- `ENDIAN_FUSION`
- `BRANCH_FLIP`

Added five new BPF test programs under `tests/kernel/progs/`:

- `test_addr_calc.bpf.c`
- `test_bitfield_extract.bpf.c`
- `test_zero_ext_elide.bpf.c`
- `test_endian_fusion.bpf.c`
- `test_branch_flip.bpf.c`

Added corresponding object-path definitions, site-discovery helpers, blob builders, packet/result helpers, and positive preservation tests in `tests/kernel/test_recompile.c`.

## Local Tree Notes

Two requested background details did not match the current tree:

1. `tests/kernel/progs/test_cmov.bpf.c` is not present here.
   - The existing COND_SELECT reference program is `tests/kernel/progs/test_diamond.bpf.c`.

2. `tests/kernel/progs/` does not use `common.h` / `DEFINE_STAGED_INPUT_XDP_BENCH`.
   - The local kernel selftest style is the existing minimal XDP + `result_map` harness.
   - The new programs were written in that same style to match the current test infrastructure exactly.

I also added `progs` and `runner` phony aliases to `tests/kernel/Makefile`, because the requested verification commands were not defined before this change.

## Shape Sanity Checks

After compiling the new `.bpf.o` files, object disassembly shows the intended canonical windows:

- `test_addr_calc.bpf.o`
  - `r1 = r6`
  - `r1 <<= 0x3`
  - `r1 += r7`

- `test_bitfield_extract.bpf.o`
  - `r6 >>= 0x5`
  - `r6 &= 0x1f`

- `test_zero_ext_elide.bpf.o`
  - `w6 += w7`
  - `r6 = r6`

- `test_endian_fusion.bpf.o`
  - `r2 = *(u32 *)(r6 + 0xc)`
  - `r2 = be32 r2`

- `test_branch_flip.bpf.o`
  - one bounded local if/else diamond with `jcc`, body A, `ja`, body B, join

`ZERO_EXT_ELIDE` is intentionally matched through live translated BPF in the runner, but the object code now already shows the exact two-insn pair the kernel validator accepts.

## Build Verification

Build-only verification completed. No VM selftests were run.

Commands executed:

```bash
make -C tests/kernel progs
make -C tests/kernel runner
```

Results:

- `make -C tests/kernel progs`: success
- `make -C tests/kernel runner`: success

Observed warning:

- The runner build still emits the long-standing vendored kernel header warning from `vendor/linux-framework/include/uapi/linux/types.h`.
- No new compiler warning or error was introduced by this selftest expansion.

## Files Changed

- `tests/kernel/Makefile`
- `tests/kernel/test_recompile.c`
- `tests/kernel/progs/test_addr_calc.bpf.c`
- `tests/kernel/progs/test_bitfield_extract.bpf.c`
- `tests/kernel/progs/test_zero_ext_elide.bpf.c`
- `tests/kernel/progs/test_endian_fusion.bpf.c`
- `tests/kernel/progs/test_branch_flip.bpf.c`
- `docs/tmp/selftest_expansion_20260319.md`
