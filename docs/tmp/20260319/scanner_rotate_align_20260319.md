# Scanner Rotate Alignment Report

- Kernel reference: `vendor/linux-framework/kernel/bpf/jit_validators.c` uses `bpf_jit_rotate_mask_matches()` to accept only the high-mask form for masked 32-bit rotates and reject low-mask shift sequences.
- Scanner change: `scanner/src/pattern_v5.cpp` now mirrors that rule explicitly via `rotate_mask_matches_kernel()` and applies it to masked rotate descriptors during pattern matching.
- Test coverage: `scanner/tests/test_scanner.cpp` now covers both 6-insn and 5-insn masked rotate low-mask rejection paths.
- Expectation updates: policy/filter tests that previously counted an invalid rotate site now expect only the live `cmov` site to match, with rotate policy entries reported as unmatched.

## Verification

- `cmake --build scanner/build --target bpf-jit-scanner --target test_scanner -j` passed
- `make scanner-tests` passed with `0` FAIL
- `make smoke` passed
