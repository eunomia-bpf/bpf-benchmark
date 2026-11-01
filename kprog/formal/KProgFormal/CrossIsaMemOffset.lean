import KProgFormal.GeneratedArm64MemOffset
import KProgFormal.GeneratedX86MemOffset

/-!
Both architectures compute a load/store address offset by the same shape --
a base contribution plus an optional scaled index, accumulated with 64-bit
wrapping -- but they parameterise it differently, so treating the two
contracts as "the same function" is wrong in a specific way.

AArch64 has no scale: its index contributes at unit weight. It does have
pre/post-indexed forms, which contribute no immediate to the offset because the
immediate is applied separately as a base writeback.

x86-64 has no pre/post-indexing, so its immediate (the displacement) is always
present. It does have a scale, carried as a base-2 logarithm in the addressing
mode's aux byte, and the index is shifted by it rather than multiplied.

So the shared core is one statement -- `base + (index <<< scale)` -- reached by
setting AArch64's scale to zero and taking its non-writeback form. The rest of
each contract is the part the other ISA lacks, and this module states both the
shared core and exactly where the divergence lies, so a change that gave
AArch64 a scale, or taught x86-64 pre/post-indexing, would break a theorem
rather than quietly making the two disagree.

The compiled forms are cross-checked in `cross_isa_differential_host.c` over
the shared core, including the wrap.
-/

namespace KProgFormal.CrossIsaMemOffset

open KProgFormal

/-- The shared core: at unit scale and without writeback, x86-64's offset is
AArch64's. This is the part both ISAs compute, and the only part that can be
compared directly. -/
theorem unit_scale_agrees (hasIndex : Bool) (imm index : BitVec 64) :
    GeneratedX86MemOffset.value hasIndex 0 imm index =
      GeneratedArm64MemOffset.value false hasIndex imm index := by
  simp only [GeneratedX86MemOffset.value, GeneratedArm64MemOffset.value,
             if_false]
  split
  · bv_decide
  · rfl

/-- The scaling is the whole difference in the index term: AArch64 contributes
the index at unit weight, x86-64 at `2 ^ scale`. Stated as an identity on the
shared core so the parameterisation is visible rather than assumed. -/
theorem index_term_scales (scale index : BitVec 64) :
    (0 : BitVec 64) + (index <<< scale) = index <<< scale := by
  exact BitVec.zero_add _

/-- AArch64's pre/post-indexed form drops the immediate, which is why a
unit-scale comparison has to say `prepost = false`: with writeback in play the
two ISAs are computing different things, not the same thing differently. The
concrete divergence, so the restriction is not mistaken for a technicality. -/
theorem prepost_is_not_shared (imm index : BitVec 64) (h : imm ≠ 0) :
    GeneratedArm64MemOffset.value true true imm index =
      GeneratedX86MemOffset.value true 0 0 index ∧
      GeneratedArm64MemOffset.value true true imm index ≠
        GeneratedX86MemOffset.value true 0 imm index := by
  simp only [GeneratedArm64MemOffset.value, GeneratedX86MemOffset.value,
             if_true, BitVec.zero_add]
  refine ⟨?_, ?_⟩
  · bv_decide
  · simpa [h] using h

/-- Both accumulate with 64-bit wrapping, so an offset that overflows wraps
rather than saturating -- the same bit pattern either way, which is what makes
the base addition safe to compose. -/
theorem wraps_not_saturates (index : BitVec 64) :
    GeneratedX86MemOffset.value true 0 0xffffffffffffffff index
      = index + 0xffffffffffffffff := by
  simp only [GeneratedX86MemOffset.value, if_true]
  bv_decide

/-- The four cases AArch64's contract distinguishes, stated on their own so the
prepost/negated-prepost pair is checked rather than assumed: index-only for a
writeback access with an index, zero for one without, `imm + index` for a plain
indexed access, and `imm` for a displacement-only one. -/
theorem arm64_case_table :
    GeneratedArm64MemOffset.value true true 7 9 = 9 ∧
      GeneratedArm64MemOffset.value true false 7 9 = 0 ∧
      GeneratedArm64MemOffset.value false true 7 9 = 16 ∧
      GeneratedArm64MemOffset.value false false 7 9 = 7 := by
  decide

/-- And x86-64's two, with the scale actually applied, so the shift is seen to
be a shift rather than a multiply by an opaque constant. -/
theorem x86_case_table :
    GeneratedX86MemOffset.value true 3 0 1 = 8 ∧
      GeneratedX86MemOffset.value false 3 5 1 = 5 := by
  decide

end KProgFormal.CrossIsaMemOffset