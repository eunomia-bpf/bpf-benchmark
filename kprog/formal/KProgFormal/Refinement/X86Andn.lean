import KProgFormal.X86AndnHandler
import KProgFormal.Refinement.X86Bzhi

namespace KProgFormal.Refinement.X86Andn

open Reference
open Reference.X86 (BzhiWidth Register Source)
open X86Bzhi (handlerWidth readWidth liftFlags)

def mask (width : BzhiWidth) : Reference.Word := BitVec.ofNat 64 (2 ^ width.bits) - 1

/-- Flags use the narrowed result even when the raw upper bits are nonzero. -/
theorem flags_refines (width : BzhiWidth) (old value : Reference.Word) :
    liftFlags old (generatedX86AndnFlags value (handlerWidth width)) =
      Reference.X86.andnFlags old (value &&& mask width) width.bits := by
  cases width <;>
    simp only [liftFlags, generatedX86AndnFlags, generatedX86LogicFlags,
      GeneratedX86LogicFlags.eval, GeneratedX86Width.zero, GeneratedX86Width.sign,
      GeneratedX86Width.narrow, GeneratedX86Width.mask, GeneratedX86Width.signMask, GeneratedX86Width.bits,
      handlerWidth, Reference.X86.andnFlags, Reference.X86.resultZero,
      Reference.X86.resultSign, Reference.X86.setFlag, mask, Reference.X86.BzhiWidth.bits,
      Reference.X86.BzhiWidth.bytes, Reference.Word] <;> bv_decide

theorem writeback_refines (width : BzhiWidth) (old : X86RegValue) (value : Reference.Word) :
    (generatedX86RegWrite old value (handlerWidth width)).bits = value &&& mask width := by
  cases width <;>
    simp only [generatedX86RegWrite, handlerWidth, GeneratedX86RegWrite.write,
      GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt,
      GeneratedX86RegWrite.bits, GeneratedX86RegWrite.byteShift,
      mask, Reference.X86.BzhiWidth.bits, Reference.X86.BzhiWidth.bytes, Reference.Word] <;> bv_decide

/-- Both production source routes read before writing the destination, including
aliasing first/destination registers and destination-addressed memory. -/
def handlerStep (width : BzhiWidth) (dst first : Register) (second : Source)
    (nextPc : Reference.Word) (s : Reference.X86.State) (tag : Tag) : Transition Reference.X86.State :=
  match X86Bt.readOperand (readWidth width) second s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let result := generatedX86AndnResult (s.gpr first) value
      let flags := generatedX86AndnFlags result (handlerWidth width)
      let written := generatedX86RegWrite ⟨s.gpr dst, tag⟩ result (handlerWidth width)
      ⟨{ s with gpr := (fun r => if r = dst then written.bits else s.gpr r), rflags := liftFlags s.rflags flags, pc := nextPc }, events, none⟩

theorem step_refines (width : BzhiWidth) (dst first : Register) (second : Source)
    (nextPc : Reference.Word) (s : Reference.X86.State) (tag : Tag) :
    handlerStep width dst first second nextPc s tag =
      Reference.X86.step (.andn width dst first second nextPc) s := by
  simp only [handlerStep, X86Bt.read_refines, Reference.X86.step,
    flags_refines, writeback_refines]
  cases width <;>
    simp only [readWidth, Reference.X86.CmovWidth.bytes, Reference.X86.BzhiWidth.bytes,
      generatedX86AndnResult, Reference.X86.andNot, mask] <;> rfl

/-- AF/PF are undefined by ANDN; all other state and every access/fault effect
agree with the handler lift. This is not the ordinary AND parity-flag rule. -/
theorem handler_refines (width : BzhiWidth) (dst first : Register) (second : Source)
    (nextPc : Reference.Word) (s : Reference.X86.State) (tag : Tag) :
    Reference.X86.Step (.andn width dst first second nextPc) s
      (handlerStep width dst first second nextPc s tag) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Andn
