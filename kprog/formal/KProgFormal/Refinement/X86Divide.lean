import KProgFormal.Refinement.X86Scalar
import KProgFormal.X86DivHandler
namespace KProgFormal.Refinement.X86Divide
open Reference
open Reference.X86 (ScalarWidth)

def longDivide : Nat → Nat → Nat → Nat → Nat × Nat
  | 0, high, _, _ => (0, high)
  | n + 1, high, low, divisor =>
      let previous := longDivide n high (low / 2) divisor
      let trial := 2 * previous.2 + low % 2
      if divisor ≤ trial then (2 * previous.1 + 1, trial - divisor)
      else (2 * previous.1, trial)

theorem longDivide_correct (n high low divisor : Nat)
    (hh : high < divisor) (hl : low < 2 ^ n) :
    let result := longDivide n high low divisor
    high * 2 ^ n + low = result.1 * divisor + result.2 ∧
      result.1 < 2 ^ n ∧ result.2 < divisor := by
  induction n generalizing low with
  | zero => simp [longDivide] at *; omega
  | succ n ih =>
      have hlhalf : low / 2 < 2 ^ n := by
        apply (Nat.div_lt_iff_lt_mul (by decide : 0 < 2)).2
        simpa only [Nat.pow_succ] using hl
      have hprev := ih (low / 2) hlhalf
      cases heq : longDivide n high (low / 2) divisor with
      | mk quotient remainder =>
          simp only [heq] at hprev
          obtain ⟨he, hq, hr⟩ := hprev
          have hbit := Nat.mod_lt low (by decide : 0 < 2)
          have hdecomp := Nat.mod_add_div low 2
          have hp : high * 2 ^ (n+1) + low =
              2 * (quotient * divisor) + (2 * remainder + low % 2) := by
            rw [Nat.pow_succ, ← Nat.mul_assoc]
            omega
          simp only [longDivide, heq]
          split
          · constructor
            · simp only [Nat.add_mul, Nat.mul_assoc]
              omega
            · constructor
              · rw [Nat.pow_succ]; omega
              · omega
          · constructor
            · simp only [Nat.mul_assoc]
              omega
            · constructor
              · rw [Nat.pow_succ]; omega
              · omega

/-- The C loop retains its 65th trial bit separately as carry. The subtraction
then produces exactly the wide remainder, including wrap in the low word. -/
theorem machine_remainder (remainder divisor bit : BitVec 64)
    (hr : BitVec.ult remainder divisor = true) (hb : BitVec.ule bit 1 = true) :
    let trial := (remainder <<< 1) ||| bit
    let wide := (remainder.setWidth 65 <<< 1) ||| bit.setWidth 65
    (if remainder.getLsbD 63 || BitVec.ule divisor trial then trial - divisor else trial).setWidth 65 =
      if BitVec.ule (divisor.setWidth 65) wide then wide - divisor.setWidth 65 else wide := by
  dsimp only
  bv_decide

theorem machine_trial (remainder bit : BitVec 64) (hb : BitVec.ule bit 1 = true) :
    (remainder.setWidth 65 <<< 1) ||| bit.setWidth 65 =
      2 * remainder.setWidth 65 + bit.setWidth 65 := by
  bv_decide

theorem machine_quotient (quotient : BitVec 64) (take : Bool) :
    (quotient <<< 1) ||| (if take then 1 else 0) =
      2 * quotient + (if take then 1 else 0) := by
  cases take <;> bv_decide

theorem byte_pack (quotient remainder : BitVec 8) :
    (remainder.setWidth 64 <<< 8) ||| quotient.setWidth 64 =
      256 * remainder.setWidth 64 + quotient.setWidth 64 := by
  bv_decide

def base (width : ScalarWidth) : Nat := 2 ^ width.bits

def low (width : ScalarWidth) (s : Reference.X86.State) : Nat :=
  if width = .w8 then (s.gpr 0).toNat % 65536 % 256
  else (s.gpr 0).toNat % base width

def high (width : ScalarWidth) (s : Reference.X86.State) : Nat :=
  if width = .w8 then (s.gpr 0).toNat % 65536 / 256
  else (s.gpr 2).toNat % base width

theorem low_lt (width : ScalarWidth) (s : Reference.X86.State) : low width s < base width := by
  cases width <;> simp [low, base, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, Nat.mod_lt]

theorem dividend_refines (width : ScalarWidth) (s : Reference.X86.State) :
    high width s * base width + low width s = Reference.X86.divideDividend width s := by
  cases width <;> simp only [high, low, base, Reference.X86.divideDividend,
    Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes, reduceCtorEq, ↓reduceIte]
  · have h := Nat.mod_add_div ((s.gpr 0).toNat % 65536) 256
    omega
  all_goals rfl

theorem quotient_fits_iff (width : ScalarWidth) (hi lo divisor : Nat)
    (hd : 0 < divisor) (hl : lo < base width) :
    (hi * base width + lo) / divisor < base width ↔ hi < divisor := by
  rw [Nat.div_lt_iff_lt_mul hd]
  cases width <;> simp only [base, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes] at * <;> omega

theorem longDivide_quot_rem (n high low divisor : Nat)
    (hh : high < divisor) (hl : low < 2 ^ n) :
    (longDivide n high low divisor).1 = (high * 2 ^ n + low) / divisor ∧
    (longDivide n high low divisor).2 = (high * 2 ^ n + low) % divisor := by
  have ⟨he, _, hr⟩ := longDivide_correct n high low divisor hh hl
  have hd : 0 < divisor := by omega
  rw [he]
  constructor
  · rw [Nat.add_comm _ (longDivide n high low divisor).2,
      Nat.add_mul_div_right _ _ hd, Nat.div_eq_of_lt hr, Nat.zero_add]
  · simp [Nat.add_mod, Nat.mod_eq_of_lt hr]

theorem zero_high_fast_path (n low divisor : Nat) (hd : 0 < divisor) (hl : low < 2 ^ n) :
    longDivide n 0 low divisor = (low / divisor, low % divisor) := by
  have h := longDivide_quot_rem n 0 low divisor hd hl
  apply Prod.ext
  · simpa using h.1
  · simpa using h.2

theorem fault_refines (width : ScalarWidth) (hi lo divisor : Nat)
    (hl : lo < base width) :
    (divisor = 0 ∨ divisor ≤ hi) ↔
      (divisor = 0 ∨ base width ≤ (hi * base width + lo) / divisor) := by
  by_cases hz : divisor = 0
  · simp [hz]
  · have hf := quotient_fits_iff width hi lo divisor (by omega) hl
    omega

def write (width : ScalarWidth) (old value : Reference.Word) : Reference.Word :=
  (generatedX86RegWriteAt ⟨old, .scalar⟩ value (X86Scalar.handlerWidth width) .low).bits

theorem write_refines (width : ScalarWidth) (old value : Reference.Word) :
    write width old value = Reference.X86.scalarWriteValue old value width (.low 0) := by
  simpa only [write, X86Scalar.lane, Reference.X86.RegisterSlice.shift] using
    X86Scalar.register_write_refines width (.low 0) old value

def handlerStep (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (operand, reads) =>
      let divisor := operand.toNat % base width
      if divisor = 0 ∨ divisor ≤ high width s then
        ⟨s, reads ++ [.fault .divide], some .divide⟩
      else
        let result := longDivide width.bits (high width s) (low width s) divisor
        if width = .w8 then
          let registers := fun r => if r = 0 then
            write .w16 (s.gpr r) (BitVec.ofNat 64 (256 * result.2 + result.1)) else s.gpr r
          ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩
        else
          let registers := fun r => if r = 0 then
            write width (s.gpr r) (BitVec.ofNat 64 result.1) else if r = 2 then
              write width (s.gpr r) (BitVec.ofNat 64 result.2) else s.gpr r
          ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩

theorem step_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width source nextPc s = Reference.X86.step (.divide width source nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.divideStep, X86Scalar.read_refines]
  cases hr : Reference.X86.scalarRead s width source with
  | error fault => simp only [hr]
  | ok pair =>
      rcases pair with ⟨operand, reads⟩
      simp only [hr]
      rw [← dividend_refines width s]
      have hf := fault_refines width (high width s) (low width s)
        (operand.toNat % base width) (low_lt width s)
      by_cases h : operand.toNat % base width = 0 ∨ operand.toNat % base width ≤ high width s
      · have href := hf.mp h
        simp only [base] at h href
        simp only [base, h, href, ↓reduceIte]
      · have href := mt hf.mpr h
        have hh : high width s < operand.toNat % base width := by omega
        have hqr := longDivide_quot_rem width.bits (high width s) (low width s)
          (operand.toNat % base width) hh (low_lt width s)
        simp only [base] at h href hqr
        simp only [base, h, href, ↓reduceIte, hqr.1, hqr.2]
        by_cases hb : width = .w8 <;>
          simp only [hb, ↓reduceIte, write_refines] <;>
          congr 2 <;> funext r <;>
          by_cases h0 : r = 0 <;> by_cases h2 : r = 2 <;>
          simp_all [write_refines, Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift]

theorem handler_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.divide width source nextPc) s (handlerStep width source nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Divide

namespace KProgFormal.Refinement.X86Divide
open Reference
open Reference.X86 (ScalarWidth)
open KProgFormal.X86SignedDivision

/-- Unsigned magnitude division with restored operand signs equals integer
truncation toward zero, including the complete double-width signed minimum. -/
theorem signed_results (dividend divisor : Int) :
    restoreSign (decide (dividend < 0) != decide (divisor < 0))
        (dividend.natAbs / divisor.natAbs) = dividend.tdiv divisor ∧
    restoreSign (decide (dividend < 0))
        (dividend.natAbs % divisor.natAbs) = dividend.tmod divisor := by
  have quotient := quotient_sign (decide (dividend < 0)) (decide (divisor < 0))
    dividend.natAbs divisor.natAbs
  have remainder := remainder_sign (decide (dividend < 0)) (decide (divisor < 0))
    dividend.natAbs divisor.natAbs
  rw [restore_signed, restore_signed] at quotient remainder
  exact ⟨quotient.symm, remainder.symm⟩

/-- Magnitude-level signed arithmetic composes with the existing generated
operand read and width-aware writes. Captured-limb/source extraction, the C
high-limb preliminary fault and restoring-loop realization, fresh flags and
compiler/physical-memory transport remain the production interfaces. -/
def signedMagnitudeStep (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (operand, reads) =>
      let dividend := (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt
      let divisor := (operand.setWidth width.bits).toInt
      let quotient := dividend.natAbs / divisor.natAbs
      let negative := decide (dividend < 0) != decide (divisor < 0)
      let limit := 2 ^ (width.bits - 1)
      if divisor.natAbs = 0 ∨ ¬quotient ≤ limit - (if negative then 0 else 1) then
        ⟨s, reads ++ [.fault .divide], some .divide⟩
      else
        let signedQuotient := restoreSign negative quotient
        let signedRemainder := restoreSign (decide (dividend < 0)) (dividend.natAbs % divisor.natAbs)
        if width = .w8 then
          let packed := (BitVec.ofInt 8 signedQuotient).toNat +
            256 * (BitVec.ofInt 8 signedRemainder).toNat
          let registers := fun r => if r = 0 then
            write .w16 (s.gpr r) (BitVec.ofNat 64 packed) else s.gpr r
          ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩
        else
          let registers := fun r => if r = 0 then
            write width (s.gpr r) (BitVec.ofInt 64 signedQuotient) else if r = 2 then
              write width (s.gpr r) (BitVec.ofInt 64 signedRemainder) else s.gpr r
          ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩

theorem signed_magnitude_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    signedMagnitudeStep width source nextPc s =
      Reference.X86.step (.signedDivide width source nextPc) s := by
  change signedMagnitudeStep width source nextPc s = Reference.X86.signedDivideStep width source nextPc s
  simp only [signedMagnitudeStep, Reference.X86.signedDivideStep, X86Scalar.read_refines]
  cases read : Reference.X86.scalarRead s width source with
  | error fault => simp only [read]
  | ok pair =>
      rcases pair with ⟨operand, reads⟩
      simp only [read]
      let dividend := (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt
      let divisor := (operand.setWidth width.bits).toInt
      let quotient := dividend.natAbs / divisor.natAbs
      let negative := decide (dividend < 0) != decide (divisor < 0)
      let limit := 2 ^ (width.bits - 1)
      have values := signed_results dividend divisor
      have positive : 0 < limit := by cases width <;> decide
      have range := quotient_range negative quotient limit positive
      rw [values.1] at range
      have limitCast : (limit : Int) = (2 : Int) ^ (width.bits - 1) := by
        cases width <;> decide
      rw [limitCast] at range
      have zero : divisor.natAbs = 0 ↔ divisor = 0 := by simp
      have faults : (divisor.natAbs = 0 ∨ ¬quotient ≤ limit - (if negative then 0 else 1)) ↔
          (divisor = 0 ∨ dividend.tdiv divisor < -((2 : Int) ^ (width.bits - 1)) ∨
            (2 : Int) ^ (width.bits - 1) ≤ dividend.tdiv divisor) := by
        rw [zero, range]
        omega
      by_cases failed : divisor.natAbs = 0 ∨ ¬quotient ≤ limit - (if negative then 0 else 1)
      · have canonical := faults.mp failed
        simp only [dividend, divisor, quotient, negative, limit] at failed canonical
        simp only [failed, canonical, ↓reduceIte]
      · have canonical := mt faults.mpr failed
        simp only [dividend, divisor, quotient, negative, limit] at failed canonical values
        simp only [failed, canonical, ↓reduceIte, values.1, values.2]
        by_cases byte : width = .w8 <;>
          simp only [byte, ↓reduceIte, write_refines] <;>
          congr 2 <;> funext r <;>
          by_cases accumulator : r = 0 <;> by_cases high : r = 2 <;>
          simp_all [write_refines, Reference.X86.scalarWriteValue, Reference.X86.RegisterSlice.shift]

theorem signed_magnitude_handler_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.signedDivide width source nextPc) s
      (signedMagnitudeStep width source nextPc s) := by
  rw [signed_magnitude_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Divide

namespace KProgFormal.Refinement.X86Divide.SignedArithmetic
open Reference.X86 (ScalarWidth)

/-- The emitted sign-bit magnitude permits the negative signed minimum and
ends one earlier for a positive quotient. -/
def limit (width : ScalarWidth) (negative : Bool) : Nat :=
  2 ^ (width.bits - 1) - (if negative then 0 else 1)

theorem limit_lt_base (width : ScalarWidth) (negative : Bool) :
    limit width negative < base width := by
  cases width <;> cases negative <;> decide

/-- Production chooses direct narrow division, the zero-high qword fast path,
and the verified radix-two qword loop. The incoming high-limb condition supplies
that loop's restoring remainder invariant. -/
def quotRem (width : ScalarWidth) (high low divisor : Nat) : Nat × Nat :=
  if width = .w64 then
    if high = 0 then (low / divisor, low % divisor)
    else longDivide 64 high low divisor
  else ((high * base width + low) / divisor, (high * base width + low) % divisor)

theorem quot_rem_matches (width : ScalarWidth) (high low divisor : Nat)
    (lowBound : low < base width) (highBound : high < divisor) :
    quotRem width high low divisor =
      ((high * base width + low) / divisor, (high * base width + low) % divisor) := by
  unfold quotRem
  by_cases wide : width = .w64
  · subst width
    rw [if_pos rfl]
    by_cases zero : high = 0
    · simp [zero]
    · rw [if_neg zero]
      have result := longDivide_quot_rem 64 high low divisor highBound lowBound
      exact Prod.ext result.1 result.2
  · rw [if_neg wide]

/-- The earlier high-magnitude condition already implies failure of the signed
quotient bound, for either quotient sign. It preserves the canonical #DE result. -/
theorem preliminary_overflow (width : ScalarWidth) (negative : Bool)
    (high low divisor : Nat) (lowBound : low < base width)
    (nonzero : divisor ≠ 0) (highFault : divisor ≤ high) :
    limit width negative < (high * base width + low) / divisor := by
  have wide := (fault_refines width high low divisor lowBound).mp (Or.inr highFault)
  have smaller := limit_lt_base width negative
  omega

/-- Two production arithmetic fault sites: the preliminary high-limb test and
then the sign-sensitive quotient limit. Architectural writes follow this result. -/
def guarded (width : ScalarWidth) (negative : Bool) (high low divisor : Nat) : Option (Nat × Nat) :=
  if divisor = 0 ∨ divisor ≤ high then none else
    let result := quotRem width high low divisor
    if limit width negative < result.1 then none else some result

/-- Flat magnitude result used by signedMagnitudeStep; this normal form keeps
the integer signed-range correspondence separate from the C arithmetic route. -/
def flatResult (width : ScalarWidth) (negative : Bool) (high low divisor : Nat) : Option (Nat × Nat) :=
  let result := ((high * base width + low) / divisor, (high * base width + low) % divisor)
  if divisor = 0 ∨ limit width negative < result.1 then none else some result

theorem guarded_matches (width : ScalarWidth) (negative : Bool) (high low divisor : Nat)
    (lowBound : low < base width) :
    guarded width negative high low divisor = flatResult width negative high low divisor := by
  by_cases early : divisor = 0 ∨ divisor ≤ high
  · rcases early with zero | highFault
    · simp [guarded, flatResult, zero]
    · by_cases zero : divisor = 0
      · simp [guarded, flatResult, zero]
      · have overflow := preliminary_overflow width negative high low divisor lowBound zero highFault
        simp [guarded, flatResult, highFault, overflow]
  · have nonzero : divisor ≠ 0 := by omega
    have highBound : high < divisor := by omega
    have result := quot_rem_matches width high low divisor lowBound highBound
    simp [guarded, flatResult, early, nonzero, result, Nat.not_le.mpr highBound]

/-- Accepted quotient and remainder fit the emitted width. This permits their
unsigned word representation before the source restores signed results. -/
theorem accepted_result_bounds (width : ScalarWidth) (negative : Bool)
    (high low divisor quotient remainder : Nat)
    (lowBound : low < base width) (divisorBound : divisor < base width)
    (accepted : guarded width negative high low divisor = some (quotient, remainder)) :
    quotient < base width ∧ remainder < base width := by
  rw [guarded_matches width negative high low divisor lowBound] at accepted
  unfold flatResult at accepted
  dsimp only at accepted
  split at accepted
  · contradiction
  · rename_i successful
    have result := Option.some.inj accepted
    have q := congrArg Prod.fst result
    have r := congrArg Prod.snd result
    have smaller := limit_lt_base width negative
    have nonzero : divisor ≠ 0 := by omega
    have remBound := Nat.mod_lt (high * base width + low) (by omega : 0 < divisor)
    simp only [Prod.fst, Prod.snd] at q r
    omega

end KProgFormal.Refinement.X86Divide.SignedArithmetic

namespace KProgFormal.Refinement.X86Divide.Capture
open Reference
open Reference.X86 (ScalarWidth)
open KProgFormal.X86SignedDivision

def highWord (width : ScalarWidth) (s : Reference.X86.State) : Reference.Word :=
  if width = .w8 then s.gpr 0 >>> 8 else s.gpr 2

theorem dividend_value (width : ScalarWidth) (s : Reference.X86.State) :
    (join (X86Scalar.handlerWidth width) (highWord width s) (s.gpr 0)).toNat =
      Reference.X86.divideDividend width s := by
  rw [join_to_nat]
  cases width <;> simp [highWord, X86Scalar.handlerWidth, x86WidthBitsSpec,
    Reference.X86.divideDividend, Reference.X86.ScalarWidth.bits,
    Reference.X86.ScalarWidth.bytes, BitVec.toNat_ushiftRight, Nat.shiftRight_eq_div_pow] <;> omega

theorem dividend_integer (width : ScalarWidth) (s : Reference.X86.State) :
    (join (X86Scalar.handlerWidth width) (highWord width s) (s.gpr 0)).toInt =
      (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt := by
  have value := dividend_value width s
  have bound := (join (X86Scalar.handlerWidth width) (highWord width s) (s.gpr 0)).isLt
  rw [value] at bound
  have numericBound : Reference.X86.divideDividend width s < 2 ^ (2 * width.bits) := by
    cases width <;> exact bound
  have sameNat : (join (X86Scalar.handlerWidth width) (highWord width s) (s.gpr 0)).toNat =
      (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toNat := by
    rw [BitVec.toNat_ofNat, Nat.mod_eq_of_lt numericBound]
    exact value
  cases width <;> exact congrArg BitVec.toInt (BitVec.eq_of_toNat_eq sameNat)

/-- The actual masked 64-bit limb sequence yields the canonical signed
AX/DX:AX/EDX:EAX/RDX:RAX magnitude from the same captured input state. -/
theorem dividend_magnitude (width : ScalarWidth) (s : Reference.X86.State) :
    (sourcePairMagnitude (X86Scalar.handlerWidth width) (highWord width s) (s.gpr 0)).toNat =
      (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt.natAbs := by
  rw [source_pair_magnitude_to_nat, dividend_integer]

theorem word_negative {bits : Nat} (value : BitVec bits) :
    value.msb = decide (value.toInt < 0) := by
  cases sign : value.msb with
  | false =>
      have positive := BitVec.toInt_nonneg_of_msb_false sign
      simp [Nat.not_lt.mpr, Int.not_lt.mpr positive]
  | true =>
      have negative := BitVec.toInt_neg_of_msb_true sign
      simp [negative]

def sourceNegative (width : ScalarWidth) (value : Reference.Word) : Bool :=
  maskedLimb (X86Scalar.handlerWidth width) value &&&
    (1 <<< (x86WidthBitsSpec (X86Scalar.handlerWidth width) - 1)) != 0

theorem dividend_negative (width : ScalarWidth) (s : Reference.X86.State) :
    sourceNegative width (highWord width s) =
      decide ((BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt < 0) := by
  have bits : sourceNegative width (highWord width s) =
      (join (X86Scalar.handlerWidth width) (highWord width s) (s.gpr 0)).msb := by
    cases width <;> simp [sourceNegative, maskedLimb, join, X86Scalar.handlerWidth,
      x86WidthBitsSpec] <;> bv_decide
  rw [bits, word_negative, dividend_integer]

theorem divisor_negative (width : ScalarWidth) (operand : Reference.Word) :
    sourceNegative width operand = decide ((operand.setWidth width.bits).toInt < 0) := by
  have bits : sourceNegative width operand = (operand.setWidth width.bits).msb := by
    cases width <;> simp [sourceNegative, maskedLimb, X86Scalar.handlerWidth,
      x86WidthBitsSpec, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes] <;> bv_decide
  rw [bits, word_negative]

def divisorMagnitude (width : ScalarWidth) (operand : Reference.Word) : Reference.Word :=
  let raw := maskedLimb (X86Scalar.handlerWidth width) operand
  if sourceNegative width operand then maskedLimb (X86Scalar.handlerWidth width) (0 - raw) else raw

theorem divisor_magnitude (width : ScalarWidth) (operand : Reference.Word) :
    (divisorMagnitude width operand).toNat = (operand.setWidth width.bits).toInt.natAbs := by
  have exactBits : divisorMagnitude width operand = (operand.setWidth width.bits).abs.setWidth 64 := by
    cases width <;> simp [divisorMagnitude, sourceNegative, maskedLimb, X86Scalar.handlerWidth,
      x86WidthBitsSpec, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
      BitVec.abs_eq] <;> bv_decide
  rw [exactBits]
  rw [BitVec.toNat_setWidth]
  have modulus : 2 ^ width.bits ≤ 2 ^ 64 := by cases width <;> decide
  have bound := Nat.lt_of_lt_of_le (operand.setWidth width.bits).abs.isLt modulus
  rw [Nat.mod_eq_of_lt bound]
  exact magnitude_to_nat _

theorem quotient_negative (width : ScalarWidth) (s : Reference.X86.State) (operand : Reference.Word) :
    Bool.xor (sourceNegative width (highWord width s)) (sourceNegative width operand) =
      (decide ((BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt < 0) !=
        decide ((operand.setWidth width.bits).toInt < 0)) := by
  rw [dividend_negative, divisor_negative]

end KProgFormal.Refinement.X86Divide.Capture
