# V4 Round 3: ROTATE Directive Fix

## Problem

Round 2 VM testing confirmed that the ROTATE directive had ZERO coverage in
the kernel JIT despite the userspace scanner finding 115 candidate sites in
`rotate64_hash.bpf.o`. The kernel `BPF_PROG_JIT_RECOMPILE` syscall returned
`EINVAL` because all 115 rules failed kernel-side validation.

For `packet_rss_hash.bpf.o` (32-bit rotations), the userspace scanner also
found zero sites because the bytecode pattern clang generates was not
recognized.

## Root Cause Analysis

### 1. 64-bit rotate: Instruction ordering mismatch

The kernel validator (`bpf_jit_validate_rotate_4insn`) expected only the
**classic** 4-insn pattern:
```
[0] mov tmp, src
[1] lsh src, N
[2] rsh tmp, (W-N)
[3] or  src, tmp
```

But clang generates two different orderings:

**Commuted 4-insn** (most common for 64-bit rotations):
```
[0] mov tmp, src
[1] rsh tmp, (W-N)     <-- RSH first, not LSH
[2] lsh src, N
[3] or  src, tmp
```

**5-insn two-copy** (used when the compiler needs separate dst/tmp):
```
[0] mov tmp, src
[1] rsh tmp, (W-N)
[2] mov dst, src        <-- second copy
[3] lsh dst, N
[4] or  dst, tmp
```

The kernel validator only handled `site_len==4` with LSH at position 1 and
`site_len==6` for masked 32-bit. It had NO handler for the commuted 4-insn
ordering or the 5-insn two-copy pattern.

### 2. 32-bit rotate: AND register vs immediate

For 32-bit rotations, clang generates masking with `AND64_X` (register AND)
instead of `AND64_K` (immediate AND). This is because mask constants like
`0xf0000000` do not fit in a sign-extended 32-bit BPF immediate, so clang
loads them via `lddw` into a register.

Example from `packet_rss_hash.bpf.o`:
```
r7 = 0xf0000000          (lddw)
r0 = r5                  (mov64_x)
r0 &= r7                 (AND64_X, not AND64_K!)
r0 >>= 0x1c              (rsh64_k)
r3 = r5                  (mov64_x)
r3 <<= 0x4               (lsh64_k)
r3 |= r0                 (or64_x)
```

Both the userspace scanner and kernel validator only accepted `AND64_K`.

### 3. 32-bit rotate: 5-insn no-copy variant

clang also generates a 5-insn masked 32-bit variant where the second MOV is
eliminated (operating directly on the original register):
```
[0] mov tmp, src
[1] and tmp, mask_reg
[2] lsh src, N           <-- operates on original, no second mov
[3] rsh tmp, (32-N)
[4] or  src, tmp
```

This pattern was not handled at all.

## Fixes Applied

### Kernel-side (vendor/linux/)

**`kernel/bpf/jit_directives.c`:**
- `bpf_jit_validate_rotate_4insn()`: Extended to accept BOTH classic
  (`mov+lsh+rsh+or`) and commuted (`mov+rsh+lsh+or`) instruction orderings.
  Added safety check for `dst_reg != src_reg`.
- `bpf_jit_validate_rotate_5insn()`: NEW function for 5-insn 64-bit
  two-copy pattern (`mov+rsh+mov+lsh+or`).
- `bpf_jit_validate_rotate_5insn_masked()`: NEW function for 5-insn masked
  32-bit pattern (`mov+and+{rsh,lsh}+{lsh,rsh}+or`).
- `bpf_jit_validate_rotate_6insn()`: Extended AND check to accept both
  `AND64_K` and `AND64_X`. Updated mask zero-check to only apply for `AND_K`.
- `bpf_jit_validate_rotate_rule()`: Now accepts `site_len==5` and tries
  both 5-insn validators (64-bit two-copy, then 32-bit masked).

**`arch/x86/net/bpf_jit_comp.c`:**
- `emit_bpf_rotate()`: Extended to handle 5-insn patterns and commuted
  4-insn patterns. For 4-insn, finds LSH at either idx+1 (classic) or
  idx+2 (commuted). For 5-insn, disambiguates between 64-bit two-copy
  (insn[1] is RSH) and 32-bit masked (insn[1] is AND).

### Userspace scanner (micro/runner/)

**`micro/runner/src/kernel_runner.cpp`:**
- 6-insn scanner: Extended to accept `AND64_X` in addition to `AND64_K`.
  Removed the `and_i.imm != 0` check that was incorrect for register AND.
- NEW 5-insn masked 32-bit scanner: Recognizes `mov+and+{rsh,lsh}+{lsh,rsh}+or`
  patterns with either lsh/rsh ordering and both AND64_K/AND64_X.

## Results After Fix

### rotate64_hash.bpf.o (64-bit rotations, 998 xlated insns)
- Scanner: 115 rotate sites found (unchanged -- scanner already worked)
- Kernel validation: requires kernel rebuild to verify
- Expected: all 115 sites should pass validation now

### packet_rss_hash.bpf.o (32-bit rotations, 261 xlated insns)
- Scanner: **11 rotate sites found** (up from 0)
- Some rotations still not matched due to compiler instruction scheduling
  that interleaves unrelated instructions into the rotation pattern.
  Recognizing those would require a gap-tolerant pattern matcher, which is
  out of scope for this fix.

### Correctness
- `rotate64_hash`: result = 2666935177028490406 (correct, unchanged)
- Both llvmbpf and stock kernel runner produce identical results

## Pattern Coverage Summary

| Pattern | Width | Scanner | Kernel Validator | Status |
|---------|-------|---------|-----------------|--------|
| mov+lsh+rsh+or (classic) | 32/64 | existing | existing | OK |
| mov+rsh+lsh+or (commuted) | 32/64 | existing | **NEW** | Fixed |
| mov+rsh+mov+lsh+or (two-copy) | 64 | existing | **NEW** | Fixed |
| mov+and_k+rsh+mov+lsh+or (6-insn) | 32 | existing | existing | OK |
| mov+and_x+rsh+mov+lsh+or (6-insn, reg AND) | 32 | **NEW** | **NEW** | Fixed |
| mov+and+{rsh,lsh}+{lsh,rsh}+or (5-insn masked) | 32 | **NEW** | **NEW** | Fixed |
| Interleaved/gap patterns | 32 | not matched | n/a | Out of scope |

## Files Modified

- `vendor/linux/kernel/bpf/jit_directives.c` -- kernel-side validators
- `vendor/linux/arch/x86/net/bpf_jit_comp.c` -- x86 JIT emitter
- `micro/runner/src/kernel_runner.cpp` -- userspace scanner

## Next Steps

1. Rebuild the custom kernel with the validator/emitter fixes
2. Run end-to-end test in VM to confirm ROTATE rules are accepted and
   the re-JITed program produces correct results
3. Measure performance impact of ror/rorx vs shift-pair for rotate64_hash
4. Consider `-mcpu=v3` compilation flag for programs with 32-bit rotations
   to get cleaner BPF bytecode (32-bit ALU ops instead of 64-bit + masking)
