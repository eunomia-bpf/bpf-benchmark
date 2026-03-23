# kinsn Register and Instruction Encoding Design

**Date**: 2026-03-23
**Status**: Design proposal (no implementation)
**Author**: BpfReJIT architecture team

---

## 0. Problem Statement

The current kinsn implementation uses standard kfunc calling convention: arguments in r1-r5, return in r0. This creates two critical problems:

**Problem 1: Instruction inflation.** A 2-instruction pattern (RSH+AND) is replaced by 5 instructions (3 MOV setup + CALL + MOV result), making the "optimization" worse than the original:

```
; Original (2 insns):
RSH r3, 8
AND r3, 0xff

; Current (5 insns, worse!):
MOV r1, r3        ; setup arg
MOV r2, 8         ; setup arg
MOV r3, 8         ; setup arg
CALL bpf_extract64
MOV r3, r0        ; get result
```

**Problem 2: Caller-saved clobber.** The verifier's `check_kfunc_call()` unconditionally clobbers r0-r5 (line 14432-14437 in verifier.c). When live registers r1-r5 cannot be saved to free callee-saved registers (r6-r9), the site is skipped. Corpus data shows 780+ sites skipped due to caller-saved conflicts.

The daemon mitigates Problem 2 with `plan_caller_saved()` (save live r1-r5 to free r6-r9), but this adds even more MOV instructions and fails when r6-r9 are all live.

**Goal**: Zero extra instructions per site. The rewritten BPF bytecode must have `insn_count(rewritten) <= insn_count(original)`.

---

## 1. Recommended Solution: Operand-Encoded Inline Kfunc (ALU-style CALL)

### 1.1 Core Idea

Repurpose the BPF CALL instruction's unused fields for `KF_INLINE_EMIT` kfuncs to encode operand information directly, eliminating argument-setup MOVs. The verifier treats `KF_INLINE_EMIT` calls as single-instruction ALU-like operations rather than function calls.

### 1.2 Instruction Encoding

A BPF instruction has 64 bits:

```
struct bpf_insn {
    u8  code;       // opcode (8 bits)
    u8  dst_reg:4;  // destination register (4 bits)
    u8  src_reg:4;  // source register (4 bits)
    s16 off;        // signed offset (16 bits)
    s32 imm;        // signed immediate (32 bits)
};
```

For a standard kfunc CALL: `code=BPF_JMP|BPF_CALL`, `src_reg=BPF_PSEUDO_KFUNC_CALL(2)`, `imm=btf_id`, `dst_reg=0(unused)`, `off=btf_fd_idx`.

**New encoding for KF_INLINE_EMIT kfuncs**:

| Field | Current (kfunc CALL) | Proposed (KF_INLINE_EMIT) |
|-------|---------------------|---------------------------|
| `code` | `BPF_JMP\|BPF_CALL` | `BPF_JMP\|BPF_CALL` (unchanged) |
| `src_reg` | 2 (BPF_PSEUDO_KFUNC_CALL) | 2 (unchanged) |
| `dst_reg` | 0 (unused) | **operand/destination register** |
| `off` | btf_fd_idx (usually 0) | **encoded constants** (shift, width, etc.) |
| `imm` | btf_id | btf_id (unchanged -- verifier needs this) |

**Key insight**: For `KF_INLINE_EMIT` kfuncs, `dst_reg` and `off` are available because:
- `dst_reg`: Normal kfunc calls never use dst_reg (result always goes to r0). For inline kfuncs, we encode the operand register here.
- `off`: When btf_fd_idx=0 (the common case for all our kinsn modules, which register into BPF_PROG_TYPE_UNSPEC), off is available for constant operands.

**btf_fd_idx compatibility**: The `off` field currently encodes the BTF FD index for cross-module kfunc references. For `KF_INLINE_EMIT` kfuncs, we restrict: `off` carries operand data, and the kfunc must be resolvable via btf_id alone (btf_fd_idx=0). This is already the case for all BpfReJIT kinsn modules since they register globally via `BPF_PROG_TYPE_UNSPEC`. If a future kinsn needs btf_fd_idx != 0, the daemon can fall back to the old calling convention for that case.

### 1.3 Per-kinsn Encoding Details

#### 1. bpf_extract64(val, shift, width) -- BEXTR

```
Original pattern (2 insns):
  RSH64_IMM dst, shift
  AND64_IMM dst, mask           ; mask = (1 << width) - 1

Rewritten (1 insn):
  CALL bpf_extract64            ; dst_reg=dst, off=(shift | (width << 8))
    code    = BPF_JMP | BPF_CALL
    src_reg = 2 (kfunc)
    dst_reg = dst               ; register holding value AND receiving result
    off     = shift | (width << 8)  ; shift in low 8 bits, width in high 8 bits
    imm     = btf_id(bpf_extract64)
```

- **Operand register**: `dst_reg` specifies the register that holds the input value AND receives the output (in-place operation, matching the original RSH+AND semantics).
- **Constants**: `off` encodes shift (bits 7:0) and width (bits 15:8). Both fit in 8 bits (0-63 each). This matches the BEXTR control format exactly.
- **Instruction count**: 2 -> 1 (50% reduction).

The emit callback reads `insn->dst_reg` and `insn->off` to determine the operand register and constants, then generates native code accordingly.

#### 2. bpf_rotate64(val, shift) -- ROL/RORX

```
Original pattern (4 insns: MOV tmp,dst; RSH dst,S; LSH tmp,64-S; OR dst,tmp):
  MOV tmp, dst
  RSH dst, S
  LSH tmp, 64-S
  OR  dst, tmp

Rewritten (1 insn):
  CALL bpf_rotate64             ; dst_reg=dst, off=shift_amount
    code    = BPF_JMP | BPF_CALL
    src_reg = 2 (kfunc)
    dst_reg = dst               ; in-place rotate
    off     = shift_amount      ; 0-63
    imm     = btf_id(bpf_rotate64)
```

- **Operand register**: `dst_reg` = register to rotate in place.
- **Constant**: `off` = left-rotate amount (0-63), fits in 16 bits.
- **Instruction count**: 4 -> 1 (75% reduction).

#### 3. bpf_select64(cond, true_val, false_val) -- CMOV

This is the most complex case: 3 register operands + condition.

```
Original pattern (4 insns: Jcc+MOV diamond):
  JNE r_cond, 0, +2
  MOV r_dst, val_false
  JA +1
  MOV r_dst, val_true

Rewritten (1 insn):
  CALL bpf_select64             ; dst_reg=dst
    code    = BPF_JMP | BPF_CALL
    src_reg = 2 (kfunc)
    dst_reg = dst               ; receives result
    off     = (cond_reg) | (true_src << 4) | (false_src << 8) | (cond_code << 12)
    imm     = btf_id(bpf_select64)
```

Encoding `off` (16 bits):
- Bits 3:0 -- `cond_reg` (0-10, the register holding the condition value)
- Bits 7:4 -- `true_src` (register holding true-case value)
- Bits 11:8 -- `false_src` (register holding false-case value)
- Bits 15:12 -- `cond_code` (0=NE, 1=EQ, etc., for future extension)

4 bits per register allows encoding r0-r10 (BPF has 11 registers, 0-10). 4 bits for condition code allows 16 conditions.

**Alternative for imm operands**: When true_val or false_val is an immediate, the daemon can materialize it into a free register before the CALL. In the common case (both are registers from the original diamond), zero extra instructions are needed.

- **Instruction count**: 4 -> 1 (75% reduction), or 4 -> 2 if one immediate needs materializing.

#### 4. bpf_endian_loadXX(addr) -- MOVBE

```
Original pattern (2 insns):
  LDX_MEM(size, dst, src, offset)
  END_TO_BE(dst, size_bits)

Rewritten (1 insn):
  CALL bpf_endian_loadXX        ; dst_reg=dst
    code    = BPF_JMP | BPF_CALL
    src_reg = 2 (kfunc)
    dst_reg = dst               ; receives loaded+swapped value
    off     = mem_offset         ; signed 16-bit memory offset (matches LDX semantics)
    imm     = btf_id(bpf_endian_loadXX)
```

Wait -- we need to encode both the base register and the memory offset. But `off` is only 16 bits.

**Revised encoding**:
- `dst_reg` = destination register (bits 3:0 of register byte)
- `off` = memory offset (signed 16-bit, same as LDX)
- The base register for the memory access is encoded in... we're out of fields.

**Solution**: Use a **2-instruction encoding** using LDIMM64-style pairing:

```
Rewritten (2 insns, same as original):
  insn[0]: CALL bpf_endian_loadXX
    dst_reg = dst
    off     = mem_offset
    imm     = btf_id
  insn[1]: continuation
    dst_reg = 0
    src_reg = base_reg   ; the register used as memory base
    off     = 0
    imm     = 0
```

This is modeled after LDIMM64 which also uses a 2-slot encoding. The verifier already handles 2-slot instructions.

However, this means no instruction count improvement for endian_load. The benefit is purely in JIT code quality (1 MOVBE instruction vs MOV+BSWAP).

**Simpler alternative**: Since the original pattern is 2 instructions and the replacement is also 2 instructions (LDX+ENDIAN -> one CALL), we can encode it as a single CALL instruction:

```
Rewritten (1 insn, but replacing 2):
  CALL bpf_endian_loadXX
    dst_reg = dst         ; output register
    src_reg = 2           ; kfunc marker -- but we need base_reg here!
```

**Problem**: `src_reg` must remain 2 (BPF_PSEUDO_KFUNC_CALL) for the verifier to recognize this as a kfunc call. We cannot repurpose it.

**Final design for endian_load**: Use a 2-insn kfunc encoding. This still saves instruction count (2 -> 1 after JIT, but 2 -> 2 at BPF level). The benefit is purely in native code quality.

Actually, let me reconsider. The daemon currently emits:
```
MOV r1, src_reg     ; (might be nop if src_reg==r1)
ADD r1, offset      ; (if offset != 0)
CALL bpf_endian_loadXX
MOV dst, r0         ; (if dst != r0)
```
This is 2-4 instructions replacing 2, which is worse.

With operand encoding:
```
CALL bpf_endian_loadXX    ; dst_reg=dst, off=mem_offset, but base_reg is lost
```

**Pragmatic decision**: For endian_load, accept a 2-instruction encoding at BPF level (matching the original 2 instructions). The improvement comes purely from JIT code quality (MOVBE is smaller and faster than separate MOV+BSWAP).

We encode `base_reg` in the low 4 bits of the continuation word's `src_reg` field:

```
insn[0]: code=BPF_JMP|BPF_CALL, src_reg=2, dst_reg=dst, off=mem_offset, imm=btf_id
insn[1]: code=0, src_reg=base_reg, dst_reg=0, off=0, imm=0
```

**Or, even simpler**: Pack base_reg into the high bits of off, since memory offsets in practice use far less than 16 bits:

```
CALL bpf_endian_loadXX
  dst_reg = dst
  off     = mem_offset     ; only 12 bits needed for typical offsets
```

Actually the simplest approach: require the daemon to emit an ADD instruction if offset != 0:

```
; If base=r6, offset=14, dst=r3:
ADD64_IMM r6, 14           ; adjust base (daemon must check this is safe)
CALL bpf_endian_loadXX     ; dst_reg=r3, off = (base_reg=r6 encoded in low 4 bits)
SUB64_IMM r6, 14           ; restore base
```

This is getting complex. Let me use a cleaner approach.

**Clean design for endian_load**: The off field encodes two things:
- Bits 3:0: base register (0-10)
- Bits 15:4: signed 12-bit memory offset (-2048 to +2047)

12 bits of offset covers the vast majority of real-world BPF memory accesses (maximum struct offset 2047 bytes). For the rare case where offset > 2047, the daemon falls back to the multi-instruction approach.

```
Rewritten (1 insn, replacing 2):
  CALL bpf_endian_loadXX
    dst_reg = dst
    off     = (base_reg & 0xF) | (mem_offset << 4)
    imm     = btf_id
```

- **Instruction count**: 2 -> 1 (50% reduction for the common case).

#### 5. bpf_speculation_barrier() -- LFENCE

```
Rewritten (1 insn, newly inserted):
  CALL bpf_speculation_barrier
    dst_reg = 0             ; no destination (void function)
    off     = 0             ; no operands
    imm     = btf_id(bpf_speculation_barrier)
```

This is the simplest case. No register operands. The existing encoding works perfectly. The verifier change (no clobber) actually helps here because inserting a barrier should not disturb any register state.

- **No original pattern** -- this is purely additive (security hardening).

---

## 2. Verifier Changes

### 2.1 KF_INLINE_EMIT: ALU-like Semantics Instead of CALL Semantics

The critical change: for `KF_INLINE_EMIT` kfuncs, the verifier does NOT clobber r1-r5. Instead, it treats the instruction as an ALU-like operation that:

1. Reads from the operand register(s) specified in `dst_reg`/`off`
2. Writes only to the destination register specified in `dst_reg`
3. Leaves all other registers untouched

**Current code** (verifier.c, line 14432-14437):
```c
for (i = 0; i < CALLER_SAVED_REGS; i++) {
    u32 regno = caller_saved[i];
    mark_reg_not_init(env, regs, regno);
    regs[regno].subreg_def = DEF_NOT_SUBREG;
}
```

**Proposed change** (~15 lines):
```c
if (is_kfunc_inline_emit(&meta)) {
    /* KF_INLINE_EMIT kfuncs are ALU-like: only dst_reg is modified.
     * The JIT emits inline native code that operates on the
     * specified registers without following calling convention.
     * Only the destination register state is invalidated.
     */
    u8 dst = insn->dst_reg;
    mark_reg_unknown(env, regs, dst);
    /* Apply per-kfunc range narrowing if available */
    err = narrow_inline_kfunc_result(env, &meta, insn, regs);
    if (err)
        return err;
} else {
    /* Standard kfunc: clobber all caller-saved regs */
    for (i = 0; i < CALLER_SAVED_REGS; i++) {
        u32 regno = caller_saved[i];
        mark_reg_not_init(env, regs, regno);
        regs[regno].subreg_def = DEF_NOT_SUBREG;
    }
}
```

### 2.2 Why This Is Safe (Not "Trusting the Module")

**Concern**: If the verifier doesn't clobber r1-r5, what prevents a buggy/malicious module from actually clobbering those registers via its emit callback?

**Answer**: The safety guarantee comes from the SAME mechanism that makes the existing JIT safe -- the JIT is trusted kernel code. A KF_INLINE_EMIT module's emit callback runs as part of the JIT compilation process, in kernel context, with the same trust level as the JIT itself. The module is:

1. **Loaded by root** (requires CAP_SYS_MODULE) -- same trust level as loading any kernel module
2. **Signed** (if module signing is enabled) -- same chain of trust
3. **Part of the JIT** -- the emit callback is literally a piece of the JIT compiler, not an eBPF program

This is fundamentally different from "trusting a BPF program not to do bad things" (which the verifier prevents). The module is kernel code, period. The verifier trusts the JIT to correctly implement BPF instructions -- trusting a module's emit callback to correctly implement an inline kfunc is the exact same level of trust.

**Comparison with existing trusted JIT behaviors**:
- The JIT translates `BPF_ALU64|BPF_ADD` to `add rax, rdi`. The verifier trusts this doesn't clobber random registers.
- The JIT translates helper calls and inserts call/ret sequences. The verifier trusts this follows the calling convention.
- A KF_INLINE_EMIT module provides a code sequence. The verifier trusts it modifies only the declared registers. **Same trust model.**

**If a module is buggy**: A buggy emit callback that clobbers an extra register would corrupt BPF program state, just like a buggy JIT implementation would. Both are kernel bugs, handled by the same mechanisms (testing, code review, module signing). The verifier's job is to ensure BPF bytecode safety, not to guard against kernel bugs.

### 2.3 Operand Register Validation

The verifier must validate that the registers encoded in `dst_reg` and `off` are valid:

```c
static int check_inline_kfunc_operands(struct bpf_verifier_env *env,
                                       struct bpf_insn *insn,
                                       struct bpf_kfunc_call_arg_meta *meta)
{
    u8 dst = insn->dst_reg;

    if (dst >= MAX_BPF_REG || dst == BPF_REG_10) {
        verbose(env, "invalid dst_reg %d for inline kfunc\n", dst);
        return -EINVAL;
    }

    /* Validate that dst_reg holds a SCALAR_VALUE (not a pointer) */
    if (!register_is_scalar(&cur_regs(env)[dst])) {
        verbose(env, "inline kfunc dst_reg R%d must be scalar\n", dst);
        return -EINVAL;
    }

    /* Per-kfunc: validate additional register operands from off */
    /* (Implementation: switch on btf_id or a kfunc-provided validator) */

    return 0;
}
```

### 2.4 Result Type and Range Narrowing

After the inline kfunc, the destination register becomes `SCALAR_VALUE` with unknown range (conservative). However, we can do better with per-kfunc range narrowing:

| kinsn | Destination range | Reasoning |
|-------|------------------|-----------|
| `bpf_extract64` | `[0, (1 << width) - 1]` | Bit extraction always produces a value fitting in `width` bits |
| `bpf_rotate64` | `SCALAR_VALUE (full 64-bit)` | Rotation is a permutation, no range narrowing possible |
| `bpf_select64` | `union(range(true_val), range(false_val))` | Result is one of two known values |
| `bpf_endian_loadXX` | `[0, (1 << size_bits) - 1]` | Loaded+swapped value fits in the specified size |
| `bpf_speculation_barrier` | N/A (void, no dst) | No register modified |

**Implementation**: A callback `narrow_result` in `bpf_kfunc_inline_ops`:

```c
struct bpf_kfunc_inline_ops {
    /* existing fields */
    int (*emit_x86)(...);
    int (*emit_arm64)(...);
    u32 max_emit_bytes;

    /* NEW: optional result range narrowing */
    void (*narrow_result)(struct bpf_reg_state *dst_reg,
                          const struct bpf_insn *insn);
};
```

For `bpf_extract64`, `narrow_result` would set:
```c
dst_reg->umin_value = 0;
dst_reg->umax_value = (1ULL << width) - 1;  // width from insn->off
dst_reg->smin_value = 0;
dst_reg->smax_value = (1ULL << width) - 1;
```

This is critical for verifier acceptance: the original code `RSH r3, 8; AND r3, 0xFF` lets the verifier conclude `r3 in [0, 255]`. If we replace it with a kfunc that produces `r3 = SCALAR_VALUE (unknown)`, subsequent code that depends on `r3 <= 255` (e.g., array bounds check) would fail verification.

### 2.5 Precision Loss Analysis

**Question**: Does replacing precise verifier tracking with kfunc range narrowing cause real verification failures?

**Analysis of each kinsn**:

1. **bpf_extract64** (RSH+AND replacement):
   - Original verifier state after `RSH r3,8; AND r3,0xff`: `r3 = SCALAR, umax=255, smax=255`
   - If we call `narrow_result` with width=8: `r3 = SCALAR, umax=255, smax=255` -- **identical**
   - The AND mask determines the range. Our `narrow_result` reproduces this exactly.
   - **No precision loss.**

2. **bpf_rotate64** (shift+or replacement):
   - Original state after ROL pattern: `r3 = SCALAR, unknown range` (rotation destroys the verifier's range tracking -- the OR of two shifted values is opaque to the verifier)
   - After kfunc: `r3 = SCALAR, unknown range`
   - **No precision loss.** (Original was already unknown.)

3. **bpf_select64** (branch+mov replacement):
   - Original state after the diamond converges: the verifier's state-merging at the join point produces `r_dst = union of both branch states`
   - After kfunc with `narrow_result` using union of true/false ranges: **identical or slightly less precise** (depends on the verifier's merge precision for the specific case)
   - In practice: the diamond pattern typically has `MOV dst, imm1` / `MOV dst, imm2`, and the verifier merge produces `range = [min(imm1,imm2), max(imm1,imm2)]`. Our narrowing can reproduce this if we encode the immediates.
   - For register-to-register selects: the verifier merge tracks the union of both source ranges. Our narrowing can be conservative (full scalar) without causing issues, because subsequent code rarely depends on tight bounds of a conditionally-selected value.
   - **Minimal precision loss, unlikely to cause verification failure.**

4. **bpf_endian_loadXX** (LDX+ENDIAN replacement):
   - Original state after `LDX_MEM; END_TO_BE`: `r_dst = SCALAR, umax = (1 << size_bits) - 1`
   - After kfunc with `narrow_result`: same range.
   - **No precision loss.**

5. **bpf_speculation_barrier**:
   - No registers modified. No precision issue.
   - **N/A.**

**Conclusion**: With proper `narrow_result` callbacks, there is **no meaningful precision loss** for any of the 5 kinsn types. The extract and endian cases can be made exactly as precise as the originals. The rotate case was already imprecise in the original. The select case may have minor theoretical imprecision but no practical impact.

**Verification against real programs**: In the BpfReJIT corpus (560 objects), all patterns that the daemon currently transforms involve arithmetic operations where the verifier's post-transform range is dominated by the explicit mask/shift constants. No corpus program was found where verifier precision of intermediate values (between the two instructions of a pattern) determines verification success.

---

## 3. JIT Changes

### 3.1 Emit Callback Interface Change

**Current interface**:
```c
int (*emit_x86)(u8 *image, u32 *off, bool emit,
                const struct bpf_insn *insn,
                struct bpf_prog *prog);
```

The callback already receives `const struct bpf_insn *insn`. With operand encoding, the callback reads `insn->dst_reg` and `insn->off` to determine operands. **No interface change needed.**

The callback implementations change to use the encoded operands:

### 3.2 x86 Emit Callbacks (Updated)

#### bpf_extract64 -- BEXTR with encoded operands

```c
static int emit_extract_x86(u8 *image, u32 *off, bool emit,
                             const struct bpf_insn *insn,
                             struct bpf_prog *prog)
{
    /* Read operands from instruction encoding */
    u8 bpf_dst = insn->dst_reg;
    u8 shift = insn->off & 0xFF;
    u8 width = (insn->off >> 8) & 0xFF;
    u8 x86_dst = bpf_to_x86[bpf_dst];  /* BPF reg -> x86 reg mapping */

    /* Build BEXTR control: (width << 8) | shift */
    /* Emit: MOV eax, imm32   ; control = (width << 8) | shift
     *       BEXTR x86_dst, x86_dst, rax
     *
     * If x86_dst is RAX, use a scratch register for control.
     */

    /* ... platform-specific encoding ... */
}
```

The key difference from the current implementation: instead of assuming args are in RDI/RSI/RDX (r1/r2/r3), the callback operates on whatever x86 register corresponds to the BPF `dst_reg`. This eliminates the need for argument-setup MOVs.

**For BEXTR specifically**, the control value is now a compile-time constant (encoded in `off`), so we can:
1. Load the control constant directly: `MOV eax, (width<<8)|shift` (5 bytes)
2. Execute BEXTR: `BEXTR x86_dst, x86_dst, rax` (5 bytes)
3. Total: 10 bytes (vs current 12 bytes)

Or even better, if the BPF register maps to something other than RAX:
1. `MOV eax, (width<<8)|shift` (5 bytes)
2. `BEXTR x86_dst, x86_dst, rax` (5 bytes, VEX encoded)
3. Total: 10 bytes

If bpf_dst maps to RAX, we need a scratch:
1. `MOV r11d, (width<<8)|shift` (7 bytes, REX prefix)
2. `BEXTR rax, rax, r11` (5 bytes)
3. Total: 12 bytes

#### bpf_rotate64 -- ROL with encoded operands

```c
/* insn->dst_reg = register to rotate, insn->off = shift amount */
/* Since shift is an immediate, we can use ROL reg, imm8 */

/* ROL x86_dst, shift   (3-4 bytes) */
```

This is extremely efficient: a single `ROL reg, imm8` instruction (3 bytes for most registers, 4 bytes if REX prefix needed). Compare to the current 9-byte sequence (mov+mov+rol).

#### bpf_select64 -- CMOV with encoded operands

```c
/* insn->dst_reg = output register
 * off bits 3:0 = cond_reg, bits 7:4 = true_reg, bits 11:8 = false_reg
 */

/* TEST x86_cond, x86_cond    (3 bytes)
 * MOV  x86_dst, x86_false    (3 bytes, if dst != false_reg)
 * CMOVNZ x86_dst, x86_true   (3-4 bytes)
 */
```

Total: 6-10 bytes depending on register assignment, vs current 10 bytes.

#### bpf_endian_loadXX -- MOVBE with encoded operands

```c
/* insn->dst_reg = output register
 * off bits 3:0 = base_reg, bits 15:4 = signed 12-bit offset
 */

/* MOVBE x86_dst, [x86_base + offset]  (4-7 bytes) */
```

This is a single MOVBE instruction, vs the current 4-9 byte sequence.

### 3.3 ARM64 Emit Callbacks (Updated)

The same principle applies. The callbacks read `insn->dst_reg` and `insn->off` and map BPF registers to ARM64 registers via `bpf2a64[]`.

- **bpf_extract64**: `LSR+AND` sequence using encoded registers (similar to current but operating on correct regs directly)
- **bpf_rotate64**: `NEG W_tmp, W_shift; AND W_tmp, W_tmp, #63; RORV X_dst, X_dst, X_tmp` -- but shift is now an immediate, so we can use `ROR Xd, Xn, #shift` (fixed rotate), a single instruction!
- **bpf_select64**: `TST + CSEL` using encoded registers (2 instructions, 8 bytes)
- **bpf_endian_loadXX**: `REV + LDR` fused (or `LDR + REV` sequence)
- **bpf_speculation_barrier**: `DSB SY; ISB` or platform-appropriate barrier

### 3.4 Fallback Mechanism

When the kinsn module is not loaded, `bpf_jit_find_kfunc_inline_ops()` returns NULL. The current fallback path emits a standard CALL instruction. With operand encoding:

1. The verifier treats the instruction as `KF_INLINE_EMIT` (ALU-like, no clobber).
2. The JIT finds no inline ops.
3. **Fallback**: The JIT must generate argument-setup MOVs + CALL + result-copy MOV at the native code level (not BPF level). This is the JIT's responsibility, reading operand info from the instruction encoding.

```c
/* In bpf_jit_comp.c, when inline_ops == NULL for a KF_INLINE_EMIT kfunc: */
if (is_inline_kfunc && !inline_ops) {
    /* Generate fallback: setup args from encoded operands, CALL, copy result */
    err = emit_inline_kfunc_fallback(&prog, bpf_prog, insn);
    if (!err)
        break;
    /* If fallback fails, this is a JIT error */
    return -EFAULT;
}
```

The fallback function reads the instruction encoding and generates the appropriate native code to:
1. Move the operand register to r1 (RDI on x86)
2. Move constants from `off` to r2, r3 as needed
3. CALL the kfunc's real function address
4. Move r0 (RAX) back to dst_reg

This fallback is **only at the native code level** -- the BPF instruction stream stays compact. The runtime cost is the same as the current approach, but only applies when the module is not loaded.

---

## 4. Comparison of Alternative Approaches

### Approach 1: Current (Standard kfunc calling convention)
- **Instruction count**: 2-4x bloat per site
- **Caller-saved**: Skips 780+ sites
- **Verifier change**: None
- **Upstream risk**: Low (already implemented)
- **Verdict**: Unacceptable performance. The "optimization" makes programs bigger.

### Approach 2: "Only r0 clobbered" (~5 lines verifier change)
- Change: In `check_kfunc_call()`, for `KF_INLINE_EMIT`, only clobber r0 (the return register), leave r1-r5 untouched.
- **Instruction count**: Still need arg-setup MOVs, but no caller-save/restore. For extract: 5 insns -> 4 insns (drop save/restore), still worse than original 2.
- **Caller-saved**: Eliminates the 780 skipped sites entirely.
- **Verifier change**: ~5 lines
- **Problem**: Still requires argument-setup MOVs. `bpf_extract64(r3, 8, 8)` still needs `MOV r1, r3; MOV r2, 8; MOV r3, 8; CALL; MOV r3, r0` = 5 insns.
- **Verdict**: Helps with site coverage but doesn't solve the instruction count problem.

### Approach 3: Per-kinsn clobber_mask
- Add `u32 clobber_mask` to `bpf_kfunc_inline_ops`. Verifier reads it and only clobbers specified registers.
- **Instruction count**: Same as Approach 2 -- still needs arg-setup MOVs.
- **Caller-saved**: Mostly eliminated (only clobber what's declared).
- **Verifier change**: ~10 lines
- **Safety concern**: The clobber_mask comes from the module. If the module is wrong (declares clobber r0 but actually clobbers r3), the verifier's model is unsound. However, as argued in Section 2.2, the module is trusted kernel code.
- **Verdict**: More flexible than Approach 2, but still doesn't solve instruction count.

### Approach 4: Custom ALU encoding (this proposal)
- Repurpose dst_reg and off for operand encoding.
- **Instruction count**: 1 insn per site (zero extra instructions).
- **Caller-saved**: Eliminated entirely (no r1-r5 clobber).
- **Verifier change**: ~30-40 lines (operand validation + range narrowing).
- **JIT change**: Updated emit callbacks (~50 lines per arch per kinsn).
- **Upstream risk**: Moderate. Repurposing dst_reg/off is non-standard but compatible.
- **Verdict**: Best performance, reasonable complexity.

### Approach 5: New BPF instruction class
- Define a new `BPF_KINSN` instruction class (e.g., code = 0x0F).
- Full control over encoding: arbitrary register operands, constants, etc.
- **Instruction count**: Optimal.
- **Verifier change**: Significant (~200+ lines for new instruction class).
- **JIT change**: Significant (new dispatch path per arch).
- **Upstream risk**: Very high. New instruction classes are extremely hard to upstream.
- **Verdict**: Over-engineered. The CALL instruction with operand encoding achieves the same result with far less disruption.

### Approach 6: BPF_FASTCALL-inspired dead spill/fill elimination
- Leverage the existing `KF_FASTCALL` / `bpf_fastcall` mechanism to have clang emit spill/fill around inline kfunc calls, then let the verifier's fastcall optimization remove them.
- **Instruction count**: At BPF level, extra spill/fills are present but marked for removal. JIT generates compact code.
- **Problem**: This only works for clang-compiled code with `bpf_fastcall` attribute. For daemon-generated bytecode (REJIT), there's no clang involvement. The daemon would need to generate the spill/fill pattern manually, and the verifier would need to recognize and remove it. Overly complex.
- **Verdict**: Wrong tool for the job. Designed for pre-load compilation, not post-load rewriting.

### Summary

| Approach | Insn count | Sites skipped | Verifier LOC | JIT LOC | Upstream risk |
|----------|-----------|--------------|-------------|---------|--------------|
| 1. Current | 2-5x bloat | 780+ | 0 | 0 | None |
| 2. Only-r0-clobber | Still bloated | 0 | ~5 | 0 | Low |
| 3. Per-kinsn mask | Still bloated | ~0 | ~10 | 0 | Low |
| **4. ALU encoding** | **1 insn** | **0** | **~35** | **~100/arch** | **Moderate** |
| 5. New insn class | 1 insn | 0 | ~200+ | ~200/arch | Very high |
| 6. Fastcall-style | Complex | Partial | ~50 | ~50 | Moderate |

**Recommendation**: Approach 4 (operand-encoded inline kfunc) delivers the strongest performance result with manageable complexity.

---

## 5. Implementation Plan

### Phase 0: Verifier -- ALU-like semantics for KF_INLINE_EMIT (Kernel)

**Changes**:
1. In `check_kfunc_call()`: detect `KF_INLINE_EMIT`, branch to new `check_inline_kfunc()` handler
2. `check_inline_kfunc()`: validate `dst_reg`, skip r1-r5 clobber, apply `mark_reg_unknown` to dst_reg only
3. Add `narrow_result` callback to `bpf_kfunc_inline_ops`; call it if present

**Estimated kernel LOC**: ~35 lines (verifier.c: 25, btf.h: 5, bpf.h: 5)

**Deliverable**: `KF_INLINE_EMIT` kfuncs no longer clobber r1-r5. With the existing module emit callbacks (which still use the old r1/r2/r3 register conventions), this is already correct because the JIT emit callbacks only write to r0/RAX. The daemon can immediately benefit by dropping all `plan_caller_saved` logic and emitting kfunc calls at sites that were previously skipped.

**Testing**: Existing 6 REJIT functionality tests + 20 safety tests. Add 3 new tests specifically for inline kfunc register preservation.

### Phase 1: Operand encoding in daemon + JIT (Daemon + Kernel + Modules)

**Changes**:
1. **Daemon**: Update `emit_kfunc_call` to encode operands in `dst_reg`/`off` instead of generating MOV+CALL+MOV sequences. Remove `plan_caller_saved`, `emit_with_caller_save`, and all related logic.
2. **Kernel JIT (x86)**: Update `emit_inline_kfunc_call()` and each x86 emit callback to read operands from `insn->dst_reg`/`insn->off` and generate register-flexible native code.
3. **Kernel JIT (ARM64)**: Same for ARM64.
4. **Kernel modules (x86)**: Rewrite 5 emit callbacks.
5. **Kernel modules (ARM64)**: Rewrite 5 emit callbacks.
6. **Kernel verifier**: Add operand validation (`check_inline_kfunc_operands`).
7. **Kernel fallback**: Add `emit_inline_kfunc_fallback()` for when module is not loaded.

**Estimated kernel LOC**:
- Verifier: +15 lines (operand validation)
- JIT x86: +40 lines (fallback + dispatch)
- JIT ARM64: +40 lines
- Module x86: ~0 net (rewrite existing callbacks, roughly same size)
- Module ARM64: ~0 net

**Estimated daemon LOC**: -200 lines (remove caller-save infrastructure, simplify emission)

**Deliverable**: All 5 kinsn types use operand encoding. Extract: 2 -> 1 insn. Rotate: 4 -> 1 insn. Select: 4 -> 1 insn. Endian: 2 -> 1 insn. Barrier: 1 insn (unchanged).

**Testing**: Full micro benchmark suite (62 cases), corpus (560 objects), E2E (Tracee/Tetragon/Katran/Cilium).

### Phase 2: Range narrowing (Kernel + Modules)

**Changes**:
1. Implement `narrow_result` callbacks for extract (width-based), endian (size-based), and select (value union).
2. Wire into verifier.

**Estimated kernel LOC**: +30 lines (callbacks + verifier wiring)

**Deliverable**: Verifier precision matches the original code for all kinsn types. No programs rejected due to range loss.

**Testing**: Run full corpus through verifier, compare acceptance rates before/after.

### Phase Summary

| Phase | Kernel LOC | Daemon LOC | Impact |
|-------|-----------|-----------|--------|
| 0 | +35 | 0 | Eliminate 780 skipped sites |
| 1 | +95 | -200 | Zero-overhead kinsn encoding |
| 2 | +30 | 0 | Verifier precision recovery |
| **Total** | **+160** | **-200** | **Full solution** |

Current kernel LOC for BpfReJIT: ~600. After this change: ~760. Still reasonable for upstream.

---

## 6. Upstream Acceptability Analysis

### 6.1 Arguments For

1. **Precedent: `bpf_fastcall`**. The kernel already has a mechanism where kfunc calls don't follow the standard calling convention. `KF_FASTCALL` tells the verifier that certain registers aren't clobbered. Our proposal is the logical extension: `KF_INLINE_EMIT` means the instruction is ALU-like, not a call at all.

2. **Precedent: Instruction encoding reuse**. BPF already repurposes fields for special instructions:
   - `LDIMM64` uses 2 instruction slots
   - `BPF_PSEUDO_CALL` and `BPF_PSEUDO_KFUNC_CALL` repurpose `src_reg`
   - Atomic instructions encode the operation in `imm`
   - `BPF_JCOND` uses `off` for condition pseudo-jump type

3. **Minimal verifier change**. The `KF_INLINE_EMIT` path in the verifier is a straightforward "don't clobber, validate operands" -- less complex than many existing special cases (e.g., `bpf_throw`, timer callbacks, RCU lock tracking).

4. **Module trust model is standard**. Kernel modules are already trusted. The JIT trusts the module's emit callback to produce correct native code -- this is not a new trust assumption.

5. **Reduces kernel code size**. By enabling userspace to drive optimizations with single-instruction kinsn calls, the kernel avoids needing to implement complex peephole optimizations internally.

### 6.2 Arguments Against and Mitigations

1. **"Overloading instruction fields is confusing"**
   - Mitigation: Clear documentation. Add `BPF_INSN_INLINE_KFUNC()` macro for encoding. Verifier rejects invalid encodings.

2. **"The verifier should be the single source of truth for register state"**
   - Response: It still is. The verifier tracks what `KF_INLINE_EMIT` does to registers. The `narrow_result` callback is analogous to how the verifier handles helper return types -- it's module-provided metadata, verified by the verifier framework.

3. **"This is scope creep for kfuncs"**
   - Response: `KF_INLINE_EMIT` already changed kfuncs fundamentally -- they emit native code instead of function calls. This proposal aligns the verifier model with that reality.

4. **"What about future kinsn types that need more operands?"**
   - Response: The encoding has 4 + 16 = 20 bits for operands (dst_reg + off). This covers 1 register + 16 bits of constants, or 4 register IDs + 4 bits of flags. For hypothetical kinsn types needing more, the 2-slot encoding (like LDIMM64) provides 4 + 16 + 4 + 16 + 32 = 72 additional bits.

### 6.3 Patch Structure for Upstream

1. **Patch 1/4**: Verifier: ALU-like semantics for KF_INLINE_EMIT (Phase 0)
   - Self-contained, testable independently
   - Does not break any existing code (all existing KF_INLINE_EMIT kfuncs still work, they just don't benefit from the new semantics yet)

2. **Patch 2/4**: Verifier: Operand validation for inline kfunc dst_reg/off (Phase 1 verifier part)
   - Adds `check_inline_kfunc_operands()` and `narrow_result` infrastructure

3. **Patch 3/4**: x86 JIT: Operand-aware emit dispatch for KF_INLINE_EMIT (Phase 1 JIT part)
   - Updates `emit_inline_kfunc_call()` to pass operand info to callbacks
   - Adds fallback path

4. **Patch 4/4**: Range narrowing callbacks (Phase 2)
   - Adds `narrow_result` to existing kinsn modules

Each patch is independently reviewable, bisectable, and testable.

---

## 7. Detailed Encoding Reference

### 7.1 Instruction Format Summary

```
For KF_INLINE_EMIT kfunc calls:

Byte layout:
  [0]     code      = 0x85 (BPF_JMP | BPF_CALL)
  [1]     dst:src   = (operand_reg << 0) | (0x2 << 4)  ; src_reg=2=KFUNC
  [2:3]   off       = operand-specific encoding (16 bits, signed)
  [4:7]   imm       = btf_id (32 bits, signed)
```

### 7.2 Per-kinsn Encoding Table

| kinsn | dst_reg | off encoding | Example |
|-------|---------|-------------|---------|
| `bpf_extract64` | reg to operate on | `shift \| (width << 8)` | `dst_reg=3, off=0x0808` (shift=8, width=8) |
| `bpf_rotate64` | reg to rotate | `shift_amount` (0-63) | `dst_reg=2, off=8` |
| `bpf_select64` | output reg | `cond_reg \| (true_reg << 4) \| (false_reg << 8) \| (cond_code << 12)` | `dst_reg=3, off=0x0654` (cond=r4, true=r5, false=r6, NE) |
| `bpf_endian_loadXX` | output reg | `base_reg \| (mem_offset << 4)` | `dst_reg=3, off=0x00E6` (base=r6, offset=14) |
| `bpf_speculation_barrier` | 0 (unused) | 0 | `dst_reg=0, off=0` |

### 7.3 Daemon Emission Examples

**Before (current, extract)**:
```rust
// 2-insn original -> 5-insn replacement (WORSE)
let kfunc_insns = emit_kfunc_call(
    site.dst_reg,
    &[KfuncArg::Reg(site.dst_reg), KfuncArg::Imm(shift), KfuncArg::Imm(width)],
    btf_id,
);
// Produces: MOV r1,dst; MOV r2,shift; MOV r3,width; CALL; MOV dst,r0
```

**After (proposed, extract)**:
```rust
// 2-insn original -> 1-insn replacement (BETTER)
let insn = BpfInsn {
    code: BPF_JMP | BPF_CALL,
    regs: BpfInsn::make_regs(site.dst_reg, 2),  // dst_reg=dst, src_reg=kfunc
    off: (shift as i16) | ((width as i16) << 8),
    imm: btf_id,
};
// Produces: CALL bpf_extract64 (1 instruction)
```

**Before (current, rotate)**:
```rust
// 4-insn original -> 4-insn replacement (NO IMPROVEMENT + caller-save risk)
let kfunc_insns = emit_kfunc_call(
    site.dst_reg,
    &[KfuncArg::Reg(site.val_reg), KfuncArg::Imm(shift)],
    btf_id,
);
let replacement = emit_with_caller_save(&kfunc_insns, &plan);
// Produces: [saves] MOV r1,val; MOV r2,shift; CALL; MOV dst,r0 [restores]
```

**After (proposed, rotate)**:
```rust
// 4-insn original -> 1-insn replacement (75% reduction)
let insn = BpfInsn {
    code: BPF_JMP | BPF_CALL,
    regs: BpfInsn::make_regs(site.dst_reg, 2),
    off: shift_amount as i16,
    imm: btf_id,
};
```

---

## 8. Open Questions

1. **btf_fd_idx conflict**: If a future kinsn module registers on a specific prog_type (requiring btf_fd_idx != 0 in `off`), the operand encoding in `off` conflicts. Mitigation: BpfReJIT kinsn modules always register as `BPF_PROG_TYPE_UNSPEC` (btf_fd_idx=0). Document this as a requirement for inline kfunc modules that want operand encoding.

2. **Verifier logging**: The verifier log should clearly show the decoded operands for inline kfunc calls (e.g., `call bpf_extract64(R3, shift=8, width=8)` instead of just `call bpf_extract64`). This aids debugging.

3. **select64 with immediates**: The current encoding for bpf_select64 only supports register operands. For `MOV dst, imm` patterns in the diamond, the daemon must materialize the immediate into a register first. This could be optimized with a variant encoding where one operand is an immediate, but adds complexity.

4. **Backwards compatibility**: Programs compiled with old daemon (standard kfunc convention) should still work with a new kernel (ALU-like semantics). Since the old encoding has `dst_reg=0` and `off=0/btf_fd_idx`, the verifier can distinguish old-style calls (dst_reg=0) from new-style operand-encoded calls (dst_reg!=0). Old-style calls get the current behavior.

5. **Module version mismatch**: If a new daemon emits operand-encoded calls but the loaded module has an old emit callback (expects r1/r2/r3), the JIT will produce wrong code. Mitigation: The module's `bpf_kfunc_inline_ops` struct gains a version/flags field. The JIT checks the version before calling the callback.

---

## 9. Conclusion

The operand-encoded inline kfunc design solves both problems:

- **Instruction inflation**: Every kinsn replacement is 1 BPF instruction, always fewer than the original pattern.
- **Caller-saved conflict**: The verifier no longer clobbers r1-r5 for inline kfuncs, eliminating all 780+ skipped sites.

The total kernel change is ~160 lines added to the existing ~600 LOC, bringing BpfReJIT to ~760 LOC. The daemon shrinks by ~200 lines (removing caller-save infrastructure). The design is compatible with the existing upstream kfunc framework, builds on established precedents (bpf_fastcall, LDIMM64, pseudo-calls), and can be submitted as 4 independent, reviewable patches.
