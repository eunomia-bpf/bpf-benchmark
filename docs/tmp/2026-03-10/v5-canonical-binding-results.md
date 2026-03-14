Date: 2026-03-10

# v5 Canonical Binding Table + Parameterized Emitters

## Scope

Implemented the missing v5 canonical-binding path in the framework kernel tree used by this checkout: `vendor/linux-framework`.

This repo's `vendor/linux` tree is still the fixed-baseline kernel and does not contain the v5 matcher/parser codepaths. The v5 implementation therefore landed in `vendor/linux-framework`, which is the tree currently carrying `BPF_JIT_RK_PATTERN`, the v2 rule parser, and the x86 directive framework.

## What changed

### Binding ABI

- Added a v2 rule-level binding table in the UAPI:
  - `binding_count`
  - `struct bpf_jit_binding`
- Mirrored the binding ABI in userspace scanner code.
- Extended v5 blob emission so bindings are serialized after constraints.

### Kernel canonical params

- Added internal kernel storage for extracted canonical parameters.
- After pattern match plus constraint validation, the kernel now extracts canonical parameters from matched BPF instruction variables through the rule's binding table.
- Added canonical-param validation per form before the rule is accepted.

### Parameterized x86 emitters

- Refactored the v5 pattern-rule x86 path to dispatch through canonical parameters instead of raw BPF instruction positions.
- `COND_SELECT` and `ROTATE` now consume `struct bpf_jit_canonical_params`.
- `WIDE_MEM` and `ADDR_CALC` were also wired to the canonical-param path for v5 pattern rules.
- Legacy v1/v4 behavior remains intact; the old raw-insn emitters are still used for non-v5 paths.

## Files changed

- `vendor/linux-framework/include/uapi/linux/bpf.h`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `scanner/include/bpf_jit_scanner/pattern_v5.hpp`
- `scanner/src/pattern_v5.cpp`
- `scanner/tests/test_scanner.cpp`

## Build and test status

- `make -C vendor/linux-framework -j$(nproc) bzImage`: success
- `make -C micro micro_exec`: success
- `cmake --build scanner/build -j4 && ./scanner/build/test_scanner`: success, `41 passed, 0 failed`

## VM smoke tests

These were quick correctness checks, not stable performance measurements. All runs used `vendor/linux-framework/arch/x86/boot/bzImage`.

### `log2_fold`

Commands:

- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/log2_fold.bpf.o --input micro/generated-inputs/log2_fold.mem --io-mode staged --input-size 1032 --repeat 1"`
- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/log2_fold.bpf.o --input micro/generated-inputs/log2_fold.mem --io-mode staged --input-size 1032 --repeat 1 --recompile-v5 --recompile-cmov"`

Results:

| mode | result | retval | jited_prog_len | xlated_prog_len | sites |
| --- | ---: | ---: | ---: | ---: | --- |
| baseline | 9 | 2 | 648 | 1112 | none |
| v5 `--recompile-cmov` | 9 | 2 | 682 | 1112 | `cmov=6` |

Checks:

- Result matches baseline.
- `xlated_prog_len` is unchanged (`1112 -> 1112`).
- Only JIT-native code changed (`648 -> 682`).

### `rotate64_hash`

Commands:

- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 1"`
- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 1 --recompile-v5 --recompile-all"`

Results:

| mode | result | retval | jited_prog_len | xlated_prog_len | sites |
| --- | ---: | ---: | ---: | ---: | --- |
| baseline | 2666935177028490406 | 2 | 3559 | 7984 | none |
| v5 `--recompile-all` | 2666935177028490406 | 2 | 2313 | 7984 | `wide=8`, `rotate=115` |

Checks:

- Result matches baseline.
- `xlated_prog_len` is unchanged (`7984 -> 7984`).
- Only JIT-native code changed (`3559 -> 2313`).

## Conclusion

The core v5 design gap is closed for the framework tree in this checkout:

- v2 rules now carry canonical bindings
- the kernel extracts canonical params after match/constraint validation
- v5 x86 emitters no longer need to know which raw BPF pattern matched
- new pattern variants that bind to the same canonical parameters can reuse the same emitter

The required paper-critical cases, `COND_SELECT` and `ROTATE`, are both on the canonical-param path and passed the requested quick VM correctness checks.
