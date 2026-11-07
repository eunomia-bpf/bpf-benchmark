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
