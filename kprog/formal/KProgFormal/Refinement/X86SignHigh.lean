import KProgFormal.Refinement.X86Cmov
import KProgFormal.X86MovHandler
namespace KProgFormal.Refinement.X86SignHigh
open Reference
open Reference.X86 (CmovWidth)

/-- The encoder feeds this expression to the existing MOV immediate writer. -/
def value (width : CmovWidth) (source : Reference.Word) : Reference.Word :=
  0 - ((source >>> (BitVec.ofNat 64 (width.bits - 1))) &&& 1)

theorem write_refines (width : CmovWidth) (old source : Reference.Word) :
    (generatedX86MovImmStep ⟨⟨old, .scalar⟩⟩ (value width source)
      (X86Cmov.handlerWidth width) .low).dst.bits =
      Reference.X86.writeValue width old (Reference.X86.signHighValue width source) := by
  cases width <;>
    simp [generatedX86MovImmStep, generatedX86RegWriteAt,
      GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt,
      GeneratedX86RegWrite.byteShift, GeneratedX86RegWrite.bits,
      X86Cmov.handlerWidth, value, Reference.X86.writeValue,
      Reference.X86.signHighValue, Reference.X86.CmovWidth.bits,
      Reference.X86.CmovWidth.bytes] <;> bv_decide

def handlerStep (width : CmovWidth) (nextPc : Reference.Word)
    (s : Reference.X86.State) : Transition Reference.X86.State :=
  let registers := fun r => if r = 2 then
    (generatedX86MovImmStep ⟨⟨s.gpr r, .scalar⟩⟩ (value width (s.gpr 0))
      (X86Cmov.handlerWidth width) .low).dst.bits else s.gpr r
  ⟨{ s with gpr := registers, pc := nextPc }, [], none⟩

theorem step_refines (width : CmovWidth) (nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width nextPc s = Reference.X86.step (.signHigh width nextPc) s := by
  simp only [handlerStep, Reference.X86.step, write_refines]
  congr 2
  funext r
  split <;> simp_all

theorem handler_refines (width : CmovWidth) (nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.signHigh width nextPc) s (handlerStep width nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Refinement.X86SignHigh
