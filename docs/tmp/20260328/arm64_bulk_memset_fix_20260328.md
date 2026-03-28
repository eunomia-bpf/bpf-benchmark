# ARM64 BpfReJIT bulk_memset blocker fix report

Date: 2026-03-28

## 1. Final status

The two ARM64 blockers from `docs/tmp/20260328/arm64_test_20260328.md` are fixed.

Final ARM64 QEMU result on 2026-03-28:

- `bulk_memset_reg_apply`: PASS
- `bulk_memcpy_offset_lower_boundary`: PASS
- `bulk_memset_max_len_zero_fill`: PASS
- no guest kernel Oops

This required three code fixes:

1. ARM64 bulk-memset payload decode bug in `module/arm64/bpf_bulk_memory.c`
2. kernel verifier stale `insn_aux_data` pointer bug in `kernel/bpf/verifier.c`
3. kernel verifier temporary patch/proof buffer limit (`INSN_BUF_SIZE=32`) that was too small for bulk-memory kinsn proof sequences

No daemon-side change was required. `daemon/src/passes/bulk_memory.rs` was inspected, but the failures were not caused by the daemon pass.

## 2. Original failures

From `docs/tmp/20260328/arm64_test_20260328.md`:

- `bulk_memset_reg_apply` failed with `REJIT failed (errno=22: Invalid argument)`
- `bulk_memset_max_len_zero_fill` reproducibly crashed the ARM64 guest kernel:

```text
Unable to handle kernel paging request at virtual address 00000000ffc40a72
pc : bpf_stack_liveness_free+0x30/0xa8
lr : bpf_check+0x4b0/0x2c70
...
bpf_prog_rejit+0x434/0xc78
__sys_bpf+0xe3c/0x2338
```

## 3. Bug 1: `bulk_memset_reg_apply` EINVAL

### Root cause

The failure came from ARM64 bulk-memset payload decode, not from the daemon pass and not from ARM64 JIT text emission.

In `module/arm64/bpf_bulk_memory.c`, `decode_memset_payload()` decoded the width class and then rejected width value `0`:

- file: `module/arm64/bpf_bulk_memory.c`
- fixed line: `119`

Relevant code after fix:

```c
if (!bulk_width_bytes(*width))
	return -EINVAL;
```

Before the fix, this check was:

```c
if (!*width)
	return -EINVAL;
```

That is wrong for eBPF width encoding because:

- `bulk_width_from_class(2)` returns `BPF_W`
- `BPF_W` is encoded as `0`
- therefore valid 32-bit memset payloads were rejected as invalid

This exactly matches `bulk_memset_reg_apply`, which uses `BPF_W`.

### Fix

Changed the validation from "raw enum value must be non-zero" to "decoded width must map to a non-zero byte size":

- file: `module/arm64/bpf_bulk_memory.c`
- change: `if (!*width)` -> `if (!bulk_width_bytes(*width))`

### Ownership

This was an ARM64 kinsn module bug.

## 4. Bug 2: `bulk_memset_max_len_zero_fill` guest kernel Oops

### Root cause

The crash was in kernel verifier cleanup during kinsn proof-region restoration.

In `restore_kinsn_proof_regions()`:

- file: `kernel/bpf/verifier.c`
- fixed region: around lines `3847-3859` in the ARM64 build worktree

The code used `env->insn_aux_data` across operations that can replace the array:

- `bpf_patch_insn_data(...)`
- `verifier_remove_insns(...)`

Those helpers can reallocate the program and its aux array. If the old pointer is reused after reallocation, the cleanup path can dereference freed memory and corrupt verifier state. The observed Oops later in `bpf_stack_liveness_free()` is consistent with that.

The fixed logic now refreshes:

- `env->prog` after patching
- `aux = env->insn_aux_data` after each mutating helper

### Fix

Refresh `aux` after every mutating operation inside `restore_kinsn_proof_regions()`:

```c
new_prog = bpf_patch_insn_data(...);
env->prog = new_prog;
aux = env->insn_aux_data;

if (region->proof_len > 1) {
	err = verifier_remove_insns(...);
	...
	aux = env->insn_aux_data;
}
```

### Ownership

This was a kernel verifier bug, not an ARM64 module bug and not a daemon bug.

## 5. Additional latent blocker exposed after fixing the first two issues

After the two root bugs above were fixed, the ARM64 bulk-memory tests no longer failed as `EINVAL` or crashed, but they were still being downgraded to:

```text
SKIP: kernel kinsn proof buffer is limited to 32 insns
```

### Why that happened

The verifier still had a hard limit:

- file: `include/linux/bpf_verifier.h`
- old value: `#define INSN_BUF_SIZE 32`

And `fixup_bpf_calls()` rejects any kinsn whose declared `max_insn_cnt` exceeds that buffer:

- file: `kernel/bpf/verifier.c`
- lines around `23769-23772`

```c
if (kinsn->max_insn_cnt > INSN_BUF_SIZE) {
	verbose(env, "kinsn max_insn_cnt %u exceeds insn_buf size %u\n",
		kinsn->max_insn_cnt, INSN_BUF_SIZE);
	return -E2BIG;
}
```

But the ARM64 bulk-memory kinsn descriptors declare:

- `bpf_memcpy_bulk_desc.max_insn_cnt = 256`
- `bpf_memset_bulk_desc.max_insn_cnt = 128`

so `32` was inherently too small for bulk-memory proof instantiation.

### Fix

Raised `INSN_BUF_SIZE` from `32` to `256`:

- file: `include/linux/bpf_verifier.h`

Rationale:

- `256` covers current bulk-memory kinsn maxima in this tree
- the buffer lives inside `struct bpf_verifier_env`, so this is a verifier heap-structure size increase, not a kernel stack blow-up
- without this change, bulk-memory ARM64 tests would remain skipped even after the real bugs were fixed

### Ownership

This is a kernel-side verifier infrastructure limit.

It was not the original reported blocker, but it became the next blocker immediately after fixing the original two issues, so it needed to be fixed to get ARM64 bulk-memory back to real PASS rather than SKIP.

## 6. Files changed

Source-of-truth changes:

- `module/arm64/bpf_bulk_memory.c`
- `vendor/linux-framework/kernel/bpf/verifier.c`
- `vendor/linux-framework/include/linux/bpf_verifier.h`

For the actual ARM64 kernel build used in QEMU, the same kernel changes were also mirrored into the ARM64 source worktree:

- `.worktrees/linux-framework-arm64-src/kernel/bpf/verifier.c`
- `.worktrees/linux-framework-arm64-src/include/linux/bpf_verifier.h`

## 7. Validation

### Build

ARM64 kernel rebuild:

```bash
make -C .worktrees/linux-framework-arm64-src \
  O=vendor/linux-framework/build-arm64 \
  ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- Image -j$(nproc)
```

ARM64 module rebuild:

```bash
make -C module/arm64 \
  KDIR=.worktrees/linux-framework-arm64-src \
  O=vendor/linux-framework/build-arm64 \
  ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- all
```

### QEMU regression

Used kernel:

- `vendor/linux-framework/build-arm64/arch/arm64/boot/Image`
- booted kernel version: `#4 SMP PREEMPT Sat Mar 28 16:21:57 PDT 2026`

Executed in ARM64 QEMU:

```bash
/mnt/module/load_all.sh
/mnt/tests/unittest/build-arm64/rejit_kinsn bulk_memset_reg_apply
/mnt/tests/unittest/build-arm64/rejit_kinsn bulk_memcpy_offset_lower_boundary
/mnt/tests/unittest/build-arm64/rejit_kinsn bulk_memset_max_len_zero_fill
```

Observed results:

```text
PASS  bulk_memset_reg_apply
PASS  bulk_memcpy_offset_lower_boundary
PASS  bulk_memset_max_len_zero_fill
```

No verifier Oops, no guest kernel panic during the test cases.

## 8. Root-cause summary by layer

- daemon: not implicated
- `bulk_memset_reg_apply`: ARM64 kinsn module bug
- `bulk_memset_max_len_zero_fill`: kernel verifier cleanup bug
- remaining post-fix SKIP: kernel verifier buffer-size limit

## 9. Temporary workaround

No workaround is needed after these fixes.

If only a partial backport were desired, the minimum safe workaround before the kernel-side fixes would have been:

- disable ARM64 bulk-memory kinsn REJIT for `bulk_memset`

But that is no longer necessary in the current fixed tree.
