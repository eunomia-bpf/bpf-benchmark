# BPF JIT Policy Framework v5: Declarative Pattern + Canonical Lowering

Date: 2026-03-09

## 1. Executive Summary

v5 is an architectural evolution of v4 that separates **pattern recognition** (what BPF instruction sequences to optimize) from **canonical lowering** (how to emit native code for a recognized semantic operation). The key insight comes directly from v4 Round 2 implementation experience: adding a 6-insn masked rotate pattern required ~80 LOC of kernel validator changes; adding a high-byte-first wide_mem variant required ~60 LOC of kernel validator changes. These are changes to *pattern recognition*, not to the lowering itself -- the x86 emitters for ROTATE and WIDE_MEM remained largely the same.

v5 moves pattern descriptions into the userspace policy blob, where they can be updated without kernel code changes. The kernel retains a small fixed set of **canonical forms** (~10), each with a well-defined semantic specification and per-architecture lowering implementations. A generic **pattern matcher** in the kernel interprets declarative pattern descriptions from the blob, extracts variable bindings, checks arithmetic constraints, and dispatches to the appropriate canonical form emitter.

This design draws an analogy to two well-understood systems:

1. **IDS signature engines** (Snort, Suricata): signatures are updatable data; the matching engine is stable code. Adding a new attack pattern does not require recompiling the engine.

2. **LLVM SelectionDAG / TableGen patterns**: target-independent patterns map to target-specific lowerings through a declarative pattern language. But LLVM runs in userspace with no safety constraints; our design must guarantee termination, bounded resources, and semantic preservation within the kernel.

### 1.1 Relationship to v4

v5 is **not** a replacement of v4 -- it is a strict generalization. v4's innovations remain:

- **Post-load re-JIT** via `BPF_PROG_JIT_RECOMPILE` (unchanged)
- **Native instruction selection as userspace policy** (unchanged)
- **Fail-closed, per-rule granularity** (unchanged)
- **`xlated_prog_len` invariant** (unchanged)

What changes:

| Dimension | v4 | v5 |
|-----------|----|----|
| Pattern recognition | Hardcoded C validators, one per rule_kind | Declarative pattern descriptions in blob |
| Adding new pattern variant | ~60-80 LOC kernel code | Userspace only |
| Adding new canonical form | N/A (conflated with pattern) | ~50-100 LOC kernel per arch (rare) |
| Kernel validator complexity | O(n) validators, n = number of pattern variants | O(1) generic matcher + O(k) canonical emitters, k << n |
| Pattern diversity | Limited by kernel release cycle | Unlimited by userspace update |
| Blob format | Fixed-size rule struct (16 bytes) | Variable-length: rule header + pattern + constraints + bindings |

### 1.2 The Problem v5 Solves

v4's `rule_kind` is a **closed enum**. Each optimization is identified by a kind value (COND_SELECT, WIDE_MEM, ROTATE, ADDR_CALC), and each kind has a hardcoded C validator function. This creates a coupling problem:

**Evidence from Round 2 (2026-03-09)**:

| Change | What Changed | Why | Kernel LOC |
|--------|-------------|-----|-----------|
| 6-insn masked rotate | `bpf_jit_validate_rotate_6insn()` | clang generates `mov+and+rsh+mov+lsh+or` instead of `mov+lsh+rsh+or` | ~80 |
| High-byte-first wide_mem | `bpf_jit_validate_wide_mem_high_first()` | clang generates `ldxb hi; lsh; ldxb lo; or` instead of `ldxb lo; ldxb hi; lsh; or` | ~60 |

Both changes added new BPF instruction patterns that map to the **same** canonical operations (ROTATE and WIDE_LOAD). The x86 emitters changed only to handle different register mappings -- the fundamental lowering (ror/rorx for rotate, movzx for wide load) was identical.

**Pattern diversity will only grow**:
- Different clang versions produce different idioms for the same computation
- Different BPF programs use different register allocation strategies
- Optimization levels (`-O2` vs `-O3` vs `-Os`) produce different instruction sequences
- Future compilers (GCC BPF backend) will produce yet more variants
- Hand-written BPF assembly (used in Cilium, Katran) has its own patterns

In v4, each new pattern variant requires a kernel code change, a kernel release cycle, and coordinated deployment. In v5, userspace ships new pattern descriptions alongside the programs that produce them.

---

## 2. Architecture

### 2.1 System Overview

```text
Userspace Policy Blob (v5 format):
  +----------------------------------------------+
  | Policy Header                                |
  |   magic, version=2, arch_id, prog_tag, etc.  |
  +----------------------------------------------+
  | Rule 0:                                      |
  |   site_start, site_len, canonical_form,      |
  |   native_choice, priority, cpu_features      |
  |   +-- Pattern Description (variable-length)  |
  |   |   element[0]: {opcode_mask, opcode_val,   |
  |   |                reg_bindings, imm_binding} |
  |   |   element[1]: ...                        |
  |   |   element[N-1]: ...                      |
  |   +-- Constraints (variable-length)          |
  |   |   constraint[0]: {var_a + var_b == 32}   |
  |   |   constraint[1]: {var_c == var_d}        |
  |   +-- Canonical Bindings                     |
  |       binding[0]: {param=DST, source=$var_3} |
  |       binding[1]: {param=SRC, source=$var_0} |
  |       binding[2]: {param=AMT, source=$imm_4} |
  +----------------------------------------------+
  | Rule 1: ...                                  |
  +----------------------------------------------+

Kernel (stable code):
  +----------------------------------------------+
  | Generic Pattern Matcher     (~200 LOC)       |
  |   Interprets pattern descriptions            |
  |   Extracts variable bindings                 |
  |   Always terminates (bounded by pattern_len) |
  +----------------------------------------------+
  | Constraint Verifier         (~50 LOC)        |
  |   Checks arithmetic constraints on bindings  |
  |   Always terminates (bounded by #constraints)|
  +----------------------------------------------+
  | Canonical Form Lowering     (~50-100 LOC/ea) |
  |   CANONICAL_SELECT -> cmovcc / branch        |
  |   CANONICAL_WIDE_LOAD -> movzx / ldr         |
  |   CANONICAL_ROTATE -> ror / rorx / extr      |
  |   CANONICAL_FUSED_ADDR -> lea / add(shifted) |
  |   ... (~10 forms total)                      |
  +----------------------------------------------+
  | Safety Checks (reused from v4)               |
  |   Interior edge check                        |
  |   Side-effect check                          |
  |   CPU feature gating                         |
  |   Digest binding                             |
  +----------------------------------------------+
```

### 2.2 Data Flow

```text
1. Userspace builds policy blob with declarative patterns
   (pattern descriptions, constraints, bindings per rule)

2. BPF_PROG_JIT_RECOMPILE(prog_fd, policy_fd)

3. Kernel parses blob header, validates digest binding

4. For each rule:
   a. Structural checks (bounds, subprog, CPU features)
   b. Generic side-effect check (no CALL/ST/ATOMIC in site)
   c. Interior edge check (no external jump into site interior)
   d. Pattern match: walk pattern elements against BPF insns at site
      - Extract variable bindings ($src, $dst, $tmp, $N, etc.)
   e. Constraint check: verify arithmetic relations between bindings
   f. Canonical form dispatch: call emitter with extracted bindings
   g. If any step fails -> reject rule, fall back to stock emission

5. Re-JIT with validated rule set (same mechanism as v4)
```

### 2.3 Separation of Concerns

| Concern | Owner | Update Frequency |
|---------|-------|-----------------|
| BPF instruction patterns | Userspace (policy blob) | Per-program, per-compiler-version |
| Arithmetic constraints on patterns | Userspace (policy blob) | Per-pattern |
| Variable-to-canonical-param bindings | Userspace (policy blob) | Per-pattern |
| Canonical form semantics | Kernel (fixed spec) | Rarely (~1-2 new forms/year) |
| Per-arch lowering code | Kernel (emitters) | Rarely (new arch or new form) |
| Safety checks | Kernel (fixed code) | Stable |
| CPU feature gating | Kernel (CPUID) | Stable |

This separation is the core contribution: **pattern diversity is pushed to userspace**, where it can evolve at the speed of compilers and programs; **semantic and safety guarantees are retained in the kernel**, where they change slowly and require careful review.

---

## 3. Declarative Pattern Language

### 3.1 Pattern Element Structure

A pattern is an ordered sequence of **pattern elements**, one per BPF instruction in the site. Each element describes what the instruction at that position must look like and what values to extract from it.

```c
/*
 * A single element in a declarative pattern description.
 * Matches one BPF instruction at position [site_start + element_index].
 */
struct bpf_jit_pattern_elem {
    /*
     * Opcode matching: (insn.code & opcode_mask) == opcode_value
     * Example: to match any ALU64 MOV:
     *   opcode_mask  = 0xFF (full byte)
     *   opcode_value = BPF_ALU64 | BPF_MOV | BPF_X  (= 0xbf)
     *
     * To match any conditional jump (JMP class, any op, any src):
     *   opcode_mask  = 0x07 (class bits only)
     *   opcode_value = BPF_JMP (= 0x05)
     */
    __u8  opcode_mask;
    __u8  opcode_value;

    /*
     * Register bindings: which pattern variable does each register
     * field map to? 0 = unbound (don't care), 1-15 = variable ID.
     *
     * reg_bind_dst: variable for insn.dst_reg
     * reg_bind_src: variable for insn.src_reg
     */
    __u8  reg_bind_dst;
    __u8  reg_bind_src;

    /*
     * Immediate binding: variable for insn.imm.
     * 0 = unbound, 1-15 = variable ID.
     */
    __u8  imm_binding;

    /*
     * Offset binding: variable for insn.off.
     * 0 = unbound, 1-15 = variable ID.
     */
    __u8  off_binding;

    /*
     * Flags:
     *   bit 0: if set, opcode match uses full 8-bit code
     *          (including SRC field); otherwise mask only class+op
     *   bit 1: if set, register binding requires exact match
     *          against a previously bound value (cross-reference)
     *   bit 2: if set, imm must equal an expected constant
     *          (expected_imm field used)
     *   bit 3: if set, dst_reg must equal expected_dst_reg
     *   bit 4: if set, src_reg must equal expected_src_reg
     *   bits 5-7: reserved, must be 0
     */
    __u8  flags;

    __u8  reserved;

    /*
     * Expected immediate value (used when flags bit 2 is set).
     * The instruction's imm field must equal this value exactly.
     */
    __s32 expected_imm;

    /*
     * Expected register constants (used when flags bits 3/4 are set).
     * The instruction's dst_reg/src_reg must equal these values exactly.
     * This is essential for instructions like BPF_JA where dst_reg and
     * src_reg must be zero to confirm it is a pure unconditional jump
     * (as opposed to a misencoded instruction with nonzero register fields).
     */
    __u8  expected_dst_reg;   /* checked when flags bit 3 is set */
    __u8  expected_src_reg;   /* checked when flags bit 4 is set */
    __u8  reserved2[2];
};
```

### 3.2 Variable Binding System

Pattern variables are identified by IDs 1-15. They are bound on first encounter and checked on subsequent encounters:

- **First binding**: When a pattern element references variable `$3` for `reg_bind_dst`, and variable `$3` has not been bound yet, the matcher records `var[3] = insn.dst_reg`.
- **Cross-reference**: When a later element references the same variable `$3` for `reg_bind_src`, the matcher checks `insn.src_reg == var[3]`. If not equal, the pattern fails.

This enables cross-instruction register consistency checks without hardcoding specific register values.

**Example: 4-insn rotate pattern**

```text
Pattern variables:
  $1 = tmp register
  $2 = src/dst register (original value, result goes here)
  $3 = rotation amount N (immediate)
  $4 = complement amount W-N (immediate)

Element[0]: mov $1, $2       // mov tmp <- src
  opcode_mask=0xFF, opcode_value=0xBF (ALU64|MOV|X)
  reg_bind_dst=$1, reg_bind_src=$2

Element[1]: lsh $2, $3       // lsh dst, N
  opcode_mask=0xFF, opcode_value=0xB7... (ALU64|LSH|K)
  reg_bind_dst=$2 (cross-ref), imm_binding=$3

Element[2]: rsh $1, $4       // rsh tmp, W-N
  opcode_mask=0xFF, opcode_value=... (ALU64|RSH|K)
  reg_bind_dst=$1 (cross-ref), imm_binding=$4

Element[3]: or $2, $1        // or dst, tmp
  opcode_mask=0xFF, opcode_value=... (ALU64|OR|X)
  reg_bind_dst=$2 (cross-ref), reg_bind_src=$1 (cross-ref)
```

### 3.3 Cross-Instruction Constraints

After pattern matching succeeds and all variables are bound, the constraint checker verifies arithmetic relations between bound values.

```c
/*
 * Constraint on pattern variables.
 * Checked after pattern matching extracts all variable bindings.
 */
struct bpf_jit_pattern_constraint {
    /*
     * Constraint type:
     *   1 = EQUAL:      var[var_a] == var[var_b]  (register or imm equality)
     *   2 = SUM_CONST:  var[var_a] + var[var_b] == constant
     *                   (e.g., shift amounts complement to width)
     *   3 = IMM_RANGE:  constant_lo <= var[var_a] <= constant_hi
     *                   (e.g., rotation amount in [1, width-1])
     *   4 = NOT_ZERO:   var[var_a] != 0
     *   5 = MASK_BITS:  var[var_a] & constant != 0
     *                   (e.g., AND mask must preserve relevant bits)
     *   6 = DIFF_CONST: var[var_a] - var[var_b] == constant
     *                   (e.g., hi_off - lo_off == 1 for contiguous byte loads)
     */
    __u8  type;

    /* Variable IDs (1-15) */
    __u8  var_a;
    __u8  var_b;       /* unused for IMM_RANGE, NOT_ZERO */

    __u8  reserved;

    /* Constant for SUM_CONST, IMM_RANGE, MASK_BITS */
    __s32 constant;

    /* Upper bound for IMM_RANGE */
    __s32 constant_hi;

    __u32 reserved2;
};
```

**Example: rotate constraint**

```text
Constraint[0]: SUM_CONST($3, $4, 32)   // N + (W-N) == 32 (for 32-bit rotate)
Constraint[1]: IMM_RANGE($3, 1, 31)    // rotation amount in [1, 31]
```

**Example: wide_mem constraint (high-byte-first 2B)**

```text
// High-byte-first 2-byte pattern: hi byte is at off+1, lo byte at off.
// The constraint proves that the two loaded bytes are contiguous:
//   off_hi - off_lo == 1
// where $3 = off_hi (bound from element[0].off_binding)
//       $5 = off_lo (bound from element[2].off_binding)
Constraint[0]: DIFF_CONST($3, $5, 1)   // off_hi - off_lo == 1
// Shift amounts (8) are fixed via expected_imm in the pattern elements.
```

**Example: wide_mem constraint (low-first 4B)**

```text
// Low-first 4-byte pattern: offsets must be contiguous.
//   $off0 = base offset (byte 0)
//   $off1 = byte 1 offset, $off2 = byte 2 offset, $off3 = byte 3 offset
// Each byte must be at the next offset:
Constraint[0]: DIFF_CONST($off1, $off0, 1)   // off[1] - off[0] == 1
Constraint[1]: DIFF_CONST($off2, $off0, 2)   // off[2] - off[0] == 2
Constraint[2]: DIFF_CONST($off3, $off0, 3)   // off[3] - off[0] == 3
// Shift amounts (8, 16, 24) are fixed via expected_imm in the pattern elements.
```

### 3.4 Safety Properties

The pattern language is intentionally restricted:

1. **Termination**: Pattern matching walks exactly `pattern_len` elements against `site_len` BPF instructions. Bounded by `site_len <= 24` (enforced by kernel). No loops, no recursion, no backtracking.

2. **Read-only**: Pattern matching only reads BPF instructions and writes to a local `var[16]` array. No side effects on any kernel state.

3. **Bounded resources**: At most 15 variables, at most 16 constraints, at most 24 pattern elements, at most 12 canonical bindings. All bounds enforced at blob parse time.

4. **Not Turing-complete**: The constraint language is a fixed set of arithmetic predicates (equality, sum, range, mask). No conditionals, no loops, no indirect references.

5. **Deterministic**: Given the same BPF instructions and pattern description, the matcher always produces the same result. No dependence on runtime state.

### 3.5 Pattern Length Limits

```c
#define BPF_JIT_MAX_PATTERN_LEN     24  /* max instructions in a pattern */
#define BPF_JIT_MAX_VARIABLES       15  /* variable IDs 1-15 */
#define BPF_JIT_MAX_CONSTRAINTS     16  /* max constraints per rule */
#define BPF_JIT_MAX_BINDINGS        12  /* max canonical param bindings per rule */
```

**Rationale for limits**:

- `BPF_JIT_MAX_PATTERN_LEN = 24`: The 8-byte wide_mem pattern requires `3*8 - 2 = 22` elements (one load + one shift + one OR per byte, minus the first byte's shift and last byte's OR). Setting the limit to 24 provides headroom for this pattern and any future patterns of similar length, while keeping the matcher loop bounded. The previous limit of 16 was a blocker for the highest-impact optimization (8-byte wide load, 50.7% surplus, 2.24x penalty). All safety properties (termination, bounded resources) remain satisfied since the loop count is still a compile-time constant upper bound.

- `BPF_JIT_MAX_BINDINGS = 12`: `CF_SELECT` requires up to 10 canonical parameters (DST_REG, COND_OP, COND_SRC, COND_A_REG, COND_B_REG, COND_B_IMM, TRUE_VAL, FALSE_VAL, TRUE_SRC_KIND, FALSE_SRC_KIND). The previous limit of 8 was insufficient. Setting to 12 provides headroom for future canonical forms.

These limits remain conservative for the patterns we care about (3-22 instructions typically) while keeping the kernel's resource usage bounded.

---

## 4. Canonical Forms

### 4.1 Overview

A canonical form is a **semantic operation** that the kernel knows how to lower to native code. The set of canonical forms is small and fixed -- roughly 10 entries covering the backend optimization opportunities identified in characterization.

Each canonical form has:
1. A unique identifier (enum value)
2. A semantic specification (what it computes)
3. A set of parameters (extracted from pattern variable bindings)
4. Per-architecture lowering implementations
5. Multiple native_choice variants per architecture

### 4.2 Canonical Form Definitions

```c
enum bpf_jit_canonical_form {
    /*
     * CANONICAL_SELECT: conditional selection
     *
     * Semantics: dst = (cond(a, b)) ? true_val : false_val
     *
     * Parameters:
     *   dst_reg:     destination register
     *   cond_op:     BPF condition code (JEQ, JNE, JGT, ...)
     *   cond_src:    BPF_K or BPF_X
     *   cond_a_reg:  first comparand register
     *   cond_b_reg:  second comparand register (if BPF_X)
     *   cond_b_imm:  second comparand immediate (if BPF_K)
     *   true_val:    value if condition true (reg or imm)
     *   false_val:   value if condition false (reg or imm)
     *
     * Native choices:
     *   x86:  CMOVCC (cmp + cmovcc) or BRANCH (cmp + jcc + mov)
     *   arm64: CSEL (cmp + csel) or CBRANCH (cmp + b.cond + mov)
     */
    BPF_JIT_CF_SELECT           = 1,

    /*
     * CANONICAL_WIDE_LOAD: wide memory load replacing byte ladder
     *
     * Semantics: dst = *(uN *)(base + offset)
     *            where N is the total width in bytes (2, 4, or 8)
     *
     * Parameters:
     *   dst_reg:     destination register (result)
     *   base_reg:    base address register
     *   base_off:    byte offset from base
     *   width:       total load width in bytes (2, 4, 8)
     *
     * Native choices:
     *   x86:  WIDE (movzx/mov) or BYTE_LADDER (stock)
     *   arm64: LDR_UBFX (ldr + ubfx) or BYTE_LADDER
     */
    BPF_JIT_CF_WIDE_LOAD       = 2,

    /*
     * CANONICAL_ROTATE: bitwise rotation
     *
     * Semantics: dst = rotate_left(src, amount, width)
     *            where width is 32 or 64
     *
     * Parameters:
     *   dst_reg:     destination register
     *   src_reg:     source register
     *   amount:      rotation amount (immediate, 1..width-1)
     *   width:       32 or 64
     *
     * Native choices:
     *   x86:  ROR (ror reg, imm) or RORX (rorx reg, reg, imm; BMI2)
     *         or SHIFT (stock shl+shr+or)
     *   arm64: ROR (ror) or EXTR (extr)
     */
    BPF_JIT_CF_ROTATE          = 3,

    /*
     * CANONICAL_FUSED_ADDR: fused address computation
     *
     * Semantics: dst = base + index * (1 << scale)
     *
     * Parameters:
     *   dst_reg:     destination register
     *   base_reg:    base register
     *   index_reg:   index register
     *   scale:       shift amount (1, 2, or 3 for *2, *4, *8)
     *
     * Native choices:
     *   x86:  LEA (lea dst, [base + index*scale])
     *         or SHIFT_ADD (stock mov+shl+add)
     *   arm64: ADD_SHIFTED (add dst, base, index, lsl #scale)
     */
    BPF_JIT_CF_FUSED_ADDR      = 4,

    /*
     * CANONICAL_WIDE_STORE: wide memory store replacing byte scatter
     *
     * Semantics: *(uN *)(base + offset) = src
     *            where N is the total width in bytes (2, 4, or 8)
     *
     * Parameters:
     *   src_reg:     source register (value to store)
     *   base_reg:    base address register
     *   base_off:    byte offset from base
     *   width:       total store width in bytes (2, 4, 8)
     *
     * Native choices:
     *   x86:  WIDE (mov word/dword/qword) or BYTE_SCATTER (stock)
     *   arm64: STR or BYTE_SCATTER
     */
    BPF_JIT_CF_WIDE_STORE      = 5,

    /*
     * CANONICAL_BITFIELD_EXTRACT: extract a contiguous bit field
     *
     * Semantics: dst = (src >> bit_offset) & ((1 << bit_width) - 1)
     *
     * Parameters:
     *   dst_reg:     destination register
     *   src_reg:     source register
     *   bit_offset:  starting bit position
     *   bit_width:   number of bits to extract
     *
     * Native choices:
     *   x86:  BEXTR (bextr; BMI1) or SHIFT_MASK (shr + and)
     *   arm64: UBFX (ubfx)
     */
    BPF_JIT_CF_BITFIELD_EXTRACT = 6,

    /*
     * CANONICAL_ZERO_EXTEND: zero-extend a narrow value
     *
     * Semantics: dst = (u32)src  (clear upper 32 bits)
     *
     * Parameters:
     *   dst_reg:     destination register
     *   src_reg:     source register
     *   width:       source width in bits (8, 16, 32)
     *
     * Native choices:
     *   x86:  MOVZX (movzx) or XOR_MOV (xor + mov)
     *   arm64: UXTB/UXTH/MOV
     */
    BPF_JIT_CF_ZERO_EXTEND     = 7,

    /* Reserved for future canonical forms */
    BPF_JIT_CF__MAX             = 8,
};
```

### 4.3 Canonical Form Semantic Contracts

Each canonical form has a formal semantic contract that the emitter must satisfy:

| Canonical Form | Input | Output | Side Effects | Invariant |
|---------------|-------|--------|--------------|-----------|
| SELECT | cond, true_val, false_val | dst = cond ? true_val : false_val | None | Flags may be clobbered |
| WIDE_LOAD | base, offset, width | dst = *(uW *)(base + offset) | None | No PROBE_MEM |
| ROTATE | src, amount, width | dst = ROL(src, amount, width) | None | amount in [1, width-1] |
| FUSED_ADDR | base, index, scale | dst = base + index << scale | None | scale in [1, 3] |
| WIDE_STORE | src, base, offset, width | *(uW *)(base + offset) = src | Memory write | Verified safe by original BPF |
| BITFIELD_EXTRACT | src, offset, width | dst = (src >> offset) & mask | None | offset + width <= 64 |
| ZERO_EXTEND | src, width | dst = zero_extend(src, width) | None | width in {8, 16, 32} |

The contract guarantees that any correct emitter implementation for a canonical form produces the same observable behavior as the original BPF instruction sequence, regardless of which specific BPF pattern triggered the rule.

### 4.4 Per-Architecture Lowering

Each canonical form has per-architecture emitter functions, indexed by `(canonical_form, native_choice, arch)`:

```c
/*
 * Canonical form emitter interface.
 *
 * @prog:     BPF program being JIT'd
 * @ctx:      JIT context (image pointer, offset tracking)
 * @bindings: array of extracted parameter values
 * @native_choice: which lowering variant to use
 * @addrs:    instruction address table (for offset commit)
 * @site_start: first BPF instruction index of the pattern
 * @site_len:   number of BPF instructions in the pattern
 *
 * Returns: number of native bytes emitted on success,
 *          negative errno on failure (triggers stock fallback).
 */
typedef int (*bpf_jit_canonical_emitter_t)(
    struct bpf_prog *prog,
    struct jit_context *ctx,
    const struct bpf_jit_binding_value *bindings,
    u16 native_choice,
    int *addrs,
    u32 site_start,
    u32 site_len
);

/* Registry: one emitter per canonical form per architecture */
static const bpf_jit_canonical_emitter_t
    canonical_emitters[BPF_JIT_CF__MAX] = {
    [BPF_JIT_CF_SELECT]           = emit_canonical_select_x86,
    [BPF_JIT_CF_WIDE_LOAD]        = emit_canonical_wide_load_x86,
    [BPF_JIT_CF_ROTATE]           = emit_canonical_rotate_x86,
    [BPF_JIT_CF_FUSED_ADDR]       = emit_canonical_fused_addr_x86,
    [BPF_JIT_CF_WIDE_STORE]       = NULL,  /* not yet implemented */
    [BPF_JIT_CF_BITFIELD_EXTRACT] = NULL,  /* not yet implemented */
    [BPF_JIT_CF_ZERO_EXTEND]      = NULL,  /* not yet implemented */
};
```

The v4 emitters (`emit_bpf_cmov_select`, `emit_bpf_wide_load`, `emit_bpf_rotate`, `emit_bpf_lea`) are refactored into this canonical interface with minimal changes -- they already implement the correct lowering, they just need to accept parameters from the generic binding array instead of re-parsing BPF instructions.

---

## 5. Binding Extraction

### 5.1 How Pattern Variables Map to Canonical Parameters

The policy blob includes a **binding table** for each rule that maps pattern variables to canonical form parameters:

```c
/*
 * Maps a pattern variable to a canonical form parameter.
 *
 * After pattern matching, the matcher has an array of bound values:
 *   var[1] = r3, var[2] = r5, var[3] = 13, var[4] = 19, ...
 *
 * The binding table tells the emitter which canonical parameter
 * each variable corresponds to:
 *   canonical_param=DST_REG, source_var=2  -> dst_reg = var[2] = r5
 *   canonical_param=SRC_REG, source_var=2  -> src_reg = var[2] = r5
 *   canonical_param=AMOUNT,  source_var=3  -> amount  = var[3] = 13
 */
struct bpf_jit_binding {
    /*
     * Canonical parameter ID.
     * These are per-canonical-form and defined by the canonical form spec.
     *
     * For CF_ROTATE:
     *   0 = DST_REG
     *   1 = SRC_REG
     *   2 = AMOUNT
     *   3 = WIDTH
     *
     * For CF_SELECT:
     *   0 = DST_REG
     *   1 = COND_OP
     *   2 = COND_SRC
     *   3 = COND_A_REG
     *   4 = COND_B_REG (or COND_B_IMM)
     *   5 = TRUE_VAL
     *   6 = FALSE_VAL
     *   7 = TRUE_SRC_KIND (REG or IMM)
     *   8 = FALSE_SRC_KIND (REG or IMM)
     */
    __u8  canonical_param;

    /*
     * Source variable ID (1-15) from pattern matching.
     * The value of var[source_var] is passed to the emitter
     * as the value of canonical_param.
     */
    __u8  source_var;

    /*
     * Source type:
     *   0 = REG: var[source_var] is a register number (u8)
     *   1 = IMM: var[source_var] is an immediate value (s32)
     *   2 = CONST: source_var is ignored, use inline_const instead
     */
    __u8  source_type;

    __u8  reserved;

    /*
     * Inline constant (used when source_type == CONST).
     * Allows embedding fixed values (like width=32) without
     * requiring a pattern variable.
     */
    __s32 inline_const;
};
```

### 5.2 Example: Binding Table for 6-insn Masked Rotate

The 6-insn masked 32-bit rotate pattern:
```text
[0] mov64  $1, $2       (tmp = src)
[1] and64  $1, $5       (tmp &= mask)
[2] rsh64  $1, $4       (tmp >>= complement)
[3] mov64  $3, $2       (dst = src)
[4] lsh64  $3, $6       (dst <<= N)
[5] or64   $3, $1       (dst |= tmp)
```

Pattern variables: `$1`=tmp, `$2`=src, `$3`=dst, `$4`=rsh_amount, `$5`=mask, `$6`=lsh_amount

Constraints: `SUM_CONST($6, $4, 32)`

Canonical bindings for `CF_ROTATE`:
```text
binding[0]: canonical_param=DST_REG, source_var=$3, source_type=REG
binding[1]: canonical_param=SRC_REG, source_var=$2, source_type=REG
binding[2]: canonical_param=AMOUNT,  source_var=$6, source_type=IMM
binding[3]: canonical_param=WIDTH,   source_type=CONST, inline_const=32
```

The kernel's `emit_canonical_rotate_x86()` receives these bindings and emits the same `ror` or `rorx` instruction it would have emitted under v4 -- it does not need to know whether the pattern was 4-insn or 6-insn.

### 5.3 Binding Value Array

The kernel passes extracted values to the canonical emitter via a fixed-size array:

```c
struct bpf_jit_binding_value {
    __s64 value;        /* register number (0-10) or immediate */
    __u8  type;         /* 0=REG, 1=IMM */
    __u8  reserved[7];
};

#define BPF_JIT_MAX_CANONICAL_PARAMS  12

/* Passed to canonical emitter */
struct bpf_jit_canonical_params {
    struct bpf_jit_binding_value params[BPF_JIT_MAX_CANONICAL_PARAMS];
    u8 param_count;
};
```

---

## 6. Security Model

### 6.1 Threat Model

The attacker is a privileged userspace process (`CAP_BPF`) that submits a malicious policy blob attempting to:
1. Crash the kernel
2. Execute arbitrary native code
3. Bypass BPF verification
4. Cause incorrect program behavior

### 6.2 Security Properties

**Property 1: Pattern matching cannot crash the kernel.**

Pattern matching is a bounded loop: `for (i = 0; i < pattern_len; i++)`, where `pattern_len <= BPF_JIT_MAX_PATTERN_LEN` (24). Each iteration reads one BPF instruction (already verified to be in bounds by `site_start + site_len <= insn_cnt`) and writes to `var[elem.reg_bind_dst]` where the index is bounded by 0-15. No allocation, no pointer chasing, no indirect calls.

**Property 2: Constraint checking cannot crash the kernel.**

Constraint checking is a bounded loop: `for (i = 0; i < constraint_count; i++)`, where `constraint_count <= BPF_JIT_MAX_CONSTRAINTS` (16). Each iteration performs one arithmetic comparison on values from `var[]`. All operations are on `s64` values; no division (no division by zero), no pointer operations.

**Property 3: Canonical lowering is kernel-controlled.**

The canonical emitter functions are compiled into the kernel image. Userspace cannot inject native code. The emitter receives parameter values (register numbers 0-10, immediates) and emits native instructions using the same `EMIT` macros as the stock JIT. If any parameter is out of range (e.g., register number > 10), the emitter returns an error and the rule falls back to stock emission.

**Property 4: BPF semantics are preserved.**

The `xlated_prog_len` invariant ensures no BPF instructions are modified. The canonical form semantic contracts (Section 4.3) guarantee that the native code produced by any correct emitter computes the same result as the original BPF instruction sequence. The pattern description in the blob defines what BPF sequence is being replaced; the canonical form's semantic spec defines what the replacement must compute; the emitter implements that spec.

**Property 5: Digest binding prevents stale policies.**

The `prog_tag` in the blob header must match the loaded program's SHA hash. If the program's BPF instructions change (e.g., due to a reload), old policies are rejected.

**Property 6: CPU feature gating prevents illegal instructions.**

Each rule's `cpu_features_required` field is checked against `boot_cpu_has()` before any emission. An emitter that would emit `rorx` on a non-BMI2 CPU is rejected at the rule level.

**Property 7: Interior edge check prevents broken control flow.**

The `bpf_jit_has_interior_edge()` check (unchanged from v4) ensures no external jump targets the interior of the replaced instruction sequence. This prevents `addrs[]` corruption when the pattern is collapsed to fewer native instructions.

**Property 8: Side-effect check prevents unsafe rewrites.**

The `bpf_jit_site_has_side_effects()` check (unchanged from v4) rejects sites containing `BPF_CALL`, `BPF_STX`, `BPF_ST`, or atomic operations. These instructions have side effects that the canonical emitter cannot reproduce.

### 6.3 New Risks in v5

| Risk | Mitigation |
|------|-----------|
| Malformed pattern blob causes OOB read | Pattern element indices bounded by `site_len`; `site_start + site_len <= insn_cnt` checked before matching |
| Pattern language expressive enough to encode unbounded computation | Pattern language is NOT Turing-complete: no loops, no conditionals, no indirect references. Fixed iteration count. |
| Constraint with division-by-zero | No division operator in constraint language. Only +, ==, <=, >=, !=, & |
| Variable ID out of range (>15) | Checked at blob parse time; rejected before matching begins |
| Canonical form ID out of range | `if (form >= BPF_JIT_CF__MAX) return -EINVAL;` |
| Pattern describes a semantically wrong mapping | This is the **residual risk**: v5 trusts the userspace-provided pattern-to-canonical mapping. If the pattern says "this 4-insn sequence is a ROTATE" but it is actually a different computation, the emitter will produce wrong native code. Mitigation: (1) `CAP_BPF` is required; (2) the emitter's output is functionally tested before deployment; (3) future work could add kernel-side semantic verification (see Section 12) |

### 6.4 Comparison with v4 Security Model

| Check | v4 | v5 |
|-------|----|----|
| Interior edge | Yes | Yes (unchanged) |
| Side-effect | Yes | Yes (unchanged) |
| CPU feature gating | Yes | Yes (unchanged) |
| Digest binding | Yes | Yes (unchanged) |
| Pattern correctness | Kernel C code (hardcoded) | Kernel interprets userspace pattern description |
| Semantic equivalence | Implicit in C validator | Explicit via canonical form contract |
| Trust boundary | Kernel verifies exact BPF pattern | Kernel verifies pattern matches; trusts pattern-to-canonical mapping |

The v5 trust boundary is slightly wider: v4's hardcoded validator *knows* that a specific BPF sequence is semantically equivalent to a ROTATE; v5's generic matcher *checks* that a BPF sequence matches a userspace-provided pattern description and *trusts* that the description correctly identifies it as a ROTATE. This is acceptable because:

1. `CAP_BPF` is already a strong privilege boundary
2. The pattern description is declarative and auditable
3. The canonical emitter is kernel-controlled and correct by construction
4. Fail-closed: incorrect pattern matching results in either no match (stock emission) or a wrong match that the constraint checker catches

---

## 7. UAPI Changes (Blob Format v2)

### 7.1 Policy Header

```c
#define BPF_JIT_POLICY_MAGIC     0x4A495450U    /* "JITP" */
#define BPF_JIT_POLICY_VERSION_1 1              /* v4: fixed rule structs */
#define BPF_JIT_POLICY_VERSION_2 2              /* v5: declarative patterns */

struct bpf_jit_policy_hdr_v2 {
    __u32 magic;                /* BPF_JIT_POLICY_MAGIC */
    __u16 version;              /* BPF_JIT_POLICY_VERSION_2 */
    __u16 hdr_len;              /* sizeof(this struct) = 32 */
    __u32 total_len;            /* entire blob size */
    __u32 rule_cnt;             /* number of rules */
    __u32 insn_cnt;             /* bound program insn_cnt */
    __u8  prog_tag[8];          /* BPF_TAG_SIZE, digest binding */
    __u16 arch_id;              /* BPF_JIT_ARCH_X86_64 etc */
    __u16 flags;                /* reserved */
};
```

The header is identical to v4 (`bpf_jit_policy_hdr`) except `version = 2`. This allows the kernel to distinguish v4 and v5 blobs at parse time.

### 7.2 v5 Rule Header

```c
/*
 * v5 rule header (variable-length).
 * Followed by pattern elements, constraints, and bindings.
 */
struct bpf_jit_rule_v2 {
    /* --- same as v4 --- */
    __u32 site_start;           /* BPF instruction offset */
    __u16 site_len;             /* span length in BPF insns */
    __u16 canonical_form;       /* enum bpf_jit_canonical_form (was rule_kind) */
    __u16 native_choice;        /* which lowering variant */
    __u16 priority;             /* higher wins on overlap */
    __u32 cpu_features_required;/* BPF_JIT_X86_* bits */

    /* --- v5 additions --- */
    __u16 pattern_count;        /* number of pattern elements */
    __u16 constraint_count;     /* number of constraints */
    __u16 binding_count;        /* number of canonical bindings */
    __u16 rule_len;             /* total bytes for this rule (header + data) */

    /*
     * Followed in the blob by:
     *   struct bpf_jit_pattern_elem  patterns[pattern_count];
     *   struct bpf_jit_pattern_constraint constraints[constraint_count];
     *   struct bpf_jit_binding      bindings[binding_count];
     *
     * rule_len = sizeof(this struct) +
     *            pattern_count * sizeof(bpf_jit_pattern_elem) +
     *            constraint_count * sizeof(bpf_jit_pattern_constraint) +
     *            binding_count * sizeof(bpf_jit_binding);
     */
};
```

### 7.3 Size Calculations

| Component | Size | Typical Count | Typical Total |
|-----------|------|--------------|---------------|
| Rule header | 24 bytes | 1 per rule | 24 |
| Pattern element | 16 bytes | 3-22 per rule | 48-352 |
| Constraint | 16 bytes | 0-7 per rule | 0-112 |
| Binding | 8 bytes | 2-10 per rule | 16-80 |
| **Rule total** | | | **88-568 bytes** |

Compare with v4's 16 bytes per rule. v5 rules are 5-35x larger, but still small (a blob with 100 rules is under 60KB, within the 64KB blob size limit). Typical patterns (3-8 elements) produce rules in the 88-200 byte range; only 8-byte wide_mem patterns approach the upper end.

### 7.4 Backward Compatibility

The kernel distinguishes v4 and v5 blobs by the `version` field:

```c
struct bpf_jit_policy *bpf_jit_parse_policy(struct bpf_prog *prog, int fd)
{
    /* ... read blob, validate header ... */

    switch (hdr->version) {
    case BPF_JIT_POLICY_VERSION_1:
        return bpf_jit_parse_policy_v4(prog, blob, blob_len);
    case BPF_JIT_POLICY_VERSION_2:
        return bpf_jit_parse_policy_v5(prog, blob, blob_len);
    default:
        return ERR_PTR(-EINVAL);
    }
}
```

v4 blobs continue to work with the existing hardcoded validators. v5 blobs use the new generic matcher. A transition tool can convert v4 rules to v5 format by encoding the hardcoded patterns as declarative descriptions.

### 7.5 Auto-Translation from v4 to v5

Each v4 `rule_kind` corresponds to one or more v5 pattern descriptions. The userspace tool can automatically generate v5 pattern blobs for known v4 patterns:

| v4 rule_kind | v5 canonical_form | v5 patterns |
|-------------|-------------------|-------------|
| `BPF_JIT_RK_COND_SELECT` | `BPF_JIT_CF_SELECT` | diamond (4-elem), compact (3-elem) |
| `BPF_JIT_RK_WIDE_MEM` | `BPF_JIT_CF_WIDE_LOAD` | low-first-2B (4-elem), high-first-2B (4-elem), low-first-4B (10-elem), low-first-8B (22-elem, within limit of 24) |
| `BPF_JIT_RK_ROTATE` | `BPF_JIT_CF_ROTATE` | 4-insn (4-elem), 6-insn-masked (6-elem) |
| `BPF_JIT_RK_ADDR_CALC` | `BPF_JIT_CF_FUSED_ADDR` | mov+shl+add (3-elem) |

---

## 8. Kernel Implementation

### 8.1 Generic Pattern Matcher

```c
/*
 * Match a declarative pattern against BPF instructions at a given site.
 *
 * @insns:      BPF instruction array
 * @insn_cnt:   total instruction count
 * @site_start: first instruction index
 * @site_len:   number of instructions in site
 * @elems:      pattern element array (from blob)
 * @elem_count: number of pattern elements (must == site_len)
 * @vars:       output variable bindings (caller-provided, zeroed)
 *
 * Returns: true if all elements match and all cross-references pass.
 *          On success, vars[1..15] contain the extracted values.
 */
static bool bpf_jit_match_pattern(
    const struct bpf_insn *insns,
    u32 insn_cnt,
    u32 site_start,
    u32 site_len,
    const struct bpf_jit_pattern_elem *elems,
    u16 elem_count,
    struct bpf_jit_var vars[BPF_JIT_MAX_VARIABLES + 1])
{
    u16 i;

    if (elem_count != site_len)
        return false;
    if (site_start + site_len > insn_cnt)
        return false;

    for (i = 0; i < elem_count; i++) {
        const struct bpf_insn *insn = &insns[site_start + i];
        const struct bpf_jit_pattern_elem *elem = &elems[i];

        /* Step 1: opcode match */
        if ((insn->code & elem->opcode_mask) != elem->opcode_value)
            return false;

        /* Step 2: expected immediate check (if flag bit 2 set) */
        if ((elem->flags & 0x04) && insn->imm != elem->expected_imm)
            return false;

        /* Step 2b: expected register constant checks (flags bits 3/4) */
        if ((elem->flags & 0x08) && insn->dst_reg != elem->expected_dst_reg)
            return false;
        if ((elem->flags & 0x10) && insn->src_reg != elem->expected_src_reg)
            return false;

        /* Step 3: register binding - dst */
        if (elem->reg_bind_dst) {
            u8 var_id = elem->reg_bind_dst;
            if (var_id > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[var_id].bound) {
                vars[var_id].value = insn->dst_reg;
                vars[var_id].type = BPF_JIT_VAR_REG;
                vars[var_id].bound = true;
            } else {
                /* Type consistency: reject cross-type binding */
                if (vars[var_id].type != BPF_JIT_VAR_REG)
                    return false;
                /* Cross-reference: must match previously bound value */
                if (vars[var_id].value != insn->dst_reg)
                    return false;
            }
        }

        /* Step 4: register binding - src */
        if (elem->reg_bind_src) {
            u8 var_id = elem->reg_bind_src;
            if (var_id > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[var_id].bound) {
                vars[var_id].value = insn->src_reg;
                vars[var_id].type = BPF_JIT_VAR_REG;
                vars[var_id].bound = true;
            } else {
                if (vars[var_id].type != BPF_JIT_VAR_REG)
                    return false;
                if (vars[var_id].value != insn->src_reg)
                    return false;
            }
        }

        /* Step 5: immediate binding */
        if (elem->imm_binding) {
            u8 var_id = elem->imm_binding;
            if (var_id > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[var_id].bound) {
                vars[var_id].value = insn->imm;
                vars[var_id].type = BPF_JIT_VAR_IMM;
                vars[var_id].bound = true;
            } else {
                if (vars[var_id].type != BPF_JIT_VAR_IMM)
                    return false;
                if (vars[var_id].value != insn->imm)
                    return false;
            }
        }

        /* Step 6: offset binding */
        if (elem->off_binding) {
            u8 var_id = elem->off_binding;
            if (var_id > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[var_id].bound) {
                vars[var_id].value = insn->off;
                vars[var_id].type = BPF_JIT_VAR_OFF;
                vars[var_id].bound = true;
            } else {
                if (vars[var_id].type != BPF_JIT_VAR_OFF)
                    return false;
                if (vars[var_id].value != (s16)insn->off)
                    return false;
            }
        }
    }

    return true;
}
```

### 8.2 Constraint Checker

```c
/*
 * Check arithmetic constraints on extracted variable bindings.
 *
 * Returns: true if all constraints are satisfied.
 */
static bool bpf_jit_check_constraints(
    const struct bpf_jit_pattern_constraint *constraints,
    u16 count,
    const struct bpf_jit_var vars[BPF_JIT_MAX_VARIABLES + 1])
{
    u16 i;

    for (i = 0; i < count; i++) {
        const struct bpf_jit_pattern_constraint *c = &constraints[i];
        s64 val_a, val_b;

        if (c->var_a == 0 || c->var_a > BPF_JIT_MAX_VARIABLES)
            return false;
        if (!vars[c->var_a].bound)
            return false;
        val_a = vars[c->var_a].value;

        switch (c->type) {
        case BPF_JIT_CSTR_EQUAL:
            if (c->var_b == 0 || c->var_b > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[c->var_b].bound)
                return false;
            val_b = vars[c->var_b].value;
            if (val_a != val_b)
                return false;
            break;

        case BPF_JIT_CSTR_SUM_CONST:
            if (c->var_b == 0 || c->var_b > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[c->var_b].bound)
                return false;
            val_b = vars[c->var_b].value;
            if (val_a + val_b != (s64)c->constant)
                return false;
            break;

        case BPF_JIT_CSTR_IMM_RANGE:
            if (val_a < (s64)c->constant || val_a > (s64)c->constant_hi)
                return false;
            break;

        case BPF_JIT_CSTR_NOT_ZERO:
            if (val_a == 0)
                return false;
            break;

        case BPF_JIT_CSTR_MASK_BITS:
            if ((val_a & (s64)c->constant) == 0)
                return false;
            break;

        case BPF_JIT_CSTR_DIFF_CONST:
            /* var[var_a] - var[var_b] == constant */
            if (c->var_b == 0 || c->var_b > BPF_JIT_MAX_VARIABLES)
                return false;
            if (!vars[c->var_b].bound)
                return false;
            val_b = vars[c->var_b].value;
            if (val_a - val_b != (s64)c->constant)
                return false;
            break;

        default:
            return false;  /* unknown constraint type -> fail-closed */
        }
    }

    return true;
}
```

### 8.3 v5 Rule Validation

The v5 rule validation replaces v4's per-`rule_kind` validators with the generic pipeline:

```c
static bool bpf_jit_validate_rule_v5(
    const struct bpf_insn *insns,
    u32 insn_cnt,
    const struct bpf_jit_rule_v5 *rule)
{
    struct bpf_jit_var vars[BPF_JIT_MAX_VARIABLES + 1] = {};

    /* Check bounds */
    if (rule->site_start + rule->site_len > insn_cnt)
        return false;

    /* Check canonical form is known */
    if (rule->canonical_form >= BPF_JIT_CF__MAX)
        return false;

    /* Check canonical emitter exists */
    if (!canonical_emitters[rule->canonical_form])
        return false;

    /* CPU feature gating */
    if (rule->cpu_features_required &&
        !bpf_jit_check_cpu_features(rule->cpu_features_required))
        return false;

    /* Layer-2: side-effect check */
    if (bpf_jit_site_has_side_effects(insns, rule->site_start, rule->site_len))
        return false;

    /* Interior edge check */
    if (bpf_jit_has_interior_edge(insns, insn_cnt,
                                   rule->site_start, rule->site_len))
        return false;

    /* Pattern matching */
    if (!bpf_jit_match_pattern(insns, insn_cnt,
                                rule->site_start, rule->site_len,
                                rule->patterns, rule->pattern_count,
                                vars))
        return false;

    /* Constraint checking */
    if (!bpf_jit_check_constraints(rule->constraints,
                                    rule->constraint_count,
                                    vars))
        return false;

    /* Extract canonical bindings */
    if (!bpf_jit_extract_bindings(rule->bindings, rule->binding_count,
                                   vars, &rule->params))
        return false;

    return true;
}
```

### 8.4 Integration with do_jit()

The integration with the JIT main loop is identical to v4:

```c
/* In do_jit() main loop */
for (i = 1; i <= insn_cnt; i++, insn++) {
    u32 bpf_idx = i - 1;
    const struct bpf_jit_rule *rule;
    int emit_len;

    rule = bpf_jit_rule_lookup(ruleset, bpf_idx);
    if (rule && (rule->flags & BPF_JIT_REWRITE_F_ACTIVE)) {
        /* v5: dispatch to canonical emitter with extracted bindings */
        emit_len = canonical_emitters[rule->canonical_form](
            prog, &ctx, &rule->params,
            rule->native_choice,
            addrs, bpf_idx, rule->site_len
        );
        if (emit_len >= 0) {
            bpf_jit_commit_addrs(addrs, bpf_idx,
                                  rule->site_len, emit_len);
            i += rule->site_len - 1;
            insn += rule->site_len - 1;
            continue;
        }
        /* Failure: fall through to stock emission */
    }

    /* Stock emission (original switch-case) */
    ...
}
```

The only difference from v4 is that rule dispatch calls through `canonical_emitters[]` instead of a `switch(rule->rule_kind)`. This is a minor refactoring.

### 8.5 Estimated Kernel Code Changes

| Component | New LOC | Modified LOC | Notes |
|-----------|---------|-------------|-------|
| Generic pattern matcher | ~80 | 0 | New function, self-contained |
| Constraint checker | ~60 | 0 | New function, self-contained |
| Binding extractor | ~30 | 0 | New function |
| v5 blob parser | ~100 | 0 | New function for version=2 |
| Canonical emitter registry | ~20 | 0 | Array of function pointers |
| v4 validator refactor | 0 | ~50 | Extract params into binding arrays |
| **Total kernel** | **~290** | **~50** | **~340 LOC total change** |

The v4 emitters (`emit_bpf_cmov_select`, `emit_bpf_wide_load`, `emit_bpf_rotate`, `emit_bpf_lea`) require minimal changes: replace direct BPF instruction access with reads from the canonical parameter array. The emission logic itself does not change.

---

## 9. Userspace Changes

### 9.1 Pattern Description Builder

The userspace tool's scanners (`find_cmov_select_sites_xlated`, `find_rotate_sites_xlated`, etc.) are replaced with a pattern-based approach. Instead of hardcoding the BPF instruction sequence in C++, the tool describes the pattern declaratively:

```python
# Pseudocode for v5 pattern builder

def build_rotate_4insn_pattern():
    """Build declarative pattern for 4-insn rotate."""
    return PatternRule(
        canonical_form=CF_ROTATE,
        pattern=[
            PatternElem(opcode=MOV64_X, dst_bind=1, src_bind=2),   # mov tmp, src
            PatternElem(opcode=LSH64_K, dst_bind=2, imm_bind=3),   # lsh dst, N
            PatternElem(opcode=RSH64_K, dst_bind=1, imm_bind=4),   # rsh tmp, W-N
            PatternElem(opcode=OR64_X,  dst_bind=2, src_bind=1),   # or dst, tmp
        ],
        constraints=[
            SumConst(var_a=3, var_b=4, constant=64),  # N + (W-N) == 64
            ImmRange(var_a=3, lo=1, hi=63),            # N in [1, 63]
        ],
        bindings=[
            Binding(param=DST_REG, source_var=2, type=REG),
            Binding(param=SRC_REG, source_var=2, type=REG),  # src==dst for in-place
            Binding(param=AMOUNT,  source_var=3, type=IMM),
            Binding(param=WIDTH,   type=CONST, value=64),
        ],
    )

def build_rotate_6insn_masked_pattern():
    """Build declarative pattern for 6-insn masked 32-bit rotate."""
    return PatternRule(
        canonical_form=CF_ROTATE,
        pattern=[
            PatternElem(opcode=MOV64_X, dst_bind=1, src_bind=2),   # mov tmp, src
            PatternElem(opcode=AND64_K, dst_bind=1, imm_bind=5),   # and tmp, mask
            PatternElem(opcode=RSH64_K, dst_bind=1, imm_bind=4),   # rsh tmp, 32-N
            PatternElem(opcode=MOV64_X, dst_bind=3, src_bind=2),   # mov dst, src
            PatternElem(opcode=LSH64_K, dst_bind=3, imm_bind=6),   # lsh dst, N
            PatternElem(opcode=OR64_X,  dst_bind=3, src_bind=1),   # or dst, tmp
        ],
        constraints=[
            SumConst(var_a=6, var_b=4, constant=32),  # N + complement == 32
            ImmRange(var_a=6, lo=1, hi=31),            # N in [1, 31]
            NotZero(var_a=5),                          # mask != 0
        ],
        bindings=[
            Binding(param=DST_REG, source_var=3, type=REG),
            Binding(param=SRC_REG, source_var=2, type=REG),
            Binding(param=AMOUNT,  source_var=6, type=IMM),
            Binding(param=WIDTH,   type=CONST, value=32),
        ],
    )
```

### 9.2 Pattern Library

The key advantage of v5 is that new patterns can be added as **data** without code changes:

```python
# Pattern library: all known patterns for each canonical form
PATTERN_LIBRARY = {
    CF_ROTATE: [
        build_rotate_4insn_pattern(),         # 64-bit, standard
        build_rotate_6insn_masked_pattern(),   # 32-bit, clang masked
        # Future: add new pattern variants here
        # No kernel changes needed!
    ],
    CF_SELECT: [
        build_select_diamond_pattern(),        # jcc+2, mov, ja+1, mov
        build_select_compact_pattern(),        # mov, jcc+1, mov
        # Future: GCC may produce different cmov patterns
    ],
    CF_WIDE_LOAD: [
        build_wide_load_low_first_2b(),        # lo-byte, hi-byte, shift, or
        build_wide_load_high_first_2b(),       # hi-byte, shift, lo-byte, or
        build_wide_load_low_first_4b(),        # 4 bytes, low first
        # Future: big-endian patterns, different register allocation
    ],
    CF_FUSED_ADDR: [
        build_fused_addr_3insn(),              # mov+shl+add
        # Future: shl+add (2-insn, when index is already in dst)
    ],
}
```

### 9.3 Scanner Refactoring

The existing per-kind scanners are replaced by a single generic scanner that tries all patterns from the library:

```python
def find_all_optimization_sites(xlated_insns, pattern_library):
    """
    Scan xlated BPF instructions for all pattern matches.
    Returns a list of (site_start, site_len, pattern_rule) tuples.
    """
    sites = []
    for canonical_form, patterns in pattern_library.items():
        for pattern in patterns:
            for i in range(len(xlated_insns) - pattern.length + 1):
                if pattern.matches(xlated_insns, i):
                    sites.append((i, pattern.length, pattern))
    return sites
```

This is simpler than v4's four separate scanner functions and automatically handles all pattern variants.

---

## 10. Concrete Example: Round 2 Fixes Without Kernel Changes

This section demonstrates the core value proposition: the Round 2 changes that required ~140 LOC of kernel code in v4 become **purely userspace changes** in v5.

### 10.1 6-insn Masked Rotate

**v4 (kernel change required)**:
- Added `bpf_jit_validate_rotate_6insn()` (~80 LOC in `jit_directives.c`)
- Modified `bpf_jit_validate_rotate_rule()` to dispatch between 4-insn and 6-insn
- Modified `emit_bpf_rotate()` in `bpf_jit_comp.c` to handle `site_len==6`

**v5 (userspace only)**:
- Add a new entry to `PATTERN_LIBRARY[CF_ROTATE]`:

```python
# This is the ENTIRE change needed in v5:
PATTERN_LIBRARY[CF_ROTATE].append(
    PatternRule(
        canonical_form=CF_ROTATE,
        pattern=[
            PatternElem(opcode=0xBF, dst_bind=1, src_bind=2),   # mov64 tmp, src
            PatternElem(opcode=0x54, dst_bind=1, imm_bind=5),   # and64 tmp, mask
            PatternElem(opcode=0x77, dst_bind=1, imm_bind=4),   # rsh64 tmp, 32-N
            PatternElem(opcode=0xBF, dst_bind=3, src_bind=2),   # mov64 dst, src
            PatternElem(opcode=0x67, dst_bind=3, imm_bind=6),   # lsh64 dst, N
            PatternElem(opcode=0x4F, dst_bind=3, src_bind=1),   # or64 dst, tmp
        ],
        constraints=[
            SumConst(var_a=6, var_b=4, constant=32),
            ImmRange(var_a=6, lo=1, hi=31),
            NotZero(var_a=5),
        ],
        bindings=[
            Binding(param=DST_REG, source_var=3, type=REG),
            Binding(param=SRC_REG, source_var=2, type=REG),
            Binding(param=AMOUNT,  source_var=6, type=IMM),
            Binding(param=WIDTH,   type=CONST, value=32),
        ],
    )
)
```

The kernel's generic pattern matcher handles this new pattern without any kernel code change. The `emit_canonical_rotate_x86()` emitter receives `{dst=r3, src=r2, amount=N, width=32}` and emits the same `ror` or `rorx` instruction it always does. It does not need to know the pattern was 6 instructions instead of 4.

### 10.2 High-Byte-First Wide Load

**v4 (kernel change required)**:
- Added `bpf_jit_validate_wide_mem_high_first()` (~60 LOC in `jit_directives.c`)
- Modified `bpf_jit_validate_wide_mem_rule()` to try both low-first and high-first
- Modified `emit_bpf_wide_load()` to detect high-first register mapping

**v5 (userspace only)**:

```python
PATTERN_LIBRARY[CF_WIDE_LOAD].append(
    PatternRule(
        canonical_form=CF_WIDE_LOAD,
        pattern=[
            # [0] ldxb tmp, [base+off+1]  (high byte)
            PatternElem(opcode=0x71, dst_bind=1, src_bind=2, off_bind=3),
            # [1] lsh64 tmp, 8
            PatternElem(opcode=0x67, dst_bind=1, expected_imm=8, flags=FLAG_CHECK_IMM),
            # [2] ldxb dst, [base+off]  (low byte, same base, off-1)
            PatternElem(opcode=0x71, dst_bind=4, src_bind=2, off_bind=5),
            # [3] or64 tmp, dst
            PatternElem(opcode=0x4F, dst_bind=1, src_bind=4),
        ],
        constraints=[
            # off_hi - off_lo == 1  (hi byte is at off+1, lo byte at off)
            # Expressed as: var[3] - var[5] == 1
            DiffConst(var_a=3, var_b=5, constant=1),
        ],
        bindings=[
            Binding(param=DST_REG, source_var=1, type=REG),   # result in tmp
            Binding(param=BASE_REG, source_var=2, type=REG),
            Binding(param=BASE_OFF, source_var=5, type=IMM),   # low byte offset
            Binding(param=WIDTH,    type=CONST, value=2),
        ],
    )
)
```

Again, the kernel's `emit_canonical_wide_load_x86()` receives `{dst=tmp, base=r2, offset=off, width=2}` and emits `movzx dst, word [base+off]`. The emitter does not need to know whether the pattern was low-first or high-first.

### 10.3 Comparison Summary

| Change | v4: Kernel LOC | v5: Kernel LOC | v5: Userspace LOC |
|--------|:---:|:---:|:---:|
| 6-insn masked rotate | ~80 | 0 | ~30 (pattern definition) |
| High-byte-first wide_mem | ~60 | 0 | ~25 (pattern definition) |
| **Total** | **~140** | **0** | **~55** |

The v5 userspace LOC is also simpler: it is declarative data (opcode values, variable IDs, constraint parameters), not imperative C code with complex control flow.

---

## 11. Extensibility Analysis

### 11.1 Adding a New Pattern for an Existing Canonical Form

**Effort**: Userspace only. Write a `PatternRule` with pattern elements, constraints, and bindings. Serialize into the policy blob.

**Kernel changes**: None.

**Examples**:
- GCC generates a different rotate idiom
- New clang version reorders a cmov diamond
- Hand-written BPF assembly uses a different register allocation for byte ladder

**Deployment**: Ship updated userspace tool. No kernel upgrade needed.

### 11.2 Adding a New Canonical Form

**Effort**: ~50-100 LOC per architecture in the kernel.

**Steps**:
1. Add new entry to `enum bpf_jit_canonical_form`
2. Define parameter set and semantic contract
3. Implement `emit_canonical_XXX_x86()` and/or `emit_canonical_XXX_arm64()`
4. Register in `canonical_emitters[]` array
5. Define `native_choice` enum values

**Frequency**: Rare. Based on characterization data, the current 7 canonical forms cover the major backend optimization opportunities. New forms would be added when a new category of optimization is discovered (e.g., loop unrolling hints, SIMD widening).

### 11.3 Adding a New Architecture

**Effort**: ~50-100 LOC per existing canonical form.

**Steps**:
1. Add `BPF_JIT_ARCH_XXX` value
2. Implement `emit_canonical_XXX_arch()` for each supported canonical form
3. Define `native_choice` enum values for arch-specific lowerings
4. Implement `bpf_jit_check_cpu_features_arch()` for arch-specific CPU feature checks

**Example**: arm64 implementation
```c
/* arm64 canonical emitters */
static int emit_canonical_select_arm64(...)  { /* csel / b.cond */ }
static int emit_canonical_rotate_arm64(...)  { /* ror / extr */ }
static int emit_canonical_wide_load_arm64(...) { /* ldr / ldrb+ubfx */ }
static int emit_canonical_fused_addr_arm64(...) { /* add shifted */ }
```

### 11.4 Extensibility Comparison

| Operation | v4 Kernel LOC | v5 Kernel LOC | v5 Userspace LOC |
|-----------|:---:|:---:|:---:|
| New BPF pattern variant | 60-80 | 0 | 20-30 |
| New canonical form | N/A | 50-100/arch | 10-20 (enum + pattern) |
| New architecture | 50-100/rule_kind | 50-100/canonical_form | 0 |
| New native_choice | 20-40 | 20-40 | 5 (enum value) |

The key improvement is the first row: new pattern variants -- the most common type of change -- require zero kernel code.

---

## 12. Risks and Mitigations

### 12.1 Pattern Correctness

**Risk**: A buggy or malicious pattern description incorrectly identifies a BPF sequence as a canonical form it does not actually implement. For example, a pattern claims a 4-insn sequence is a ROTATE, but the sequence actually computes something else.

**Impact**: The canonical emitter would produce native code that computes a rotation instead of the correct operation. This would silently corrupt program execution.

**Mitigations**:
1. **Privilege boundary**: `CAP_BPF` is required. Only privileged loaders can submit policies.
2. **Functional testing**: The userspace tool can verify patterns against known BPF programs before deployment (e.g., run with and without the policy and compare outputs).
3. **Constraint narrowing**: Arithmetic constraints reduce the space of possible matches. A pattern that accidentally matches an unintended sequence would likely fail constraint checks.
4. **Future work: kernel-side semantic verification**. For high-assurance deployments, the kernel could optionally verify that the original BPF instruction sequence and the canonical form compute the same output by running both paths on a few test inputs (similar to BPF_PROG_TEST_RUN). This is expensive but could be gated behind a flag.

### 12.2 Pattern Matching Performance

**Risk**: The generic pattern matcher is slower than v4's hardcoded C validators.

**Analysis**: The generic matcher performs `pattern_len * 6` comparisons per rule (opcode match + up to 4 register/imm bindings + expected_imm). For a typical 4-element pattern, this is 24 comparisons. v4's hardcoded validator performs roughly the same number of comparisons but with fewer indirections. The overhead is:
- One additional array indexing per element (into the `elems[]` array)
- One additional branch per element (bound/unbound check in variable binding)

For a typical program with 10-20 rules and JIT compilation taking milliseconds, the pattern matching overhead is negligible (microseconds).

**Mitigation**: If profiling shows pattern matching is a bottleneck, patterns can be pre-compiled to a compact bytecode at blob parse time. But this optimization is unlikely to be needed.

### 12.3 Canonical Form Set Growth

**Risk**: The set of canonical forms grows unboundedly, eventually requiring frequent kernel changes.

**Analysis**: Based on characterization data and the optimization literature, the current 7 canonical forms cover the major categories:
- Data movement: WIDE_LOAD, WIDE_STORE, ZERO_EXTEND
- Arithmetic: ROTATE, FUSED_ADDR, BITFIELD_EXTRACT
- Control flow: SELECT

New canonical forms would correspond to fundamentally new categories of optimization, which are discovered rarely in mature architectures. LLVM's SelectionDAG has ~100 target-independent nodes, but most are not applicable to the BPF JIT (which does not do register allocation, instruction scheduling, or loop optimization). We estimate 1-2 new canonical forms per year at most.

**Mitigation**: The canonical form set is designed to be small and stable. If a new optimization does not fit any existing canonical form, it is a signal that a new form is needed -- but this should be rare.

### 12.4 Pattern Language Expressiveness

**Risk**: Some patterns cannot be expressed in the current pattern language.

**Known limitations**:
- Patterns with **variable length** (e.g., N-byte wide load for arbitrary N) cannot be expressed as a single pattern. Workaround: define separate patterns for each supported width (2, 4, 8).
- Patterns with **non-contiguous instructions** (e.g., two ALU operations separated by an unrelated instruction) cannot be expressed. Workaround: only match contiguous instruction sequences (this is already the v4 constraint).
- Patterns requiring **data-flow analysis** (e.g., "this register is not used after this point") cannot be expressed. Workaround: rely on the original BPF program's structure (the verifier has already done data-flow analysis; the pattern matcher just checks structural shapes).

**Mitigation**: The pattern language is intentionally conservative. It handles the patterns we have identified in practice (3-8 contiguous instructions with register/immediate constraints). If future patterns require more expressiveness, the language can be extended (e.g., adding wildcard elements, optional elements, or data-flow constraints) without breaking existing patterns.

---

## 13. Comparison with Related Work

### 13.1 LLVM SelectionDAG / TableGen Patterns

LLVM's instruction selection uses TableGen to declaratively describe target-specific patterns:
```
def : Pat<(rotl GR32:$src, (i8 imm:$amt)),
          (ROL32ri GR32:$src, imm:$amt)>;
```

This is the closest analogy to v5's declarative patterns. Key differences:

| Dimension | LLVM TableGen | v5 Declarative Patterns |
|-----------|--------------|------------------------|
| Trust model | Runs in userspace, no safety constraints | Runs in kernel, must guarantee termination and safety |
| Pattern complexity | Arbitrary DAG patterns | Linear instruction sequence only |
| Optimization scope | Full compiler backend | Post-verification JIT lowering only |
| Update mechanism | Recompile LLVM | Update policy blob at runtime |
| Target abstraction | Full target description (register classes, instruction scheduling, etc.) | Minimal (canonical form params, CPU feature bits) |

Our contribution is demonstrating that the *concept* of declarative pattern matching can be adapted to the kernel JIT context with strict safety guarantees and runtime updatability.

### 13.2 GCC Machine Descriptions

GCC uses `.md` files to describe target instructions:
```
(define_insn "rotlsi3"
  [(set (match_operand:SI 0 "register_operand" "=r")
        (rotate:SI (match_operand:SI 1 "register_operand" "0")
                   (match_operand:QI 2 "immediate_operand" "I")))]
  ...
  "rol{l}\t{%2, %0|%0, %2}")
```

These are compiled into the compiler itself. They cannot be updated at runtime and do not have a safety verification layer. Our canonical forms serve a similar role to GCC's "standard pattern names" (rotlsi3, etc.) but with a runtime-updateable pattern-matching frontend.

### 13.3 Superoptimizers (STOKE, Souper)

Superoptimizers search for optimal instruction sequences by enumerating or synthesizing candidates. They are expensive (minutes to hours per sequence) and run purely in userspace. v5's canonical form lowering is closer to pattern-driven instruction selection than superoptimization -- it selects from a fixed set of known-good lowerings rather than searching for new ones.

### 13.4 BPF Bytecode Optimizers (K2, Merlin, EPSO)

These tools optimize at the BPF bytecode level (before JIT). They cannot affect native code emission choices. v5 operates at a different layer entirely -- after BPF verification, during JIT compilation. The two approaches are complementary: a K2-optimized BPF program can still benefit from v5's native lowering improvements.

### 13.5 Summary of Positioning

Our contribution is the first system that combines:
1. **Declarative pattern matching** (like LLVM TableGen)
2. **In-kernel execution with safety guarantees** (unlike any compiler)
3. **Runtime updatability** (unlike any compiled compiler)
4. **User-controllable policy** (unlike any existing kernel JIT)

This is a new point in the design space: a kernel subsystem that accepts user-defined optimization rules, verifies their safety declaratively, and applies them during JIT compilation.

---

## 14. Implementation Plan

### 14.1 Phase 1: Generic Pattern Matcher + Constraint Checker (~250 LOC kernel)

**Goal**: Implement the core v5 machinery alongside the existing v4 validators.

**Steps**:
1. Add `bpf_jit_match_pattern()` and `bpf_jit_check_constraints()` functions
2. Add v5 blob parser (`bpf_jit_parse_policy_v5`) that creates rules with pattern descriptions
3. Add `bpf_jit_validate_rule_v5()` that uses the generic matcher instead of per-kind validators
4. Wire up version dispatch in `bpf_jit_parse_policy()`

**Validation**: Create v5 pattern descriptions for the existing v4 patterns (4-insn rotate, low-first wide_mem) and verify they produce identical rule sets.

### 14.2 Phase 2: Canonical Emitter Registry (~50 LOC kernel)

**Goal**: Refactor v4 emitters into the canonical emitter interface.

**Steps**:
1. Define `bpf_jit_canonical_emitter_t` function pointer type
2. Refactor `emit_bpf_cmov_select()`, `emit_bpf_wide_load()`, `emit_bpf_rotate()`, `emit_bpf_lea()` to accept `bpf_jit_canonical_params` instead of re-parsing BPF instructions
3. Register in `canonical_emitters[]` array
4. Update `do_jit()` dispatch to use canonical emitter lookup

**Validation**: Run all v4 test cases with the refactored emitters. Verify identical JIT output.

### 14.3 Phase 3: Userspace Pattern Blob Builder (~200 LOC Python)

**Goal**: Replace hardcoded C++ scanners with pattern-library-based blob generation.

**Steps**:
1. Define pattern library data structure in Python
2. Encode all known patterns (including Round 2 additions) as declarative descriptions
3. Implement v5 blob serialization
4. Validate against VM tests: v5 blobs must produce identical re-JIT results as v4 blobs

### 14.4 Phase 4: New Patterns Without Kernel Changes (~0 LOC kernel)

**Goal**: Demonstrate the core value proposition by adding new pattern variants.

**Candidates**:
- 32-bit rotate with different register allocation
- 4-byte wide load (low-first and high-first variants)
- Compact cmov with BPF_JMP32 condition
- Address calculation with 2-insn pattern (shl+add, no mov prefix)

Each of these would require kernel code changes in v4 but only userspace pattern definitions in v5.

### 14.5 Phase 5: New Canonical Forms (~100 LOC kernel)

**Goal**: Add BITFIELD_EXTRACT and WIDE_STORE canonical forms.

**Steps**:
1. Implement `emit_canonical_bitfield_extract_x86()` (using `bextr` on BMI1 CPUs, `shr+and` otherwise)
2. Implement `emit_canonical_wide_store_x86()`
3. Define userspace patterns for these operations
4. Validate with benchmarks

---

## 15. Paper Story

### 15.1 How v5 Strengthens the Paper

The paper's core thesis is that **backend JIT optimization should be separated into a stable kernel legality plane and an updatable userspace policy plane**. v5 makes this separation concrete and demonstrable:

1. **Canonical forms ARE the legality plane**. The kernel guarantees that any emitter for a canonical form produces semantically correct native code. The set of canonical forms changes slowly (kernel release cycle), like the set of syscalls.

2. **Declarative patterns ARE the policy plane**. Userspace describes which BPF instruction sequences to optimize and what canonical forms they correspond to. New patterns can be shipped without kernel changes, like new application code.

3. **The analogy to eBPF itself becomes precise**. Just as eBPF separates program semantics (defined by userspace) from safe execution (guaranteed by the kernel verifier), v5 separates optimization decisions (defined by userspace patterns) from safe lowering (guaranteed by canonical form emitters). This is a clean, principled extension of the eBPF philosophy.

### 15.2 Contribution Hierarchy

1. **Framework contribution**: A declarative pattern matching + canonical lowering architecture for kernel JIT optimization, with formal safety properties (termination, bounded resources, fail-closed).

2. **System contribution**: `BPF_PROG_JIT_RECOMPILE` with post-load, iterative, user-controllable instruction selection policy.

3. **Evaluation contribution**: Demonstration that pattern diversity from real compilers (clang -O2 vs -O3, different versions) necessitates the declarative approach, and that a small set of canonical forms (~7-10) covers the major backend optimization opportunities.

### 15.3 "Why Not Just LLVM?"

A natural objection: if we want LLVM-style pattern matching, why not just use LLVM (or a similar compiler) to JIT BPF?

Answers:

1. **LLVM runs in userspace; this runs in kernel**. The kernel JIT must guarantee bounded compilation time, no allocation failures that crash the system, and concurrent safety with running programs. LLVM provides none of these guarantees.

2. **LLVM optimizes the whole program; this optimizes specific sites**. v5's pattern matching is applied to individual instruction sequences identified by userspace. This is much cheaper than running a full compiler backend and allows fine-grained control over which optimizations to apply.

3. **LLVM's patterns are compiled in; v5's patterns are loaded at runtime**. An LLVM version ships with a fixed set of patterns. v5 allows patterns to be updated without rebuilding or reinstalling the kernel or the JIT.

4. **Separation of concerns**. Even if the kernel used LLVM for JIT compilation, the question of *which optimizations to apply* would still be a policy decision. v5 makes this policy explicitly controllable rather than hardcoded in the compiler.

5. **The kernel community would not accept LLVM in the kernel**. The Linux kernel has a strict "no C++ in kernel" policy and avoids large external dependencies. v5's pattern matcher is ~200 LOC of simple C, consistent with kernel coding standards.

---

## 16. Summary

v5 "Declarative Pattern + Canonical Lowering" addresses the fundamental extensibility limitation of v4's closed enum design. By moving pattern descriptions into the userspace policy blob and retaining a small fixed set of canonical form emitters in the kernel, v5 achieves the ideal separation:

- **Pattern recognition** (what to optimize) evolves at the speed of compilers and programs -- userspace only.
- **Canonical lowering** (how to emit native code) evolves at the speed of architectures -- kernel changes, rare.
- **Safety guarantees** (termination, correctness, fail-closed) are enforced by the kernel's generic matcher and canonical emitter framework -- always active.

The design is implementable incrementally on top of v4 (~340 LOC kernel changes) and maintains full backward compatibility with v4 policy blobs. It provides the definitive answer to the paper's framing question: the BPF JIT's "instruction selection framework" is not a full compiler backend, but a small, safe, pattern-driven substrate that gives deployment operators the same control over native code generation that they already have over BPF programs themselves.

| Property | v4 | v5 |
|----------|----|----|
| New pattern variant | ~60-80 LOC kernel | 0 LOC kernel |
| Canonical forms | Implicit in rule_kind | Explicit, specified, ~10 total |
| Pattern language | Hardcoded C | Declarative, runtime-loaded |
| Safety model | Per-validator audit | Generic matcher + formal properties |
| Backward compatibility | N/A | v4 blobs auto-dispatched |
| Paper story | "A set of JIT optimizations" | "A framework for composing JIT optimizations safely" |

---

## 17. Changelog (v5 Review Fixes)

Fixes addressing the 5 must-fix items identified in `docs/tmp/jit-pass-framework-v5-review.md`.

### Fix 1: DIFF_CONST constraint type (Review G1)

**Problem**: The constraint language lacked a way to express `var[a] - var[b] == constant`, which is required for verifying offset contiguity in multi-byte wide_mem patterns (e.g., `off_hi - off_lo == 1`). Without this, high-byte-first 2B and low-first 4B/8B patterns could not be correctly expressed, and the claim that Round 2 changes are "purely userspace" was false.

**Changes**:
- Added `DIFF_CONST` (type=6) to `bpf_jit_pattern_constraint.type` enum in Section 3.3.
- Added `BPF_JIT_CSTR_DIFF_CONST` case to `bpf_jit_check_constraints()` in Section 8.2: validates `val_a - val_b == (s64)c->constant` with standard bounds and binding checks.
- Updated the wide_mem constraint example in Section 3.3 to show `DIFF_CONST($3, $5, 1)` for the high-byte-first 2B pattern and `DIFF_CONST` chains for 4B patterns.
- Updated the high-byte-first wide_mem example in Section 10.2 to use `DiffConst(var_a=3, var_b=5, constant=1)` instead of the previous unresolved placeholder comment.
- **Safety**: No overflow risk -- `s64` subtraction of BPF offset values (s16 range) cannot overflow. Same bounded-loop, fail-closed properties as other constraint types.

### Fix 2: 8-byte wide_mem pattern length limit (Review G2)

**Problem**: The 8-byte wide_mem pattern requires `3*8 - 2 = 22` pattern elements, which exceeded the previous `BPF_JIT_MAX_PATTERN_LEN = 16`. This meant the highest-impact optimization (50.7% surplus, 2.24x penalty) could not be expressed as a single v5 pattern.

**Changes**:
- Increased `BPF_JIT_MAX_PATTERN_LEN` from 16 to 24 in Section 3.5.
- Added rationale explaining why 24 was chosen (22 needed for 8-byte, +2 headroom).
- Updated safety properties in Section 3.4 to reflect the new bound (`site_len <= 24`).
- Updated the auto-translation table in Section 7.5: changed `low-first-8B (22-elem, exceeds limit -- must chunk)` to `low-first-8B (22-elem, within limit of 24)`.
- **Alternative considered**: A `REPEAT` primitive (repeat_from + repeat_count) was considered but rejected. It would add complexity to the matcher (nested loops, variable offset tracking) for marginal benefit -- only the 8-byte case exceeds 16. Raising the limit to 24 is simpler, adds only 8 more loop iterations (microseconds), and maintains the flat, bounded-loop safety model.

### Fix 3: Variable type confusion in cross-reference matching (Review G3)

**Problem**: The variable binding system tracked type (`BPF_JIT_VAR_REG`, `BPF_JIT_VAR_IMM`, `BPF_JIT_VAR_OFF`) but did not check type consistency on cross-references. A variable first bound via `reg_bind_dst` (type=REG, value=5) could later be cross-referenced via `imm_binding`, and the matcher would accept `insn.imm == 5` as a match despite the type mismatch. This is incorrect: a register number is semantically different from an immediate value.

**Changes**:
- Added type consistency checks to all four binding paths (dst_reg, src_reg, imm, off) in `bpf_jit_match_pattern()` in Section 8.1. On cross-reference (variable already bound), the matcher now checks `vars[var_id].type != expected_type` and returns false on mismatch, before checking the value equality.
- This means: a variable bound as REG can only be cross-referenced by another `reg_bind_dst` or `reg_bind_src`; a variable bound as IMM can only be cross-referenced by another `imm_binding`; a variable bound as OFF can only be cross-referenced by another `off_binding`.
- **Impact**: Low severity (registers are 0-10 and immediates can be any s32, so accidental cross-type matches are rare in practice), but the fix is simple and eliminates a correctness hole.

### Fix 4: Diamond cmov `ja` instruction register field checks (Review G4)

**Problem**: The v4 validator checks `ja_insn->dst_reg == 0 && ja_insn->src_reg == 0` to confirm the `BPF_JA` instruction is a pure unconditional jump. The v5 pattern language had no way to express "this instruction's register field must equal a specific constant." A malicious pattern could match a non-standard `ja` instruction with nonzero register fields.

**Changes**:
- Added `expected_dst_reg` and `expected_src_reg` fields to `bpf_jit_pattern_elem` in Section 3.1.
- Added flags bits 3 and 4: bit 3 enables `expected_dst_reg` checking, bit 4 enables `expected_src_reg` checking.
- Added Step 2b to the matcher in Section 8.1: after opcode and expected_imm checks, the matcher now checks `insn->dst_reg != elem->expected_dst_reg` (if flag bit 3) and `insn->src_reg != elem->expected_src_reg` (if flag bit 4).
- **Usage for diamond cmov**: The `ja` element in the diamond pattern sets `flags = 0x1C` (bits 2+3+4), `expected_imm = 0`, `expected_dst_reg = 0`, `expected_src_reg = 0`, confirming the instruction is `BPF_JMP|BPF_JA` with all-zero register and immediate fields.
- **Struct size**: `bpf_jit_pattern_elem` grows by 4 bytes (2 u8 fields + 2 bytes padding). The per-rule blob size increase is at most `24 * 4 = 96 bytes`, well within limits.

### Fix 5: BPF_JIT_MAX_BINDINGS too small for CF_SELECT (Review G5/6.5)

**Problem**: `CF_SELECT` has up to 10 canonical parameters (DST_REG, COND_OP, COND_SRC, COND_A_REG, COND_B_REG, COND_B_IMM, TRUE_VAL, FALSE_VAL, TRUE_SRC_KIND, FALSE_SRC_KIND). The previous `BPF_JIT_MAX_BINDINGS = 8` was insufficient, causing the binding table to overflow.

**Changes**:
- Increased `BPF_JIT_MAX_BINDINGS` from 8 to 12 in Section 3.5.
- Added rationale explaining that CF_SELECT requires 10 and 12 provides headroom for future canonical forms.
- Updated the bounded resources description in Section 3.4 to reflect the new limit.
- **Note**: `BPF_JIT_MAX_CANONICAL_PARAMS` was already 12 in Section 5.3, so the emitter-side array was already correctly sized. This fix aligns the blob-side binding count limit with the emitter-side parameter array size.
