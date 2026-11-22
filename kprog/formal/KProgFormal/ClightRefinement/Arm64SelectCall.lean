import KProgFormal.ClightRefinement.Arm64SelectBody

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select.Call

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage
open Arm64RegisterStorageFrontier
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntrySelectCall (arguments initialTemps entry_valid)

/-- Carry the original producer resource through the true generic allocation. -/
def allocatedStorage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) : Storage initial (Arm64Nop.allocation world before).2 entry :=
  storage.frame (Arm64Nop.entry_frame world before)

/-- The actual generic call result includes the source stores, real frame
release and native correspondence at the caller's original observer frontier. -/
structure Result {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (native : Reference.AArch64.State)
    (k : CC.Cont) (count : Nat) (value : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (written after : CC.Mem) (finalStorage : Storage initial after entry) : Prop where
  effect : Arm64PointerWrite.ValueResult (allocatedStorage storage) 5 value tag written
  valueRep : Arm64Registers.ValueRep addresses value raw
  selected : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0)
    (if ConditionHolds (0#4) native.machine then (1 : Fin 31) else 2).val =
      some (value,.Vint (tag.setWidth 32))
  word : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 5) 0 = some value
  tagRead : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 5) 0 =
    some (.Vint (tag.setWidth 32))
  run : InternalRun world count
    (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
    (.Returnstate .Vundef k after)
  registers : Arm64Registers.Represents addresses origins (fun r => r.val)
    before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step native).state
  nativeStep : Reference.AArch64.step native =
    ⟨Arm64Nop.atCursor (read_pc native.machine + 4#64)
      (Arm64PointerWrite.nativeUpdate origins native 5 raw tag), [], none⟩
  free : CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after
  freeFrame : FrameBelow before.nextblock written after
  contents : after.contents = written.contents
  nextblock : after.nextblock = written.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
    ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false
  caller : FrameBelow initial.nextblock before after
  kept : Arm64CacheLocalFrame.Kept initial before after 5
  bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (notLocal : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation world before).1.get name = none := by
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound world before) notLocal

private theorem helper_names :
    Arm64Program._arm64_width_effective ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_condition ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_csel_path ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_pointer ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_tag ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_write_pointer ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem parameters (b : CC.Block) :
      (initialTemps b).get Arm64Program._entry = some (.Vptr b 0) ∧
      (initialTemps b).get Arm64Program._src = some (.Vlong (1#64)) ∧
      (initialTemps b).get Arm64Program._src2 = some (.Vlong (2#64)) ∧
      (initialTemps b).get Arm64Program._dst = some (.Vlong (5#64)) ∧
      (initialTemps b).get Arm64Program._aux = some (.Vint (0#32)) ∧
      (initialTemps b).get Arm64Program._op = some (.Vint (28#32)) ∧
      (initialTemps b).get Arm64Program._flags = some (Arm64Width.argument (8#8)) := by
    simp +decide only [initialTemps,Arm64Width.argument,CC.PTree.gss,CC.PTree.gso,and_self]

/-- Bind all nine original arguments, allocate the real generic frame, execute
its complete CSEL body and derive successful release/return. No resulting store,
free, register value or native post-state is a caller premise. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (decoded : instruction.decoded = .DPR (.Conditional_select (Native.fields 5 1 2 (0#4))))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ count value raw tag written after, ∃ finalStorage : Storage initial after entry,
      Result storage addresses origins native k count value raw tag written after finalStorage := by
  have allocationFrame := Arm64Nop.entry_frame world before
  let carried := allocatedStorage storage
  have allocatedOld := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) native).mpr represented
  have allocated := (represents_iff carried before.nextblock bound addresses origins native).mp allocatedOld
  let le := initialTemps entry.block
  have data := parameters entry.block
  obtain ⟨count,value,raw,tag,written,finalTemps,read,bits,effect,body,registers,bodyKept,step⟩ :=
    Body.execute carried addresses origins native instruction 5 1 2 allocated
      (Arm64Nop.allocation world before).1 le k
      (unshadowed before Arm64Program._arm64_width_effective helper_names.1) (unshadowed before Arm64Program._kprog_arm64_program_condition helper_names.2.1)
      (unshadowed before Arm64Program._kprog_arm64_csel_path helper_names.2.2.1) (unshadowed before Arm64Program._kprog_arm64_program_pointer helper_names.2.2.2.1)
      (unshadowed before Arm64Program._kprog_arm64_program_tag helper_names.2.2.2.2.1) (unshadowed before Arm64Program._kprog_arm64_program_write_pointer helper_names.2.2.2.2.2)
      data.1 data.2.1 data.2.2.1 data.2.2.2.1 data.2.2.2.2.1 data.2.2.2.2.2.1 data.2.2.2.2.2.2
      decoded noError fetched
  have selected : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0)
      (if ConditionHolds (0#4) native.machine then (1 : Fin 31) else 2).val =
      some (value,.Vint (tag.setWidth 32)) := by
    exact (Arm64EntryMemory.gpr_frame allocationFrame (.Vptr entry.block 0) _).symm.trans
      ((gpr_eq carried before.nextblock bound _).trans read)
  have owned : ∀ id v, (Arm64Nop.allocation world before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof world.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated_bound world before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation world before).2)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans live
  obtain ⟨after,freed,freeFrame,contents,next,released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated_bound world before) owned
  let finalStorage := storage_frame effect.storage before.nextblock bound freeFrame
  have word : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 5) 0 = some value := by
    change CC.Mem.load .Mint64 after ((storage.tables false).cellBlock 5) 0 = _
    exact (freeFrame.load .Mint64 _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables false).cellBinding 5)) bound)).trans effect.word
  have tagRead : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 5) 0 =
      some (.Vint (tag.setWidth 32)) := by
    change CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock 5) 0 = _
    exact (freeFrame.load .Mint8unsigned _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables true).cellBinding 5)) bound)).trans effect.tag
  have liveRegisters : Arm64Registers.Represents addresses origins (fun r => r.val)
      written.nextblock written (.Vptr entry.block 0) (Reference.AArch64.step native).state :=
    Eq.mpr (congrArg (fun frontier => Arm64Registers.Represents addresses origins (fun r => r.val)
      frontier written (.Vptr entry.block 0) (Reference.AArch64.step native).state) effect.nextblock) registers
  have oldRegisters := (represents_iff effect.storage before.nextblock bound addresses origins
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
  have kept := ((Arm64CacheLocalFrame.of_frame before.nextblock 5 bound allocationFrame).trans bodyKept).trans
    (Arm64CacheLocalFrame.of_frame before.nextblock 5 bound freeFrame)
  have entered : InternalRun world 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k (Arm64Nop.allocation world before).1 le
        (Arm64Nop.allocation world before).2) :=
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
  exact ⟨_,value,raw,tag,written,after,finalStorage,⟨effect,bits,selected,word,tagRead,
    (entered.trans body).trans returned,finalRegisters,step,freed,freeFrame,contents,next,released,
    (callerAlloc.trans effect.caller).trans callerFree,kept,finalBound⟩⟩

end KProgFormal.ClightRefinement.Arm64Select.Call
