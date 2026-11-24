import KProgFormal.ClightRefinement.Arm64UaddlvBody
import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.Call

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage Arm64RegisterStorageFrontier
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryUaddlvCall (arguments initialTemps entry_valid)

def allocatedStorage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) : Storage initial (Arm64Nop.allocation world before).2 entry :=
  old.frame (Arm64Nop.entry_frame world before)

private theorem allocated_vectors {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) : (allocatedStorage old).vectors = old.vectors := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem frame_vectors {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (frontier : CC.Block)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after) : (storage_frame old frontier bound frame).vectors = old.vectors := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem written_vectors {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (low high : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block low high) :
    (VectorStorage.storage old low high effect).vectors = old.vectors := rfl

/-- The original generic call, all three real vector stores, actual release and
return, and complete caller storage/native correspondence. -/
structure Result {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (k : CC.Cont) (count : Nat) (written after : CC.Mem)
    (finalStorage : Storage initial after entry) : Prop where
  effect : VectorMemory.Effect (Arm64Nop.allocation world before).2 written old.vectors.block
    (((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0).setWidth 64)).setWidth 64))
    (((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0 >>> 64).setWidth 64)).setWidth 64))
  low : CC.Mem.load .Mint64 after finalStorage.vectors.block 0 =
    some (.Vlong (((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0).setWidth 64)).setWidth 64) + ((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0 >>> 64).setWidth 64)).setWidth 64)))
  high : CC.Mem.load .Mint64 after finalStorage.vectors.block 8 =
    some (.Vlong (0#64))
  writable : Arm64VectorWritable.Writable finalStorage.vectors after
  run : InternalRun world count (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
    (.Returnstate .Vundef k after)
  registers : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after
    (.Vptr entry.block 0) (Reference.AArch64.step native).state
  nativeStep : Reference.AArch64.step native = ⟨Native.after native,[],none⟩
  free : CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after
  freeFrame : FrameBelow before.nextblock written after
  contents : after.contents = written.contents
  nextblock : after.nextblock = written.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
    ∀ offset, row.2.1 ≤ offset → offset < row.2.2 →
    ∀ kind permission, CC.Mem.perm after row.1 offset kind permission = false
  caller : FrameBelow initial.nextblock before after
  locals : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
    id ≠ Arm64Entry.___a64_vectors → ∀ chunk offset,
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset
  bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat

private theorem helper_names :
    Arm64Program._arm64_width_effective ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_reduction ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (outside : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation world before).1.get name = none := by
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound world before) outside

private theorem parameters (b : CC.Block) :
    (initialTemps b).get Arm64Program._entry = some (.Vptr b 0) ∧
    (initialTemps b).get Arm64Program._op = some (.Vint (37#32)) ∧
    (initialTemps b).get Arm64Program._aux = some (.Vint (16#32)) ∧
    (initialTemps b).get Arm64Program._flags = some (Arm64Width.argument (8#8)) := by
  simp +decide only [initialTemps,Arm64Width.argument,CC.PTree.gss,CC.PTree.gso,and_self]

/-- Bind the nine genuine arguments, allocate the original frame, execute
the whole original UADDLV handler and derive its real free/return and caller
correspondence. Original storage supplies all input and write permissions. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (decoded : instruction.decoded = .DPSFP (.Advanced_simd_across_lanes Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ count written after, ∃ finalStorage : Storage initial after entry,
      Result old addresses origins native k count written after finalStorage := by
  have allocationFrame := Arm64Nop.entry_frame world before
  let carried := allocatedStorage old
  have allocatedOld := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) native).mpr represented
  have allocated := (represents_iff carried before.nextblock bound addresses origins native).mp allocatedOld
  have vectorOwned := Nat.lt_of_lt_of_le (local_owned initial _ _ _ old.vectors.binding) bound
  obtain ⟨entryData,opData,auxData,flagsData⟩ := parameters entry.block
  obtain ⟨count,written,finalTemps,body,effect,writePermissions,registers,tempKept,localKept,step⟩ :=
    Body.corresponds carried addresses origins native instruction allocated
      (Arm64Nop.allocation world before).1 (initialTemps entry.block) k
      (unshadowed before _ helper_names.1) (unshadowed before _ helper_names.2)
      entryData opData auxData flagsData decoded noError fetched
  have actualEffect : VectorMemory.Effect (Arm64Nop.allocation world before).2 written old.vectors.block
      (((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0).setWidth 64)).setWidth 64))
      (((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0 >>> 64).setWidth 64)).setWidth 64)) := by
    rw [← allocated_vectors old]
    exact effect
  have owned : ∀ id v, (Arm64Nop.allocation world before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof world.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated_bound world before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation world before).2)
      (fun offset => by simp only [CC.Mem.perm,effect.access])).trans live
  obtain ⟨after,freed,freeFrame,contents,next,released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated_bound world before) owned
  let writtenStorage := VectorStorage.storage carried _ _ effect
  let finalStorage := storage_frame writtenStorage before.nextblock bound freeFrame
  have writtenVectors : writtenStorage.vectors = carried.vectors := written_vectors carried _ _ effect
  have finalVectors : finalStorage.vectors = old.vectors :=
    (frame_vectors writtenStorage before.nextblock bound freeFrame).trans
      (writtenVectors.trans (allocated_vectors old))
  have low : CC.Mem.load .Mint64 after finalStorage.vectors.block 0 =
      some (.Vlong (((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0).setWidth 64)).setWidth 64) + ((DPSFP.simd_unsigned_sum_long 8 ((Reference.AArch64.readVector native 0 >>> 64).setWidth 64)).setWidth 64))) := by
    rw [finalVectors]
    exact (freeFrame.load .Mint64 _ 0 vectorOwned).trans actualEffect.low
  have high : CC.Mem.load .Mint64 after finalStorage.vectors.block 8 =
      some (.Vlong (0#64)) := by
    rw [finalVectors]
    exact (freeFrame.load .Mint64 _ 8 vectorOwned).trans actualEffect.high
  have finalWritable : Arm64VectorWritable.Writable finalStorage.vectors after := by
    rw [finalVectors]
    have currentWritable : Arm64VectorWritable.Writable old.vectors written := by
      rw [← allocated_vectors old]
      exact writePermissions
    exact Arm64VectorWritable.frame old.vectors currentWritable before.nextblock bound freeFrame
  have liveRegisters : Arm64Registers.Represents addresses origins (fun r => r.val)
      written.nextblock written (.Vptr entry.block 0) (Reference.AArch64.step native).state :=
    Eq.mpr (congrArg (fun frontier => Arm64Registers.Represents addresses origins (fun r => r.val)
      frontier written (.Vptr entry.block 0) (Reference.AArch64.step native).state) effect.nextblock) registers
  have oldRegisters := (represents_iff writtenStorage before.nextblock bound addresses origins
    (Reference.AArch64.step native).state).mpr liveRegisters
  have finalRegisters := (Arm64Registers.frame freeFrame (.Vptr entry.block 0)
    (Reference.AArch64.step native).state).mpr oldRegisters
  have initialBound := Nat.le_trans ((FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1) bound
  have callerAlloc : FrameBelow initial.nextblock before (Arm64Nop.allocation world before).2 :=
    fun block owned => allocationFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have callerFree : FrameBelow initial.nextblock written after :=
    fun block owned => freeFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have bodyCaller : FrameBelow initial.nextblock (Arm64Nop.allocation world before).2 written := by
    obtain ⟨first,middle,partialStore,lowStore,highStore⟩ := actualEffect
    exact ((FrameBelow.store old.vectors.fresh partialStore).trans
      (FrameBelow.store old.vectors.fresh lowStore)).trans (FrameBelow.store old.vectors.fresh highStore)
  have kept : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block,ty) →
      id ≠ Arm64Entry.___a64_vectors → ∀ chunk offset,
      CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
    intro id ty block binding different chunk offset
    have oldBlock := Nat.lt_of_lt_of_le (local_owned initial id ty block binding) bound
    exact ((freeFrame.load chunk block offset oldBlock).trans
      (localKept id ty block binding different chunk offset)).trans (allocationFrame.load chunk block offset oldBlock)
  have entered : InternalRun world 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k (Arm64Nop.allocation world before).1
        (initialTemps entry.block) (Arm64Nop.allocation world before).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry.block)) (.refl _)
  have returned : InternalRun world 1
      (.State Arm64Nop.handler .Sskip k (Arm64Nop.allocation world before).1 finalTemps written)
      (.Returnstate .Vundef k after) :=
    .step trivial (.skip_call _ _ _ _ _ _ valid freed) (.refl _)
  have finalNext := next.trans effect.nextblock
  have finalBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat :=
    Eq.mpr (congrArg (fun frontier : CC.Block =>
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat) finalNext)
      (Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
        before.nextblock (Nat.le_refl _)).1)
  exact ⟨_,written,after,finalStorage,⟨actualEffect,low,high,finalWritable,(entered.trans body).trans returned,
    finalRegisters,step,freed,freeFrame,contents,next,released,(callerAlloc.trans bodyCaller).trans callerFree,kept,finalBound⟩⟩

end KProgFormal.ClightRefinement.Arm64Uaddlv.Call
