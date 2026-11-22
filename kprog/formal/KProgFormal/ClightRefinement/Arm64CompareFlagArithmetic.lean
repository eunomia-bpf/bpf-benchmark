import KProgFormal.ClightRefinement.Arm64CompareNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Compare.FlagArithmetic

/-- Arithmetic fact about the imported carry primitive used by the real CMP. -/
theorem subtraction (x y : BitVec 64) : (AddWithCarry x (~~~y) (1#1)).fst = x - y := by
  rw [fst_AddWithCarry_eq_sub_neg,BitVec.not_not]

/-- The mature zero flag tests equality of the actual operands. -/
theorem zero (x y : BitVec 64) :
    (AddWithCarry x (~~~y) (1#1)).snd.z = if x = y then 1#1 else 0#1 := by
  change (if (AddWithCarry x (~~~y) (1#1)).fst = BitVec.zero 64 then 1#1 else 0#1) = _
  have test : x - y = BitVec.zero 64 ↔ x = y := by
    have hx := x.isLt
    have hy := y.isLt
    constructor
    · intro same
      apply BitVec.eq_of_toNat_eq
      have bits := congrArg BitVec.toNat same
      change (x-y).toNat = 0 at bits
      simp only [BitVec.toNat_sub] at bits
      omega
    · rintro rfl
      apply BitVec.eq_of_toNat_eq
      change (x-x).toNat = 0
      simp only [BitVec.toNat_sub]
      omega
  rw [subtraction]
  simp only [test]

private theorem unsigned_sum (x y : BitVec 64) :
    (x.setWidth 65 + (~~~y).setWidth 65 + (1#1).setWidth 65).toNat =
      x.toNat + 18446744073709551616 - y.toNat := by
  have hx := x.isLt
  have hy := y.isLt
  simp only [BitVec.toNat_add,BitVec.toNat_setWidth,BitVec.toNat_not,BitVec.toNat_ofNat]
  omega

/-- The mature carry flag is one exactly when unsigned subtraction needs no
borrow. This follows from the actual widened unsigned sum, not another ISA rule. -/
theorem carry (x y : BitVec 64) :
    (AddWithCarry x (~~~y) (1#1)).snd.c = if x.toNat < y.toNat then 0#1 else 1#1 := by
  let sum := x.setWidth 65 + (~~~y).setWidth 65 + (1#1).setWidth 65
  have total : sum.toNat = x.toNat + 18446744073709551616 - y.toNat := unsigned_sum x y
  have hx := x.isLt
  have hy := y.isLt
  have exactWidth : (sum.setWidth 64).setWidth 65 = sum ↔ x.toNat < y.toNat := by
    constructor
    · intro same
      have bits := congrArg BitVec.toNat same
      simp only [BitVec.toNat_setWidth] at bits
      omega
    · intro less
      apply BitVec.eq_of_toNat_eq
      simp only [BitVec.toNat_setWidth]
      omega
  change (if (sum.setWidth 64).setWidth 65 = sum then 0#1 else 1#1) = _
  simp only [exactWidth]

end KProgFormal.ClightRefinement.Arm64Compare.FlagArithmetic
