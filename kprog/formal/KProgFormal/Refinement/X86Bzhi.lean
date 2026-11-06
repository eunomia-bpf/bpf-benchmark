import KProgFormal.X86BzhiHandler
import KProgFormal.Refinement.X86Bt

namespace KProgFormal.Refinement.X86Bzhi

open Reference
open Reference.X86 (BzhiWidth Source Register)

def handlerWidth : BzhiWidth → X86Width
  | .w32 => .w32
  | .w64 => .w64

def readWidth : BzhiWidth → Reference.X86.CmovWidth
  | .w32 => .w32
  | .w64 => .w64

theorem value_refines (width : BzhiWidth) (value count : Reference.Word) :
    generatedX86BzhiResult value count (handlerWidth width) =
      Reference.X86.zeroHighBits value count width.bits := by
  rw [x86_bzhi_result_refines]
  cases width <;> rfl

/-- Preserve unmodified RFLAGS bits while lifting the four actual flag writes. -/
def liftFlags (old : Reference.Word) (flags : X86Flags) : Reference.Word :=
  Reference.X86.setFlag (Reference.X86.setFlag
    (Reference.X86.setFlag (Reference.X86.setFlag old 0 flags.cf) 6 flags.zf)
    7 flags.sf) 11 flags.of

theorem flags_refines (width : BzhiWidth) (old count result : Reference.Word) :
    liftFlags old (generatedX86BzhiFlags count result (handlerWidth width)) =
      Reference.X86.bzhiFlags old count result width.bits := by
  cases width <;> rfl

theorem writeback_refines (width : BzhiWidth) (old : X86RegValue)
    (value count : Reference.Word) :
    (generatedX86RegWrite old (Reference.X86.zeroHighBits value count width.bits)
      (handlerWidth width)).bits = Reference.X86.zeroHighBits value count width.bits := by
  cases width <;>
    simp only [handlerWidth, generatedX86RegWrite, GeneratedX86RegWrite.write,
      GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt,
      GeneratedX86RegWrite.bits, GeneratedX86RegWrite.byteShift,
      Reference.X86.zeroHighBits, Reference.X86.BzhiWidth.bits,
      Reference.X86.BzhiWidth.bytes, Reference.Word] <;> bv_decide

/-- Lift the existing generated register/memory handler primitives to all native
registers, full flags, vector, memory, PC, faults and ordered read effects. -/
def handlerStep (width : BzhiWidth) (dst : Register) (source : Source) (count : Register)
    (nextPc : Reference.Word) (s : Reference.X86.State) (tag : Tag) : Transition Reference.X86.State :=
  match X86Bt.readOperand (readWidth width) source s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let count := s.gpr count &&& 0xff
      let result := generatedX86BzhiResult value count (handlerWidth width)
      let flags := generatedX86BzhiFlags count result (handlerWidth width)
      let written := generatedX86RegWrite ⟨s.gpr dst, tag⟩ result (handlerWidth width)
      ⟨{ s with gpr := (fun r => if r = dst then written.bits else s.gpr r), rflags := liftFlags s.rflags flags, pc := nextPc }, events, none⟩

theorem step_refines (width : BzhiWidth) (dst : Register) (source : Source) (count : Register)
    (nextPc : Reference.Word) (s : Reference.X86.State) (tag : Tag) :
    handlerStep width dst source count nextPc s tag =
      Reference.X86.step (.bzhi width dst source count nextPc) s := by
  simp only [handlerStep, X86Bt.read_refines, Reference.X86.step]
  cases width <;>
    simp only [readWidth, Reference.X86.CmovWidth.bytes, Reference.X86.BzhiWidth.bytes,
      writeback_refines, flags_refines, value_refines] <;> rfl

/-- Undefined AF/PF are unconstrained by the architectural relation; every
other architectural component agrees with the production handler lift. -/
theorem handler_refines (width : BzhiWidth) (dst : Register) (source : Source) (count : Register)
    (nextPc : Reference.Word) (s : Reference.X86.State) (tag : Tag) :
    Reference.X86.Step (.bzhi width dst source count nextPc) s
      (handlerStep width dst source count nextPc s tag) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Bzhi
