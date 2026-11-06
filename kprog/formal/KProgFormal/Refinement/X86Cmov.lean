import KProgFormal.Reference.X86
import KProgFormal.X86CmovHandler

namespace KProgFormal.Refinement.X86Cmov

open Reference

def handlerWidth : Reference.X86.CmovWidth → X86Width
  | .w16 => .w16
  | .w32 => .w32
  | .w64 => .w64

/-- Full-word native value production after the source has been read. Tags
remain arbitrary proof metadata; the reference observes only architectural bits. -/
def handlerValue (width : Reference.X86.CmovWidth) (taken : Bool)
    (old source : X86RegValue) : X86RegValue :=
  if taken then
    if handlerWidth width = .w64 then
      (generatedX86MovPointerWrite { dst := old } source.bits source.tag).dst
    else generatedX86RegWrite old source.bits (handlerWidth width)
  else if handlerWidth width = .w32 then
    generatedX86RegWrite old old.bits .w32
  else old

theorem value_refines (width : Reference.X86.CmovWidth) (taken : Bool)
    (old source : X86RegValue) :
    (handlerValue width taken old source).bits =
      Reference.X86.cmovValue width taken old.bits source.bits := by
  cases width <;> cases taken <;>
    simp [handlerValue, handlerWidth, Reference.X86.cmovValue,
      generatedX86MovPointerWrite, generatedX86RegWrite,
      GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt,
      GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits,
      GeneratedX86RegWrite.byteShift, GeneratedPtrAdd.bits] <;> bv_decide

/-- The shared reference's additive little-endian fold equals the generated
byte-ladder load, at every legal CMOV width and every address/memory value. -/
theorem memory_value_refines (width : Reference.X86.CmovWidth)
    (m : Reference.Memory) (address : Reference.Word) :
    GeneratedX86MemAccess.load
      (fun i => m.value (address + BitVec.ofNat 64 i)) (handlerWidth width) =
      Reference.wordAt m address width.bytes := by
  cases width <;>
    simp [handlerWidth, Reference.X86.CmovWidth.bytes,
      GeneratedX86MemAccess.load, GeneratedX86MemAccess.assemble,
      GeneratedX86Width.mask, Reference.wordAt, Reference.bytesAt,
      Reference.littleEndian, List.range_succ] <;> bv_decide

/-- The writeback under study is exactly the generated CMOV/CMOV_MEM
handler, for every decoded condition and memory source, not a replacement
implementation selected only by the reference. -/
theorem generated_step_writeback (width : Reference.X86.CmovWidth)
    (state : X86CmovState) (op : GeneratedX86Cmov.X86CmovOp)
    (src : X86CmovSrc) (mem : X86CmovMem) (aux : BitVec 32)
    (flags : X86Flags) (memWidth : X86Width) (ptrValue : BitVec 64) :
    let effect := generatedX86CmovStep state op src mem aux flags
      (handlerWidth width) memWidth ptrValue
    effect.dst = handlerValue width effect.cond state.dst ⟨effect.value, src.tag⟩ := by
  cases width <;>
    simp only [generatedX86CmovStep, handlerValue, handlerWidth,
      GeneratedX86Cmov.writeBack, x86WidthIs64, reduceCtorEq, ↓reduceIte]

def handlerFlags (flags : Reference.Word) : X86Flags :=
  ⟨flags.getLsbD 0, flags.getLsbD 6, flags.getLsbD 7, flags.getLsbD 11⟩

def nativeCondition : X86Cond → Fin 16
  | .o => 0 | .no => 1 | .b => 2 | .ae => 3
  | .e => 4 | .ne => 5 | .be => 6 | .a => 7
  | .s => 8 | .ns => 9 | .l => 12 | .ge => 13 | .le => 14 | .g => 15

/-- Architectural RFLAGS projection and condition interpretation agree for
every existing typed condition, with no assumption on any flag bit. -/
theorem condition_refines (flags : Reference.Word) (cc : X86Cond) :
    generatedX86Cond (handlerFlags flags) cc =
      Reference.X86.condition flags (nativeCondition cc) := by
  cases cc <;> rfl

/-- Whole-state lift of the handler's writeback, with the common architectural
memory read determining both source value and effects. The caller supplies the
already-decoded condition; the condition decoder is related separately. -/
def handlerStep (width : Reference.X86.CmovWidth) (cc : X86Cond) (dst : Reference.X86.Register)
    (source : Reference.X86.Source) (nextPc : Reference.Word) (s : Reference.X86.State)
    (dstTag sourceTag : Tag) : Transition Reference.X86.State :=
  match Reference.X86.readSource s source width.bytes with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (value, events) =>
      let result := handlerValue width (generatedX86Cond (handlerFlags s.rflags) cc)
        ⟨s.gpr dst, dstTag⟩ ⟨value, sourceTag⟩
      ⟨{ s with gpr := (fun r => if r = dst then result.bits else s.gpr r), pc := nextPc }, events, none⟩

/-- The complete state and ordered effects agree, including PC, all untouched
registers, RFLAGS, XMM0 and memory. A source fault preserves the entire state. -/
theorem step_refines (width : Reference.X86.CmovWidth) (cc : X86Cond) (dst : Reference.X86.Register)
    (source : Reference.X86.Source) (nextPc : Reference.Word) (s : Reference.X86.State)
    (dstTag sourceTag : Tag) :
    handlerStep width cc dst source nextPc s dstTag sourceTag =
      Reference.X86.step (.cmov width (nativeCondition cc) dst source nextPc) s := by
  cases h : Reference.X86.readSource s source width.bytes with
  | error fault => simp only [handlerStep, Reference.X86.step, h]
  | ok pair =>
      rcases pair with ⟨value, events⟩
      simp only [handlerStep, Reference.X86.step, h, value_refines, condition_refines]

/-- Missing read permission is observable for every condition, including false.
No initialized-memory premise is introduced: native uninitialized bytes retain
arbitrary input values and their initialization bit in the access event. -/
theorem memory_fault_is_unconditional (width : Reference.X86.CmovWidth)
    (cc : Fin 16) (dst : Reference.X86.Register) (address nextPc : Reference.Word) (s : Reference.X86.State)
    (h : permitted s.memory.readable address width.bytes = false) :
    Reference.X86.step (.cmov width cc dst (.memory address) nextPc) s =
      ⟨s, [.fault (.read address width.bytes)], some (.read address width.bytes)⟩ := by
  simp [Reference.X86.step, Reference.X86.readSource, readMemory, h, Except.map]

/-- This is the hardware counterexample missed by the old false-condition
contract: EAX retains its low half, but RAX's old high half is always cleared. -/
theorem false_w32_high_half_cleared :
    Reference.X86.cmovValue .w32 false 0xdeadbeef12345678 0x9999999999999999 =
      0x12345678 := by decide

end KProgFormal.Refinement.X86Cmov
