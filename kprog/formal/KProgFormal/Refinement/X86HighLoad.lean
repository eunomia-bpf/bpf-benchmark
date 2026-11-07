import KProgFormal.Refinement.X86Scalar
import KProgFormal.X86MovHandler
namespace KProgFormal.Refinement.X86HighLoad
open Reference

def aux : BitVec 32 := GeneratedX86RegLaneAux.pack 0 8 0

theorem destination_shift : GeneratedX86RegLaneAux.dstShift aux = 8 := by decide

theorem write_refines (dst : Fin 4) (old : X86RegValue) (value : Reference.Word) :
    (generatedX86MovImmStep ⟨old⟩ value .w8 .high).dst.bits =
      Reference.X86.scalarWriteValue old.bits value .w8 (.high dst) := by
  simpa only [generatedX86MovImmStep, generatedX86RegWriteAt, X86Scalar.handlerWidth, X86Scalar.lane] using
    X86Scalar.register_write_refines .w8 (.high dst) old.bits value

/-- READ_MEM_VALUE is evaluated before the existing MOV_IMM_AUX writer.
A failing read leaves every register/flag untouched; no scratch GPR is used. -/
def handlerStep (dst : Fin 4) (address nextPc : Reference.Word) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  match X86Scalar.read s .w8 (.memory address) with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, reads) =>
      let reg := (Reference.X86.RegisterSlice.high dst).reg
      let registers := fun r => if r = reg then
        (generatedX86MovImmStep ⟨⟨s.gpr r, .scalar⟩⟩ value .w8 .high).dst.bits else s.gpr r
      ⟨{ s with gpr := registers, pc := nextPc }, reads, none⟩

theorem step_refines (dst : Fin 4) (address nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep dst address nextPc s =
      Reference.X86.step (.move .w8 (.register (.high dst)) (.memory address) nextPc) s := by
  simp only [handlerStep, Reference.X86.step, Reference.X86.moveStep, X86Scalar.read_refines]
  cases h : Reference.X86.scalarRead s .w8 (.memory address) with
  | error fault => simp only [h]
  | ok pair =>
      simp only [h, write_refines dst, Reference.X86.scalarWrite, List.append_nil]

theorem handler_refines (dst : Fin 4) (address nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.move .w8 (.register (.high dst)) (.memory address) nextPc) s
      (handlerStep dst address nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
end KProgFormal.Refinement.X86HighLoad
