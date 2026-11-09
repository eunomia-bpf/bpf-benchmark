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

/-- Keep bitvector normalization in a word-only context; importing this module
alongside other state refinements then shares only the canonical enum definitions. -/
theorem high_sign_matches (width : ScalarWidth) (high low : Reference.Word) :
    sourceNegative width high =
      (join (X86Scalar.handlerWidth width) high low).msb := by
  cases width <;> simp [sourceNegative, maskedLimb, join, X86Scalar.handlerWidth,
    x86WidthBitsSpec] <;> bv_decide

theorem dividend_negative (width : ScalarWidth) (s : Reference.X86.State) :
    sourceNegative width (highWord width s) =
      decide ((BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt < 0) := by
  rw [high_sign_matches width (highWord width s) (s.gpr 0), word_negative, dividend_integer]

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

namespace KProgFormal.Refinement.X86Divide.SourceState
open Reference
open Reference.X86 (ScalarWidth)
open KProgFormal.X86SignedDivision

/-- The actual masked/negated high and low 64-bit source words feed the two
fault tests and native-width quotient routes. C loop/source/compiler and AUX
transport remain separate interfaces. -/
def outcome (width : ScalarWidth) (s : Reference.X86.State) (operand : Reference.Word) : Option (Nat × Nat) :=
  let limbs := sourceMagnitudeLimbs (X86Scalar.handlerWidth width)
    (Capture.highWord width s) (s.gpr 0)
  SignedArithmetic.guarded width
    (Bool.xor (Capture.sourceNegative width (Capture.highWord width s))
      (Capture.sourceNegative width operand)) limbs.1.toNat limbs.2.toNat
    (Capture.divisorMagnitude width operand).toNat

theorem outcome_matches (width : ScalarWidth) (s : Reference.X86.State) (operand : Reference.Word) :
    outcome width s operand =
      let dividend := (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt
      let divisor := (operand.setWidth width.bits).toInt
      let negative := decide (dividend < 0) != decide (divisor < 0)
      let quotient := dividend.natAbs / divisor.natAbs
      if divisor.natAbs = 0 ∨ SignedArithmetic.limit width negative < quotient then none
      else some (quotient, dividend.natAbs % divisor.natAbs) := by
  unfold outcome
  dsimp only
  have projection := source_limbs_split (X86Scalar.handlerWidth width)
    (Capture.highWord width s) (s.gpr 0)
  have radix : 2 ^ x86WidthBitsSpec (X86Scalar.handlerWidth width) = base width := by
    cases width <;> rfl
  rw [radix] at projection
  rw [projection.1, projection.2]
  have positive : 0 < base width := by cases width <;> decide
  rw [SignedArithmetic.guarded_matches _ _ _ _ _ (Nat.mod_lt _ positive)]
  unfold SignedArithmetic.flatResult
  rw [Capture.dividend_magnitude, Capture.divisor_magnitude, Capture.quotient_negative]
  rw [Nat.mul_comm (_ / base width), Nat.div_add_mod]

def restoredWord (negative : Bool) (magnitude : Nat) : Reference.Word :=
  if negative then 0 - BitVec.ofNat 64 magnitude else BitVec.ofNat 64 magnitude

theorem restored_word (negative : Bool) (magnitude : Nat) :
    restoredWord negative magnitude = BitVec.ofInt 64 (restoreSign negative magnitude) := by
  cases negative <;> simp [restoredWord, restoreSign, BitVec.ofInt_neg]

def packedBytes (quotient remainder : Reference.Word) : Reference.Word :=
  ((remainder &&& 255) <<< 8) ||| (quotient &&& 255)

theorem byte_pack_words (quotient remainder : Reference.Word) :
    packedBytes quotient remainder = BitVec.ofNat 64
      ((quotient.setWidth 8).toNat + 256 * (remainder.setWidth 8).toNat) := by
  have separated : packedBytes quotient remainder =
      (quotient.setWidth 8).setWidth 64 + ((remainder.setWidth 8).setWidth 64 <<< 8) := by
    simp [packedBytes, Reference.Word]
    bv_decide
  rw [separated]
  apply BitVec.eq_of_toNat_eq
  simp [BitVec.toNat_add, BitVec.toNat_shiftLeft, BitVec.toNat_setWidth]
  omega

theorem low_int_byte (value : Int) :
    (BitVec.ofInt 64 value).setWidth 8 = BitVec.ofInt 8 value := by
  cases value <;> simp [BitVec.setWidth_ofNat_of_le, BitVec.setWidth_not]

theorem byte_pack_matches (quotient remainder : Int) :
    packedBytes (BitVec.ofInt 64 quotient) (BitVec.ofInt 64 remainder) =
      BitVec.ofNat 64 ((BitVec.ofInt 8 quotient).toNat +
        256 * (BitVec.ofInt 8 remainder).toNat) := by
  rw [byte_pack_words, low_int_byte, low_int_byte]

/-- A source arithmetic state model: captured inputs precede every write,
preliminary and signed-limit faults use guarded, unsigned word negations restore
sign, and byte results use the emitted masks/shift/OR packing. -/
def arithmeticStep (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (operand, reads) =>
      match outcome width s operand with
      | none => ⟨s, reads ++ [.fault .divide], some .divide⟩
      | some (quotient, remainder) =>
          let negative := Capture.sourceNegative width (Capture.highWord width s)
          let qnegative := Bool.xor negative (Capture.sourceNegative width operand)
          let qword := restoredWord qnegative quotient
          let rword := restoredWord negative remainder
          if width = .w8 then
            let registers := fun r => if r = 0 then
              write .w16 (s.gpr r) (packedBytes qword rword) else s.gpr r
            ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩
          else
            let registers := fun r => if r = 0 then write width (s.gpr r) qword
              else if r = 2 then write width (s.gpr r) rword else s.gpr r
            ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩

theorem arithmetic_step_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    arithmeticStep width source nextPc s = signedMagnitudeStep width source nextPc s := by
  unfold arithmeticStep signedMagnitudeStep
  cases read : X86Scalar.read s width source with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨operand, reads⟩
      simp only [outcome_matches]
      have condition :
          (operand.setWidth width.bits).toInt.natAbs = 0 ∨
            SignedArithmetic.limit width
              (decide ((BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt < 0) !=
                decide ((operand.setWidth width.bits).toInt < 0)) <
              (BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt.natAbs /
                (operand.setWidth width.bits).toInt.natAbs ↔
          (operand.setWidth width.bits).toInt.natAbs = 0 ∨
            ¬(BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt.natAbs /
                (operand.setWidth width.bits).toInt.natAbs ≤
              2 ^ (width.bits - 1) -
                (if decide ((BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt < 0) !=
                  decide ((operand.setWidth width.bits).toInt < 0) then 0 else 1) := by
        simp [SignedArithmetic.limit, Nat.not_le]
      simp only [condition]
      by_cases failed : (operand.setWidth width.bits).toInt.natAbs = 0 ∨
          ¬(BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt.natAbs /
              (operand.setWidth width.bits).toInt.natAbs ≤
            2 ^ (width.bits - 1) -
              (if decide ((BitVec.ofNat (2 * width.bits) (Reference.X86.divideDividend width s)).toInt < 0) !=
                decide ((operand.setWidth width.bits).toInt < 0) then 0 else 1)
      · simp only [failed, ↓reduceIte]
      · simp only [failed, ↓reduceIte]
        simp only [Capture.dividend_negative width s, Capture.divisor_negative width operand,
          show ∀ a b : Bool, Bool.xor a b = (a != b) from fun _ _ => rfl,
          restored_word, byte_pack_matches]

/-- Source order CF, ZF, SF, OF, PF, AF. Each bit is an arbitrary fresh choice. -/
def freshFlags (old : Reference.Word) (fresh : Nat → Bool) : Reference.Word :=
  Reference.X86.setFlag (Reference.X86.setFlag (Reference.X86.setFlag
    (Reference.X86.setFlag (Reference.X86.setFlag (Reference.X86.setFlag
      old 0 (fresh 0)) 6 (fresh 1)) 7 (fresh 2)) 11 (fresh 3)) 2 (fresh 4)) 4 (fresh 5)

theorem fresh_flags_mask (old : Reference.Word) (fresh : Nat → Bool) :
    freshFlags old fresh &&& 0xfffffffffffff72a = old &&& 0xfffffffffffff72a := by
  simp only [freshFlags, Reference.X86.setFlag]
  bv_decide

def refresh (fresh : Nat → Bool) (result : Transition Reference.X86.State) :
    Transition Reference.X86.State :=
  if result.fault.isSome then result else
    { result with state := { result.state with rflags := freshFlags result.state.rflags fresh } }

def handlerStep (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (fresh : Nat → Bool) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  refresh fresh (arithmeticStep width source nextPc s)

theorem handler_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (fresh : Nat → Bool) (s : Reference.X86.State) :
    Reference.X86.Step (.signedDivide width source nextPc) s
      (handlerStep width source nextPc fresh s) := by
  unfold handlerStep
  rw [arithmetic_step_refines, signed_magnitude_refines]
  unfold Reference.X86.Step Reference.X86.matchesTransition
  generalize Reference.X86.step (.signedDivide width source nextPc) s = result
  rcases result with ⟨state, events, fault⟩
  cases fault <;> simp [refresh, Reference.X86.definedFlags, Reference.X86.observedRegisters,
    fresh_flags_mask]
  exact (fresh_flags_mask state.rflags fresh).symm

end KProgFormal.Refinement.X86Divide.SourceState

namespace KProgFormal.Refinement.X86Divide.RestoringLoop

/-- The local C loop's word-sized update, including its separately saved carry. -/
def advance (quotient remainder divisor bit : Reference.Word) :
    Reference.Word × Reference.Word :=
  let trial := (remainder <<< 1) ||| bit
  let take := remainder.getLsbD 63 || BitVec.ule divisor trial
  ((quotient <<< 1) ||| (if take then 1 else 0),
    if take then trial - divisor else trial)

theorem carry_comparison (remainder divisor bit : Reference.Word)
    (hb : BitVec.ule bit 1 = true) :
    (remainder.getLsbD 63 || BitVec.ule divisor ((remainder <<< 1) ||| bit)) =
      BitVec.ule (divisor.setWidth 65)
        ((remainder.setWidth 65 <<< 1) ||| bit.setWidth 65) := by
  simp only [Reference.Word] at *
  bv_decide

theorem trial_value (remainder bit : Reference.Word)
    (hb : bit.toNat ≤ 1) :
    (((remainder.setWidth 65 <<< 1) ||| bit.setWidth 65).toNat) =
      2 * remainder.toNat + bit.toNat := by
  have bound := remainder.isLt
  have extended : remainder.toNat < 2^65 := by omega
  have bitBound : bit.toNat < 2^65 := by omega
  rw [machine_trial remainder bit (BitVec.ule_iff_toNat_le.mpr (by simpa using hb))]
  simp only [BitVec.toNat_add, BitVec.toNat_mul, BitVec.toNat_setWidth,
    BitVec.toNat_ofNat]
  change (2 * (remainder.toNat % 36893488147419103232) % 36893488147419103232 +
    bit.toNat % 36893488147419103232) % 36893488147419103232 = _
  rw [Nat.mod_eq_of_lt extended, Nat.mod_eq_of_lt bitBound,
    Nat.mod_eq_of_lt (show 2 * remainder.toNat < 36893488147419103232 by omega),
    Nat.mod_eq_of_lt (by omega)]

theorem advance_remainder (quotient remainder divisor bit : Reference.Word)
    (hr : remainder.toNat < divisor.toNat) (hb : bit.toNat ≤ 1) :
    (advance quotient remainder divisor bit).2.toNat =
      if divisor.toNat ≤ 2 * remainder.toNat + bit.toNat then
        2 * remainder.toNat + bit.toNat - divisor.toNat
      else 2 * remainder.toNat + bit.toNat := by
  have bitRule : BitVec.ule bit 1 = true := BitVec.ule_iff_toNat_le.mpr (by simpa using hb)
  have remainderRule : BitVec.ult remainder divisor = true := BitVec.ult_iff_toNat_lt.mpr hr
  have equation := congrArg BitVec.toNat (machine_remainder remainder divisor bit remainderRule bitRule)
  have wideValue := trial_value remainder bit hb
  have widen (x : Reference.Word) : (x.setWidth 65).toNat = x.toNat := by
    rw [BitVec.toNat_setWidth, Nat.mod_eq_of_lt (by have := x.isLt; omega)]
  change ((if remainder.getLsbD 63 || BitVec.ule divisor ((remainder <<< 1) ||| bit)
    then ((remainder <<< 1) ||| bit) - divisor else (remainder <<< 1) ||| bit).setWidth 65).toNat = _ at equation
  rw [widen] at equation
  change (advance quotient remainder divisor bit).2.toNat = _
  rw [show (advance quotient remainder divisor bit).2.toNat =
    (if remainder.getLsbD 63 || BitVec.ule divisor ((remainder <<< 1) ||| bit)
      then ((remainder <<< 1) ||| bit) - divisor else (remainder <<< 1) ||| bit).toNat from rfl,
    equation]
  by_cases take : divisor.toNat ≤ 2 * remainder.toNat + bit.toNat
  · have wordTake : divisor.setWidth 65 ≤ (remainder.setWidth 65 <<< 1) ||| bit.setWidth 65 := by
      apply BitVec.le_def.mpr
      simpa only [widen, wideValue] using take
    simp only [BitVec.ule_iff_le.mpr wordTake, ↓reduceIte, take]
    rw [BitVec.toNat_sub_of_le wordTake, wideValue, widen]
  · have wordSkip : ¬divisor.setWidth 65 ≤ (remainder.setWidth 65 <<< 1) ||| bit.setWidth 65 := by
      simpa only [BitVec.le_def, widen, wideValue] using take
    have skipped : BitVec.ule (divisor.setWidth 65)
        ((remainder.setWidth 65 <<< 1) ||| bit.setWidth 65) = false := by
      simpa only [BitVec.ule_eq_decide_le, decide_eq_false_iff_not] using wordSkip
    simp only [skipped, Bool.false_eq_true, ↓reduceIte, take, wideValue]

theorem advance_quotient (quotient remainder divisor bit : Reference.Word)
    (hb : bit.toNat ≤ 1) (hq : 2 * quotient.toNat + 1 < 2^64) :
    (advance quotient remainder divisor bit).1.toNat =
      2 * quotient.toNat +
        (if divisor.toNat ≤ 2 * remainder.toNat + bit.toNat then 1 else 0) := by
  have bitRule : BitVec.ule bit 1 = true := BitVec.ule_iff_toNat_le.mpr (by simpa using hb)
  have wideValue := trial_value remainder bit hb
  have widen (x : Reference.Word) : (x.setWidth 65).toNat = x.toNat := by
    rw [BitVec.toNat_setWidth, Nat.mod_eq_of_lt (by have := x.isLt; omega)]
  have takeRule : (remainder.getLsbD 63 || BitVec.ule divisor ((remainder <<< 1) ||| bit)) =
      decide (divisor.toNat ≤ 2 * remainder.toNat + bit.toNat) := by
    rw [carry_comparison remainder divisor bit bitRule]
    simp only [BitVec.ule_eq_decide_le, BitVec.le_def, widen, wideValue]
  simp only [advance, takeRule, machine_quotient]
  by_cases take : divisor.toNat ≤ 2 * remainder.toNat + bit.toNat
  · simp only [take, decide_true, ↓reduceIte, BitVec.toNat_add, BitVec.toNat_mul]
    change (2 * quotient.toNat % 18446744073709551616 + 1) %
      18446744073709551616 = 2 * quotient.toNat + 1
    rw [Nat.mod_eq_of_lt (show 2 * quotient.toNat < 18446744073709551616 by omega),
      Nat.mod_eq_of_lt hq]
  · simp only [take, decide_false, Bool.false_eq_true, ↓reduceIte,
      BitVec.toNat_add, BitVec.toNat_mul]
    change (2 * quotient.toNat % 18446744073709551616 + 0) %
      18446744073709551616 = 2 * quotient.toNat + 0
    rw [Nat.mod_eq_of_lt (show 2 * quotient.toNat < 18446744073709551616 by omega)]
    simp only [Nat.add_zero]
    exact Nat.mod_eq_of_lt (by omega)

/-- The C `for (bit=63; bit>=0; --bit)` recurrence, parameterized by its count. -/
def run : Nat → (Reference.Word × Reference.Word) → Reference.Word →
    Reference.Word → Reference.Word × Reference.Word
  | 0, result, _, _ => result
  | n+1, result, low, divisor =>
      run n (advance result.1 result.2 divisor ((low >>> n) &&& 1)) low divisor

theorem run_last (n : Nat) (result : Reference.Word × Reference.Word)
    (low divisor : Reference.Word) :
    run (n+1) result low divisor =
      let previous := run n result (low >>> 1) divisor
      advance previous.1 previous.2 divisor (low &&& 1) := by
  induction n generalizing result with
  | zero => simp [run]
  | succ n ih =>
      rw [run, ih]
      have shift : low >>> 1 >>> n = low >>> (n+1) := by
        apply BitVec.eq_of_toNat_eq
        simp only [BitVec.toNat_ushiftRight, Nat.shiftRight_eq_div_pow, Nat.div_div_eq_div_mul]
        congr 1
        simp [Nat.pow_succ, Nat.mul_comm]
      simp only [run, shift]

/-- Every descending C iteration realizes the unbounded radix-two recurrence.
The remainder invariant protects its 65th bit; the count bounds quotient writes. -/
theorem run_matches (n : Nat) (high low divisor : Reference.Word)
    (count : n ≤ 64) (initial : high.toNat < divisor.toNat)
    (input : low.toNat < 2^n) :
    let result := run n (0, high) low divisor
    (result.1.toNat, result.2.toNat) =
      longDivide n high.toNat low.toNat divisor.toNat := by
  induction n generalizing low with
  | zero => rfl
  | succ n ih =>
      have halfValue : (low >>> 1).toNat = low.toNat / 2 := by
        simp [BitVec.toNat_ushiftRight, Nat.shiftRight_eq_div_pow]
      have halfBound : (low >>> 1).toNat < 2^n := by
        rw [halfValue]
        apply (Nat.div_lt_iff_lt_mul (by decide : 0 < 2)).2
        simpa only [Nat.pow_succ] using input
      have previous := ih (low >>> 1) (by omega) halfBound
      simp only [halfValue] at previous
      have quotientValue := congrArg Prod.fst previous
      have remainderValue := congrArg Prod.snd previous
      dsimp only at quotientValue remainderValue
      have bounds := longDivide_correct n high.toNat (low.toNat / 2) divisor.toNat initial
        (by simpa only [halfValue] using halfBound)
      have quotientBound : 2 * (run n (0, high) (low >>> 1) divisor).1.toNat + 1 < 2^64 := by
        have power : 2^n * 2 ≤ 2^64 := by
          simpa only [Nat.pow_succ] using Nat.pow_le_pow_right (by decide : 1 ≤ 2) count
        simp only [quotientValue]
        omega
      have remainderBound : (run n (0, high) (low >>> 1) divisor).2.toNat < divisor.toNat := by
        rw [remainderValue]; exact bounds.2.2
      have bitValue : (low &&& 1).toNat = low.toNat % 2 := by
        simp only [BitVec.toNat_and]; exact Nat.and_one_is_mod _
      have bitBound : (low &&& 1).toNat ≤ 1 := by
        rw [bitValue]; have := Nat.mod_lt low.toNat (by decide : 0 < 2); omega
      rw [run_last]
      apply Prod.ext
      · rw [advance_quotient _ _ _ _ bitBound quotientBound]
        simp only [longDivide, quotientValue, remainderValue, bitValue]
        split <;> rename_i take <;> simp [take]
      · rw [advance_remainder _ _ _ _ remainderBound bitBound]
        simp only [longDivide, quotientValue, remainderValue, bitValue]
        split <;> rename_i take <;> simp [take]

/-- The complete source loop computes division of every fitting 128-bit pair. -/
theorem run64_quot_rem (high low divisor : Reference.Word)
    (initial : high.toNat < divisor.toNat) :
    let result := run 64 (0, high) low divisor
    result.1.toNat = (high.toNat * 2^64 + low.toNat) / divisor.toNat ∧
      result.2.toNat = (high.toNat * 2^64 + low.toNat) % divisor.toNat := by
  have loop := run_matches 64 high low divisor (by decide) initial low.isLt
  have exactResult := longDivide_quot_rem 64 high.toNat low.toNat divisor.toNat initial low.isLt
  exact ⟨(congrArg Prod.fst loop).trans exactResult.1,
    (congrArg Prod.snd loop).trans exactResult.2⟩

/-- The emitted qword branch keeps its native unsigned zero-high fast path. -/
def qword (high low divisor : Reference.Word) : Reference.Word × Reference.Word :=
  if high = 0 then (low.udiv divisor, low.umod divisor)
  else run 64 (0, high) low divisor

theorem qword_matches (high low divisor : Reference.Word)
    (initial : high.toNat < divisor.toNat) :
    let result := qword high low divisor
    (result.1.toNat, result.2.toNat) =
      SignedArithmetic.quotRem .w64 high.toNat low.toNat divisor.toNat := by
  by_cases zero : high = 0
  · subst high
    simp [qword, SignedArithmetic.quotRem, BitVec.toNat_udiv, BitVec.toNat_umod]
  · have numeric : high.toNat ≠ 0 := by
      intro eq
      apply zero
      apply BitVec.eq_of_toNat_eq
      exact eq
    simp only [qword, zero, ↓reduceIte, SignedArithmetic.quotRem, numeric]
    exact run_matches 64 high low divisor (by decide) initial low.isLt

/-- The two source fault sites compose the word loop with the signed magnitude
contract, for either sign and every word, before any architectural write. -/
def guardedQword (negative : Bool) (high low divisor : Reference.Word) :
    Option (Nat × Nat) :=
  if divisor = 0 ∨ divisor.toNat ≤ high.toNat then none else
    let result := qword high low divisor
    if SignedArithmetic.limit .w64 negative < result.1.toNat then none
    else some (result.1.toNat, result.2.toNat)

theorem guarded_qword_matches (negative : Bool) (high low divisor : Reference.Word) :
    guardedQword negative high low divisor =
      SignedArithmetic.guarded .w64 negative high.toNat low.toNat divisor.toNat := by
  have zero : divisor = 0 ↔ divisor.toNat = 0 := by
    constructor
    · intro h; simp [h]
    · intro h; apply BitVec.eq_of_toNat_eq; exact h
  have fields : (divisor = 0 ∨ divisor.toNat ≤ high.toNat) ↔
      (divisor.toNat = 0 ∨ divisor.toNat ≤ high.toNat) := or_congr zero Iff.rfl
  by_cases early : divisor.toNat = 0 ∨ divisor.toNat ≤ high.toNat
  · simp only [guardedQword, if_pos (fields.mpr early),
      SignedArithmetic.guarded, if_pos early]
  · have initial : high.toNat < divisor.toNat := by omega
    have result := qword_matches high low divisor initial
    have quotient := congrArg Prod.fst result
    have remainder := congrArg Prod.snd result
    dsimp only at quotient remainder
    simp only [guardedQword, if_neg (mt fields.mp early), SignedArithmetic.guarded,
      if_neg early, quotient, remainder]

/-- The captured signed qword magnitudes now consume the concrete word loop
and its native fast path before the established state/refinement laws. -/
theorem source_qword_outcome (s : Reference.X86.State) (operand : Reference.Word) :
    let limbs := KProgFormal.X86SignedDivision.sourceMagnitudeLimbs
      (X86Scalar.handlerWidth .w64) (Capture.highWord .w64 s) (s.gpr 0)
    guardedQword (Bool.xor (Capture.sourceNegative .w64 (Capture.highWord .w64 s))
        (Capture.sourceNegative .w64 operand)) limbs.1 limbs.2
        (Capture.divisorMagnitude .w64 operand) = SourceState.outcome .w64 s operand := by
  exact guarded_qword_matches _ _ _ _

end KProgFormal.Refinement.X86Divide.RestoringLoop

namespace KProgFormal.Refinement.X86Divide.SourceWords
open Reference.X86 (ScalarWidth)
open KProgFormal.X86SignedDivision

theorem masked_stable (width : ScalarWidth) (value : Reference.Word)
    (bound : value.toNat < base width) :
    maskedLimb (X86Scalar.handlerWidth width) value = value := by
  apply BitVec.eq_of_toNat_eq
  rw [masked_limb_refines, BitVec.toNat_setWidth, BitVec.toNat_setWidth]
  have radix : 2 ^ x86WidthBitsSpec (X86Scalar.handlerWidth width) = base width := by
    cases width <;> rfl
  rw [radix, Nat.mod_eq_of_lt bound, Nat.mod_eq_of_lt value.isLt]

/-- The narrow branch packs its two bounded limbs into the emitted64-bit word. -/
def packed (width : ScalarWidth) (high low : Reference.Word) : Reference.Word :=
  (high <<< width.bits) ||| low

theorem packed_masked (width : ScalarWidth) (high low : Reference.Word)
    (narrow : width ≠ .w64) :
    packed width (maskedLimb (X86Scalar.handlerWidth width) high)
        (maskedLimb (X86Scalar.handlerWidth width) low) =
      (join (X86Scalar.handlerWidth width) high low).setWidth 64 := by
  cases width <;> simp [packed, maskedLimb, join, X86Scalar.handlerWidth,
    x86WidthBitsSpec, Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
    Reference.Word] at * <;> bv_decide

theorem packed_value (width : ScalarWidth) (high low : Reference.Word)
    (narrow : width ≠ .w64) (highBound : high.toNat < base width)
    (lowBound : low.toNat < base width) :
    (packed width high low).toNat = high.toNat * base width + low.toNat := by
  have equation : packed width high low =
      (join (X86Scalar.handlerWidth width) high low).setWidth 64 := by
    calc
      packed width high low = packed width
          (maskedLimb (X86Scalar.handlerWidth width) high)
          (maskedLimb (X86Scalar.handlerWidth width) low) := by
        rw [masked_stable width high highBound, masked_stable width low lowBound]
      _ = _ := packed_masked width high low narrow
  have radix : 2 ^ x86WidthBitsSpec (X86Scalar.handlerWidth width) = base width := by
    cases width <;> rfl
  have size : 2 * x86WidthBitsSpec (X86Scalar.handlerWidth width) ≤ 64 := by
    cases width <;> simp [X86Scalar.handlerWidth, x86WidthBitsSpec] at *
  have bound : (join (X86Scalar.handlerWidth width) high low).toNat < 2^64 :=
    Nat.lt_of_lt_of_le (join (X86Scalar.handlerWidth width) high low).isLt
      (Nat.pow_le_pow_right (by decide : 1 ≤ 2) size)
  rw [equation, BitVec.toNat_setWidth, Nat.mod_eq_of_lt bound,
    join_to_nat, radix, Nat.mod_eq_of_lt highBound, Nat.mod_eq_of_lt lowBound]

/-- All emitted arithmetic routes operate on words: direct narrow division,
the qword zero-high fast path and the complete descending restoring loop. -/
def quotRem (width : ScalarWidth) (high low divisor : Reference.Word) :
    Reference.Word × Reference.Word :=
  if width = .w64 then RestoringLoop.qword high low divisor else
    let dividend := packed width high low
    (dividend.udiv divisor, dividend.umod divisor)

theorem quot_rem_matches (width : ScalarWidth) (high low divisor : Reference.Word)
    (highBound : high.toNat < base width) (lowBound : low.toNat < base width)
    (initial : high.toNat < divisor.toNat) :
    let result := quotRem width high low divisor
    (result.1.toNat, result.2.toNat) =
      SignedArithmetic.quotRem width high.toNat low.toNat divisor.toNat := by
  by_cases wide : width = .w64
  · subst width
    simpa only [quotRem, ↓reduceIte] using RestoringLoop.qword_matches high low divisor initial
  · have dividend := packed_value width high low wide highBound lowBound
    simp only [quotRem, SignedArithmetic.quotRem, wide, ↓reduceIte]
    change ((packed width high low).toNat / divisor.toNat,
      (packed width high low).toNat % divisor.toNat) = _
    rw [dividend]

/-- The actual unsigned source threshold retains the signed minimum magnitude. -/
def limitWord (width : ScalarWidth) (negative : Bool) : Reference.Word :=
  (1 <<< (width.bits - 1)) - (if negative then 0 else 1)

theorem limit_value (width : ScalarWidth) (negative : Bool) :
    (limitWord width negative).toNat = SignedArithmetic.limit width negative := by
  cases width <;> cases negative <;> decide

/-- The C body tests the preliminary limbs and then the unsigned sign limit,
keeping the quotient and remainder as source words until architectural writes. -/
def guarded (width : ScalarWidth) (negative : Bool)
    (high low divisor : Reference.Word) : Option (Reference.Word × Reference.Word) :=
  if divisor = 0 ∨ BitVec.ule divisor high then none else
    let result := quotRem width high low divisor
    if BitVec.ult (limitWord width negative) result.1 then none else some result

theorem guarded_matches (width : ScalarWidth) (negative : Bool)
    (high low divisor : Reference.Word) (highBound : high.toNat < base width)
    (lowBound : low.toNat < base width) :
    (guarded width negative high low divisor).map (fun pair => (pair.1.toNat, pair.2.toNat)) =
      SignedArithmetic.guarded width negative high.toNat low.toNat divisor.toNat := by
  have zero : divisor = 0 ↔ divisor.toNat = 0 := by
    constructor
    · intro h; simp [h]
    · intro h; apply BitVec.eq_of_toNat_eq; exact h
  have fields : (divisor = 0 ∨ BitVec.ule divisor high) ↔
      (divisor.toNat = 0 ∨ divisor.toNat ≤ high.toNat) :=
    or_congr zero BitVec.ule_iff_toNat_le
  by_cases early : divisor.toNat = 0 ∨ divisor.toNat ≤ high.toNat
  · rw [guarded, if_pos (fields.mpr early), SignedArithmetic.guarded, if_pos early]
    rfl
  · have initial : high.toNat < divisor.toNat := by omega
    have result := quot_rem_matches width high low divisor highBound lowBound initial
    have quotient := congrArg Prod.fst result
    have remainder := congrArg Prod.snd result
    dsimp only at quotient remainder
    simp only [guarded, if_neg (mt fields.mp early), SignedArithmetic.guarded,
      if_neg early, BitVec.ult_iff_toNat_lt, limit_value, quotient]
    split
    · rfl
    · change some ((quotRem width high low divisor).1.toNat,
        (quotRem width high low divisor).2.toNat) = _
      exact congrArg some result

/-- Actual source masks/signs feed the word arithmetic on every emitted width. -/
def outcome (width : ScalarWidth) (s : Reference.X86.State) (operand : Reference.Word) :
    Option (Reference.Word × Reference.Word) :=
  let limbs := sourceMagnitudeLimbs (X86Scalar.handlerWidth width)
    (Capture.highWord width s) (s.gpr 0)
  guarded width (Bool.xor (Capture.sourceNegative width (Capture.highWord width s))
    (Capture.sourceNegative width operand)) limbs.1 limbs.2 (Capture.divisorMagnitude width operand)

theorem outcome_matches (width : ScalarWidth) (s : Reference.X86.State) (operand : Reference.Word) :
    (outcome width s operand).map (fun pair => (pair.1.toNat, pair.2.toNat)) =
      SourceState.outcome width s operand := by
  have bounds := source_limbs_bounds (X86Scalar.handlerWidth width)
    (Capture.highWord width s) (s.gpr 0)
  have radix : 2 ^ x86WidthBitsSpec (X86Scalar.handlerWidth width) = base width := by
    cases width <;> rfl
  rw [radix] at bounds
  exact guarded_matches _ _ _ _ _ bounds.1 bounds.2

/-- The actual word quotient/remainder receive unsigned sign restoration and
the existing byte or wider architectural writes after both fault sites. -/
def arithmeticStep (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) : Reference.Transition Reference.X86.State :=
  match X86Scalar.read s width source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (operand, reads) =>
      match outcome width s operand with
      | none => ⟨s, reads ++ [.fault .divide], some .divide⟩
      | some (quotient, remainder) =>
          let negative := Capture.sourceNegative width (Capture.highWord width s)
          let qnegative := Bool.xor negative (Capture.sourceNegative width operand)
          let qword := if qnegative then 0 - quotient else quotient
          let rword := if negative then 0 - remainder else remainder
          if width = .w8 then
            let registers := fun r => if r = 0 then
              write .w16 (s.gpr r) (SourceState.packedBytes qword rword) else s.gpr r
            ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩
          else
            let registers := fun r => if r = 0 then write width (s.gpr r) qword
              else if r = 2 then write width (s.gpr r) rword else s.gpr r
            ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩

theorem arithmetic_step_matches (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (s : Reference.X86.State) :
    arithmeticStep width source nextPc s = SourceState.arithmeticStep width source nextPc s := by
  unfold arithmeticStep SourceState.arithmeticStep
  cases read : X86Scalar.read s width source with
  | error fault => rfl
  | ok pair =>
      rcases pair with ⟨operand, reads⟩
      simp only []
      rw [← outcome_matches width s operand]
      cases result : outcome width s operand with
      | none => rfl
      | some pair =>
          rcases pair with ⟨quotient, remainder⟩
          simp [Option.map, SourceState.restoredWord]

/-- All six source-order flags remain arbitrary fresh choices. -/
def handlerStep (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (fresh : Nat → Bool) (s : Reference.X86.State) :
    Reference.Transition Reference.X86.State :=
  SourceState.refresh fresh (arithmeticStep width source nextPc s)

theorem handler_matches (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (fresh : Nat → Bool) (s : Reference.X86.State) :
    handlerStep width source nextPc fresh s = SourceState.handlerStep width source nextPc fresh s := by
  rw [handlerStep, arithmetic_step_matches]
  rfl

theorem handler_refines (width : ScalarWidth) (source : Reference.X86.ScalarSource)
    (nextPc : Reference.Word) (fresh : Nat → Bool) (s : Reference.X86.State) :
    Reference.X86.Step (.signedDivide width source nextPc) s
      (handlerStep width source nextPc fresh s) := by
  rw [handler_matches]
  exact SourceState.handler_refines width source nextPc fresh s

end KProgFormal.Refinement.X86Divide.SourceWords
