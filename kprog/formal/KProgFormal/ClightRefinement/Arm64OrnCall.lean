import KProgFormal.ClightRefinement.Arm64OrnBodyNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryOrnCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Orn.Call

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64RegisterStorageFrontier
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryOrnCall (arguments initialTemps entry_valid)

/-- The same producer storage survives the real generic-frame allocation. -/
def allocatedStorage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) : Storage initial (Arm64Nop.allocation world before).2 entry :=
  storage.frame (Arm64Nop.entry_frame world before)

/-- Actual raw numeric argument passed to the width4 scalar writer. -/
def sourceResult (s : Reference.AArch64.State) : BitVec 64 :=
  ((Reference.AArch64.gpr s 6 ||| ~~~((Reference.AArch64.gpr s 3 <<< 1) &&& (4294967295#64))) &&& (4294967295#64))

def nativeResult (s : Reference.AArch64.State) : BitVec 64 :=
  Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)

/-- Result of the original nine-argument ORN call and live-frame free. -/
structure Result {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (native : Reference.AArch64.State)
    (k : CC.Cont) (count : Nat) (written after : CC.Mem)
    (finalStorage : Storage initial after entry) : Prop where
  effect : Arm64RegisterWrite.Result (allocatedStorage storage) 7 (sourceResult native) true written
  word : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 7) 0 =
    some (.Vlong (Arm64RegisterWrite.written true (nativeResult native)))
  tag : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 7) 0 = some (.Vint 0)
  run : InternalRun world count
    (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
    (.Returnstate .Vundef k after)
  registers : Arm64Registers.Represents addresses origins (fun r => r.val)
    before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step native).state
  nativeStep : Reference.AArch64.step native =
    ⟨Arm64Nop.atCursor (read_pc native.machine + 4#64)
      (Arm64RegisterWrite.nativeUpdate native 7 (nativeResult native) true), [], none⟩
  free : CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after
  freeFrame : FrameBelow before.nextblock written after
  contents : after.contents = written.contents
  nextblock : after.nextblock = written.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
    ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false
  caller : FrameBelow initial.nextblock before after
  kept : Arm64CacheLocalFrame.Kept initial before after 7
  bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (notLocal : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation world before).1.get name = none := by
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound world before) notLocal

private theorem helper_names :
    Arm64Program._arm64_width_effective ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_modified ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_write ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem parameters (b : CC.Block) :
      (initialTemps b).get Arm64Program._entry = some (.Vptr b 0) ∧
      (initialTemps b).get Arm64Program._src = some (.Vlong (6#64)) ∧
      (initialTemps b).get Arm64Program._src2 = some (.Vlong (3#64)) ∧
      (initialTemps b).get Arm64Program._dst = some (.Vlong (7#64)) ∧
      (initialTemps b).get Arm64Program._aux = some (.Vint (65792#32)) ∧
      (initialTemps b).get Arm64Program._op = some (.Vint (53#32)) ∧
      (initialTemps b).get Arm64Program._flags = some (Arm64Width.argument (4#8)) := by
    simp +decide only [initialTemps,Arm64Width.argument,CC.PTree.gss,CC.PTree.gso,and_self]

/-- Bind original arguments, allocate the real generic frame, execute the
full source/native body, derive live-local release and return at the caller's
original observation frontier. Inputs describe the pre-memory only. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (raw : BitVec 64) (tag : BitVec 8) (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 6 =
      some (.Vlong raw, .Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false before.nextblock before
      (.Vptr entry.block 0) origins.stack)
    (rhsValue : BitVec 64)
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhsValue))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 3) 0 = some (.Vint 0))
    (decoded : instruction.decoded = .DPR (.Logical_shifted_reg Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ count written after, ∃ finalStorage : Storage initial after entry,
      Result storage addresses origins native k count written after finalStorage := by
  have allocationFrame := Arm64Nop.entry_frame world before
  let carried := allocatedStorage storage
  have allocatedOld := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) native).mpr represented
  have allocated := (represents_iff carried before.nextblock bound addresses origins native).mp allocatedOld
  have allocatedRead := (gpr_eq carried before.nextblock bound 6).symm.trans
    ((Arm64EntryMemory.gpr_frame allocationFrame (.Vptr entry.block 0) 6).trans observed)
  have allocationKept := Arm64CacheLocalFrame.of_frame before.nextblock 7 bound allocationFrame
  have allocatedPointers := allocationKept.pointers header pointers
  have allocatedCache (warm : tag = 4) : Arm64RegisterReads.WarmEntryCache false
      (Arm64Nop.allocation world before).2.nextblock (Arm64Nop.allocation world before).2
      (.Vptr entry.block 0) origins.stack := by
    have old := allocationKept.warm before.nextblock header bound pointers false origins.stack (cache warm)
    exact (Arm64CacheLocalFrame.warm_iff before.nextblock header bound allocatedPointers false origins.stack).mp old
  let le := initialTemps entry.block
  have allocatedRhsWord : CC.Mem.load .Mint64 (Arm64Nop.allocation world before).2
      ((carried.tables false).cellBlock 3) 0 = some (.Vlong rhsValue) :=
    (allocationFrame.load .Mint64 _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables false).cellBinding 3)) bound)).trans rhsWord
  have allocatedRhsTag : CC.Mem.load .Mint8unsigned (Arm64Nop.allocation world before).2
      ((carried.tables true).cellBlock 3) 0 = some (.Vint 0) :=
    (allocationFrame.load .Mint8unsigned _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables true).cellBinding 3)) bound)).trans rhsTag
  obtain ⟨entryData,sourceData,rhsData,destData,auxData,opData,widthData⟩ := parameters entry.block
  obtain ⟨count, written, finalTemps, effect, body, registers, bodyKept, tempKept, step⟩ :=
    Body.corresponds carried addresses origins native instruction allocated raw tag tags rhsValue allocatedRead allocatedCache
      allocatedRhsWord allocatedRhsTag
      (Arm64Nop.allocation world before).1 le k
      (unshadowed before Arm64Program._arm64_width_effective helper_names.1)
      (unshadowed before Arm64Program._kprog_arm64_program_read helper_names.2.1)
      (unshadowed before Arm64Program._kprog_arm64_program_modified helper_names.2.2.1)
      (unshadowed before Arm64Program._kprog_arm64_program_write helper_names.2.2.2)
      entryData sourceData rhsData destData opData auxData widthData
      decoded noError fetched
  have owned : ∀ id v, (Arm64Nop.allocation world before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof world.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated_bound world before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation world before).2)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans live
  obtain ⟨after,freed,freeFrame,contents,next,released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated_bound world before) owned
  let finalStorage := storage_frame effect.storage before.nextblock bound freeFrame
  have word : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 7) 0 =
      some (.Vlong (Arm64RegisterWrite.written true (nativeResult native))) := by
    change CC.Mem.load .Mint64 after ((storage.tables false).cellBlock 7) 0 = _
    exact (freeFrame.load .Mint64 _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables false).cellBinding 7)) bound)).trans
      (by simpa only [Body.masked_written,nativeResult,carried,allocatedStorage,Storage.frame] using effect.word)
  have tagRead : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 7) 0 =
      some (.Vint 0) := by
    change CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock 7) 0 = _
    exact (freeFrame.load .Mint8unsigned _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables true).cellBinding 7)) bound)).trans effect.tag
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
  have kept := ((Arm64CacheLocalFrame.of_frame before.nextblock 7 bound allocationFrame).trans bodyKept).trans
    (Arm64CacheLocalFrame.of_frame before.nextblock 7 bound freeFrame)
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
  exact ⟨_, written, after, finalStorage, ⟨effect, word, tagRead,
    (entered.trans body).trans returned, finalRegisters, step, freed, freeFrame, contents, next, released,
    (callerAlloc.trans effect.caller).trans callerFree, kept, finalBound⟩⟩

end KProgFormal.ClightRefinement.Arm64Orn.Call
