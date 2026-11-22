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

/-- A C-style high-bit mask is nonzero exactly when the operand sign bit is set. -/
theorem sign_mask (x : BitVec 64) :
    x &&& (9223372036854775808#64) ≠ 0#64 ↔ x.msb = true := by
  change x &&& BitVec.twoPow 64 63 ≠ 0#64 ↔ x.msb = true
  rw [BitVec.and_twoPow]
  change (if x.msb then BitVec.twoPow 64 63 else 0#64) ≠ 0#64 ↔ x.msb = true
  cases h : x.msb <;> simp +decide [h]

private theorem signed_sum (x y : BitVec 64) :
    x.signExtend 65 + (~~~y).signExtend 65 + (1#1).setWidth 65 =
      x.signExtend 65 - y.signExtend 65 := by
  rw [BitVec.signExtend_not (by decide : 0 < 64)]
  change (x.signExtend 65 + ~~~(y.signExtend 65)) + 1#65 = _
  rw [BitVec.add_assoc,← BitVec.neg_eq_not_add,BitVec.add_neg_eq_sub]

private theorem signed_value (x y : BitVec 64) :
    (x.signExtend 65 - y.signExtend 65).toInt = x.toInt - y.toInt := by
  have hxlo := BitVec.le_two_mul_toInt (x := x)
  have hxhi := BitVec.two_mul_toInt_lt (x := x)
  have hylo := BitVec.le_two_mul_toInt (x := y)
  have hyhi := BitVec.two_mul_toInt_lt (x := y)
  have sx : (x.signExtend 65).toInt = x.toInt := BitVec.toInt_signExtend_of_le (by decide)
  have sy : (y.signExtend 65).toInt = y.toInt := BitVec.toInt_signExtend_of_le (by decide)
  have noOverflow : ¬ (x.signExtend 65).ssubOverflow (y.signExtend 65) := by
    simp only [BitVec.ssubOverflow,sx,sy,Bool.or_eq_true,decide_eq_true_eq,not_or]
    constructor <;> omega
  rw [BitVec.toInt_sub_of_not_ssubOverflow noOverflow,sx,sy]

/-- The imported V test is precisely the core signed-subtraction overflow predicate. -/
theorem overflow (x y : BitVec 64) :
    (AddWithCarry x (~~~y) (1#1)).snd.v = if x.ssubOverflow y then 1#1 else 0#1 := by
  have exactWidth : (x-y).signExtend 65 = x.signExtend 65 - y.signExtend 65 ↔ ¬ x.ssubOverflow y := by
    constructor
    · intro same
      have bits := congrArg BitVec.toInt same
      rw [BitVec.toInt_signExtend_of_le (by decide),signed_value] at bits
      have low := BitVec.le_two_mul_toInt (x := x-y)
      have high := BitVec.two_mul_toInt_lt (x := x-y)
      simp only [BitVec.ssubOverflow,Bool.or_eq_true,decide_eq_true_eq,not_or]
      constructor <;> omega
    · intro noOverflow
      apply BitVec.eq_of_toInt_eq
      rw [BitVec.toInt_signExtend_of_le (by decide),signed_value,
        BitVec.toInt_sub_of_not_ssubOverflow noOverflow]
  change (if (AddWithCarry x (~~~y) (1#1)).fst.signExtend 65 =
      x.signExtend 65 + (~~~y).signExtend 65 + (1#1).setWidth 65 then 0#1 else 1#1) = _
  simp only [subtraction,signed_sum,exactWidth]
  cases h : x.ssubOverflow y <;> simp [h]

/-- The exact source XOR/AND high-bit expression computes the mature V flag. -/
theorem overflow_mask (x y : BitVec 64) :
    (AddWithCarry x (~~~y) (1#1)).snd.v =
      if ((x ^^^ y) &&& (x ^^^ (x-y))) &&& (9223372036854775808#64) ≠ 0#64 then 1#1 else 0#1 := by
  have bits : x.ssubOverflow y = ((x ^^^ y) &&& (x ^^^ (x-y))).msb := by
    simp only [BitVec.ssubOverflow_eq,BitVec.msb_and,BitVec.msb_xor]
    cases x.msb <;> cases y.msb <;> cases (x-y).msb <;> rfl
  rw [overflow]
  simp only [sign_mask,← bits]

/-- The exact source nonzero sign mask computes the mature N flag. -/
theorem negative_mask (x y : BitVec 64) :
    (AddWithCarry x (~~~y) (1#1)).snd.n =
      if (x-y) &&& (9223372036854775808#64) ≠ 0#64 then 1#1 else 0#1 := by
  change BitVec.lsb (AddWithCarry x (~~~y) (1#1)).fst 63 = _
  rw [subtraction]
  have onebit : ∀ b : BitVec 1, b = if b == 1#1 then 1#1 else 0#1 := by decide +kernel
  change (x-y).extractLsb' 63 1 = _
  calc
    (x-y).extractLsb' 63 1 = if (x-y).extractLsb' 63 1 == 1#1 then 1#1 else 0#1 := onebit _
    _ = _ := by
      rw [← BitVec.getLsbD_eq_extractLsb']
      change (if (x-y).msb then 1#1 else 0#1) = _
      simp only [sign_mask]

end KProgFormal.ClightRefinement.Arm64Compare.FlagArithmetic
