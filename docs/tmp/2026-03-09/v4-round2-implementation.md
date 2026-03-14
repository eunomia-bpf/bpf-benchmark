# v4 Round 2 Implementation: ROTATE 6-insn, WIDE_MEM high-byte-first, rotate64_hash benchmark

## Problem Statement

Round 1 testing showed that ROTATE and WIDE_MEM directives had **ZERO coverage** because the scanners only matched idealized patterns that clang does not actually generate. This round extends both scanners and validators to match clang's actual codegen.

## Changes Summary

### Task 1: ROTATE 6-insn Masked 32-bit Pattern

**Problem**: The existing ROTATE scanner expects a clean 4-insn `mov+lsh+rsh+or` pattern. But for 32-bit rotates in 64-bit context, clang generates a 6-insn masked pattern:
```
[0] mov64  tmp, src       (copy for right-shift path)
[1] and64  tmp, mask      (mask high bits for 32-bit extraction)
[2] rsh64  tmp, (32-N)    (right shift by complement)
[3] mov64  dst, src       (copy for left-shift path)
[4] lsh64  dst, N         (left shift)
[5] or64   dst, tmp       (combine)
```

**Changes**:

1. **`vendor/linux/kernel/bpf/jit_directives.c`**:
   - Refactored `bpf_jit_validate_rotate_rule()` into two sub-validators:
     - `bpf_jit_validate_rotate_4insn()` -- existing 4-insn pattern
     - `bpf_jit_validate_rotate_6insn()` -- new 6-insn masked 32-bit pattern
   - The wrapper `bpf_jit_validate_rotate_rule()` now accepts both `site_len==4` and `site_len==6`
   - 6-insn validation checks: both movs share same src_reg, AND is non-zero, N + rsh_amount == 32, or dst/src match correctly

2. **`vendor/linux/arch/x86/net/bpf_jit_comp.c`**:
   - Extended `emit_bpf_rotate()` to handle `site_len==6`
   - For 6-insn: always 32-bit, src from `insns[idx].src_reg`, dst from `insns[idx+3].dst_reg`, rot_amount from `insns[idx+4].imm`
   - For ROR: emits `mov dst, src; ror32 dst, (32-N)` if src != dst, or just `ror32 dst, (32-N)` if src == dst
   - For RORX: emits `rorx32 dst, src, (32-N)` (non-destructive, handles src != dst natively)

3. **`micro/runner/src/kernel_runner.cpp`**:
   - Extended `find_rotate_sites_xlated()` to scan for 6-insn pattern first (more specific), then fall back to 4-insn
   - 6-insn detection: checks `mov64+and64+rsh64+mov64+lsh64+or64` with same-src constraint and N + rsh_amount == 32
   - Emits rule with `site_len=6`

### Task 2: rotate64_hash Benchmark

**New file**: `micro/programs/rotate64_hash.bpf.c`

- SipHash-like hash function using 6 distinct 64-bit rotation amounts (13, 32, 16, 21, 17, 32)
- Processes 8 input u64 words through 2 rounds each plus 4 finalization rounds
- Total: 12 SIPROUND calls x 6 rotations = 72 rotation sites (many will be CSE'd by clang, but should produce many 4-insn patterns)
- Uses `DEFINE_STAGED_INPUT_XDP_BENCH` pattern
- Expected result: 2666935177028490406

**Input generator**: `generate_rotate64_hash()` in `micro/input_generators.py`
- 8 u64 words = 64 bytes, deterministic LCG-based generation

**Config entry**: Added to `config/micro_pure_jit.yaml` as `rotate64_hash` in the alu-mix category.

### Task 3: WIDE_MEM High-Byte-First Pattern

**Problem**: The existing WIDE_MEM scanner expects low-byte-first sequential ladder, but clang generates high-byte-first with reversed register roles:
```
[0] ldxb tmp, [base+off+1]    (byte 1 FIRST)
[1] lsh64 tmp, 8
[2] ldxb dst, [base+off]      (byte 0 SECOND)
[3] or64 tmp, dst             (combine into tmp, NOT dst)
```

**Changes**:

1. **`vendor/linux/kernel/bpf/jit_directives.c`**:
   - Refactored `bpf_jit_validate_wide_mem_rule()` into two sub-validators:
     - `bpf_jit_validate_wide_mem_low_first()` -- existing low-byte-first pattern
     - `bpf_jit_validate_wide_mem_high_first()` -- new high-byte-first 2-byte pattern
   - The wrapper tries low-first, then falls back to high-first
   - High-first validation: checks lsh immediately follows first load, second load offset is first-1, or dst is first load's dst (tmp), or src is second load's dst

2. **`vendor/linux/arch/x86/net/bpf_jit_comp.c`**:
   - Extended `emit_bpf_wide_load()` to detect high-byte-first variant
   - Detection: site_len==4 AND insns[idx+1] is lsh64 with imm==8 AND insns[idx+2] loads from offset-1
   - For high-first: result_reg = first load's dst_reg (tmp), base_off from second load (low byte)
   - Emits same `movzx result_reg, word ptr [base_reg+off]` -- just with different register mapping

3. **`micro/runner/src/kernel_runner.cpp`**:
   - Extended `find_wide_load_sites_xlated()` to check for high-byte-first 2-byte pattern before low-byte-first
   - Detection: after ldxb, checks if next insn is lsh64 imm=8 (not another ldxb), then checks ldxb at offset-1, then or64
   - Emits rule with `site_len=4`

## Files Modified

| File | Change |
|------|--------|
| `vendor/linux/kernel/bpf/jit_directives.c` | ROTATE 6-insn validator + WIDE_MEM high-first validator |
| `vendor/linux/arch/x86/net/bpf_jit_comp.c` | ROTATE 6-insn emitter + WIDE_MEM high-first emitter |
| `micro/runner/src/kernel_runner.cpp` | ROTATE 6-insn scanner + WIDE_MEM high-first scanner |
| `micro/programs/rotate64_hash.bpf.c` | NEW: 64-bit rotation benchmark |
| `micro/input_generators.py` | NEW: rotate64_hash generator |
| `config/micro_pure_jit.yaml` | NEW: rotate64_hash entry |

## Design Invariants Preserved

1. **xlated_prog_len invariant**: No BPF bytecode changes. All transformations are JIT-level only.
2. **Interior edge check**: All patterns still call `bpf_jit_has_interior_edge()`.
3. **Side-effect check**: `bpf_jit_site_has_side_effects()` still runs before validation.
4. **Backward compatibility**: Existing 4-insn ROTATE and low-byte-first WIDE_MEM patterns still work.
5. **main_scan_len**: All scanners respect the main subprog boundary.

## Expected Impact

- **ROTATE**: Should now match packet_rss_hash's 32-bit rotations (6-insn pattern) AND rotate64_hash's 64-bit rotations (4-insn pattern)
- **WIDE_MEM**: Should now match clang's high-byte-first 2-byte loads (common in packet parsing)
- Combined with existing CMOV and LEA coverage, all 4 directive families should have non-zero site counts
