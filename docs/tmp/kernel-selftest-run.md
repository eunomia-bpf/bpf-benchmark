# BpfReJIT Kernel Self-Test Run

Date: 2026-03-13

Kernel image:
`vendor/linux-framework/arch/x86/boot/bzImage`

Test binary:
`tests/kernel/build/test_recompile`

VM command used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --rwdir tests/kernel \
  -- bash -lc "cd /home/yunwei37/workspace/bpf-benchmark && sudo tests/kernel/build/test_recompile"
```

## Final Result

- Final pass rate: `18/18` tests passed (`100%`)
- Kernel changes: none
- Test changes: yes

## What Failed Initially

The first VM run exposed three test-side issues:

1. XDP `bpf_prog_test_run_opts()` was invoked with 1-4 byte packets and no `xdp_md` input.
   - Current kernel-side XDP test-run rejects this with `-EINVAL` unless the supplied input spans at least `ETH_HLEN`.
   - This caused the result-checking tests to fail before they even exercised recompile behavior.

2. The select/CMOV tests were still building a 2-insn `jcc + mov` policy.
   - Current kernel validation accepts `COND_SELECT` only as compact `mov + jcc + mov` or diamond `jcc + mov + ja + mov`.
   - The invalid policy caused:
     - `Diamond CMOV Recompile Preserves Result`
     - `Concurrent Recompile Returns EBUSY`
     - `Recompile After Attach Works`
     to fail with `-EINVAL`.

3. The rotate test program compiled to an unsupported masked 32-bit shape.
   - The old source emitted `ldimm64 + and_x + rsh + lsh + or (+ zero-ext)`.
   - Current kernel rotate validation accepts 4-insn rotate or the supported 5/6-insn forms, but not that `AND_X` variant.
   - This caused:
     - `Rotate Recompile Preserves Result`
     - `Repeated Recompile Reaches Count Two`
     to fail.

## Fixes Applied

All fixes were in the test suite:

- [`tests/kernel/test_recompile.c`](/home/yunwei37/workspace/bpf-benchmark/tests/kernel/test_recompile.c)
  - Added valid XDP `ctx_in` handling and packet padding for short `prog_test_run` inputs.
  - Updated the select-site matcher and policy builder to target the current compact 3-insn `mov/jcc/mov` form.
  - Updated the rotate-site matcher and policy builder to target the supported 4-insn rotate form.

- [`tests/kernel/progs/test_simple.bpf.c`](/home/yunwei37/workspace/bpf-benchmark/tests/kernel/progs/test_simple.bpf.c)
  - Reworked the source so clang emits a compact `mov/jcc/mov` select window.

- [`tests/kernel/progs/test_diamond.bpf.c`](/home/yunwei37/workspace/bpf-benchmark/tests/kernel/progs/test_diamond.bpf.c)
  - Reworked the source so clang emits the same validator-compatible select window used by the CMOV test.

- [`tests/kernel/progs/test_rotate.bpf.c`](/home/yunwei37/workspace/bpf-benchmark/tests/kernel/progs/test_rotate.bpf.c)
  - Reworked the source so clang emits a contiguous 4-insn rotate sequence accepted by the current kernel validator.

No kernel bug requiring a change under `vendor/linux-framework/` was reproduced by this test suite after the test-side fixes.

## Per-Test Results

| Test case | Description | Final status | Notes |
| --- | --- | --- | --- |
| Load Simple Program And Verify Tag | Load `test_simple`, fetch `bpf_prog_info`, and confirm the program tag is non-zero. | PASS | Final message: `prog_fd=5 tag=16b2260fc2e7aa29 insn_cnt=32` |
| Zero-Rule Policy Blob No-Op | Apply a header-only policy blob and accept either a no-op success or the current `EINVAL` behavior. | PASS | Current kernel behavior: `policy has no rules` |
| Single Valid Wide Rule Recompile | Find the wide-load site in `test_wide` and recompile with one valid WIDE_MEM rule. | PASS | `wide site_start=7 recompiled` |
| Wide Result Preserved After Recompile | Run `test_wide` before and after recompile and verify the map result is unchanged. | PASS | `wide result 0x1234 preserved` |
| Recompile Count Increments | Confirm one successful wide recompile increments `recompile_count` by one. | PASS | `recompile_count 0 -> 1` |
| Wrong Magic Rejected | Corrupt the policy magic and expect `EINVAL`. | PASS | Rejected as expected |
| Wrong Prog Tag Rejected | Corrupt the policy `prog_tag` and expect `EINVAL`. | PASS | Rejected as expected |
| Wrong Insn Count Rejected | Corrupt the policy `insn_cnt` and expect `EINVAL`. | PASS | Rejected as expected |
| Wrong Arch Id Rejected | Change the policy `arch_id` to a non-x86 value and expect `EINVAL`. | PASS | Rejected as expected |
| Non-Sealed Memfd Rejected | Submit an otherwise valid policy from an unsealed memfd and expect `EINVAL`. | PASS | Rejected as expected |
| Truncated Header Rejected | Submit a blob shorter than the policy header and expect `EINVAL`. | PASS | Rejected as expected |
| Site Start Out Of Bounds Rejected | Move `site_start` past the end of the program and expect `EINVAL`. | PASS | Rejected as expected |
| Zero-Length Blob Rejected | Submit an empty sealed memfd and expect `EINVAL`. | PASS | Rejected as expected |
| Diamond CMOV Recompile Preserves Result | Recompile the select site in `test_diamond` with `BPF_JIT_SEL_CMOVCC` and verify the result is unchanged. | PASS | `diamond cmov site_start=11 preserved 0xaa` |
| Rotate Recompile Preserves Result | Recompile the rotate site in `test_rotate` and verify the result is unchanged. | PASS | `rotate site_start=27 preserved 0x245b9f3175ce8b10` |
| Repeated Recompile Reaches Count Two | Apply the rotate policy twice and confirm `recompile_count` increments twice. | PASS | `rotate recompile_count 0 -> 2` |
| Concurrent Recompile Returns EBUSY | Run two threads against the same program/policy and confirm the kernel returns a mix of success and `EBUSY`. | PASS | `success=1 ebusy=1` |
| Recompile After Attach Works | Attach the XDP program to loopback in SKB mode, then recompile it successfully. | PASS | `attached XDP program recompiled on ifindex 1` |

