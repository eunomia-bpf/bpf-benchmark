import KProgFormal.ClightRefinement.Arm64MemsetIterationResources
import KProgFormal.ClightRefinement.Arm64MemsetTagByteTransport

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetIterationStep

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- One complete real byte-store iteration on the actual setup-SP domain
retains all invariants needed by the next source iteration: current resources,
all24 tag bytes, source SP, actual header view and every other stack byte.
The original bias/action/stores/post-store test and loop exits all execute. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (spAtBase : storage.spValue = (-32#64))
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ tagged after,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLossSetup.store (Arm64MemsetLossSetup.continuation k) e le m) CC.E0
        (.State handler .Sskip k e
          (Arm64MemsetStackBaseBackedge.temps (Arm64MemsetStoreExecution.temps view le i byte) storage.sp.block) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged view.stack.block ((Arm64MemsetStoreExecution.index i).val : Int)
        (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index i).val : Int) = some (.Vint (byte.setWidth 32)) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      Nonempty (Arm64MemsetHeaderView.View initial after entry) ∧
      Arm64ProgramEntryResources.Resources initial after entry ∧
      (∀ j : Fin 24, CC.Mem.load .Mint8unsigned after view.tags.block (j.val : Int) = some (.Vint 0)) ∧
      CC.Mem.load CC.Mptr after entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 after storage.sp.block 0 = some (.Vlong (-32#64)) ∧
      ∀ j : Fin 16, j ≠ i →
        CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int) =
          CC.Mem.load .Mint8unsigned m view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int) := by
  obtain ⟨tagged,after,run,tagStore,byteStore,byteRead,tagRead,frame,access,next,outside,newView⟩ :=
    Arm64MemsetStackBaseBackedge.with_stores view resources storage spAtBase e le k i byte
      hentry hoff hwidth hvalue tagBytes
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have tagStack : view.tags.block ≠ view.stack.block :=
    separate _ _ _ _ view.tags.binding view.stack.binding (by decide +kernel)
  have currentResources := Arm64MemsetIterationResources.after_stores view resources i byte tagStore byteStore
  have currentTags := Arm64MemsetTagByteTransport.both_stores tagStore byteStore tagStack tagBytes
  have entryTag : entry.block ≠ view.tags.block := separate _ _ _ _ entry.binding view.tags.binding (by decide +kernel)
  have entryStack : entry.block ≠ view.stack.block := separate _ _ _ _ entry.binding view.stack.binding (by decide +kernel)
  have spTag : storage.sp.block ≠ view.tags.block := separate _ _ _ _ storage.sp.binding view.tags.binding (by decide +kernel)
  have spStack : storage.sp.block ≠ view.stack.block := separate _ _ _ _ storage.sp.binding view.stack.binding (by decide +kernel)
  have pointer := (outside CC.Mptr entry.block 40 entryTag entryStack).trans storage.spPointer
  have spRead : CC.Mem.load .Mint64 after storage.sp.block 0 = some (.Vlong (-32#64)) := by
    rw [outside .Mint64 storage.sp.block 0 spTag spStack,storage.spRead,spAtBase]
  refine ⟨tagged,after,run,tagStore,byteStore,byteRead,frame,access,next,outside,newView,currentResources,currentTags,pointer,spRead,?_⟩
  intro j different
  have offsetDifferent : j.val ≠ i.val := by intro same; exact different (Fin.ext same)
  have disjoint : ((Arm64MemsetStoreExecution.index j).val : Int) + 1 ≤
      ((Arm64MemsetStoreExecution.index i).val : Int) ∨
      ((Arm64MemsetStoreExecution.index i).val : Int) + 1 ≤
        ((Arm64MemsetStoreExecution.index j).val : Int) := by
    dsimp only [Arm64MemsetStoreExecution.index]
    omega
  have byteOther := CC.Mem.load_store_other byteStore .Mint8unsigned view.stack.block
    ((Arm64MemsetStoreExecution.index j).val : Int)
    (Or.inr disjoint)
  have tagOther := CC.Mem.load_store_other tagStore .Mint8unsigned view.stack.block
    ((Arm64MemsetStoreExecution.index j).val : Int) (Or.inl (Ne.symm tagStack))
  exact byteOther.trans tagOther

end KProgFormal.ClightRefinement.Arm64MemsetIterationStep
