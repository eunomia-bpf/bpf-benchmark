import KProgFormal.ClightRefinement.Arm64FmovBodyNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryFmovCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Call

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage Arm64RegisterStorageFrontier
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryFmovCall (arguments initialTemps entry_valid)

def allocatedStorage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) : Storage initial (Arm64Nop.allocation world before).2 entry :=
  old.frame (Arm64Nop.entry_frame world before)

private theorem allocated_vectors {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) : (allocatedStorage old).vectors = old.vectors := by
  run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem allocated_tables {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) : (allocatedStorage old).tables = old.tables := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem frame_vectors {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (frontier : CC.Block)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after) : (storage_frame old frontier bound frame).vectors = old.vectors := by
  run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem written_vectors {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value) :
    (VectorStorage.storage old value effect).vectors = old.vectors := rfl

/-- The true generic call, both actual vector stores and live-local release,
at the original caller frontier. -/
structure Result {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (k : CC.Cont) (count : Nat) (written after : CC.Mem)
    (finalStorage : Storage initial after entry) : Prop where
  effect : VectorMemory.Effect (Arm64Nop.allocation world before).2 written old.vectors.block value
  low : CC.Mem.load .Mint64 after finalStorage.vectors.block 48 = some (.Vlong value)
  high : CC.Mem.load .Mint64 after finalStorage.vectors.block 56 = some (.Vlong 0)
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
    Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_fmov_dest ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (outside : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation world before).1.get name = none := by
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound world before) outside

private theorem parameters (b : CC.Block) :
    (initialTemps b).get Arm64Program._entry = some (.Vptr b 0) ∧
    (initialTemps b).get Arm64Program._src2 = some (.Vlong (3#64)) ∧
    (initialTemps b).get Arm64Program._src = some (.Vlong (7#64)) ∧
    (initialTemps b).get Arm64Program._aux = some (.Vint 0) ∧
    (initialTemps b).get Arm64Program._op = some (.Vint (35#32)) ∧
    (initialTemps b).get Arm64Program._flags = some (Arm64Width.argument (8#8)) := by
  simp +decide only [initialTemps,Arm64Width.argument,CC.PTree.gss,CC.PTree.gso,and_self]

/-- Bind the original nine arguments, allocate the real generic frame,
execute its entire original source/native body and derive actual release,
return, all other producer-local loads and caller register correspondence. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (writable : Arm64VectorWritable.Writable old.vectors before) (oldLow value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (oldVector : CC.Mem.load .Mint64 before old.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock 7) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock 7) 0 = some (.Vint 0))
    (decoded : instruction.decoded = .DPSFP (.Conversion_between_FP_and_Int Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ count written after, ∃ finalStorage : Storage initial after entry,
      Result old value addresses origins native k count written after finalStorage := by
  have allocationFrame := Arm64Nop.entry_frame world before
  let carried := allocatedStorage old
  have allocatedOld := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) native).mpr represented
  have allocated := (represents_iff carried before.nextblock bound addresses origins native).mp allocatedOld
  have vectorOwned := Nat.lt_of_lt_of_le (local_owned initial _ _ _ old.vectors.binding) bound
  have vectorRead : CC.Mem.load .Mint64 (Arm64Nop.allocation world before).2 carried.vectors.block 48 = some (.Vlong oldLow) := by
    rw [allocated_vectors]
    exact (allocationFrame.load .Mint64 _ 48 vectorOwned).trans oldVector
  have scalarRead : CC.Mem.load .Mint64 (Arm64Nop.allocation world before).2 ((carried.tables false).cellBlock 7) 0 = some (.Vlong value) := by
    rw [allocated_tables]
    exact (allocationFrame.load .Mint64 _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((old.tables false).cellBinding 7)) bound)).trans word
  have tagRead : CC.Mem.load .Mint8unsigned (Arm64Nop.allocation world before).2 ((carried.tables true).cellBlock 7) 0 = some (.Vint 0) := by
    rw [allocated_tables]
    exact (allocationFrame.load .Mint8unsigned _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((old.tables true).cellBinding 7)) bound)).trans tag
  have allocatedWritable : Arm64VectorWritable.Writable carried.vectors (Arm64Nop.allocation world before).2 := by
    rw [allocated_vectors]
    exact Arm64VectorWritable.frame old.vectors writable before.nextblock bound allocationFrame
  obtain ⟨entryData,indexData,sourceData,auxData,opData,widthData⟩ := parameters entry.block
  obtain ⟨count,written,finalTemps,effect,writePermissions,body,registers,tempKept,localKept,step⟩ :=
    Body.corresponds carried allocatedWritable oldLow value addresses origins native instruction allocated
      vectorRead scalarRead tagRead (Arm64Nop.allocation world before).1 (initialTemps entry.block) k
      (unshadowed before _ helper_names.1) (unshadowed before _ helper_names.2.1)
      (unshadowed before _ helper_names.2.2) entryData indexData sourceData auxData opData widthData
      decoded noError fetched
  have actualEffect : VectorMemory.Effect (Arm64Nop.allocation world before).2 written old.vectors.block value := by
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
  let writtenStorage := VectorStorage.storage carried value effect
  let finalStorage := storage_frame writtenStorage before.nextblock bound freeFrame
  have finalVectors : finalStorage.vectors = old.vectors :=
    (frame_vectors writtenStorage before.nextblock bound freeFrame).trans
      ((written_vectors carried value effect).trans (allocated_vectors old))
  have low : CC.Mem.load .Mint64 after finalStorage.vectors.block 48 = some (.Vlong value) := by
    rw [finalVectors]
    exact (freeFrame.load .Mint64 _ 48 vectorOwned).trans actualEffect.low
  have high : CC.Mem.load .Mint64 after finalStorage.vectors.block 56 = some (.Vlong 0) := by
    rw [finalVectors]
    exact (freeFrame.load .Mint64 _ 56 vectorOwned).trans actualEffect.high
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
    obtain ⟨middle,lowStore,highStore⟩ := actualEffect
    exact (FrameBelow.store old.vectors.fresh lowStore).trans (FrameBelow.store old.vectors.fresh highStore)
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

end KProgFormal.ClightRefinement.Arm64Fmov.Call
