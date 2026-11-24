import KProgFormal.ClightRefinement.Arm64MovImmediateOrdinaryCall
import KProgFormal.ClightRefinement.Arm64RegisterStorageFrontier
import KProgFormal.ClightRefinement.Arm64CacheLocalFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.OrdinaryCall

open Arm64ProgramEntryAllocation (world)
open Arm64ProducerRegisterStorage Arm64RegisterStorageFrontier

def allocatedStorage {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Storage initial before entry) : Storage initial (Arm64Nop.allocation world before).2 entry :=
  storage.frame (Arm64Nop.entry_frame world before)

/-- Complete actual C return and imported architectural register effect,
including the same allocated storage, every released local and caller frame. -/
structure Result {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 31) (value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (k : CC.Cont) (written after : CC.Mem) : Prop where
  effect : Arm64RegisterWrite.Result (allocatedStorage storage) i value false written
  run : InternalRun world 203
    (.Callstate (.Internal Arm64Nop.handler) (Dispatch.arguments (operands entry.block i value) false) k before)
    (.Returnstate .Vundef k after)
  freed : CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after
  frame : FrameBelow before.nextblock written after
  contents : after.contents = written.contents
  nextblock : after.nextblock = written.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
    ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false
  registers : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s i value false)
  kept : Arm64CacheLocalFrame.Kept initial before after i
  caller : FrameBelow initial.nextblock before after

/-- Derive the full register relation and surviving caller/cache locals from
the same actual C execution and its two stores, including the real final free. -/
theorem corresponds {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (i : Fin 31) (value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, Result storage i value addresses origins s k written after := by
  obtain ⟨written,after,effect,run,freed,frame,contents,next,released⟩ := execute storage i value k valid
  have allocationFrame := Arm64Nop.entry_frame world before
  have priorRep := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) s).mpr represented
  have allocatedRep := (represents_iff (allocatedStorage storage) before.nextblock bound addresses origins s).mp priorRep
  have nativeAtWritten : Arm64Registers.Represents addresses origins (fun r => r.val)
      written.nextblock written (.Vptr entry.block 0) (Arm64RegisterWrite.nativeUpdate s i value false) := by
    simpa only [effect.nextblock] using effect.represents addresses origins s allocatedRep
  have nativeAtCaller := (represents_iff effect.storage before.nextblock bound addresses origins
    (Arm64RegisterWrite.nativeUpdate s i value false)).mpr nativeAtWritten
  have finalRegisters := (Arm64Registers.frame frame (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s i value false)).mpr nativeAtCaller
  have allocateKept := Arm64CacheLocalFrame.of_frame before.nextblock i bound allocationFrame
  have writerKept : Arm64CacheLocalFrame.Kept initial (Arm64Nop.allocation world before).2 written i := effect.local_load
  have freeKept := Arm64CacheLocalFrame.of_frame before.nextblock i bound frame
  have kept := (allocateKept.trans writerKept).trans freeKept
  have canonicalGrowth := (FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1
  have initialBound := Nat.le_trans canonicalGrowth bound
  have allocationCaller : FrameBelow initial.nextblock before (Arm64Nop.allocation world before).2 :=
    fun block old => allocationFrame block (Nat.lt_of_lt_of_le old initialBound)
  have freeCaller : FrameBelow initial.nextblock written after :=
    fun block old => frame block (Nat.lt_of_lt_of_le old initialBound)
  exact ⟨written,after,⟨effect,run,freed,frame,contents,next,released,finalRegisters,kept,
    (allocationCaller.trans effect.caller).trans freeCaller⟩⟩

/-- The same producer storage survives the complete call and actual free. -/
def Result.storage {initial before written after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 31} {value : BitVec 64}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {s : Reference.AArch64.State} {k : CC.Cont}
    (result : Result storage i value addresses origins s k written after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat) :
    Storage initial after entry := storage_frame result.effect.storage before.nextblock bound result.frame

end KProgFormal.ClightRefinement.Arm64MovImmediate.OrdinaryCall
