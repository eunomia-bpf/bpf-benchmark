# v5 Iteration Results

Date: 2026-03-10

## What changed

### Userspace / scanner

- Moved the runner-local v5 declarative matcher, builtin descriptor tables, and v5 blob builder into the shared scanner library:
  - `scanner/include/bpf_jit_scanner/pattern_v5.hpp`
  - `scanner/src/pattern_v5.cpp`
- Added v5 `COND_SELECT` descriptor coverage for both policy-sensitive cmov shapes:
  - 4-insn diamond: `jcc +2`, `mov`, `ja +1`, `mov`
  - 3-insn compact select: `mov`, `jcc +1`, `mov`
- Added shared v5 builtin scanning for all four families:
  - `cmov`
  - `wide_mem`
  - `rotate`
  - `addr_calc`
- Added v5 blob serialization to the shared scanner library so both `micro_exec` and the standalone scanner CLI use the same implementation.
- Added scanner CLI `--v5` mode and verified it can scan a synthetic cmov site and emit a v5 blob.
- Added scanner unit coverage for v5 cmov scanning and v5 blob versioning.

### Runner integration

- Removed the private v5 matcher/blob-builder from `micro/runner/src/kernel_runner.cpp`.
- Wired `micro_exec` v5 recompile mode to the shared scanner library.
- Enabled:
  - `--recompile-v5 --recompile-cmov`
  - `--recompile-v5 --recompile-all`
- Added CLI compatibility aliases needed by the benchmark commands:
  - `--input` as an alias for `--memory`
  - `--kernel-input-size` as an alias for `--input-size`

### Kernel / x86

- Added overflow-safe site range helpers in `vendor/linux-framework/kernel/bpf/jit_directives.c`.
- Replaced unchecked `site_start + site_len` arithmetic in validator and lookup paths with overflow-safe checks.
- Derived required CPU features in-kernel from `(canonical_form, native_choice)`:
  - `COND_SELECT + CMOVCC` implies `BPF_JIT_X86_CMOV`
  - `ROTATE + RORX` implies `BPF_JIT_X86_BMI2`
- Added a defensive x86-side `RORX` legality check in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`.

## Build status

- `cmake --build scanner/build -j4 && ./scanner/build/test_scanner`: success, `38 passed, 0 failed`
- `make -C micro micro_exec`: success
- `make -C vendor/linux-framework -j$(nproc) bzImage`: success
- Scanner CLI v5 smoke test:
  - `./scanner/build/bpf-jit-scanner scan --v5 --xlated /tmp/cmov_v5_test.xlated --cmov --output /tmp/cmov_v5_test.blob`
  - result: `Accepted 1 v5 site(s)`, wrote a `124`-byte v5 blob

## Notes on inputs

- The prompt referenced benchmark input files under `micro/generated-inputs/*.bin`.
- This checkout contains the corresponding generated inputs as `*.mem`, not `*.bin`.
- I ran the requested VM matrix against the existing `*.mem` inputs using the new `--input` alias.

## Test results

Raw parsed outputs were saved to `docs/tmp/v5-iteration-raw-results.json`.

| program | mode | result | exec_ns | jited_prog_len | sites |
|---|---|---:|---:|---:|---|
| log2_fold | baseline | 9 | 622 | 648 | 0 |
| log2_fold | v5 cmov | 9 | 1095 | 682 | 6 (cmov=6) |
| rotate64_hash | baseline | 2666935177028490406 | 298 | 3559 | 0 |
| rotate64_hash | v5 all | 2666935177028490406 | 578 | 2313 | 123 (wide=8, rotate=115) |
| load_byte_recompose | baseline | 1253018829653002637 | 583 | 422 | 0 |
| load_byte_recompose | v5 wide | 1253018829653002637 | 452 | 410 | 1 (wide=1) |
| stride_load_16 | baseline | 17112594108265627168 | 598 | 517 | 0 |
| stride_load_16 | v5 lea | 17112594108265627168 | 521 | 511 | 1 (lea=1) |
| packet_rss_hash | baseline | 11016707074064960918 | 165 | 1021 | 0 |
| packet_rss_hash | v5 rotate | 11016707074064960918 | 171 | 1007 | 1 (rotate=1) |

## Correctness verification

- `log2_fold`
  - baseline result: `9`
  - v5 cmov result: `9`
- `rotate64_hash`
  - baseline result: `2666935177028490406`
  - v5 all result: `2666935177028490406`
- `load_byte_recompose`
  - baseline result: `1253018829653002637`
  - v5 wide result: `1253018829653002637`
- `stride_load_16`
  - baseline result: `17112594108265627168`
  - v5 lea result: `17112594108265627168`
- `packet_rss_hash`
  - baseline result: `11016707074064960918`
  - v5 rotate result: `11016707074064960918`

All benchmark pairs produced matching results. For the non-cmov programs, correctness matched baseline exactly.

## CMOV policy-sensitivity check

- `log2_fold` baseline: `622 ns`, `648` bytes
- `log2_fold` v5 cmov: `1095 ns`, `682` bytes, `6` cmov sites
- Delta: `+76.0%` slower

This is the expected policy-sensitivity signal: forcing cmov on this workload made it slower while preserving correctness.

## Remaining issues

- v5 still does not implement the full canonical binding-table design from `jit-pass-framework-v5-design.md`; x86 emitters still recover operands from raw BPF instruction positions.
- The v5 matcher is still exact-opcode based; the design’s richer opcode-mask/value matcher is not implemented yet.
- v5 overlap arbitration is still a simple greedy descriptor-order scan, not the full priority-aware policy mechanism discussed in the review.
- `rotate64_hash --recompile-v5 --recompile-all` produced the correct result and much smaller code (`3559 -> 2313` bytes), but the 5-repeat VM timing regressed (`298 -> 578 ns`). That needs a higher-repeat rerun or cycle-focused follow-up before making a strong profitability claim.
