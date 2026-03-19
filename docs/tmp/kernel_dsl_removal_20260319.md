# Kernel DSL Removal Report

Date: 2026-03-19

## Scope

This change removes the generic kernel-side pattern/constraint/binding DSL from
BpfReJIT policy handling and simplifies the v2 policy blob so each rule now
contains only:

- `site_start`
- `site_len`
- `canonical_form`
- `native_choice`

No backwards compatibility was kept for the old blob layout.

## What Changed

### Kernel

- Deleted generic pattern matching, constraint checking, binding extraction, and
  blob-side canonical parameter validation from
  `vendor/linux-framework/kernel/bpf/jit_directives.c`.
- Simplified policy parsing so `bpf_jit_parse_policy_format_v2()` reads a flat
  array of fixed-size rewrite rules.
- Removed UAPI pattern/constraint/binding enums and structs from
  `vendor/linux-framework/include/uapi/linux/bpf.h`.
- Kept canonical parameter definitions only as internal kernel definitions in
  `vendor/linux-framework/include/linux/bpf_jit_directives.h`.
- Moved CPU feature gating to per-form validation paths using `boot_cpu_has()`:
  - conditional select -> `CMOV`
  - rotate -> `BMI2` for `RORX`
  - endian fusion -> `MOVBE`
- Dropped `rule_kind`, priority, inline DSL counts, and CPU feature bitmasks
  from the on-wire rule format.

### Scanner

- Simplified `V5RuleWire` to the new fixed-size minimal rule layout.
- Simplified the public `V5PolicyRule` summary object to site metadata only.
- Kept scanner-side pattern descriptors private inside `pattern_v5.cpp`; they no
  longer leak into the public scanner API or blob format.
- Updated manifest / policy-filter code to use `site_len` and `pattern_kind`
  directly instead of reconstructing metadata from bindings.
- Updated scanner tests to validate the new minimal rule shape.

### Self-tests

- Simplified kernel self-test blob construction to write only
  `struct bpf_jit_rewrite_rule_v2` entries.
- Removed all user-space construction of old pattern/constraint/binding arrays.

## Line Count Comparison

Tracked files before vs. after this change:

| File | Before | After | Delta |
| --- | ---: | ---: | ---: |
| `vendor/linux-framework/kernel/bpf/jit_directives.c` | 4012 | 3146 | -866 |
| `vendor/linux-framework/include/uapi/linux/bpf.h` | 7956 | 7803 | -153 |
| `vendor/linux-framework/include/linux/bpf_jit_directives.h` | 197 | 254 | +57 |
| `scanner/include/bpf_jit_scanner/pattern_v5.hpp` | 286 | 80 | -206 |
| `scanner/include/bpf_jit_scanner/types.h` | 59 | 57 | -2 |
| `scanner/src/pattern_v5.cpp` | 1870 | 2017 | +147 |
| `scanner/src/policy_config.cpp` | 610 | 531 | -79 |
| `scanner/tests/test_scanner.cpp` | 943 | 912 | -31 |
| `tests/kernel/test_recompile.c` | 2374 | 2156 | -218 |
| **Total** | **18307** | **16956** | **-1351** |

Notes:

- `include/linux/bpf_jit_directives.h` grew because canonical parameter enums
  that used to live in UAPI were moved into the internal kernel header.
- `scanner/src/pattern_v5.cpp` grew because scanner-private descriptor structs
  and `pattern_kind` derivation were consolidated there while the public API was
  simplified.

## Validation

All requested validation steps passed:

1. `cd vendor/linux-framework && make -j$(nproc) bzImage`
2. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest`
   - Passed all 20 kernel self-tests
3. `make vm-micro-smoke`
   - `simple` and `load_byte_recompose` both passed for `kernel` and
     `kernel-recompile`
4. `cmake --build scanner/build --target test_scanner && ./scanner/build/test_scanner`
   - Passed `PASS 180`

## Result

The kernel no longer interprets or validates the generic rule DSL. Policy blobs
are flat minimal site descriptors, scanner/self-tests generate the new format,
and CPU feature checks now happen in per-form validation instead of generic
constraint handling.
