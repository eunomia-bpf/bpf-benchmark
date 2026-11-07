import KProgFormal.Refinement.X86Cmov
import KProgFormal.X86LeaHandler
namespace KProgFormal.Refinement.X86Lea
open Reference
open Reference.X86 (CmovWidth)

/-- Inputs are materialized native address bits. Stack-relative simulator
payloads require the existing entry/stack-address relation before this core. -/
def address (base displacement : Reference.Word) (hasIndex : Bool)
    (scale : BitVec 2) (index : Reference.Word) : Reference.Word :=
  base + (if hasIndex then displacement + (index <<< scale.setWidth 64) else displacement)

theorem scale_refines (scale : BitVec 2) (index : Reference.Word) :
    index <<< scale.setWidth 64 = index * BitVec.ofNat 64 (2 ^ scale.toNat) := by
  have hs : scale = 0 ∨ scale = 1 ∨ scale = 2 ∨ scale = 3 := by bv_decide
  rcases hs with hs | hs | hs | hs
  · subst scale; change index <<< (0 : Nat) = index * 1; bv_decide
  · subst scale; change index <<< (1 : Nat) = index * 2; bv_decide
  · subst scale; change index <<< (2 : Nat) = index * 4; bv_decide
  · subst scale; change index <<< (3 : Nat) = index * 8; bv_decide

def value (width : CmovWidth) (old base displacement : Reference.Word)
    (hasIndex : Bool) (scale : BitVec 2) (index : Reference.Word) : Reference.Word :=
  (generatedX86LeaStep ⟨⟨old, .scalar⟩⟩ ⟨base, .scalar, false, false⟩
    displacement false (X86Cmov.handlerWidth width) hasIndex (scale.setWidth 64) index 0).dst.bits

theorem value_refines (width : CmovWidth) (old base displacement : Reference.Word)
    (hasIndex : Bool) (scale : BitVec 2) (index : Reference.Word) :
    value width old base displacement hasIndex scale index =
      Reference.X86.writeValue width old (address base displacement hasIndex scale index) := by
  cases width <;> cases hasIndex <;>
    simp [value, address, generatedX86LeaStep, generatedX86LeaPointerWrite,
      X86Cmov.handlerWidth, GeneratedX86MemOffset.value, GeneratedPtrAdd.stackReference,
      GeneratedPtrAdd.bits, GeneratedPtrAdd.tag, generatedX86RegWrite,
      GeneratedX86RegWrite.write, GeneratedX86RegWrite.writeAt,
      GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits, GeneratedX86RegWrite.byteShift,
      Reference.X86.writeValue] <;> bv_decide

def handlerStep (width : CmovWidth) (dst : Reference.X86.Register)
    (base displacement : Reference.Word) (hasIndex : Bool) (scale : BitVec 2)
    (index nextPc : Reference.Word) (s : Reference.X86.State) : Transition Reference.X86.State :=
  let result := value width (s.gpr dst) base displacement hasIndex scale index
  ⟨{ s with gpr := (fun r => if r = dst then result else s.gpr r), pc := nextPc }, [], none⟩

theorem step_refines (width : CmovWidth) (dst : Reference.X86.Register)
    (base displacement : Reference.Word) (hasIndex : Bool) (scale : BitVec 2)
    (index nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep width dst base displacement hasIndex scale index nextPc s =
      Reference.X86.step (.lea width dst (address base displacement hasIndex scale index) nextPc) s := by
  simp only [handlerStep, value_refines, Reference.X86.step]

theorem handler_refines (width : CmovWidth) (dst : Reference.X86.Register)
    (base displacement : Reference.Word) (hasIndex : Bool) (scale : BitVec 2)
    (index nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.Step (.lea width dst (address base displacement hasIndex scale index) nextPc) s
      (handlerStep width dst base displacement hasIndex scale index nextPc s) := by
  rw [step_refines]
  exact ⟨rfl, rfl, rfl⟩
/-- Address-size32 followed by a native 64-bit write is the existing
32-bit LEA writeback. This normalization scalarizes and zero-extends the
address; it does not add a guard or assume high input bits are zero. -/
theorem address32_step_refines (dst : Reference.X86.Register)
    (base displacement : Reference.Word) (hasIndex : Bool) (scale : BitVec 2)
    (index nextPc : Reference.Word) (s : Reference.X86.State) :
    handlerStep .w32 dst base displacement hasIndex scale index nextPc s =
      Reference.X86.step (.lea .w64 dst
        (((address base displacement hasIndex scale index).setWidth 32).setWidth 64)
        nextPc) s := by
  simp [handlerStep, value_refines, Reference.X86.step, Reference.X86.writeValue]

/-- Unit-scale index-only addressing has the same native address as the
corresponding base-only form, for every wrapping64-bit displacement/index. -/
theorem unit_index_to_base (index displacement : Reference.Word) :
    address 0 displacement true 0 index = address index displacement false 0 0 := by
  simp only [address, ↓reduceIte, Reference.Word]
  bv_decide

/-- The producer normalization preserves the complete canonical LEA step,
including every other register, flags, PC, memory and ordered effects/faults. -/
theorem unit_index_step_refines (width : CmovWidth) (dst : Reference.X86.Register)
    (index displacement nextPc : Reference.Word) (s : Reference.X86.State) :
    Reference.X86.step (.lea width dst (address 0 displacement true 0 index) nextPc) s =
      Reference.X86.step (.lea width dst (address index displacement false 0 0) nextPc) s := by
  rw [unit_index_to_base]

end KProgFormal.Refinement.X86Lea
