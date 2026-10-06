# KinsnLean4

Machine-checked equivalence between BPF *kinsn* expansions and the native code a JIT
emits for them, so a back-end can apply the rewrite with a proof rather than a
comment.

Lean 4.28 / Mathlib `v4.28.0`. `lake exe cache get && lake build`. No `sorry`; the
build fails if the axiom audit finds anything beyond `propext`, `Classical.choice`,
`Quot.sound`.

## What is proved

For each kinsn `k` with specification `spec : BitVec 64 → BitVec 64`:

```
BPF.exec   (k.bpfInsns dst src t₀ t₁) rf dst          = spec (rf src)
ARM64.exec (k.armInsns dst src t₀ t₁) rf |>.get dst   = spec (rf.get src)
X86.exec   (k.x86Insns dst src t₀ t₁) rf dst          = spec (rf src)
```

plus a write-set bound `writes ⊆ {dst, t₀, t₁}` on each side. `KinsnEquiv` bundles
these; the pairwise equivalences (`bpf_arm_equiv`, `bpf_x86_equiv`,
`arm_x86_equiv`) are corollaries through `spec`.

The result a back-end actually needs is `KinsnEquiv.arm_refines` /
`x86_refines`: given an injective, `xzr`-avoiding register map `φ` and agreement
before the block,

```
ARMSimExcept φ [t₀, t₁] (BPF.exec (k.bpfInsns …) brf) (ARM64.exec (k.armInsns (φ …)) arf)
```

i.e. splicing the native block in place of the BPF block preserves the whole machine
state outside the scratch registers. `Kinsn/Catalog.lean` instantiates this at
`bpf2a64` (`arch/arm64/net/bpf_jit_comp.c`) and `reg2hex`
(`arch/x86/net/bpf_jit_comp.c`) as `arm_jit_sound` / `x86_jit_sound`.

## Catalogue

| kinsn | spec | BPF | ARM64 | x86-64 |
|---|---|---|---|---|
| `extract[hi:lo]` | `(src >> lsb) & mask` | 4 | 1 `UBFX` | 4 (or 2 with `BEXTR`) |
| `ror n` | `rotateRight` | 5 | 1 `EXTR` | 2 |
| `rol n` | `rotateLeft` | 5 | 1 `EXTR` | 2 |
| `sxt w` | `signExtend` | 3 | 1 `SBFM` | 1 `MOVSX` |
| `bswap64` | `Bits.bswap64` | 19 | 1 `REV` | 2 |
| `ldimm64` | constant | 1 | 4 (`MOVZ`+3×`MOVK`) | 1 `MOVABS` |
| `bfi[lsb+w-1:lsb]` | binary, see below | 7 | 1 `BFM` | 7 |

Bitfield insert reads its destination, so its spec is binary and it does not
instantiate the unary record; `Kinsn/Insert.lean` states the three-way equivalence
directly.

Where BPF has since grown a native instruction, the expansion is also proved equal
to it: `SignExtend.bpf_expansions_agree` (vs `BPF_MOVSX`),
`Bswap.bpf_expansions_agree` (vs `BPF_BSWAP`).

## Design

**Spec-mediated.** Nothing is proved by relating two instruction streams directly;
each side is proved against a pure `BitVec` function. Adding a back-end is one new
correctness proof, not one per existing back-end.

**Two scratch registers.** BPF immediates are sign-extended 32-bit fields, so a
general 64-bit mask must be materialised with `LD_IMM64` into a register of its own,
on top of the one holding the partial result. `bswap64` is the kinsn that forces
this. `Extract.mask_imm32_ok` proves when the shorter three-instruction form is
legal (`width ≤ 31`).

**ARM64 bitfields from the pseudocode.** `execUBFM`/`execSBFM`/`execBFM` implement
the ARM ARM directly —

```
(wmask, tmask) = DecodeBitMasks(1, imms, immr, FALSE)
UBFM: X[d] = (ROR(X[n], R) AND wmask) AND tmask
```

— specialised to the 64-bit `N = 1` variant, where `esize = 64` makes `Replicate`
the identity. Every alias the JIT emits is then *derived*, not assumed:
`execUBFM_eq_ubfx` (`imms ≥ immr`), `execUBFM_eq_lsl` (the `imms < immr` branch),
`execUBFM_eq_lsr`, `execUBFM_eq_uxt`, `execSBFM_eq_{sxt,asr,sbfx}`,
`execBFM_eq_bfi`, `execEXTR_self` (`ROR`), `bitmaskImm_lowMask`
(`AND Xd, Xn, #mask`).

**Modelling fidelity.** Shift counts are masked to the operand width on both BPF
(`src & 63`, `& 31` for ALU32) and x86 (`& 0x3f`) — unmasked `BitVec` shifts would
make several wrong expansions provable. ALU32 zero-extends into the full 64-bit
register. `xzr` reads as zero and swallows writes. x86 `imm32` operands
sign-extend.

**Frame conditions.** `exec_of_not_mem_writes` on each ISA is what turns "the
destination matches" into a statement about the whole register file; without it the
refinement theorems are unstateable.

**Kernel-checkable byte reversal.** `Bits.bswap*` is written with shifts and masks
rather than `BitVec.append`, because `getLsbD` lemmas fire on the former. The
19-instruction `bswap64` expansion and the `MOVZ`/`MOVK` chain are discharged by
`interval_cases i <;> simp` over the 64 bit positions, so no SAT certificate — and
hence no `ofReduceBool` / `trustCompiler` — enters the trust base.

## Layout

```
Util/Bits.lean        low masks, rotations, sign extension, byte reversal
BPF/{Defs,Semantics}  ALU32/ALU64, LD_IMM64, BPF_END; exec, frame lemmas
ARM64/{Defs,Semantics} UBFM/SBFM/BFM/EXTR/MOVZ/MOVK/REV; alias derivations
X86/{Defs,Semantics}  MOV/ALU/shift/rotate/BSWAP/BEXTR/MOVSX
Kinsn/Defs.lean       KinsnEquiv, register maps, refinement theorems
Kinsn/*.lean          the individual kinsns
Kinsn/Catalog.lean    JIT register maps, instances, #guard evaluation checks
AxiomCheck.lean       trust-base audit (build-failing)
```
