import KProgFormal.ClightRefinement.Arm64UaddlvReduction
import KProgFormal.ClightRefinement.Arm64UaddlvNative
import KProgFormal.ClightRefinement.Arm64CntPopcount

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.Lanes

private def byte {n : Nat} (value : BitVec n) (i : Nat) : BitVec 8 :=
  (value >>> (8 * i)).setWidth 8

private def accumulate {n : Nat} (width : Nat) (value : BitVec n) (start : Nat) : Nat → BitVec width
  | 0 => 0
  | count+1 => accumulate width value start count + (byte value (start+count)).setWidth width

private def window {n : Nat} (value : BitVec n) (start : Nat) : Nat → Nat
  | 0 => 0
  | count+1 => window value start count + (byte value (start+count)).toNat

private theorem window_bound {n : Nat} (value : BitVec n) (start count : Nat) :
    window value start count ≤ 255 * count := by
  induction count with
  | zero => simp only [window,Nat.mul_zero,Nat.le_refl]
  | succ count ih =>
    have bound := (byte value (start+count)).isLt
    change (byte value (start+count)).toNat < 256 at bound
    simp only [window,Nat.mul_succ]
    omega

private theorem accumulate_nat {n : Nat} (value : BitVec n) (width start : Nat) (wide : 8 ≤ width) :
    ∀ count, 255 * count < 2^width → (accumulate width value start count).toNat = window value start count := by
  intro count
  induction count with
  | zero => intro bound; rfl
  | succ count ih =>
    intro bound
    have previous := ih (by omega)
    have size := window_bound value start count
    have byteBound := (byte value (start+count)).isLt
    change (byte value (start+count)).toNat < 256 at byteBound
    have addBound : (accumulate width value start count).toNat +
        ((byte value (start+count)).setWidth width).toNat < 2^width := by
      rw [previous,BitVec.toNat_setWidth_of_le wide]
      omega
    simp only [accumulate,window]
    rw [BitVec.toNat_add_of_lt addBound,previous,BitVec.toNat_setWidth_of_le wide]

private theorem loop64 (value : BitVec 64) :
    DPSFP.simd_unsigned_sum_long 8 value = accumulate 16 value 0 8 := by
  simp only [accumulate,byte,BitVec.setWidth_ushiftRight_eq_extractLsb]
  run_tac Lean.Meta.withTransparency .all do
    (← Lean.Elab.Tactic.getMainGoal).applyRfl

private theorem loop128 (value : BitVec 128) :
    DPSFP.simd_unsigned_sum_long 8 value = accumulate 16 value 0 16 := by
  simp only [accumulate,byte,BitVec.setWidth_ushiftRight_eq_extractLsb]
  run_tac Lean.Meta.withTransparency .all do
    (← Lean.Elab.Tactic.getMainGoal).applyRfl

private theorem lane (value : BitVec 64) (i : Fin 8) :
    Reduction.lane value i = (byte value i.val).setWidth 64 := Arm64Cnt.Popcount.byte_operand value i

private theorem c_sum (value : BitVec 64) : Reduction.sum value = accumulate 64 value 0 8 := by
  simp only [Reduction.sum,lane]
  rfl

private theorem imported64_nat (value : BitVec 64) :
    (DPSFP.simd_unsigned_sum_long 8 value).toNat = window value 0 8 := by
  rw [loop64]
  exact accumulate_nat value 16 0 (by decide) 8 (by decide)

private theorem imported128_nat (value : BitVec 128) :
    (DPSFP.simd_unsigned_sum_long 8 value).toNat = window value 0 16 := by
  rw [loop128]
  exact accumulate_nat value 16 0 (by decide) 16 (by decide)

/-- The actual64-bit C accumulator is exactly the imported widened
16-bit word sum, with no truncation at either width. -/
theorem word (value : BitVec 64) :
    Reduction.sum value = (DPSFP.simd_unsigned_sum_long 8 value).setWidth 64 := by
  apply BitVec.eq_of_toNat_eq
  rw [c_sum,BitVec.toNat_setWidth_of_le (by decide),imported64_nat]
  exact accumulate_nat value 64 0 (by decide) 8 (by decide)

theorem word_bound (value : BitVec 64) : (Reduction.sum value).toNat ≤ 2040 := by
  rw [c_sum,accumulate_nat value 64 0 (by decide) 8 (by decide)]
  exact window_bound value 0 8

theorem vector_bound (value : BitVec 128) :
    (DPSFP.simd_unsigned_sum_long 8 value).toNat ≤ 4080 := by
  rw [imported128_nat]
  exact window_bound value 0 16

private theorem window_add {n : Nat} (value : BitVec n) (start a b : Nat) :
    window value start (a+b) = window value start a + window value (start+a) b := by
  induction b with
  | zero => simp only [Nat.add_zero,window]
  | succ b ih =>
    change window value start (a+b) + (byte value (start+(a+b))).toNat =
      window value start a + (window value (start+a) b + (byte value ((start+a)+b)).toNat)
    rw [ih,Nat.add_assoc,Nat.add_assoc]

private theorem low_byte (value : BitVec 128) (i : Nat) (bound : i < 8) :
    byte (value.setWidth 64) i = byte value i := by
  simp only [byte,BitVec.setWidth_ushiftRight_eq_extractLsb]
  exact BitVec.extractLsb'_setWidth_of_le (by omega)

private theorem high_byte (value : BitVec 128) (i : Nat) (bound : i < 8) :
    byte ((value >>> 64).setWidth 64) i = byte value (8+i) := by
  simp only [byte,BitVec.setWidth_ushiftRight_eq_extractLsb]
  apply BitVec.eq_of_getLsbD_eq
  intro j bitBound
  have inner : 8*i+j < 64 := by omega
  simp only [BitVec.getLsbD_extractLsb',bitBound,inner,decide_true,Bool.true_and]
  congr 1 <;> omega

private theorem low_window (value : BitVec 128) :
    ∀ count, count ≤ 8 → window (value.setWidth 64) 0 count = window value 0 count := by
  intro count
  induction count with
  | zero => intro bound; rfl
  | succ count ih =>
    intro bound
    simp only [window,Nat.zero_add]
    rw [ih (by omega),low_byte value count (by omega)]

private theorem high_window (value : BitVec 128) :
    ∀ count, count ≤ 8 → window ((value >>> 64).setWidth 64) 0 count = window value 8 count := by
  intro count
  induction count with
  | zero => intro bound; rfl
  | succ count ih =>
    intro bound
    simp only [window,Nat.zero_add]
    rw [ih (by omega),high_byte value count (by omega)]

/-- The imported128-bit reduction is precisely the sum of both actual
word reductions, widened to the original C accumulator width. -/
theorem halves128 (value : BitVec 128) :
    (DPSFP.simd_unsigned_sum_long 8 value).setWidth 64 =
      (DPSFP.simd_unsigned_sum_long 8 (value.setWidth 64)).setWidth 64 +
      (DPSFP.simd_unsigned_sum_long 8 ((value >>> 64).setWidth 64)).setWidth 64 := by
  apply BitVec.eq_of_toNat_eq
  have addBound : ((DPSFP.simd_unsigned_sum_long 8 (value.setWidth 64)).setWidth 64).toNat +
      ((DPSFP.simd_unsigned_sum_long 8 ((value >>> 64).setWidth 64)).setWidth 64).toNat < 2^64 := by
    rw [BitVec.toNat_setWidth_of_le (by decide),BitVec.toNat_setWidth_of_le (by decide),
      imported64_nat,imported64_nat]
    have lo := window_bound (value.setWidth 64) 0 8
    have hi := window_bound ((value >>> 64).setWidth 64) 0 8
    omega
  rw [BitVec.toNat_add_of_lt addBound,BitVec.toNat_setWidth_of_le (by decide),
    BitVec.toNat_setWidth_of_le (by decide),BitVec.toNat_setWidth_of_le (by decide),
    imported128_nat,imported64_nat,imported64_nat]
  rw [low_window value 8 (by decide),high_window value 8 (by decide)]
  exact window_add value 0 8 8

end KProgFormal.ClightRefinement.Arm64Uaddlv.Lanes
