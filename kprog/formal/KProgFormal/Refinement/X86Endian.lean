import KProgFormal.Refinement.X86Bzhi
import KProgFormal.X86Bswap

namespace KProgFormal.Refinement.X86Endian

open Reference
open Reference.X86 (CmovWidth BzhiWidth Register)
open X86Cmov (handlerWidth)

theorem reversal_refines (width : CmovWidth) (value : Reference.Word) :
    GeneratedX86Bswap.value value (handlerWidth width) =
      Reference.X86.reverseBytes value width.bytes := by
  rw [x86_bswap_refines]
  cases width <;> rfl

theorem write_refines (width : CmovWidth) (old : X86RegValue) (value : Reference.Word) :
    (generatedX86RegWrite old value (handlerWidth width)).bits = Reference.X86.writeValue width old.bits value := by
  cases width <;>
    simp only [generatedX86RegWrite, handlerWidth, GeneratedX86RegWrite.write,
      GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits,
      GeneratedX86RegWrite.byteShift, Reference.X86.writeValue, Reference.Word] <;> bv_decide

theorem store_byte_refines (width : CmovWidth) (value : Reference.Word) (i : Nat) (h : i < width.bytes) :
    GeneratedX86MemAccess.store value (handlerWidth width) i = (value >>> (8 * i)).setWidth 8 := by
  have hi : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 := by
    cases width <;> simp only [Reference.X86.CmovWidth.bytes] at h <;> omega
  rcases hi with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;>
    cases width <;> simp only [Reference.X86.CmovWidth.bytes] at h <;> try omega
  all_goals
    simp only [GeneratedX86MemAccess.store, GeneratedX86MemAccess.storeByte,
      handlerWidth, GeneratedX86Width.mask, Reference.Word] <;> bv_decide

def store (width : CmovWidth) (m : Memory) (address value : Reference.Word) : Memory :=
  { m with
    value := fun a => if (a - address).toNat < width.bytes then
      GeneratedX86MemAccess.store value (handlerWidth width) (a - address).toNat else m.value a
    initialized := fun a => if (a - address).toNat < width.bytes then true else m.initialized a }

theorem store_refines (width : CmovWidth) (m : Memory) (address value : Reference.Word) :
    store width m address value = storeMemory m address value width.bytes := by
  unfold store storeMemory
  congr 1
  funext a
  dsimp only
  split <;> rename_i h
  · exact store_byte_refines width value _ h
  · rfl

def swapStep (width : BzhiWidth) (dst : Register) (nextPc : Reference.Word) (s : Reference.X86.State)
    (tag : Tag) : Transition Reference.X86.State :=
  let value := GeneratedX86Bswap.value (s.gpr dst) (X86Bzhi.handlerWidth width)
  let written := generatedX86RegWrite ⟨s.gpr dst, tag⟩ value (X86Bzhi.handlerWidth width)
  ⟨{ s with gpr := fun r => if r = dst then written.bits else s.gpr r, pc := nextPc }, [], none⟩

def loadStep (width : CmovWidth) (dst : Register) (address nextPc : Reference.Word) (s : Reference.X86.State)
    (tag : Tag) : Transition Reference.X86.State :=
  match X86Bt.readOperand width (.memory address) s with
  | .error fault => ⟨s, [.fault fault], some fault⟩
  | .ok (source, events) =>
      let value := GeneratedX86Bswap.value source (handlerWidth width)
      let written := generatedX86RegWrite ⟨s.gpr dst, tag⟩ value (handlerWidth width)
      ⟨{ s with gpr := fun r => if r = dst then written.bits else s.gpr r, pc := nextPc }, events, none⟩

def storeStep (width : CmovWidth) (src : Register) (address nextPc : Reference.Word) (s : Reference.X86.State) :
    Transition Reference.X86.State :=
  let value := GeneratedX86Bswap.value (s.gpr src) (handlerWidth width)
  if permitted s.memory.writable address width.bytes then
    ⟨{ s with memory := store width s.memory address value, pc := nextPc },
      [.memory .write address (valueBytes value width.bytes) true], none⟩
  else ⟨s, [.fault (.write address width.bytes)], some (.write address width.bytes)⟩

theorem swap_value_refines (width : BzhiWidth) (old : X86RegValue) :
    (generatedX86RegWrite old
      (GeneratedX86Bswap.value old.bits (X86Bzhi.handlerWidth width))
      (X86Bzhi.handlerWidth width)).bits = Reference.X86.reverseBytes old.bits width.bytes := by
  cases width <;>
    simp only [generatedX86RegWrite, X86Bzhi.handlerWidth, GeneratedX86RegWrite.write,
      GeneratedX86RegWrite.writeAt, GeneratedX86RegWrite.bitsAt, GeneratedX86RegWrite.bits,
      GeneratedX86RegWrite.byteShift, GeneratedX86Bswap.value,
      Reference.X86.reverseBytes, Reference.X86.BzhiWidth.bytes, valueBytes, littleEndian,
      Reference.Word, List.range_succ, List.range_zero, List.map_append,
      List.map_cons, List.map_nil, List.reverse_append, List.reverse_cons, List.reverse_nil,
      List.nil_append, List.cons_append, List.append_nil] <;> bv_decide

theorem swap_step_refines (width : BzhiWidth) (dst : Register) (nextPc : Reference.Word) (s : Reference.X86.State)
    (tag : Tag) : swapStep width dst nextPc s tag = Reference.X86.step (.byteSwap width dst nextPc) s := by
  unfold swapStep Reference.X86.step Reference.X86.swapStep
  dsimp only
  rw [swap_value_refines width ⟨s.gpr dst, tag⟩]

theorem load_step_refines (width : CmovWidth) (dst : Register) (address nextPc : Reference.Word)
    (s : Reference.X86.State) (tag : Tag) :
    loadStep width dst address nextPc s tag = Reference.X86.step (.movbeLoad width dst address nextPc) s := by
  simp only [loadStep, Reference.X86.step, Reference.X86.movbeLoadStep, X86Bt.read_refines, write_refines, reversal_refines]
  rfl

theorem store_step_refines (width : CmovWidth) (src : Register) (address nextPc : Reference.Word)
    (s : Reference.X86.State) :
    storeStep width src address nextPc s = Reference.X86.step (.movbeStore width src address nextPc) s := by
  simp only [storeStep, Reference.X86.step, Reference.X86.movbeStoreStep, reversal_refines, writeMemory, store_refines]
  split <;> rename_i h <;> simp only [h, ↓reduceIte]

theorem swap_handler_refines (width : BzhiWidth) (dst : Register) (nextPc : Reference.Word)
    (s : Reference.X86.State) (tag : Tag) :
    Reference.X86.Step (.byteSwap width dst nextPc) s (swapStep width dst nextPc s tag) := by
  rw [swap_step_refines]
  exact ⟨rfl, rfl, rfl⟩

theorem load_handler_refines (width : CmovWidth) (dst : Register) (address nextPc : Reference.Word)
    (s : Reference.X86.State) (tag : Tag) :
    Reference.X86.Step (.movbeLoad width dst address nextPc) s (loadStep width dst address nextPc s tag) := by
  rw [load_step_refines]
  exact ⟨rfl, rfl, rfl⟩

theorem store_handler_refines (width : CmovWidth) (src : Register) (address nextPc : Reference.Word)
    (s : Reference.X86.State) :
    Reference.X86.Step (.movbeStore width src address nextPc) s (storeStep width src address nextPc s) := by
  rw [store_step_refines]
  exact ⟨rfl, rfl, rfl⟩

end KProgFormal.Refinement.X86Endian
