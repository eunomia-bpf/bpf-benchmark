import KProgFormal.ClightRefinement.Arm64MemsetIterationStep
import KProgFormal.ClightRefinement.Arm64MemsetIterationStorage

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetIterationAdvance

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

def continuation (k : CC.Cont) : CC.Cont :=
  Arm64MemsetTagRead.continuation (Arm64MemsetLoop.writeCont k)

/-- Exit both actual do/while wrappers around the byte write. -/
theorem wrappers (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4
      (.State handler .Sskip (continuation k) e le m)
      (.State handler .Sskip (Arm64MemsetLoop.writeCont k) e le m) := by
  apply internalRun_of_steps
  · simp [InternalPath,InternalState,steps,CC.doStep,continuation,
      Arm64MemsetTagRead.continuation,Arm64MemsetStackSetup.continuation]
  · simp only [steps,CC.doStep,continuation,Arm64MemsetTagRead.continuation,
      Arm64MemsetStackSetup.continuation,CC.E0,CC.Eapp,List.nil_append]

/-- Both real wrapper exits followed by the original unsigned counter
increment and loop backedge take seven source transitions on the same heap. -/
theorem advance (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : BitVec 64)
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong i)) :
    InternalRun world 7 (.State handler .Sskip (continuation k) e le m)
      (.State handler Arm64MemsetLoop.loop k e
        (le.set Arm64Program.___a64_lib_i (.Vlong (i + (1#64)))) m) := by
  exact (wrappers e le m k).trans (Arm64MemsetLoop.advance e le m k i hi)

def temps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (byte : BitVec 8) (sp : CC.Block) : CC.TempEnv :=
  Arm64MemsetStackBaseBackedge.temps (Arm64MemsetStoreExecution.temps view le i byte) sp

/-- Inspect the actual complete store/post-store temporary setters; the
outer loop counter and parameters retain their original source values. -/
theorem observations {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (byte : BitVec 8) (sp : CC.Block) :
    (temps view le i byte sp).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps view le i byte sp).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (temps view le i byte sp).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps view le i byte sp).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  have writeInputs := Arm64MemsetStackWrite.temps_inputs (Arm64MemsetStoreRoute.temps le i byte)
    (Arm64MemsetStoreExecution.index i) view.tags.block view.stack.block 0 byte
  have routeInputs := Arm64MemsetStoreRoute.temps_inputs le i byte
  have writeLoop := Arm64MemsetStackWrite.temps_loop (Arm64MemsetStoreRoute.temps le i byte)
    (Arm64MemsetStoreExecution.index i) view.tags.block view.stack.block 0 byte
  have routeLoop := Arm64MemsetStoreRoute.temps_loop le i byte
  simp +decide only [temps,Arm64MemsetStackBaseBackedge.temps,CC.PTree.gso]
  exact ⟨writeInputs.1.trans routeInputs.1,writeLoop.1.trans routeLoop.1,
    writeLoop.2.1.trans routeLoop.2.1,writeLoop.2.2.trans routeLoop.2.2⟩

/-- The next real loop head has the incremented counter and the original
entry, length and byte observations. -/
theorem next_observations {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (byte : BitVec 8) (sp : CC.Block) :
    let next := (temps view le i byte sp).set Arm64Program.___a64_lib_i
      (.Vlong (BitVec.ofNat 64 i.val + (1#64)))
    next.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 i.val + (1#64))) ∧
    next.get Arm64Program._entry = le.get Arm64Program._entry ∧
    next.get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    next.get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  dsimp only
  simp +decide only [CC.PTree.gss,CC.PTree.gso]
  have kept := observations view le i byte sp
  exact ⟨trivial,kept.1,kept.2.2.1,kept.2.2.2⟩

/-- Complete both actual stores, SP=-32 control, both enclosing wrapper
exits and the original counter increment. The next loop head uses the SAME
final heap with all previous-byte, tag, permission and storage observations. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (spAtBase : storage.spValue = (-32#64))
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ tagged after,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemsetLossSetup.store
          (Arm64MemsetLossSetup.continuation (continuation k)) e le m) CC.E0
        (.State handler Arm64MemsetLoop.loop k e
          ((temps view le i byte storage.sp.block).set Arm64Program.___a64_lib_i
            (.Vlong (BitVec.ofNat 64 i.val + (1#64)))) after) ∧
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
      (∀ j : Fin 16, j ≠ i →
        CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int) =
          CC.Mem.load .Mint8unsigned m view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int)) ∧
      ∃ current : Arm64ProducerRegisterStorage.Storage initial after entry,
        current.spValue = (-32#64) := by
  obtain ⟨tagged,after,run,tagStore,byteStore,byteRead,frame,access,next,outside,newView,
      currentResources,currentTags,pointer,spRead,otherBytes⟩ :=
    Arm64MemsetIterationStep.execute view resources storage spAtBase e le (continuation k) i byte
      hentry hoff hwidth hvalue tagBytes
  have counter := (observations view le i byte storage.sp.block).2.1.trans hi
  have back := advance e (temps view le i byte storage.sp.block) after k (BitVec.ofNat 64 i.val) counter
  let current := Arm64MemsetIterationStorage.storage view i byte tagStore byteStore storage
  refine ⟨tagged,after,?_,tagStore,byteStore,byteRead,frame,access,next,outside,newView,
    currentResources,currentTags,pointer,spRead,otherBytes,current,?_⟩
  · simpa only [temps,CC.E0,CC.Eapp,List.nil_append] using star_trans run back.sound
  · exact spAtBase

end KProgFormal.ClightRefinement.Arm64MemsetIterationAdvance
