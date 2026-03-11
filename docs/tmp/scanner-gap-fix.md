# Scanner Gap Fix for Rotate-Heavy TC Programs

Date: 2026-03-10

## Summary

The v5 rotate gap was not caused by a new clang rotate lowering that v5 failed to model.

The affected programs all use the already-intended 6-insn masked 32-bit rotate-with-register-mask shape:

```text
mov64 tmp, src
and64 tmp, mask_reg
rsh64 tmp, 32-N
mov64 dst, src
lsh64 dst, N
or64  dst, tmp
```

Examples from the corpus:

- `core_kern.bpf.o` site at insn `20`:
  - `bf r3 = r5`
  - `5f r3 &= r4`
  - `77 r3 >>= 28`
  - `bf r7 = r5`
  - `67 r7 <<= 4`
  - `4f r7 |= r3`
- `test_verif_scale2.bpf.o` site at insn `19`: same shape
- `from_hep_debug.bpf.o` site at insn `27590`: same shape

## Root Cause

`scanner/src/pattern_v5.cpp` already had a `rotate6_masked(kAnd64X)` descriptor, but it was malformed.

The `AND64_X` descriptor bound variable `6` twice with incompatible meanings:

- on insn 1, var `6` was the `and64_x` source register
- on insn 4, var `6` was the `lsh64_k` immediate rotate amount

The v5 matcher enforces both value and type equality for repeated variables, so this made the descriptor impossible to satisfy. Because these corpus programs are dominated by the 6-insn `AND64_X` rotate form, v5 reported `0` sites.

This was a descriptor encoding bug, not a missing logical rotate family.

## Fix

No new rotate family was needed.

I corrected the existing `rotate6_masked(kAnd64X)` descriptor to give the `and64_x` source register its own variable id, leaving the rotate amount binding untouched.

Code change:

- `scanner/src/pattern_v5.cpp`
  - changed `rotate6_masked(kAnd64X)` so the `AND64_X` source register uses var `7` instead of reusing var `6`

Regression coverage:

- `scanner/tests/test_scanner.cpp`
  - added a v5 unit test for the 6-insn masked rotate `AND64_X` form

## Before / After Counts

Counts below were reproduced offline by extracting the executable `tc` section with:

```bash
llvm-objcopy --dump-section tc=/tmp/<name>.bin <object>
```

and scanning with:

```bash
./scanner/build/bpf-jit-scanner scan --xlated /tmp/<name>.bin --rotate --output /dev/null
./scanner/build/bpf-jit-scanner scan --v5 --xlated /tmp/<name>.bin --rotate --output /dev/null
```

| object | v4 scanner | v5 before | v5 after |
| --- | ---: | ---: | ---: |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o` | 818 | 0 | 818 |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o` | 992 | 0 | 992 |
| `corpus/build/calico/from_hep_debug.bpf.o` | 10 | 0 | 10 |

## Notes

- I could not dump fresh live xlated programs in this environment because `bpftool prog loadall` fails here with `RLIMIT_MEMLOCK` / `EPERM`.
- Existing prior runtime logs already show the same rotate counts on the loaded xlated path for the two linux-selftests programs:
  - `docs/tmp/corpus-perf-results.json`
  - `docs/tmp/corpus-v5-recompile-results.md`
- So the raw-section reproduction is sufficient to isolate the matcher bug, and the counts line up with the earlier xlated-path evidence.

## Verification

- Rebuilt scanner: `cmake --build scanner/build -j4`
- Unit tests: `scanner/build/test_scanner` -> `OK: 47 passed, 0 failed`
- Post-fix v5 scan:
  - `core_kern`: `818` rotate sites
  - `test_verif_scale2`: `992` rotate sites
  - `from_hep_debug`: `10` rotate sites
