# x86 native C instruction gap vs current kInsn passes

Date: 2026-05-12

This note answers one narrow question: which x86 instructions are actually
emitted when the same BPF-oriented C sources are compiled directly to native
x86, where they appear, and what gap remains versus the current bpfopt kInsn
matchers and x86 emitters.

The key distinction:

- **Direct C -> x86 evidence** means clang compiled a `.bpf.c`/C source to
  x86 assembly. These are the only rows I treat as "C compiler really emits
  this instruction".
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/*.llvmbpf.asm` are
  useful cross-checks, but they are BPF-bytecode-through-LLVM-JIT artifacts,
  not direct source-C compilation evidence.
- `bpfopt/testbin/` is BPF bytecode evidence: it tells us whether the current
  pass can recover an equivalent semantic site from production bytecode.

## Evidence sources

### Direct C -> x86

1. Katran full native artifact:
   `docs/tmp/katran_native_compile/clang.s`

   Source corresponds to Katran `balancer.bpf.c`, function
   `balancer_ingress`.

2. Fresh local native compiles of selected micro BPF C sources:

   ```sh
   clang -O3 -march=x86-64-v3 \
     -D__TARGET_ARCH_x86 \
     -D__wsum=__u32 -D__be16=__u16 -D__be32=__u32 -D__be64=__u64 \
     -Imicro/programs -S -masm=intel micro/programs/<name>.bpf.c
   ```

   This is only an instruction-shape check. It does not replace the real BPF
   loader path.

3. Cross-check against existing native/JIT dumps:
   `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/`.

### Current bpfopt/testbin checks

The committed testbin contains 542 live corpus programs:
`bpfopt/testbin/README.md`.

Relevant current local checks:

- Katran `bpfopt/testbin/katran/530_balancer_ingress`:
  - `rotate`: 20 matched / 20 applied, delta -80 BPF insns.
  - `cond_select`: 7 matched / 7 applied.
  - `endian_fusion`: 6 matched / 6 applied.
  - `extract`: 0.
- Current rotate pass after the masked/in-place matcher work:
  - total testbin rotate sites: 64 applied.
  - Katran: 20.
  - Tetragon observer: 44.

The older full corpus result
`corpus/results/x86_kvm_corpus_20260423_124338_026179/result.json` is useful
for broad pass-location hints, but it predates the current rotate matcher and
some cond_select behavior, so I do not use it as current rotate/cond_select
truth.

## Direct native instruction census

### Micro direct C compiles

| Source program | Native x86 instructions observed | Interpretation |
|---|---:|---|
| `micro/programs/rotate_dense.bpf.c` | `rorx` 256, `lea` 135 | Strong rotate64 evidence. |
| `micro/programs/rotate64_hash.bpf.c` | `rorx` 116, `lea` 2 | Strong rotate64/hash evidence. |
| `micro/programs/cond_select_dense.bpf.c` | `cmov` 104, `lea` 2 | Strong compare/select evidence. |
| `micro/programs/cmov_dense.bpf.c` | `cmov` 32, `rorx` 32, `lea` 34 | Combined select + rotate evidence. |
| `micro/programs/cmov_select.bpf.c` | `cmov` 1, `rorx` 4, `shrx` 5, `shlx` 1, `lea` 12 | Select plus BMI2 variable shifts. |
| `micro/programs/endian_swap_dense.bpf.c` | `movbe` 256, `lea` 2 | Strong fused endian-load evidence. |
| `micro/programs/extract_dense.bpf.c` | `shr`/`and` pairs, `lea` 3; **no `bextr`** | Native clang does not choose BEXTR here. |
| `micro/programs/load_byte_recompose.bpf.c` | `shrx` 1, `lea` 2 | BMI2 variable shift, but not a kInsn gap by itself. |
| `micro/programs/large_mixed_500.bpf.c` | `rorx` 7, `cmov` 4, `shlx` 1, `lea` 23 | Mixed rotate/select/address evidence. |
| `micro/programs/bitcount.bpf.c` | `shrx` 1, `lea` 2; **no `popcnt`** | No direct popcnt evidence for current source. |
| `micro/programs/bounds_ladder.bpf.c` | `cmov` 2, `lea` 2 | Bounds/boolean lowering can become cmov. |

### Katran direct C compile

`docs/tmp/katran_native_compile/clang.s` contains:

| Native instruction family | Count | Where / why |
|---|---:|---|
| `rorx` | 20 | jhash in `balancer_ingress`; this matches the 20 Katran BPF rotate sites. |
| `cmov*` | 16 | min/select and conditional pointer/value selection in packet path. |
| `setcc` | 3 | Boolean materialization near bounds/condition handling. |
| `bswap` | 2 | Endian conversion after load into register. |
| `rol r16, 8` | 7 | 16-bit byte swap form. |
| `lea` | 152 | Address arithmetic and add/add-constant folding. |
| vector moves/arithmetic (`vmov*`, `vpaddq`, `vpmovzxwq`, `vshufps`) | present | Small fixed copies, counter updates, checksum-style reductions. |

The important Katran point is that jhash is not a special opaque operation in
native code. Native clang emits ordinary 32-bit `rorx` sites, and the current
BPF bytecode has recoverable rotate32 shapes. That argues for a general
`rotate32` matcher, not a `jhash` super-kInsn.

## Current pass/emitter gap by instruction family

### 1. `rorx` / rotate

Direct native evidence:

- `rotate_dense`: 256 `rorx`.
- `rotate64_hash`: 116 `rorx`.
- `cmov_dense`: 32 `rorx`.
- `large_mixed_500`: 7 `rorx`.
- Katran `balancer_ingress`: 20 `rorx` from jhash.

Current BPF/kInsn state:

- `rotate` pass supports `bpf_rotate64` and `bpf_rotate32`.
- Current matcher handles:
  - clean split-copy rotate;
  - same-source complementary shifts;
  - Katran masked 32-bit jhash rotate;
  - Tetragon in-place masked 32-bit rotate.
- Current x86 emitter:
  - `bpf_rotate32` emits BMI2 `rorx r32, r/m32, imm`.
  - `bpf_rotate64` still emits the older `mov + rol` sequence.

Gap:

- Katran rotate32 parity is now good: 20/20 sites become `bpf_rotate32`, and
  the x86 emitter can lower to `rorx`.
- Tetragon has 44 real rotate32 sites in BPF bytecode; current matcher applies.
  This is BPF evidence, not direct C-native evidence.
- rotate64 micro/hash parity is still incomplete because native C emits
  `rorxq`, while `bpf_rotate64` emits `mov + rol`.

Recommendation:

1. Keep rotate as a general semantic kInsn, not a jhash kInsn.
2. Change `bpf_rotate64` x86 emitter to `rorxq` to match native C for
   `rotate_dense` / `rotate64_hash`.
3. Keep DCE after rotate; masked rotate recovery can leave dead mask/copy
   instructions depending on the bytecode shape.

### 2. `cmov` / branchless select

Direct native evidence:

- `cond_select_dense`: 104 `cmov`.
- `cmov_dense`: 32 `cmov`.
- `cmov_select`: 1 `cmov`.
- `bounds_ladder`: 2 `cmov`.
- `large_mixed_500`: 4 `cmov`.
- Katran `balancer_ingress`: 16 `cmov`.

Current BPF/kInsn state:

- `cond_select` matches branch+move diamond shapes and emits `bpf_select64`.
- `bpf_select64` x86 emitter emits:
  - `test cond_reg, cond_reg`;
  - optional `mov dst, false`;
  - `cmovz/cmovnz` between the two value registers.
- Current Katran testbin check applies 7 sites.

Gap:

- Native C often emits `cmp/test` directly followed by `cmovcc`, using the
  flags from the original comparison.
- Current `bpf_select64` ABI only accepts a boolean condition register. For
  non-zero-test conditions, `cond_select` must first materialize a predicate
  register in BPF bytecode. In the general case that prefix itself uses a
  branch:

  ```text
  pred = 0/1
  original compare branch sets pred
  CALL bpf_select64
  x86: test pred,pred; cmov...
  ```

- This recovers some branchless value selection, but it is not native-like
  compare+cmov. It can also increase BPF instruction count when immediates or
  predicate materialization need temp registers.
- Katran shows this concretely: native C has 16 `cmov*`; current bytecode pass
  finds/applies 7 `cond_select` sites.

Recommendation:

1. Add a compare-select kInsn rather than overloading `bpf_select64` too far.
   Example semantic shape:

   ```text
   bpf_select_cmp64(dst, true_reg, false_reg, lhs_reg, rhs_or_imm, cmp_op)
   ```

   x86 emitter can generate `cmp/test + cmovcc` directly.

2. Keep `bpf_select64` for already-boolean conditions.
3. Add immediate-value support only when the replacement does not require
   expensive save/restore; otherwise it defeats the purpose of cmov parity.
4. A smaller companion pass, `cond_bool`, may be useful for true `setcc`
   materialization, but compare-select has higher immediate value.

### 3. `movbe`, `bswap`, `rol16` / endian load

Direct native evidence:

- `endian_swap_dense`: 256 `movbe`.
- Katran `balancer_ingress`: 2 `bswap`, 7 `rol r16,8`.

Cross-check:

- Existing kernel JIT dump for `endian_swap_dense` shows 256 `bswap`, not
  `movbe`.

Current BPF/kInsn state:

- `endian_fusion` pass emits `bpf_endian_load16/32/64`.
- x86 emitter currently emits:
  - load16 + `rol16 8`;
  - load32 + `bswap32`;
  - load64 + `bswap64`.
- It does **not** emit `movbe`, even though the target JSON used locally has a
  `movbe` feature.
- Current Katran testbin check applies 6 endian sites.

Gap:

- The kInsn name and semantics are "fused endian load", but the x86 emitter
  still uses two instructions for 32/64-bit loads.
- Direct native C proves clang will choose `movbe` for dense memory bswap32.

Recommendation:

1. Add `movbe` emission for `bpf_endian_load16/32/64` on x86 when the probed
   target supports it.
2. If the kernel module cannot safely assume MOVBE on every supported x86 CPU,
   split capability exposure so `bpf_endian_load*` is only registered/probed
   with MOVBE-capable lowering, or add a separate `bpf_movbe_load*` kInsn.
3. Keep load+bswap only as a different target capability if fallback policy is
   explicitly desired. For strict native parity, `movbe` is the missing emitter
   piece.

### 4. `lea` / address-generation and add folding

Direct native evidence:

- Katran: 152 `lea`.
- `rotate_dense`: 135 `lea`.
- `cmov_dense`: 34 `lea`.
- `large_mixed_500`: 23 `lea`.
- Many other direct micro compiles have small `lea` counts.

Current BPF/kInsn state:

- There is no current `lea` pass or `bpf_lea*` kInsn.
- BPF memory operands can express `base + imm`, but not x86's full
  `base + index * scale + disp` addressing or arithmetic `lea` as an ALU op.
- The kernel JIT may use `lea` for some pointer additions internally, but it
  cannot generally combine multiple BPF ALU instructions into one x86 LEA.

Gap:

- Native C uses `lea` both for address computation and arithmetic addition
  without flags.
- BPF bytecode usually preserves these as multiple `mov/add/lsh/add`
  instructions.

Recommendation:

1. Do a bytecode census before adding code:
   - scalar `dst = base + index`;
   - `dst = base + (idx << 1/2/3) + imm`;
   - add/add-constant chains in hash and packet parser paths.
2. Treat pointer and scalar cases separately. Pointer arithmetic changes
   verifier-visible state; scalar-only LEA is much safer.
3. If the site count is high, add a narrow `bpf_lea64` kInsn for scalar
   arithmetic first. Do not start with pointer LEA.

### 5. `shrx` / `shlx` variable shifts

Direct native evidence:

- `cmov_select`: `shrx` 5, `shlx` 1.
- `load_byte_recompose`: `shrx` 1.
- `large_mixed_500`: `shlx` 1.
- `bitcount`: `shrx` 1.

Cross-check:

- Existing kernel JIT dumps already contain `shrx`/`shlx` for the corresponding
  variable-shift cases.

Current BPF/kInsn state:

- No dedicated kInsn.
- Likely not needed on x86: the kernel JIT already knows how to lower BPF
  variable shifts to BMI2 in at least these artifacts.

Recommendation:

- Do not add a variable-shift kInsn now. It is real native C output, but it is
  not a demonstrated BPF/kernel-JIT gap.

### 6. Small fixed copies, vector moves, and bulk memory

Direct native evidence:

- Katran native has `vmovups`, `vmovdqu`, `vmovdqa`, `vpaddq`,
  `vpmovzxwq`, and `vshufps`.
- Katran source has many small `memcpy` sites: 6-byte MAC copies and 16-byte
  IPv6/address copies.

Current BPF/kInsn state:

- `wide_mem` is BPF->BPF and can collapse byte ladders to wider scalar
  loads/stores.
- `bulk_memory` kInsn currently targets larger memcpy/memset runs:
  - `MIN_BULK_BYTES = 32`;
  - x86 emitter uses `rep movsb` / `rep stosb`;
  - it has alias checks and chunking.

Gap:

- Native clang does not use `rep movsb` for Katran's small fixed copies; it
  uses scalar/vector moves.
- Current `bulk_memory` intentionally ignores small copies below 32 bytes, so
  it is not the Katran small-copy parity mechanism.
- A general SIMD kInsn would be a large semantic and ABI expansion: BPF has no
  vector registers in verifier state, and saving/restoring vector state inside
  BPF JIT code is not production-safe as a first step.

Recommendation:

1. Prefer extending `wide_mem` / scalar small-copy recognition before adding
   vector kInsns.
2. Add a small-copy path only for fixed 8/16/24-byte scalar copies when alias
   and alignment/range safety are clear.
3. Keep `bulk_memory` for larger runs; do not use `rep movsb` as the answer for
   Katran's 6/16-byte copies.

### 7. `setcc` / boolean materialization

Direct native evidence:

- Katran: 3 `setcc`.
- Micro entry/bounds code commonly has a few `seta` instructions.

Current BPF/kInsn state:

- No dedicated `cond_bool` kInsn.
- Some uses are part of compiler-generated bounds aggregation; some can be
  consumed by compare-select if the final use is a selected value.

Gap:

- Native C can materialize a bool with `setcc` without a branch.
- BPF often keeps explicit branches or converts condition into a register via
  multiple BPF insns.

Recommendation:

- Do not prioritize a standalone `cond_bool` until after compare-select.
  `cond_bool` is only clearly useful when the boolean value itself is consumed
  later; compare-select covers the hotter cmov-style cases.

## Things that are not proven by direct C native evidence

### `bextr`

`extract_dense` direct C native emits `shr` + `and`, not `bextr`.

Current `bpf_extract64` x86 emitter also emits `shr` + `and`, so there is no
native-parity gap here. Changing the emitter to BMI1 `bextr` might still be a
valid experiment, but it is not justified by "clang native already does this"
for the current sources.

### `popcnt`, `lzcnt`, `tzcnt`

`bitcount.bpf.c` direct C native did not emit `popcnt`; it emitted ordinary
loop/shift code. No current corpus/micro direct-native evidence justifies a
popcount kInsn.

### `prefetch`

No direct C source in this check emitted `prefetch*`. The existing
`bpf_prefetch` pass is a runtime/profile-oriented idea, not a C-native parity
gap demonstrated by these programs.

### Generic SIMD

SIMD is real in Katran native output, but it is not a good first-class BPF kInsn
target unless scoped to a very narrow memory primitive. General vector ALU state
does not fit current BPF verifier/register semantics.

## Program-level map

| Program / source | True native C instruction family | Current bpfopt status | Gap |
|---|---|---|---|
| Katran `balancer_ingress` | 20 `rorx` jhash | `rotate` applies 20/20; `bpf_rotate32` emits `rorx` | Mostly closed for jhash rotate. |
| Katran `balancer_ingress` | 16 `cmov` | `cond_select` applies 7 local testbin sites | Need compare-select kInsn using original compare flags. |
| Katran `balancer_ingress` | 2 `bswap`, 7 `rol16` | `endian_fusion` applies 6 sites; emitter load+bswap/rol | OK for bswap/rol shape; not `movbe` parity. |
| Katran `balancer_ingress` | 152 `lea` | No LEA pass | Needs scalar LEA census. |
| Katran `balancer_ingress` | vector moves/arithmetic | `wide_mem`/`bulk_memory` only partial scalar/bulk coverage | Consider small scalar copy, not generic SIMD. |
| Tetragon observer testbin | 44 rotate32 bytecode sites | `rotate` applies 44 | BPF evidence only; current matcher covers it. |
| `rotate_dense` / `rotate64_hash` | many `rorxq` | `rotate` has `bpf_rotate64`, but x86 emitter is `mov+rol` | Change rotate64 emitter to `rorxq`. |
| `cond_select_dense` / `cmov_dense` | many `cmov` | `cond_select` exists but boolean-cond ABI is weaker than native cmp+cmov | Add compare-select kInsn. |
| `endian_swap_dense` | 256 `movbe` | `endian_fusion` exists, emitter is load+bswap | Add MOVBE emitter/capability. |
| `extract_dense` | `shr` + `and`, no `bextr` | `extract` matcher/emitter also uses `shr` + `and` | No native-parity gap. |
| `load_byte_recompose`, `large_mixed_500`, `bitcount` | `shrx`/`shlx` | Kernel JIT already emits BMI2 variable shifts in artifacts | No kInsn needed now. |

## Priority order

1. **Finish rotate parity**
   - `bpf_rotate32` is already the right Katran/Tetragon direction.
   - Change `bpf_rotate64` emitter to `rorxq`.

2. **Add compare-select**
   - This is the largest proven remaining native-C gap after rotate.
   - It addresses Katran's remaining cmov gap and the micro `cond_select*`
     family.

3. **Use MOVBE for endian fused loads**
   - Direct C emits `movbe`; current emitter does not.
   - This is a clean emitter-side improvement if target probing/module
     capability is made strict.

4. **Run LEA census**
   - The native evidence is strong, but the safe BPF rewrite surface is not yet
     scoped.
   - Start with scalar-only patterns.

5. **Small fixed-copy scalar widening**
   - Useful for Katran copies, but should be implemented as scalar wide
     load/store recognition, not generic SIMD.

6. **Defer BEXTR/POPCNT/PREFETCH**
   - They are plausible x86 features, but not demonstrated by direct C native
     output for the current sources.

