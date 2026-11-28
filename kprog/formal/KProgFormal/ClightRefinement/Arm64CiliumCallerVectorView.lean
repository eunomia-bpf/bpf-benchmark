import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopEntry
import KProgFormal.ClightRefinement.Arm64ProducerVectorView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorView
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerVectorSource (Storage)
open Arm64CiliumCallerVectorPointerLoopSource (headerOffset)
open Arm64CiliumCallerVectorPointerLoopValues (vectorPointerOffset)

def inputIndex (high : Bool) (i : Fin 32) : Fin 64 :=
  ⟨2*i.val+(if high then 1 else 0),
    by have bound := i.isLt;cases high <;> simp_all <;> omega⟩

theorem input_offsets : ∀ (high : Bool) (i : Fin 32),
    8*((inputIndex high i).val : Int) = 16*(i.val : Int)+(if high then 8 else 0) := by
  decide +kernel

theorem data_readbacks {m memory : CC.Mem} (vectors : Storage m) (inputs : Fin 64 → BitVec 64)
    (data : Arm64CiliumCallerVectorSequence.Initialized vectors memory inputs 64) :
    ∀ (high : Bool) (i : Fin 32),
      CC.Mem.load .Mint64 memory vectors.block (16*(i.val : Int)+(if high then 8 else 0)) =
        some (.Vlong (inputs (inputIndex high i))) := by
  intro high i
  have read := data (inputIndex high i) (inputIndex high i).isLt
  rw [input_offsets high i] at read
  exact read

/-- Only the allocation-independent mature reader theorem is reused.
Both actual pointer slots and pointee loads come from SAME caller resources. -/
theorem vector_readbacks {m memory : CC.Mem} (header : Header m) (vectors : Storage m)
    (inputs : Fin 64 → BitVec 64)
    (pointers : Arm64CiliumCallerVectorPointerLoopSequence.Initialized header vectors memory 32)
    (data : Arm64CiliumCallerVectorSequence.Initialized vectors memory inputs 64) :
    ∀ i : Fin 32,Arm64EntryMemory.vector memory.nextblock memory (.Vptr header.block 0) i =
      some (.Vlong (inputs (inputIndex false i)),.Vlong (inputs (inputIndex true i))) := by
  intro i
  apply Arm64ProducerVectorView.vector_readback memory header.block vectors.block vectors.block i
    (vectorPointerOffset false i) (vectorPointerOffset true i)
    (.Vlong (inputs (inputIndex false i))) (.Vlong (inputs (inputIndex true i)))
  · simpa [CC.Mptr,CC.Archi.ptr64,headerOffset] using pointers false i i.isLt
  · simpa [CC.Mptr,CC.Archi.ptr64,headerOffset] using pointers true i i.isLt
  · simpa only [(Arm64CiliumCallerVectorPointerLoopValues.offsets false i).2] using
      data_readbacks vectors inputs data false i
  · simpa only [(Arm64CiliumCallerVectorPointerLoopValues.offsets true i).2] using
      data_readbacks vectors inputs data true i

/-- Native input correspondence remains explicit; no whole-state refinement is assumed. -/
theorem native_vectors {m memory : CC.Mem} (header : Header m) (vectors : Storage m)
    (inputs : Fin 64 → BitVec 64)
    (pointers : Arm64CiliumCallerVectorPointerLoopSequence.Initialized header vectors memory 32)
    (data : Arm64CiliumCallerVectorSequence.Initialized vectors memory inputs 64)
    (s : Reference.AArch64.State)
    (matching : ∀ (high : Bool) (i : Fin 32),
      inputs (inputIndex high i) = Arm64ProducerVectorView.vectorHalf s high i) :
    ∀ i : Fin 32,Arm64EntryMemory.vector memory.nextblock memory (.Vptr header.block 0) i =
      some (.Vlong (Arm64ProducerVectorView.vectorHalf s false i),
        .Vlong (Arm64ProducerVectorView.vectorHalf s true i)) := by
  intro i
  rw [vector_readbacks header vectors inputs pointers data i,matching false i,matching true i]

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorView
