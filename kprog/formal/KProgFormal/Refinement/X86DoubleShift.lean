import KProgFormal.X86DoubleShiftArmHandler
import KProgFormal.Refinement.X86Cmov
import KProgFormal.Refinement.X86LegacyShift

namespace KProgFormal.Refinement.X86DoubleShift
open Reference
open Reference.X86 (CmovWidth Register)
open X86Cmov (handlerWidth)

def scalarWidth : CmovWidth → Reference.X86.ScalarWidth
  | .w16 => .w16 | .w32 => .w32 | .w64 => .w64

def value (width : CmovWidth) (left : Bool) (destination source count : Reference.Word) : Reference.Word :=
  if left then GeneratedX86DoubleShift.shld destination source count width.bytes
  else GeneratedX86DoubleShift.shrd destination source count width.bytes

theorem value_refines (width : CmovWidth) (left : Bool) (destination source count : Reference.Word) :
    value width left destination source count =
      Reference.X86.doubleShiftValue left destination source count width.bits := by
  have h : width.bytes = 1 ∨ width.bytes = 2 ∨ width.bytes = 4 ∨ width.bytes = 8 := by cases width <;> decide
  cases left
  · simpa [value, x86ShrdSpec, Reference.X86.CmovWidth.bits, Nat.mul_comm] using x86_shrd_refines destination source count width.bytes h
  · simpa [value, x86ShldSpec, Reference.X86.CmovWidth.bits, Nat.mul_comm] using x86_shld_refines destination source count width.bytes h

theorem count_refines (width : CmovWidth) (count : Reference.Word) :
    GeneratedX86ShiftCount.count count (handlerWidth width) = Reference.X86.doubleShiftCount count width.bits := by
  cases width <;> rfl

theorem bits_refine (width : CmovWidth) :
    GeneratedX86Width.bits (handlerWidth width) = width.bits := by cases width <;> rfl

theorem scalar_bridge (width : CmovWidth) :
    X86Scalar.handlerWidth (scalarWidth width) = handlerWidth width ∧ (scalarWidth width).bits = width.bits := by
  cases width <;> exact ⟨rfl,rfl⟩

theorem narrow_refines (width : CmovWidth) (a : Reference.Word) :
    GeneratedX86Width.narrow a (handlerWidth width) = (a.setWidth width.bits).setWidth 64 := by
  cases width <;> simp only [handlerWidth, GeneratedX86Width.narrow, GeneratedX86Width.mask,
    Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes, Nat.reduceMul, Reference.Word] <;> bv_decide

theorem count_one (x : Reference.Word) : x.toNat = 1 ↔ x = 1 := by
  constructor
  · intro h; apply BitVec.eq_of_toNat_eq; simpa using h
  · intro h; simp [h]

theorem narrow_value (width : CmovWidth) (left : Bool) (a b count : Reference.Word) :
    GeneratedX86Width.narrow (Reference.X86.doubleShiftValue left a b count width.bits) (handlerWidth width) =
      Reference.X86.doubleShiftValue left a b count width.bits := by
  cases width <;> cases left <;>
    simp only [handlerWidth, GeneratedX86Width.narrow, GeneratedX86Width.mask,
      Reference.X86.doubleShiftValue, Reference.X86.CmovWidth.bits, Reference.X86.CmovWidth.bytes,
      Nat.reduceMul, Reference.Word] <;> bv_decide

theorem value_narrow (width : CmovWidth) (left : Bool) (a b count : Reference.Word) :
    ((Reference.X86.doubleShiftValue left a b count width.bits).setWidth width.bits).setWidth 64 =
      Reference.X86.doubleShiftValue left a b count width.bits := by
  rw [← narrow_refines]
  exact narrow_value width left a b count

/-- Generated shift CF/ZF/SF/PF followed by the production OF correction. AF
is retained as an undefined representative; zero-count preserves all flags. -/
def flags (width : CmovWidth) (left : Bool) (a result count old : Reference.Word) : Reference.Word :=
  let w := handlerWidth width
  let first := GeneratedX86ShiftFlags.apply (if left then .shl else .shr) a count result w
    ⟨old.getLsbD 0,old.getLsbD 6,old.getLsbD 7,old.getLsbD 11⟩
  let count := GeneratedX86ShiftCount.count count w
  let of := GeneratedX86DoubleShiftArm.overflow (GeneratedX86Width.sign a w)
    (GeneratedX86Width.sign result w) count first.of
  let pf := if count.toNat = 0 then old.getLsbD 2 else GeneratedX86AuxFlags.parity result
  X86Arithmetic.flagsWord old ⟨first.cf,first.zf,first.sf,of⟩ pf (old.getLsbD 4)

theorem sign_refines (width : CmovWidth) (a : Reference.Word) :
    GeneratedX86Width.sign a (handlerWidth width) = a.getLsbD (width.bits-1) := by
  simpa only [(scalar_bridge width).1, (scalar_bridge width).2] using X86LegacyShift.sign (scalarWidth width) a

theorem nested_else (p : Prop) [Decidable p] (a b c : Bool) :
    (if p then a else if p then b else c) = (if p then a else c) := by
  by_cases h : p <;> simp [h]

theorem flags_refine (width : CmovWidth) (left : Bool) (a b count old : Reference.Word) :
    flags width left a (Reference.X86.doubleShiftValue left a b count width.bits) count old =
      Reference.X86.doubleShiftFlags width left a b count old := by
  cases left <;> by_cases hn : (Reference.X86.doubleShiftCount count width.bits).toNat = 0 <;>
    simp only [flags, Reference.X86.doubleShiftFlags, GeneratedX86ShiftFlags.apply,
      count_refines, bits_refine, hn, ↓reduceIte, Bool.false_eq_true, Bool.true_eq_false,
      GeneratedX86ShiftFlags.shlCf, GeneratedX86ShiftFlags.rightCf, narrow_value,
      sign_refines, narrow_refines, count_one, GeneratedX86DoubleShiftArm.overflow, Reference.X86.doubleShiftOverflow,
      Reference.X86.resultSign, X86AuxFlags.parity_refines]
  · have hz := (X86LegacyShift.count_zero _).mpr hn
    simpa [hz] using X86LegacyShift.pack_old old
  · rw [X86LegacyShift.pack]
    simp only [value_narrow, nested_else]
  · have hz := (X86LegacyShift.count_zero _).mpr hn
    simpa [hz] using X86LegacyShift.pack_old old
  · rw [X86LegacyShift.pack]
    simp only [value_narrow, nested_else]

def handlerStep (width : CmovWidth) (left : Bool) (dst source : Register)
    (count nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  let result := value width left (s.gpr dst) (s.gpr source) count
  let written := GeneratedX86RegWrite.bits (s.gpr dst) result (handlerWidth width)
  ⟨{ s with gpr := fun r => if r = dst then written else s.gpr r, rflags := flags width left (s.gpr dst) result count s.rflags, pc := nextPc }, [], none⟩

theorem write_refines (width : CmovWidth) (old result : Reference.Word) :
    GeneratedX86RegWrite.bits old result (handlerWidth width) = Reference.X86.writeValue width old result := by
  cases width <;> simp only [handlerWidth, GeneratedX86RegWrite.bits, Reference.X86.writeValue, Reference.Word] <;> bv_decide

theorem step_refines (width : CmovWidth) (left : Bool) (dst source : Register)
    (count nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width left dst source count nextPc s =
      Reference.X86.step (.doubleShift width left dst source count nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.doubleShiftStep,
    value_refines, write_refines, flags_refine]
  congr 2
  funext r
  by_cases h : r = dst <;> simp [h]

theorem handler_refines (width : CmovWidth) (left : Bool) (dst source : Register)
    (count nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.doubleShift width left dst source count nextPc) s
      (handlerStep width left dst source count nextPc s) := by
  rw [step_refines]
  exact ⟨rfl,rfl,rfl⟩

end KProgFormal.Refinement.X86DoubleShift
