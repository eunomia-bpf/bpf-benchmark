import KProgFormal.ClightRefinement.Arm64AddImmediateBody
import KProgFormal.ClightRefinement.Arm64MovImmediateCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.CallRights

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryLinked (ge)
open Arm64RegisterStorageFrontier

def arguments (b : CC.Block) (i : Fin 31) (rhs : BitVec 64) (src2 src3 : CC.Val) : List CC.Val :=
  [.Vptr b 0, .Vint (3#32), .Vlong (BitVec.ofNat 64 i.val), .Vlong (32#64),
    src2, src3, .Vint (8#32), .Vint (0#32), .Vlong rhs]

def initialTemps (b : CC.Block) (i : Fin 31) (rhs : BitVec 64) (src2 src3 : CC.Val) : CC.TempEnv :=
  ((((((((((CC.createUndefTemps Arm64Nop.handler.fn_temps).set Arm64Program._entry (.Vptr b 0)).set Arm64Program._op (.Vint (3#32))).set Arm64Program._dst (.Vlong (BitVec.ofNat 64 i.val))).set Arm64Program._src (.Vlong (32#64))).set Arm64Program._src2 src2).set Arm64Program._src3 src3).set Arm64Program._flags (.Vint (8#32))).set Arm64Program._aux (.Vint (0#32))).set Arm64Program._imm (.Vlong rhs))

/-- Actual nine-parameter binding and the existing complete generic allocation. -/
theorem entry_valid (before : CC.Mem) (b : CC.Block) (i : Fin 31) (rhs : BitVec 64) (src2 src3 : CC.Val) :
    CC.FunctionEntry2 ge Arm64Nop.handler (arguments b i rhs src2 src3) before
      (Arm64Nop.allocation ge before).1 (initialTemps b i rhs src2 src3) (Arm64Nop.allocation ge before).2 :=
  .intro Arm64NopDeclarations.vars_norepet Arm64NopDeclarations.params_norepet
    Arm64NopDeclarations.params_temps_disjoint (Arm64MovImmediate.allocated_bound ge before) rfl

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (notLocal : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation ge before).1.get name = none := by
  simpa only [CC.emptyEnv, CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound ge before) notLocal

private theorem width_not_local : Arm64Program._arm64_width_effective ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem read_not_local : Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem selector_not_local : Arm64Program._kprog_arm64_alu_source ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem tag_not_local : Arm64Program._kprog_arm64_program_tag ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem pointer_not_local : Arm64Program._kprog_arm64_program_pointer ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem writer_not_local : Arm64Program._kprog_arm64_program_write_pointer ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

private theorem frame_sp {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (frame : FrameBelow before.nextblock before after) :
    (storage.frame frame).spValue = storage.spValue := rfl

private theorem result_frontier {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Arm64PointerWrite.Result storage i value tag after)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (registers : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after
      (.Vptr entry.block 0) (Arm64PointerWrite.nativeUpdate origins native i value tag)) :
    Arm64Registers.Represents addresses origins (fun r => r.val) after.nextblock after
      (.Vptr entry.block 0) (Arm64PointerWrite.nativeUpdate origins native i value tag) :=
  Eq.mpr (congrArg (fun frontier => Arm64Registers.Represents addresses origins (fun r => r.val)
    frontier after (.Vptr entry.block 0) (Arm64PointerWrite.nativeUpdate origins native i value tag)) result.nextblock) registers

private theorem result_bound {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 31} {value : BitVec 64} {tag : BitVec 8}
    (result : Arm64PointerWrite.Result storage i value tag after)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat) :
    (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat :=
  Eq.mpr (congrArg (fun frontier : CC.Block =>
    (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat) result.nextblock) bound

/-- Complete generic ADD-immediate call, deriving actual frame release and
retaining the caller's original observer frontier, canonical header and warm cache. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (i : Fin 31) (rhs : BitVec 64) (src2 src3 : CC.Val) (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 = some (.Vlong (storage.spValue + rhs)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint (4#32)) ∧
      InternalRun ge 333 (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block i rhs src2 src3) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins native i (storage.spValue + rhs) (4#8)) ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after i ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat ∧
      (∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
        CC.PMap.get block after.access = CC.PMap.get block before.access) := by
  have allocationFrame := Arm64Nop.entry_frame ge before
  let carried := storage.frame allocationFrame
  have carriedSP : carried.spValue = storage.spValue := frame_sp storage allocationFrame
  have allocationKept := Arm64CacheLocalFrame.of_frame before.nextblock i bound allocationFrame
  have allocatedPointers := allocationKept.pointers header pointers
  have allocatedWarmOld := allocationKept.warm before.nextblock header bound pointers false origins.stack warm
  have allocatedWarm := (Arm64CacheLocalFrame.warm_iff before.nextblock header bound allocatedPointers
    false origins.stack).mp allocatedWarmOld
  have allocatedRegistersOld := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) native).mpr represented
  have allocatedRegisters := (represents_iff carried before.nextblock bound addresses origins native).mp allocatedRegistersOld
  let le := initialTemps entry.block i rhs src2 src3
  have data :
      le.get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      le.get Arm64Program._src = some (.Vlong (32#64)) ∧
      le.get Arm64Program._flags = some (.Vint (8#32)) ∧
      le.get Arm64Program._op = some (.Vint (3#32)) ∧
      le.get Arm64Program._aux = some (.Vint (0#32)) ∧
      le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
      le.get Arm64Program._imm = some (.Vlong rhs) := by
    simp +decide only [le, initialTemps, CC.PTree.gss, CC.PTree.gso, and_self]
  obtain ⟨written, result, body, registers, bodyKept⟩ := Body.execute carried addresses origins native
    allocatedRegisters allocatedWarm (Arm64Nop.allocation ge before).1 le k i rhs
    (unshadowed before Arm64Program._arm64_width_effective width_not_local) (unshadowed before Arm64Program._kprog_arm64_program_read read_not_local)
    (unshadowed before Arm64Program._kprog_arm64_alu_source selector_not_local) (unshadowed before Arm64Program._kprog_arm64_program_tag tag_not_local)
    (unshadowed before Arm64Program._kprog_arm64_program_pointer pointer_not_local) (unshadowed before Arm64Program._kprog_arm64_program_write_pointer writer_not_local)
    data.1 data.2.1 data.2.2.1 data.2.2.2.1 data.2.2.2.2.1 data.2.2.2.2.2.1 data.2.2.2.2.2.2
  have owned : ∀ id v, (Arm64Nop.allocation ge before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof ge.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated_bound ge before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation ge before).2)
      (fun offset => by simp only [CC.Mem.perm, result.access])).trans live
  obtain ⟨after, freed, freeFrame, contents, next, released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated_bound ge before) owned
  let finalStorage := Arm64RegisterStorageFrontier.storage_frame result.storage before.nextblock bound freeFrame
  have word : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 =
      some (.Vlong (storage.spValue + rhs)) := by
    change CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0 = _
    have ownedWord := Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables false).cellBinding i)) bound
    have preservedWord := freeFrame.load .Mint64 ((storage.tables false).cellBlock i) 0 ownedWord
    have writtenWord := result.word
    have wordValue := congrArg (fun raw => some (CC.Val.Vlong (raw + rhs))) carriedSP
    exact preservedWord.trans (writtenWord.trans wordValue)
  have tag : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint (4#32)) := by
    change CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0 = _
    have ownedTag := Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables true).cellBinding i)) bound
    have preservedTag := freeFrame.load .Mint8unsigned ((storage.tables true).cellBlock i) 0 ownedTag
    have writtenTag := result.tag
    change CC.Mem.load .Mint8unsigned written ((storage.tables true).cellBlock i) 0 = some (.Vint (4#32)) at writtenTag
    exact preservedTag.trans writtenTag
  have registersLiveCarried := result_frontier result addresses origins native registers
  have updateEq := congrArg (fun raw => Arm64PointerWrite.nativeUpdate origins native i (raw + rhs) (4#8)) carriedSP
  have registersLive := Eq.mp (congrArg (fun updated => Arm64Registers.Represents addresses origins (fun r => r.val)
    written.nextblock written (.Vptr entry.block 0) updated) updateEq) registersLiveCarried
  have registersOld := (represents_iff result.storage before.nextblock bound addresses origins
    (Arm64PointerWrite.nativeUpdate origins native i (storage.spValue + rhs) (4#8))).mpr registersLive
  have finalRegisters := (Arm64Registers.frame freeFrame (.Vptr entry.block 0)
    (Arm64PointerWrite.nativeUpdate origins native i (storage.spValue + rhs) (4#8))).mpr registersOld
  have initialBound := Nat.le_trans ((FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1) bound
  have allocationCaller : FrameBelow initial.nextblock before (Arm64Nop.allocation ge before).2 :=
    fun block owned => allocationFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have freeCaller : FrameBelow initial.nextblock written after :=
    fun block owned => freeFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have kept := (allocationKept.trans bodyKept).trans (Arm64CacheLocalFrame.of_frame before.nextblock i bound freeFrame)
  have enter : InternalRun ge 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block i rhs src2 src3) k before)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k (Arm64Nop.allocation ge before).1 le
        (Arm64Nop.allocation ge before).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry.block i rhs src2 src3)) (.refl _)
  have leave : InternalRun ge 1
      (.State Arm64Nop.handler .Sskip k (Arm64Nop.allocation ge before).1
        (Body.finalTemps le native rhs carried.spValue) written)
      (.Returnstate .Vundef k after) :=
    .step trivial (.skip_call _ _ _ _ _ _ valid freed) (.refl _)
  have writtenBound := result_bound result (Nat.le_trans bound
    (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound ge before) before.nextblock (Nat.le_refl _)).1)
  have finalBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat :=
    Eq.mpr (congrArg (fun frontier : CC.Block =>
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat) next) writtenBound
  have permissionFrame : ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
      CC.PMap.get block after.access = CC.PMap.get block before.access := by
    intro block ownedBlock
    have oldBlock := Nat.lt_of_lt_of_le ownedBlock bound
    exact (freeFrame block oldBlock).2.trans
      ((congrArg (CC.PMap.get block) result.access).trans (allocationFrame block oldBlock).2)
  exact ⟨written, after, finalStorage, word, tag, (enter.trans body).trans leave, finalRegisters,
    (allocationCaller.trans result.caller).trans freeCaller, freed, freeFrame, contents, next, released,
    kept, kept.pointers header pointers, kept.warm before.nextblock header bound pointers false origins.stack warm, finalBound,permissionFrame⟩

end KProgFormal.ClightRefinement.Arm64AddImmediate.CallRights
