# vm-selftest 5-form validation

Date: 2026-03-19
Workspace: `/home/yunwei37/workspace/bpf-benchmark`
Log: `docs/tmp/selftest_5form_validation_20260319.log`

## Commands run

```bash
source /home/yunwei37/workspace/.venv/bin/activate
cd vendor/linux-framework && make -j$(nproc) bzImage
cd /home/yunwei37/workspace/bpf-benchmark && make -C tests/kernel clean && make -C tests/kernel
make vm-selftest
```

## Summary

- Total tests: 24
- Passed: 24
- Failed: 0
- Existing pre-expansion tests: 19/19 passed
- New 5-form tests: 5/5 passed

No selftest failures were observed, so no follow-up code changes or reruns were required.

## New 5-form test results

- PASS `Addr Calc Recompile Preserves Result`: `addr_calc site_start=9 preserved 0x55b9`
- PASS `Bitfield Extract Recompile Preserves Result`: `bitfield_extract site_start=16 site_len=2 preserved 0x1234`
- PASS `Zero Ext Elide Recompile Preserves Result`: `zero_ext_elide site_start=7 preserved 0x100000056`
- PASS `Endian Fusion Recompile Preserves Result`: `endian_fusion site_start=17 preserved 0x100aa55`
- PASS `Branch Flip Recompile Preserves Result`: `branch_flip site_start=7 site_len=9 preserved 0x2376`

## Suite result

The VM selftest run finished with:

```text
PASS all 24 test(s)
```
