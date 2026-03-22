# Micro Policy Rotate-Site Check (2026-03-20)

Checked `micro/policies/` for rotate-bearing v3 YAMLs, then re-ran the scanner on the corresponding micro benchmark objects with:

```bash
scanner/build/bpf-jit-scanner generate-policy micro/programs/<bench>.bpf.o --all
```

The scanner currently rejects low-mask rotate patterns in code and tests (`scanner/src/pattern_v5.cpp`, `scanner/tests/test_scanner.cpp`). The question here was whether any checked-in micro policies still referenced rotate sites that would no longer be emitted.

## Result

No stale rotate sites were found. No regeneration was needed, and `micro/policies/` was left unchanged.

## Benchmarks checked

| Benchmark | Rotate-bearing policy files checked | Fresh scanner result | Status |
| --- | --- | --- | --- |
| `cmov_dense` | `micro/policies/cmov_dense.yaml`, `micro/policies/variants/all-apply/cmov_dense.yaml`, `micro/policies/ablation/rotate/cmov_dense.yaml` | 26 rotate sites | Exact match |
| `large_mixed_500` | `micro/policies/large_mixed_500.yaml` | 7 rotate sites | Exact match |
| `large_mixed_1000` | `micro/policies/large_mixed_1000.yaml` | 7 rotate sites | Exact match |
| `rotate64_hash` | `micro/policies/rotate64_hash.yaml` | 116 rotate sites | Exact match |
| `rotate_dense` | `micro/policies/rotate_dense.yaml`, `micro/policies/variants/all-apply/rotate_dense.yaml`, `micro/policies/ablation/rotate/rotate_dense.yaml` | 256 rotate sites | Exact match |
| `memcmp_prefix_64` | `micro/policies/variants/all-apply/memcmp_prefix_64.yaml`, `micro/policies/ablation/rotate/memcmp_prefix_64.yaml` | 3 rotate sites | Exact match |

## Note on `memcmp_prefix_64`

`micro/policies/memcmp_prefix_64.yaml` is intentionally empty in the default policy set because the rotate-only selection was previously cleared for performance reasons. That file was not stale: it does not claim any rotate sites. The rotate-only variant files for the same benchmark still match current scanner output exactly.

## Misc

The one-liner used to list rotate-bearing YAMLs reports some top-level files twice because it globs both `micro/policies/*.yaml` and `micro/policies/**/*.yaml`. The duplicate lines did not affect the verification above; comparisons were done against the distinct policy files listed in the table.
