# Micro Inline Policy v1→v2 Fix

Date: 2026-03-12

## Summary

- `config/micro_pure_jit.yaml` only had two remaining inline micro policies:
  - `log2_fold`
  - `cmov_select`
- Both were converted to explicit `policy_file` references.
- `micro/benchmark_catalog.py` no longer generates v1 inline policy JSON.
- Inline manifest `policy:` is now rejected at suite-load time with a clear error telling callers to use `policy_file`.

## Changes

- Updated `config/micro_pure_jit.yaml`
  - `log2_fold` now uses `policy_file: micro/policies/log2_fold.yaml`
  - `cmov_select` now uses `policy_file: micro/policies/cmov_select.yaml`
- Added `micro/policies/log2_fold.yaml`
  - v2 family-level denylist
  - `default: apply`
  - `families: {cmov: skip}`
- Added `micro/policies/cmov_select.yaml`
  - v2 family-level allowlist
  - `default: skip`
  - `families: {cmov: apply}`
- Updated `micro/benchmark_catalog.py`
  - removed inline v1 JSON generation
  - removed inline policy normalization logic
  - added hard failure for residual inline `policy:` usage
- Updated `micro/_driver_impl_run_micro.py`
  - `resolve_policy_inputs()` now always returns `policy_file`
  - no inline `--policy` text is generated anymore

## Validation

1. `python3 -m py_compile micro/benchmark_catalog.py micro/run_micro.py`
   - passed
2. `python3 micro/run_micro.py --list`
   - passed
   - all benchmarks, including `log2_fold` and `cmov_select`, parsed successfully
3. New policy files parse as valid v2 YAML
   - `micro/policies/log2_fold.yaml`:
     - `version: 2`
     - `program: log2_fold_xdp`
     - `default: apply`
     - `families: {cmov: skip}`
   - `micro/policies/cmov_select.yaml`:
     - `version: 2`
     - `program: cmov_select_xdp`
     - `default: skip`
     - `families: {cmov: apply}`
4. Scanner smoke checks
   - `scanner/build/bpf-jit-scanner compile-policy micro/programs/log2_fold.bpf.o --program-name log2_fold_xdp --config micro/policies/log2_fold.yaml --output /tmp/log2_fold_policy.blob`
     - passed
     - wrote `452` bytes
     - selected `3/11` rules
   - `scanner/build/bpf-jit-scanner compile-policy micro/programs/cmov_select.bpf.o --program-name cmov_select_xdp --config micro/policies/cmov_select.yaml --output /tmp/cmov_select_policy.blob`
     - passed
     - wrote `32` bytes
     - selected `0/10` rules

## Notes

- `cmov_select`'s new file is valid and scanner-consumable, but offline `.bpf.o` scanning currently sees no `cmov` sites there, so the compiled blob is empty in this check.
- That is separate from the inline v1→v2 breakage fixed here. Historical live/kernel scans for `cmov_select` have reported one `cmov` site plus additional `wide`/`rotate` sites, so the family-level v2 file still encodes the intended benchmark policy.
- There are still `version: 1` files under `micro/policies/per_family/`. They were not part of this fix.
