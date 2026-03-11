# cmov_dense benchmark

## Summary

- Added `micro/programs/cmov_dense.bpf.c` as a staged-input XDP benchmark with 32 explicit inlined compare/select sites in `bench_cmov_dense`.
- Added `generate_cmov_dense()` to `micro/input_generators.py` to emit four 32-element pseudo-random `u64` arrays (`a`, `b`, `x`, `y`) into a 1024-byte staged input blob.
- Added `cmov_dense` to `config/micro_pure_jit.yaml` with `kernel_input_size: 1024` and `expected_result: 15544056576594566652`.

## Verification

- Built programs with `make -C micro programs`.
- Materialized input with `python3 -c 'from micro.input_generators import materialize_input; print(materialize_input("cmov_dense", force=True))'`.
- `llvm-objdump -d micro/programs/cmov_dense.bpf.o` shows repeated compact conditional-select sites in the main body:

```text
18: bf 31 00 00 00 00 00 00   r1 = r3
19: 2d 45 01 00 00 00 00 00   if r5 > r4 goto +0x1
20: bf 21 00 00 00 00 00 00   r1 = r2
```

- Kernel scan command:

```bash
sudo micro/build/runner/micro_exec run-kernel \
  --program micro/programs/cmov_dense.bpf.o \
  --memory micro/generated-inputs/cmov_dense.mem \
  --input-size 1024 \
  --io-mode staged \
  --recompile-cmov \
  --compile-only
```

- Host-kernel scanner result: `32` cmov-select sites in the xlated program (`618` insns).
- Normal execution command:

```bash
sudo micro/build/runner/micro_exec run-kernel \
  --program micro/programs/cmov_dense.bpf.o \
  --memory micro/generated-inputs/cmov_dense.mem \
  --input-size 1024 \
  --io-mode staged \
  --repeat 100
```

- Normal execution result: `15544056576594566652`.

## Notes

- Clang lowered the selects to the scanner's compact `mov / jcc+1 / mov` form instead of the 4-insn `jcc / mov / ja / mov` diamond.
- The repo's CMOV scanner matches both compact and diamond forms; on this host kernel it reported all 32 intended sites.
- `BPF_PROG_JIT_RECOMPILE` returned `EINVAL` on the host kernel during the compile-only scan path, but the program loaded and executed correctly in normal `run-kernel` mode.
