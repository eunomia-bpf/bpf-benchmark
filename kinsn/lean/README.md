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

## Module-source coverage (2026-10-06)

The original files and conceptual catalogue above are preserved. The new
`Kinsn/Module*.lean` files model the module instruction streams, including omitted
self-moves, ALU32 zero extension, signed immediates, forward branch offsets,
spills, and reverse-order restores. All **96 non-debug operations are proved**
after the module fixes. The table lists each operation's certificate and the
bug fixed, if any. Both native-lab modules are excluded as requested.

Final checks: both x86 and arm64 modules compile against the existing kernel
build trees with `KCFLAGS=-Werror`; `lake build` succeeds (938 jobs).
AxiomCheck audits 3,439 declarations and reports **zero non-standard axioms**.
Only `propext`, `Quot.sound`, and `Classical.choice` are used. No VMs,
benchmarks, kernel rebuilds, kernel-core edits, or bpfopt edits were performed.

`ArmStateEquiv` and `X86StateEquiv` extend the original spec-mediated pattern to
`Outcome`: all mapped registers, every memory byte, and an ordered access trace
(address, size, value). Their `arm_refines` / `x86_refines`, `bpf_frame`, and
`native_frame` theorems derive from spec correctness and write-set bounds.
`ModuleCatalog.arm_jit_sound` / `x86_jit_sound` use the Linux register maps.
Parenthesized names in the table identify the certificate supplied to these
theorems. The corrected certificates observe every mapped register, including
explicit payload temporaries. `ModuleArmRotate.cert` and the strengthened
`ModuleCatalog.bpf_arm64_extr_w_refines` / `_x_refines` include the ARM rotate
temporary. The original abstract EXTR-leaf proofs are retained in `ModuleRotate`.

The byte-memory semantics cover successful ordinary single-threaded accesses,
with wrapping 64-bit addresses. They do not model MMIO, concurrent interference,
alignment/access faults, or pair-instruction atomicity. Pair loads/stores
preserve both eight-byte accesses and their order; `Machine.storeLE_frame`
bounds changed bytes. Direct MOVBE32/64 and ARM LDR+REV compositions additionally
have full-state certificates in `ModuleEndian`. Direct unsigned loads and
ordinary register stores have certificates in `ModuleMemory`. The corrected
MOV-family certificates cover their remaining accepted operand forms too.
Temporary save/restore accesses are explicit on both sides: no proof assumes
spill memory private or erases a spill's effects.

Native flags are present in the machine state. BPF has no condition-code
register, so flags are not part of `Outcome`. `ModuleFlags.tst_flags`,
`cmp_zero_flag`, `ccmp_zero_flag`, and `cmp_flags_condition` describe the flag
channel these modules use. `ModuleCsel` proves the self-contained TST+CSEL
emitted by CSEL_NE; `ModuleCset` proves CSET's local CMP/CCMP chain for arbitrary
incoming flags. `ModuleCmov` covers both 32-bit and 64-bit value forms of all
three fused CMP/CMOV operations, including false predicates and operand aliases.
General x86 arithmetic flag behavior outside these flag-consuming templates is
not certified.

Prefetch has identity spec, no register writes, and no architectural memory or
flag effect: `ModulePrefetch.bpf_correct`, `arm_correct`, and `x86_correct`. This
matches the module's `BPF_JMP_A(0)` expansion and native cache hint and makes no
assertion about cache timing.

`Payload.lean` models the shared escape decoder, operand fields, signed
offsets/displacements, and native register numbers. `arm_load_payload_refines`
and `arm_rotate_payload_refines` connect those fields to the proofs. Other
certificates take decoded operands, with explicit alias/width bounds where
needed; C decoder/emitter acceptance constraints restrict their domains.
Instruction models are handwritten from the cited C, as in the original
framework. This is not an automated verification of C compilation or a proof
that arbitrary emitted byte arrays decode correctly. The canonical catalogue
map is the ordinary Linux JIT map. Corrected x86 certificates are generic over
the stated injective register map and cover optional private-stack R10→R9
mapping; both ordinary and ARCH emitters apply the program-specific map.
No current kernel invariant initializes persistent R6–R8 spill slots. Corrected
ARCH lowerings use live operands, with explicit matching spills where needed.
Decoder changes reject writes to read-only R10 and unsupported raw register
IDs 11–15; loadable operand forms and payload formats are preserved.
`ModuleDivl.guarded_no_divide_error` proves the native DIV64 path has a nonzero
divisor and a quotient that fits 64 bits. The emitter handles zero explicitly
and truncates outputs to implement BPF semantics, including DIV32 overflow inputs.

Historical counterexamples are kernel checked with `decide +kernel` in
`PreFixCounterexamples.lean`, explicitly modelling the pre-fix C snapshot at
`69f9a30f6`; `Counterexamples.lean` remains an import wrapper. They include
selected complete spill/restore sequences. `Counterexamples.lift_arm_related` and
`lift_x86_related` establish equal initial observations under the real maps.
The INCB witness records the old unconditional rejection; DIVL witnesses
record the old BPF completion versus native divide error. ARM EXTR witnesses
record the old native omission of the decoded temporary update. These historical
failures remain checked alongside the corrected universal certificates.

Paths in the table are relative to `kinsn/module/`; Lean names are under `Kinsn`.
The table follows the requested category order.

| Operation | C expansion (`file:function`) | C emit (`file:function`) | Lean theorem / certificate | Status | Bug fixed |
|---|---|---|---|---|---|
| `bpf_arm64_extr_w` | `arm64/bpf_arm64_extr.c:instantiate_rotate32` | `arm64/bpf_arm64_extr.c:emit_rotate32_arm64` | `ModuleCatalog.bpf_arm64_extr_w_refines` | proved | native omitted decoded temporary update |
| `bpf_arm64_extr_x` | `arm64/bpf_arm64_extr.c:instantiate_rotate64` | `arm64/bpf_arm64_extr.c:emit_rotate64_arm64` | `ModuleCatalog.bpf_arm64_extr_x_refines` | proved | native omitted decoded temporary update |
| `bpf_x86_roll` | `x86/bpf_x86_rotate.c:instantiate_roll` | `x86/bpf_x86_rotate.c:emit_roll_x86` | `ModuleX86Rotate.bpf_x86_roll` | proved | scratch restore overwrote destination |
| `bpf_x86_rolq` | `x86/bpf_x86_rotate.c:instantiate_rolq` | `x86/bpf_x86_rotate.c:emit_rolq_x86` | `ModuleX86Rotate.bpf_x86_rolq` | proved | scratch restore overwrote destination |
| `bpf_x86_rorxl` | `x86/bpf_x86_rotate.c:instantiate_rotate32` | `x86/bpf_x86_rotate.c:emit_rotate32_x86` | `ModuleX86Rotate.bpf_x86_rorxl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_arm64_csel_ne` | `arm64/bpf_arm64_csel.c:instantiate_csel_ne` | `arm64/bpf_arm64_csel.c:emit_csel_ne_arm64` | `ModuleCsel.bpf_arm64_csel_ne_refines` | proved | standalone flags/register predicates disagree |
| `bpf_arm64_tst` | `arm64/bpf_arm64_csel.c:instantiate_tst` | `arm64/bpf_arm64_csel.c:emit_tst_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_tst)` | proved | — |
| `bpf_x86_cmp_cmovb` | `x86/bpf_x86_cmov.c:instantiate_cmp_cmovb` | `x86/bpf_x86_cmov.c:emit_cmp_cmovb_x86` | `ModuleCmov.bpf_x86_cmp_cmovb` | proved | failed CMOV32 clears upper bits |
| `bpf_x86_cmp_cmove` | `x86/bpf_x86_cmov.c:instantiate_cmp_cmove` | `x86/bpf_x86_cmov.c:emit_cmp_cmove_x86` | `ModuleCmov.bpf_x86_cmp_cmove` | proved | failed CMOV32 clears upper bits |
| `bpf_x86_cmp_cmovne` | `x86/bpf_x86_cmov.c:instantiate_cmp_cmovne` | `x86/bpf_x86_cmov.c:emit_cmp_cmovne_x86` | `ModuleCmov.bpf_x86_cmp_cmovne` | proved | failed CMOV32 clears upper bits |
| `bpf_arm64_ubfm_x` | `arm64/bpf_arm64_ubfm.c:instantiate_extract` | `arm64/bpf_arm64_ubfm.c:emit_ubfm_x_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ubfm_x)` | proved | — |
| `bpf_x86_bextrq` | `x86/bpf_x86_bmi1.c:instantiate_bextrq` | `x86/bpf_x86_bmi1.c:emit_bextrq_x86` | `ModuleBextr.bpf_x86_bextrq` | proved | control register clobbered before read |
| `bpf_arm64_rev16_w` | `arm64/bpf_arm64_rev.c:instantiate_rev16_w` | `arm64/bpf_arm64_rev.c:emit_rev16_w_arm64` | `ModuleRev16.bpf_arm64_rev16_w_refines` | proved | native retained a second swapped halfword |
| `bpf_arm64_rev_w` | `arm64/bpf_arm64_rev.c:instantiate_rev_w` | `arm64/bpf_arm64_rev.c:emit_rev_w_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_rev_w)` | proved | — |
| `bpf_arm64_rev_x` | `arm64/bpf_arm64_rev.c:instantiate_rev_x` | `arm64/bpf_arm64_rev.c:emit_rev_x_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_rev_x)` | proved | — |
| `bpf_x86_movbe16` | `x86/bpf_x86_movbe.c:instantiate_movbe16_indexed` | `x86/bpf_x86_movbe.c:emit_movbe16_indexed_x86` | `ModuleMovbe16.bpf_x86_movbe16` | proved | high temporary clobbers index |
| `bpf_x86_movbe32` | `x86/bpf_x86_movbe.c:instantiate_movbe32_indexed` | `x86/bpf_x86_movbe.c:emit_movbe32_indexed_x86` | `ModuleMovbeWide.bpf_x86_movbe32` | proved | indexed scratch alias |
| `bpf_x86_movbe64` | `x86/bpf_x86_movbe.c:instantiate_movbe64_indexed` | `x86/bpf_x86_movbe.c:emit_movbe64_indexed_x86` | `ModuleMovbeWide.bpf_x86_movbe64` | proved | indexed scratch alias |
| `bpf_arm64_prfm_pldl1keep` | `arm64/bpf_arm64_prfm.c:instantiate_prfm_pldl1keep` | `arm64/bpf_arm64_prfm.c:emit_prfm_pldl1keep_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_prfm_pldl1keep)` | proved | — |
| `bpf_x86_prefetcht0` | `x86/bpf_x86_prefetch.c:instantiate_prefetcht0` | `x86/bpf_x86_prefetch.c:emit_prefetcht0_x86` | `ModuleCatalog.x86_jit_sound (bpf_x86_prefetcht0)` | proved | — |
| `bpf_arm64_ldp_x` | `arm64/bpf_arm64_ldp.c:instantiate_ldp` | `arm64/bpf_arm64_ldp.c:emit_ldp_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ldp_x)` | proved | — |
| `bpf_arm64_ldr_w` | `arm64/bpf_arm64_ldr.c:instantiate_ldr_w_mem` | `arm64/bpf_arm64_ldr.c:emit_ldr_w_mem_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ldr_w)` | proved | — |
| `bpf_arm64_ldr_x` | `arm64/bpf_arm64_ldr.c:instantiate_ldr_x_mem` | `arm64/bpf_arm64_ldr.c:emit_ldr_x_mem_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ldr_x)` | proved | — |
| `bpf_arm64_ldrb` | `arm64/bpf_arm64_ldr.c:instantiate_ldrb_mem` | `arm64/bpf_arm64_ldr.c:emit_ldrb_mem_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ldrb)` | proved | — |
| `bpf_arm64_ldrh` | `arm64/bpf_arm64_ldr.c:instantiate_ldrh_mem` | `arm64/bpf_arm64_ldr.c:emit_ldrh_mem_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ldrh)` | proved | — |
| `bpf_arm64_stp_x` | `arm64/bpf_arm64_ldp.c:instantiate_stp` | `arm64/bpf_arm64_ldp.c:emit_stp_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_stp_x)` | proved | — |
| `bpf_arm64_str_w` | `arm64/bpf_arm64_str.c:instantiate_str_w` | `arm64/bpf_arm64_str.c:emit_str_w_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_str_w)` | proved | — |
| `bpf_arm64_str_x` | `arm64/bpf_arm64_str.c:instantiate_str_x` | `arm64/bpf_arm64_str.c:emit_str_x_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_str_x)` | proved | — |
| `bpf_arm64_strb` | `arm64/bpf_arm64_str.c:instantiate_strb` | `arm64/bpf_arm64_str.c:emit_strb_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_strb)` | proved | — |
| `bpf_arm64_strh` | `arm64/bpf_arm64_str.c:instantiate_strh` | `arm64/bpf_arm64_str.c:emit_strh_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_strh)` | proved | — |
| `bpf_x86_movb` | `x86/bpf_x86_mov.c:instantiate_movb` | `x86/bpf_x86_mov.c:emit_movb_x86` | `ModuleMovb.bpf_x86_movb` | proved | ARCH store read an unsaved address slot |
| `bpf_x86_movl` | `x86/bpf_x86_mov.c:instantiate_movl` | `x86/bpf_x86_mov.c:emit_movl_x86` | `ModuleMovWide.bpf_x86_movl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_movq` | `x86/bpf_x86_mov.c:instantiate_movq` | `x86/bpf_x86_mov.c:emit_movq_x86` | `ModuleMovWide.bpf_x86_movq` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_movswl` | `x86/bpf_x86_mov.c:instantiate_movswl_rr` | `x86/bpf_x86_mov.c:emit_movswl_x86` | `ModuleMovswl.bpf_x86_movswl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_movsxd` | `x86/bpf_x86_mov.c:instantiate_movsxd` | `x86/bpf_x86_mov.c:emit_movsxd_x86` | `ModuleMovsxd.bpf_x86_movsxd` | proved | scratch restore overwrote destination |
| `bpf_x86_movw` | `x86/bpf_x86_mov.c:instantiate_movw` | `x86/bpf_x86_mov.c:emit_movw_x86` | `ModuleMovStore.bpf_x86_movw` | proved | ARCH store read an unsaved address slot |
| `bpf_x86_movzbl` | `x86/bpf_x86_mov.c:instantiate_movzbl` | `x86/bpf_x86_mov.c:emit_movzbl_x86` | `ModuleMovzx.bpf_x86_movzbl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_movzwl` | `x86/bpf_x86_mov.c:instantiate_movzwl` | `x86/bpf_x86_mov.c:emit_movzwl_x86` | `ModuleMovzx.bpf_x86_movzwl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_leal` | `x86/bpf_x86_lea.c:instantiate_lea32` | `x86/bpf_x86_lea.c:emit_lea32_x86` | `ModuleCatalog.x86_jit_sound (bpf_x86_leal)` | proved | — |
| `bpf_x86_leaq` | `x86/bpf_x86_lea.c:instantiate_lea64` | `x86/bpf_x86_lea.c:emit_lea64_x86` | `ModuleCatalog.x86_jit_sound (bpf_x86_leaq)` | proved | — |
| `bpf_arm64_ccmp_w` | `arm64/bpf_arm64_ccmp.c:instantiate_ccmp` | `arm64/bpf_arm64_ccmp.c:emit_ccmp_w_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ccmp_w)` | proved | — |
| `bpf_arm64_ccmp_x` | `arm64/bpf_arm64_ccmp.c:instantiate_ccmp` | `arm64/bpf_arm64_ccmp.c:emit_ccmp_x_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_ccmp_x)` | proved | — |
| `bpf_arm64_cmp_w` | `arm64/bpf_arm64_ccmp.c:instantiate_cmp` | `arm64/bpf_arm64_ccmp.c:emit_cmp_w_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_cmp_w)` | proved | — |
| `bpf_arm64_cmp_x` | `arm64/bpf_arm64_ccmp.c:instantiate_cmp` | `arm64/bpf_arm64_ccmp.c:emit_cmp_x_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_cmp_x)` | proved | — |
| `bpf_arm64_cset_x_cond` | `arm64/bpf_arm64_ccmp.c:instantiate_cset` | `arm64/bpf_arm64_ccmp.c:emit_cset_arm64` | `ModuleCset.bpf_arm64_cset_x_cond_refines` | proved | standalone flags/register predicates disagree |
| `bpf_arm64_mov_x` | `arm64/bpf_arm64_mov.c:instantiate_mov_x` | `arm64/bpf_arm64_mov.c:emit_mov_x_arm64` | `ModuleCatalog.arm_jit_sound (bpf_arm64_mov_x)` | proved | — |
| `bpf_x86_addb` | `x86/bpf_x86_alu.c:instantiate_addb` | `x86/bpf_x86_alu.c:emit_addb_x86` | `ModuleByteAlu.bpf_x86_addb` | proved | scratch restore overwrote destination |
| `bpf_x86_addl` | `x86/bpf_x86_alu.c:instantiate_addl` | `x86/bpf_x86_alu.c:emit_addl_x86` | `ModuleAluWide.bpf_x86_addl` | proved | scratch restore overwrote destination |
| `bpf_x86_addq` | `x86/bpf_x86_alu.c:instantiate_addq` | `x86/bpf_x86_alu.c:emit_addq_x86` | `ModuleAluWide.bpf_x86_addq` | proved | scratch restore overwrote destination |
| `bpf_x86_andb` | `x86/bpf_x86_alu.c:instantiate_andb` | `x86/bpf_x86_alu.c:emit_andb_x86` | `ModuleNarrowLogic.bpf_x86_andb` | proved | scratch restore overwrote destination |
| `bpf_x86_andl` | `x86/bpf_x86_alu.c:instantiate_andl` | `x86/bpf_x86_alu.c:emit_andl_x86` | `ModuleAluWide.bpf_x86_andl` | proved | scratch restore overwrote destination |
| `bpf_x86_andq` | `x86/bpf_x86_alu.c:instantiate_andq` | `x86/bpf_x86_alu.c:emit_andq_x86` | `ModuleAluWide.bpf_x86_andq` | proved | scratch restore overwrote destination |
| `bpf_x86_blsiq` | `x86/bpf_x86_bmi1.c:instantiate_blsiq` | `x86/bpf_x86_bmi1.c:emit_blsiq_x86` | `ModuleLowBit.bpf_x86_blsiq` | proved | scratch restore overwrote destination |
| `bpf_x86_blsrq` | `x86/bpf_x86_bmi1.c:instantiate_blsrq` | `x86/bpf_x86_bmi1.c:emit_blsrq_x86` | `ModuleLowBit.bpf_x86_blsrq` | proved | scratch restore overwrote destination |
| `bpf_x86_bswapl` | `x86/bpf_x86_byteorder.c:instantiate_bswapl` | `x86/bpf_x86_byteorder.c:emit_bswapl_x86` | `ModuleByteorder.bpf_x86_bswapl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_bswapq` | `x86/bpf_x86_byteorder.c:instantiate_bswapq` | `x86/bpf_x86_byteorder.c:emit_bswapq_x86` | `ModuleByteorder.bpf_x86_bswapq` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_bzhil` | `x86/bpf_x86_bmi2_shift.c:instantiate_bzhil` | `x86/bpf_x86_bmi2_shift.c:emit_bzhil_x86` | `ModuleBzhi.bpf_x86_bzhil` | proved | count=256 not masked to low byte |
| `bpf_x86_bzhiq` | `x86/bpf_x86_bmi2_shift.c:instantiate_bzhiq` | `x86/bpf_x86_bmi2_shift.c:emit_bzhiq_x86` | `ModuleBzhi.bpf_x86_bzhiq` | proved | count=256 not masked to low byte |
| `bpf_x86_divl` | `x86/bpf_x86_alu.c:instantiate_divl` | `x86/bpf_x86_alu.c:emit_divl_x86` | `ModuleDivl.bpf_x86_divl` | proved | zero/overflow #DE; scratch/ARCH aliases |
| `bpf_x86_imulq` | `x86/bpf_x86_imul.c:instantiate_imulq_rr` | `x86/bpf_x86_imul.c:emit_imulq_rr_x86` | `ModuleImul.bpf_x86_imulq_refines` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_incb` | `x86/bpf_x86_alu.c:instantiate_incb` | `x86/bpf_x86_alu.c:emit_incb_x86` | `ModuleInc.bpf_x86_incb` | proved | expansion rejects every byte width |
| `bpf_x86_incl` | `x86/bpf_x86_alu.c:instantiate_incl` | `x86/bpf_x86_alu.c:emit_incl_x86` | `ModuleInc.bpf_x86_incl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_incq` | `x86/bpf_x86_alu.c:instantiate_incq` | `x86/bpf_x86_alu.c:emit_incq_x86` | `ModuleInc.bpf_x86_incq` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_notb` | `x86/bpf_x86_not.c:instantiate_notb_r` | `x86/bpf_x86_not.c:emit_notb_r_x86` | `ModuleNot.bpf_x86_notb` | proved | scratch restore overwrote destination |
| `bpf_x86_notl` | `x86/bpf_x86_not.c:instantiate_notl_r` | `x86/bpf_x86_not.c:emit_notl_r_x86` | `ModuleNot.bpf_x86_notl` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_notq` | `x86/bpf_x86_not.c:instantiate_notq_r` | `x86/bpf_x86_not.c:emit_notq_r_x86` | `ModuleNot.bpf_x86_notq` | proved | ARCH read unsaved slots / left destination stale |
| `bpf_x86_notw` | `x86/bpf_x86_not.c:instantiate_notw_r` | `x86/bpf_x86_not.c:emit_notw_r_x86` | `ModuleNot.bpf_x86_notw` | proved | scratch restore overwrote destination |
| `bpf_x86_orb` | `x86/bpf_x86_alu.c:instantiate_orb` | `x86/bpf_x86_alu.c:emit_orb_x86` | `ModuleNarrowLogic.bpf_x86_orb` | proved | scratch restore overwrote destination |
| `bpf_x86_orl` | `x86/bpf_x86_alu.c:instantiate_orl` | `x86/bpf_x86_alu.c:emit_orl_x86` | `ModuleAluWide.bpf_x86_orl` | proved | scratch restore overwrote destination |
| `bpf_x86_orq` | `x86/bpf_x86_alu.c:instantiate_orq` | `x86/bpf_x86_alu.c:emit_orq_x86` | `ModuleAluWide.bpf_x86_orq` | proved | scratch restore overwrote destination |
| `bpf_x86_orw` | `x86/bpf_x86_alu.c:instantiate_orw` | `x86/bpf_x86_alu.c:emit_orw_x86` | `ModuleNarrowLogic.bpf_x86_orw` | proved | scratch restore overwrote destination |
| `bpf_x86_popcntq` | `x86/bpf_x86_popcnt.c:instantiate_popcntq` | `x86/bpf_x86_popcnt.c:emit_popcntq_x86` | `ModulePopcnt.bpf_x86_popcntq` | proved | scratch restore overwrote destination |
| `bpf_x86_rolw` | `x86/bpf_x86_byteorder.c:instantiate_rolw_imm` | `x86/bpf_x86_byteorder.c:emit_rolw_imm_x86` | `ModuleByteorder.bpf_x86_rolw` | proved | 16-bit swap upper bits disagreed |
| `bpf_x86_sarl` | `x86/bpf_x86_alu.c:instantiate_sarl` | `x86/bpf_x86_alu.c:emit_sarl_x86` | `ModuleAluShift.bpf_x86_sarl` | proved | scratch restore overwrote destination |
| `bpf_x86_sarq` | `x86/bpf_x86_alu.c:instantiate_sarq` | `x86/bpf_x86_alu.c:emit_sarq_x86` | `ModuleAluShift.bpf_x86_sarq` | proved | scratch restore overwrote destination |
| `bpf_x86_shlb` | `x86/bpf_x86_alu.c:instantiate_shlb` | `x86/bpf_x86_alu.c:emit_shlb_x86` | `ModuleByteAlu.bpf_x86_shlb` | proved | scratch/ARCH aliases; aliased CL count changed before read |
| `bpf_x86_shldl` | `x86/bpf_x86_shd.c:instantiate_shldl_imm` | `x86/bpf_x86_shd.c:emit_shldl_imm_x86` | `ModuleShd.bpf_x86_shldl` | proved | scratch restore overwrote destination |
| `bpf_x86_shldq` | `x86/bpf_x86_shd.c:instantiate_shldq_imm` | `x86/bpf_x86_shd.c:emit_shldq_imm_x86` | `ModuleShd.bpf_x86_shldq` | proved | scratch restore overwrote destination |
| `bpf_x86_shll` | `x86/bpf_x86_alu.c:instantiate_shll` | `x86/bpf_x86_alu.c:emit_shll_x86` | `ModuleAluShift.bpf_x86_shll` | proved | scratch restore overwrote destination |
| `bpf_x86_shlq` | `x86/bpf_x86_alu.c:instantiate_shlq` | `x86/bpf_x86_alu.c:emit_shlq_x86` | `ModuleAluShift.bpf_x86_shlq` | proved | scratch restore overwrote destination |
| `bpf_x86_shlxl` | `x86/bpf_x86_bmi2_shift.c:instantiate_shlxl` | `x86/bpf_x86_bmi2_shift.c:emit_shlxl_x86` | `ModuleBmiShift.bpf_x86_shlxl` | proved | scratch restore overwrote destination |
| `bpf_x86_shlxq` | `x86/bpf_x86_bmi2_shift.c:instantiate_shlxq` | `x86/bpf_x86_bmi2_shift.c:emit_shlxq_x86` | `ModuleBmiShift.bpf_x86_shlxq` | proved | scratch restore overwrote destination |
| `bpf_x86_shrb` | `x86/bpf_x86_alu.c:instantiate_shrb` | `x86/bpf_x86_alu.c:emit_shrb_x86` | `ModuleByteAlu.bpf_x86_shrb` | proved | scratch/ARCH aliases; aliased CL count changed before read |
| `bpf_x86_shrdl` | `x86/bpf_x86_shd.c:instantiate_shrdl_imm` | `x86/bpf_x86_shd.c:emit_shrdl_imm_x86` | `ModuleShd.bpf_x86_shrdl` | proved | scratch restore overwrote destination |
| `bpf_x86_shrdq` | `x86/bpf_x86_shd.c:instantiate_shrdq_imm` | `x86/bpf_x86_shd.c:emit_shrdq_imm_x86` | `ModuleShd.bpf_x86_shrdq` | proved | scratch restore overwrote destination |
| `bpf_x86_shrl` | `x86/bpf_x86_alu.c:instantiate_shrl` | `x86/bpf_x86_alu.c:emit_shrl_x86` | `ModuleAluShift.bpf_x86_shrl` | proved | scratch restore overwrote destination |
| `bpf_x86_shrq` | `x86/bpf_x86_alu.c:instantiate_shrq` | `x86/bpf_x86_alu.c:emit_shrq_x86` | `ModuleAluShift.bpf_x86_shrq` | proved | scratch restore overwrote destination |
| `bpf_x86_shrxl` | `x86/bpf_x86_bmi2_shift.c:instantiate_shrxl` | `x86/bpf_x86_bmi2_shift.c:emit_shrxl_x86` | `ModuleBmiShift.bpf_x86_shrxl` | proved | scratch restore overwrote destination |
| `bpf_x86_shrxq` | `x86/bpf_x86_bmi2_shift.c:instantiate_shrxq` | `x86/bpf_x86_bmi2_shift.c:emit_shrxq_x86` | `ModuleBmiShift.bpf_x86_shrxq` | proved | scratch restore overwrote destination |
| `bpf_x86_subb` | `x86/bpf_x86_alu.c:instantiate_subb` | `x86/bpf_x86_alu.c:emit_subb_x86` | `ModuleByteAlu.bpf_x86_subb` | proved | scratch restore overwrote destination |
| `bpf_x86_subl` | `x86/bpf_x86_alu.c:instantiate_subl` | `x86/bpf_x86_alu.c:emit_subl_x86` | `ModuleAluWide.bpf_x86_subl` | proved | scratch restore overwrote destination |
| `bpf_x86_subq` | `x86/bpf_x86_alu.c:instantiate_subq` | `x86/bpf_x86_alu.c:emit_subq_x86` | `ModuleAluWide.bpf_x86_subq` | proved | scratch restore overwrote destination |
| `bpf_x86_xorb` | `x86/bpf_x86_alu.c:instantiate_xorb` | `x86/bpf_x86_alu.c:emit_xorb_x86` | `ModuleNarrowXor.bpf_x86_xorb` | proved | scratch restore overwrote destination |
| `bpf_x86_xorl` | `x86/bpf_x86_alu.c:instantiate_xorl` | `x86/bpf_x86_alu.c:emit_xorl_x86` | `ModuleAluWide.bpf_x86_xorl` | proved | scratch restore overwrote destination |
| `bpf_x86_xorq` | `x86/bpf_x86_alu.c:instantiate_xorq` | `x86/bpf_x86_alu.c:emit_xorq_x86` | `ModuleAluWide.bpf_x86_xorq` | proved | scratch restore overwrote destination |
| `bpf_x86_xorw` | `x86/bpf_x86_alu.c:instantiate_xorw` | `x86/bpf_x86_alu.c:emit_xorw_x86` | `ModuleNarrowXor.bpf_x86_xorw` | proved | scratch restore overwrote destination |

### Historical counterexample inputs and source locations (69f9a30f6)

All rows below describe the pre-fix snapshot. Unless stated otherwise,
unspecified registers/memory bytes/flags are zero,
R10=4096, and native registers hold the corresponding BPF values. Spill slots
are R10-40/-32/-24 for R6/R7/R8. Each named theorem contains its selected expansion.

| Family and C location | Accepted decoded input | BPF versus native |
|---|---|---|
| ARM `bpf_arm64_rev.c:instantiate_rev16_w` | R0=0x12340000 | 0 versus 0x34120000 |
| ARM `bpf_arm64_csel.c:instantiate_csel_ne/emit_csel_ne_arm64` | dst=R0, yes=R2=11, no=R3=22, cond=R1=1, Z=1 | 11 versus 22; preceding TST establishes the needed flags |
| ARM `bpf_arm64_ccmp.c:instantiate_cset/emit_cset_arm64` | dst=R0, terms R1=R2=1, FAIL_EQ, width64, Z=1 | 1 versus 0; standalone CSET ignores term registers |
| x86 `bpf_x86_cmov.c:instantiate_cmp_cmov_rr` | dst=R3=0x100000001, value32=1, false EQ/NE/B condition | 0x100000001 versus 1 |
| x86 `bpf_x86_rotate.c:instantiate_rol_cl` | dst=R6=1, count=R4=1, width32/64 | 1 versus 2 after restore |
| x86 `bpf_x86_rotate.c:instantiate_rotate` | ARCH_IMM dst=R0, src=R8=1, shift=1, width32 | 0 versus 2; R8 slot was not saved |
| x86 `bpf_x86_bmi1.c:instantiate_bextrq` | dst=R1, src=R0=255, ctl=R6=0x0801 (payload 0x601) | 0 versus 127; first read overwrites control |
| x86 `bpf_x86_bmi1.c:instantiate_blsiq/instantiate_blsrq` | dst=R6=0, src=R0=3 | 0 versus 1 / 2 |
| x86 `bpf_x86_bmi2_shift.c:instantiate_bmi2_shift` | dst=R6=0, src=R0=1 (left) / 2 (right), count=R2=1 | 0 versus 2 / 1, both widths |
| x86 `bpf_x86_bmi2_shift.c:instantiate_bzhi` | dst=R1, src=R0=all ones, count=R2=256 | full-width ones versus 0; native consumes count[7:0] |
| x86 `bpf_x86_movbe.c:instantiate_movbe_indexed` (16) | dst=R0, base=R6=0, index=R7=1, scale=0; mem[1]=1 | 1 versus 256; high_reg overwrites index |
| same (32/64) | dst=R6=0, base=R7=256, index=R8=0, scale=0; mem[256]=1 | 0 versus 0x01000000 / 0x0100000000000000; dst/address/value alias |
| x86 `bpf_x86_mov.c:instantiate_mov_imm_store` | ARCH_STORE_IMM base=R7=256, offset=0, imm=0x5a, byte/halfword | writes address 0 versus 256 |
| x86 `bpf_x86_mov.c:instantiate_movq_value/instantiate_movl_reg/instantiate_movzx_rr/instantiate_movswl_rr` | ARCH_RR dst=R0, src=R7=1 | 0 versus 1; source slot was not saved |
| x86 `bpf_x86_mov.c:instantiate_movsxd` | RR dst=R6=0, src=R0=1 | 0 versus 1 after restore |
| x86 `bpf_x86_not.c:instantiate_not_narrow` | nonarch dst=R6=0, byte/halfword | 0 versus 255 / 65535 |
| x86 `bpf_x86_not.c:instantiate_notl_r/instantiate_notq_r` | ARCH_IMM dst=R7=1 | 1 versus 0xfffffffe / 0xfffffffffffffffe |
| x86 `bpf_x86_byteorder.c:instantiate_rolw_imm` | dst=R0=0x10000, imm=8 | 0 versus 0x10000; native preserves upper 48 bits |
| x86 `bpf_x86_byteorder.c:instantiate_bswap` | ARCH_IMM dst=R7=1, width32/64 | 1 versus 0x01000000 / 0x0100000000000000 |
| x86 `bpf_x86_imul.c:instantiate_imulq_rr` | ARCH_RR dst=R8=2, src=R0=3 | 2 versus 6 |
| x86 `bpf_x86_popcnt.c:instantiate_popcntq` | nonarch dst=R6=0, src=R0=3 | 0 versus 2; fallback restores destination |
| x86 `bpf_x86_shd.c:instantiate_shd_imm` | nonarch dst=R6=1, src=R0=1, count=1 | 1 versus 2 (left) / top bit (right), both widths |
| x86 `bpf_x86_alu.c:instantiate_x86_alu_sib` | dst=R8=2, base=R1=0, index=R2=0, scale=0, mem[0]=1 | 2 versus ADD=3, SUB=1, AND=0, XOR=3, OR=3, widths32/64 |
| x86 `bpf_x86_alu.c:instantiate_x86_shift_cl` | nonarch dst=R6=2, count=R4=1 | 2 versus SHL=4, SHR/SAR=1, widths32/64 |
| x86 `bpf_x86_alu.c:instantiate_x86_alu_narrow` | nonarch dst=R6=2, src=R0=1; shifts use R4=1 | 2 versus ADD=3, SUB=1, AND=0, OR=3, SHL=4, SHR=1 |
| x86 `bpf_x86_alu.c:instantiate_xorb_imm` | nonarch dst=R6=0, imm=1 | 0 versus 1 |
| x86 `bpf_x86_alu.c:instantiate_x86_xorw_mem` | dst=R6=2, base=R7=0, mem[0]=1 | 2 versus 3; scratch fallback returns destination |
| x86 `bpf_x86_alu.c:instantiate_inc` | ARCH_IMM dst=R6=2, imm=0, width32/64 | 2 versus 3 |
| x86 `bpf_x86_alu.c:instantiate_incb/instantiate_inc` | width is always 8 | expansion always -EINVAL at width !=32 && width !=64; emitter accepts INC byte |
| x86 `bpf_x86_alu.c:instantiate_divl/emit_divl_x86` | EDX=1, EAX=0, divisor=1; or EAX=7, divisor=0 | BPF quotient 0 and normal completion versus native #DE |

ARCH-form witnesses use the requested architectural register-map relation,
without an external spill-slot invariant. That invariant would be an additional
precondition and would still not justify equating all memory effects.
Save/restore writes are retained in the semantics, never erased.

The failed CMOV32 behavior follows the [Intel Software Developer's Manual,
volume 2, CMOVcc operation](https://cdrdv2-public.intel.com/835757/325383-sdm-vol-2abcd.pdf):
the 32-bit false path clears destination bits 63:32.
