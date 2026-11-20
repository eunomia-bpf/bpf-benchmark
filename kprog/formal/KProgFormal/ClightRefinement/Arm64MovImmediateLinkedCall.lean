import KProgFormal.ClightRefinement.Arm64MovImmediateLinkedRead
import KProgFormal.ClightRefinement.Arm64CacheLocalFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.LinkedCall

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64RegisterStorageFrontier

/-- The complete actual first-operand generic MOV_IMM call, including its
allocation, real cold-SP provider trace, both cache/GPR stores and actual free.
The invocation's origin outcome/frame stays explicit. The original fixture
callsite and fetched native instruction sequence are separate obligations. -/
theorem entry_call {initial before supplied : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (access : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block before.access = CC.PMap.get block (allocation initial).2.access)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cold : Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (mark : BitVec 32) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] (Arm64Nop.allocation world before).2 trace (.Vlong origins.stack) supplied)
    (outcome : Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world before).2 supplied)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 = some (.Vlong (mark.setWidth 64)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Nop.handler) (Dispatch.arguments (LinkedRead.entry_operands entry.block mark) false)
          k before) trace (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false) ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = (Arm64Nop.allocation world before).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack := by
  let allocated := (Arm64Nop.allocation world before).2
  let env := (Arm64Nop.allocation world before).1
  have halloc := Arm64MovImmediate.allocated_bound world before
  obtain ⟨growth, allocationFrame⟩ := FrameBelow.allocVariables halloc before.nextblock (Nat.le_refl _)
  let carried := storage.frame allocationFrame
  have allocatedPointers : ∀ i, CC.Mem.load CC.Mptr allocated entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0) := fun i =>
    (allocationFrame.load CC.Mptr entry.block _ (load_live CC.Mptr before entry.block _ _ (pointers i))).trans (pointers i)
  have allocatedAccess : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block allocated.access = CC.PMap.get block (allocation initial).2.access := by
    intro block owned
    exact (allocationFrame block (Nat.lt_of_lt_of_le owned bound)).2.trans (access block owned)
  have allocatedBound := Nat.le_trans bound growth
  have priorRep := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) s).mpr represented
  have allocatedRep := (represents_iff carried before.nextblock bound addresses origins s).mp priorRep
  have priorCold := (Arm64EntryMemory.borrowed_frame allocationFrame .Mint8unsigned
    (.Vptr entry.block 0) Arm64Program._sp_valid).trans cold
  have cacheFrontier := borrowed_eq allocated before.nextblock entry.block
    (Nat.lt_of_lt_of_le entry.owned bound) 6 (header 6).block 0
    (Nat.lt_of_lt_of_le (header 6).owned bound) .Mint8unsigned (allocatedPointers 6)
  have allocatedCold : Arm64EntryMemory.borrowed allocated.nextblock .Mint8unsigned allocated (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0) := cacheFrontier.symm.trans priorCold
  have inputs := LinkedRead.entry_temp_data entry.block mark
  have names := Arm64MovImmediate.unshadowed_bound world before
  obtain ⟨locals, middle, cached, written, cachedStorage, body, storeBase, storeValid, warm,
    cacheFrame, cachedRep, result, registers, caller, permissions, next⟩ :=
    LinkedRead.scalar_write carried header allocatedPointers allocatedAccess allocatedBound allocatedCold
      addresses origins s allocatedRep trace provider outcome env (LinkedRead.entry_temps entry.block mark)
      1 (mark.setWidth 64) false names.1 names.2 inputs.1 inputs.2.1 inputs.2.2.1
      inputs.2.2.2.1 inputs.2.2.2.2.1 inputs.2.2.2.2.2
  have owned : ∀ id value, env.get id = some value →
      CC.Mem.rangePerm written value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true := by
    intro id value binding
    have live := ((allocated_local_storage halloc).1 id value binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := allocated)
      (fun ofs => by simp only [CC.Mem.perm, permissions, allocated])).trans live
  obtain ⟨after, freed, freeFrame, contents, freeNext, released⟩ := deallocate_live_locals halloc owned
  have nativeAtWritten : Arm64Registers.Represents addresses origins (fun r => r.val)
      written.nextblock written (.Vptr entry.block 0) (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false) := by
    simpa only [next] using registers
  have nativeAtCaller := (represents_iff result.storage before.nextblock bound addresses origins
    (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)).mpr nativeAtWritten
  have finalRegisters := (Arm64Registers.frame freeFrame (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false)).mpr nativeAtCaller
  have canonicalGrowth := (FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1
  have initialBound := Nat.le_trans canonicalGrowth bound
  have allocateCaller : FrameBelow initial.nextblock before allocated := fun block owned =>
    allocationFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have freeCaller : FrameBelow initial.nextblock written after := fun block owned =>
    freeFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have leave : InternalRun world 1
      (.State Arm64Nop.handler .Sskip .Kstop env
        (Suffix.writerTempsRead (LinkedRead.entry_temps entry.block mark) (Reference.AArch64.sp s) (mark.setWidth 64)) written)
      (.Returnstate .Vundef .Kstop after) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  have dispatch := LinkedRead.entry_dispatch before entry.block mark
  let finalStorage := storage_frame result.storage before.nextblock bound freeFrame
  have finalWord : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 =
      some (.Vlong (mark.setWidth 64)) := by
    change CC.Mem.load .Mint64 after ((cachedStorage.tables false).cellBlock 1) 0 = _
    have kept := freeFrame.load .Mint64 ((cachedStorage.tables false).cellBlock 1) 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((cachedStorage.tables false).cellBinding 1)) bound)
    simpa only [Arm64RegisterWrite.written, Bool.false_eq_true, ite_false] using kept.trans result.word
  have finalTag : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) := by
    change CC.Mem.load .Mint8unsigned after ((cachedStorage.tables true).cellBlock 1) 0 = _
    exact (freeFrame.load .Mint8unsigned ((cachedStorage.tables true).cellBlock 1) 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((cachedStorage.tables true).cellBinding 1)) bound)).trans result.tag
  have cachedPointers : ∀ j, CC.Mem.load CC.Mptr cached entry.block (8 * (j.val : Int)) =
      some (.Vptr (header j).block 0) := by
    intro j
    exact (cacheFrame.local_load _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
      CC.Mptr _).trans (allocatedPointers j)
  have writerKept : Arm64CacheLocalFrame.Kept initial cached written 1 := result.local_load
  have freeKept := Arm64CacheLocalFrame.of_frame before.nextblock (1 : Fin 31) bound freeFrame
  have kept := writerKept.trans freeKept
  have cachedWarm : Arm64RegisterReads.WarmEntryCache false cached.nextblock cached (.Vptr entry.block 0) origins.stack := by
    simpa only [cacheFrame.nextblock] using warm
  have priorWarm := (Arm64CacheLocalFrame.warm_iff before.nextblock header bound cachedPointers false origins.stack).mpr cachedWarm
  have finalWarm := kept.warm before.nextblock header bound cachedPointers false origins.stack priorWarm
  have finalPointers := kept.pointers header cachedPointers
  refine ⟨written, after, finalStorage, finalWord, finalTag, ?_, finalRegisters,
    (allocateCaller.trans caller).trans freeCaller, freed, freeFrame, contents, freeNext.trans next, released, finalPointers, finalWarm⟩
  have run : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64Nop.handler) (Dispatch.arguments (LinkedRead.entry_operands entry.block mark) false)
        .Kstop before) trace (.Returnstate .Vundef .Kstop after) := by
    simpa only [CC.Eapp, CC.E0, List.nil_append, List.append_nil] using
      star_trans (star_trans dispatch.1.sound body) leave.sound
  simpa only [Continuation.state, Continuation.extend] using Continuation.star_extend k valid run

end KProgFormal.ClightRefinement.Arm64MovImmediate.LinkedCall
