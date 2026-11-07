import KProgFormal.Refinement.X86BmiShift
import KProgFormal.Refinement.X86LegacyShift

namespace KProgFormal.Refinement.X86RotateRight
open Reference
open Reference.X86 (ScalarWidth ScalarDestination)

def value (width : ScalarWidth) (source count : Reference.Word) : Reference.Word :=
  GeneratedX86ShiftResult.ror source count (X86Scalar.handlerWidth width)

/-- The C classic-ROR flag macro preserves every flag except CF/OF. -/
def flags (width : ScalarWidth) (result count old : Reference.Word) : Reference.Word :=
  let n := (GeneratedX86ShiftCount.count count (X86Scalar.handlerWidth width)).toNat
  let bits := GeneratedX86Width.bits (X86Scalar.handlerWidth width)
  let cf := (result >>> (bits - 1)).getLsbD 0
  let of := cf != (result >>> (bits - 2)).getLsbD 0
  if n = 0 then old else
    X86Arithmetic.flagsWord old ⟨cf, old.getLsbD 6, old.getLsbD 7,
      if n = 1 then of else old.getLsbD 11⟩ (old.getLsbD 2) (old.getLsbD 4)

theorem shifted_bit (width : ScalarWidth) (result : Reference.Word) :
    (result >>> (width.bits - 1)).getLsbD 0 = result.getLsbD (width.bits - 1) ∧
    (result >>> (width.bits - 2)).getLsbD 0 = result.getLsbD (width.bits - 2) := by
  cases width <;> simp only [Reference.X86.ScalarWidth.bits, Reference.X86.ScalarWidth.bytes,
    Nat.reduceMul, Nat.reduceSub, Reference.Word] <;> bv_decide

theorem flags_refine (width : ScalarWidth) (source count old : Reference.Word) :
    flags width (Reference.X86.rotateRightValue width source count) count old =
      Reference.X86.rotateRightFlags width source count old := by
  simp only [flags, value, X86BmiShift.legacy_ror_value_refines,
    X86LegacyShift.count_refines, X86LegacyShift.bits_refines,
    Reference.X86.rotateRightFlags, (shifted_bit width _).1, (shifted_bit width _).2]
  by_cases h : (Reference.X86.legacyCount width count).toNat = 0
  · simp only [h, ↓reduceIte]
  · simp only [h, ↓reduceIte, X86LegacyShift.pack_rotate]


def handlerStep (width : ScalarWidth) (dst : ScalarDestination)
    (count nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  match X86Scalar.read s width dst.source with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (source, reads) =>
      match X86Scalar.write s width dst (value width source count) with
      | .error fault => ⟨s, reads ++ [.fault fault], some fault⟩
      | .ok (result, writes) =>
          ⟨{ result with rflags := flags width (value width source count) count s.rflags, pc := nextPc }, reads ++ writes, none⟩

theorem step_refines (width : ScalarWidth) (dst : ScalarDestination)
    (count nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width dst count nextPc s =
      Reference.X86.step (.rotateRight width dst count nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.rotateRightStep,
    X86Scalar.read_refines, X86Scalar.write_refines, flags_refine,
    value, X86BmiShift.legacy_ror_value_refines]
  rfl

theorem handler_refines (width : ScalarWidth) (dst : ScalarDestination)
    (count nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.rotateRight width dst count nextPc) s
      (handlerStep width dst count nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Refinement.X86RotateRight
