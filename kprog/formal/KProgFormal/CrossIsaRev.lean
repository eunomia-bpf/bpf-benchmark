import KProgFormal.GeneratedArm64Extrev
import KProgFormal.GeneratedX86Bswap

/-!
Byte reversal is the one cross-ISA operation here where both sides do the same
thing by different means and neither is simpler: AArch64's `REV` is generated
as a shift-and-mask disjunction over the destination width, x86-64's `BSWAP`
picks the width first and then reverses over it, clearing the bytes above. They
also differ in the widths they admit -- `REV` at W and X, `BSWAP` at all four,
with `BSWAP` at 8 bits being the identity.

The agreement is worth stating because a byte-reversal fault is quiet. Swap two
of the eight terms and most inputs still change plausibly; the fault shows only
where the swapped bytes differ, which sampling of round numbers tends to miss.
The two are proved equal at both widths AArch64 encodes, and the case that
gives the operation its meaning is pinned separately: reversal is an involution
on the width-truncated value, so applying it twice returns the original. That
second property is what a transposed term in the disjunction would break while
still coincidentally agreeing at some inputs.

The compiled forms are cross-checked over six hundred thousand inputs in
`cross_isa_differential_host.c`.
-/

namespace KProgFormal.CrossIsaRev

open KProgFormal

/-- AArch64's `REV` at 32 bits is x86-64's `BSWAP` at the same width. -/
theorem rev_w32 (v : BitVec 64) :
    GeneratedArm64Extrev.rev v .w32 = GeneratedX86Bswap.value v .w32 := by
  simp only [GeneratedArm64Extrev.rev, GeneratedX86Bswap.value,
             GeneratedX86Width.narrow, GeneratedX86Width.mask]
  bv_decide

/-- And at 64 bits. -/
theorem rev_w64 (v : BitVec 64) :
    GeneratedArm64Extrev.rev v .w64 = GeneratedX86Bswap.value v .w64 := by
  simp only [GeneratedArm64Extrev.rev, GeneratedX86Bswap.value,
             GeneratedX86Width.narrow, GeneratedX86Width.mask]
  bv_decide

/-- Reversal is an involution: applying it twice returns the width-truncated
value. This is the property that distinguishes a correct byte permutation from
one that merely looks plausible -- a transposed term still produces a
permutation, but not an order-two one. -/
theorem rev_involutive_w64 (v : BitVec 64) :
    GeneratedArm64Extrev.rev (GeneratedArm64Extrev.rev v .w64) .w64 = v := by
  simp only [GeneratedArm64Extrev.rev]
  split <;> bv_decide

/-- The same at 32 bits, where the second application must not disturb the
bytes above the word either. -/
theorem rev_involutive_w32 (v : BitVec 64) :
    GeneratedArm64Extrev.rev (GeneratedArm64Extrev.rev v .w32) .w32
      = v &&& 0xffffffff := by
  simp only [GeneratedArm64Extrev.rev]
  split <;> bv_decide

/-- A concrete instance, so the two widths are seen to differ rather than being
two statements of one fact: reversing `0x0123456789abcdef` at 64 bits gives
`0xefcdab8967452301`, and at 32 bits gives `0xefcdab89` with the high half
cleared. -/
theorem rev_concrete :
    GeneratedArm64Extrev.rev 0x0123456789abcdef .w64 = 0xefcdab8967452301 ∧
      GeneratedArm64Extrev.rev 0x0123456789abcdef .w32 = 0x00000000efcdab89 := by
  refine ⟨?_, ?_⟩ <;> decide

/-- The 8-bit `BSWAP` is the identity, and `REV` has no 8-bit arm, so the two
are related at exactly two of the four widths x86-64 admits. Recorded so the
two-width theorem is not read as a four-width one. -/
theorem bswap_w8_is_identity (v : BitVec 64) :
    GeneratedX86Bswap.value v .w8 = v &&& 0xff := by rfl

end KProgFormal.CrossIsaRev