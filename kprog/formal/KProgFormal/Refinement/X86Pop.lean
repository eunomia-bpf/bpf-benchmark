import KProgFormal.X86PushPopHandler
import KProgFormal.Refinement.X86Bt

namespace KProgFormal.Refinement.X86Pop

open Reference
open Reference.X86 (StackWidth Register)

def handlerWidth (width : StackWidth) : X86Width :=
  X86Cmov.handlerWidth width.registerWidth

def widthCode : StackWidth → GeneratedX86Store.Code
  | .w16 => .b16 | .w64 => .b64

/-- The real stack-transfer arm uses the generated width and step tables. -/
theorem stack_address_refines (width : StackWidth) (rsp : Reference.Word) :
    generatedX86PushPopAccessAt .pop rsp (widthCode width) = rsp ∧
    generatedX86PushPopRspAt .pop rsp (widthCode width) =
      rsp + BitVec.ofNat 64 width.bytes := by
  cases width <;> exact ⟨rfl, rfl⟩

/-- The destination is read after the old RSP has been advanced. This includes
partial SP writes and carries from its low sixteen bits into its upper bits. -/
def handlerStep (width : StackWidth) (dst : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) (dstTag : Tag) : Transition Reference.X86.State :=
  let address := generatedX86PushPopAccessAt .pop (s.gpr 4) (widthCode width)
  match X86Bt.readOperand width.registerWidth (.memory address) s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let advanced := generatedX86PushPopRspAt .pop (s.gpr 4) (widthCode width)
      let afterStack := fun r => if r = 4 then advanced else s.gpr r
      let result := generatedX86RegWrite ⟨afterStack dst, dstTag⟩ value (handlerWidth width)
      ⟨{ s with gpr := (fun r => if r = dst then result.bits else afterStack r), pc := nextPc }, events, none⟩

theorem writeback_refines (width : StackWidth) (old : X86RegValue) (value : Reference.Word) :
    (generatedX86RegWrite old value (handlerWidth width)).bits =
      Reference.X86.cmovValue width.registerWidth true old.bits value := by
  cases width <;>
    simp only [handlerWidth, Reference.X86.StackWidth.registerWidth,
      X86Cmov.handlerWidth, Reference.X86.cmovValue, generatedX86RegWrite,
      GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt,
      GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits,
      GeneratedX86RegWrite.byteShift, Reference.Word] <;> bv_decide

/-- Whole architectural state and ordered memory effects agree, for all
sixteen destinations, arbitrary tags, and arbitrary mapped or faulting stack. -/
theorem step_refines (width : StackWidth) (dst : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) (tag : Tag) :
    handlerStep width dst nextPc s tag =
      Reference.X86.step (.pop width dst nextPc) s := by
  simp only [handlerStep, (stack_address_refines width (s.gpr 4)).1,
    X86Bt.read_refines, Reference.X86.step,
    (stack_address_refines width (s.gpr 4)).2, writeback_refines]
  cases width <;> rfl

theorem handler_refines (width : StackWidth) (dst : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) (tag : Tag) :
    Reference.X86.Step (.pop width dst nextPc) s (handlerStep width dst nextPc s tag) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

/-- A stack fault occurs before the increment and destination write. -/
theorem fault_preserves_state (width : StackWidth) (dst : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State)
    (h : permitted s.memory.readable (s.gpr 4) width.bytes = false) :
    Reference.X86.step (.pop width dst nextPc) s =
      ⟨s, [.fault (.read (s.gpr 4) width.bytes)], some (.read (s.gpr 4) width.bytes)⟩ := by
  simp only [Reference.X86.step, Reference.X86.readSource, readMemory, h, Bool.false_eq_true,
    ↓reduceIte]

end KProgFormal.Refinement.X86Pop
