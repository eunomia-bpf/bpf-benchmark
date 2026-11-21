import KProgFormal.ClightRefinement.Arm64MulBody
import KProgFormal.ClightRefinement.Arm64ProgramEntryMulCall
import KProgFormal.ClightRefinement.Arm64RegisterWriteFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Mul.Call
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView Arm64RegisterStorageFrontier
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryMulCall (arguments initialTemps entry_valid)

private theorem unshadowed (before : CC.Mem) (name : CC.Positive)
    (notLocal : name ∉ CC.varNames Arm64Nop.handler.fn_vars) :
    (Arm64Nop.allocation world before).1.get name = none := by
  simpa only [CC.emptyEnv, CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64MovImmediate.allocated_bound world before) notLocal

private theorem width_not_local : Arm64Program._arm64_width_effective ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel
private theorem read_not_local : Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel
private theorem writer_not_local : Arm64Program._kprog_arm64_program_write ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

/-- The actual fifth MUL caller's nine arguments, generic frame, source body,
real frame release and return. All register observations and warm cache survive
at the original caller frontier; no final-readback premise is assumed. -/
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
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 3) 0 = some (.Vint 0))
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 4) 0 = some (.Vlong (lhs * rhs)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 4) 0 = some (.Vint 0) ∧
      InternalRun world 437 (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate native 4 (lhs * rhs) false) ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after 4 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  have allocationFrame := Arm64Nop.entry_frame world before
  let carried := storage.frame allocationFrame
  have allocationKept := Arm64CacheLocalFrame.of_frame before.nextblock 4 bound allocationFrame
  have allocatedPointers := allocationKept.pointers header pointers
  have allocatedRegistersOld := (Arm64Registers.frame allocationFrame (.Vptr entry.block 0) native).mpr represented
  have allocatedRegisters := (represents_iff carried before.nextblock bound addresses origins native).mp allocatedRegistersOld
  have cell (tags : Bool) (i : Fin 31) (chunk : CC.Chunk) :
      CC.Mem.load chunk (Arm64Nop.allocation world before).2 ((carried.tables tags).cellBlock i) 0 =
      CC.Mem.load chunk before ((storage.tables tags).cellBlock i) 0 :=
    allocationFrame.load chunk _ 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables tags).cellBinding i)) bound)
  let le := initialTemps entry.block
  have data :
      le.get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      le.get Arm64Program._src = some (.Vlong (1#64)) ∧
      le.get Arm64Program._src2 = some (.Vlong (3#64)) ∧
      le.get Arm64Program._dst = some (.Vlong (4#64)) ∧
      le.get Arm64Program._flags = some (.Vint (8#32)) ∧
      le.get Arm64Program._op = some (.Vint (12#32)) ∧
      le.get Arm64Program._src3 = some (.Vlong (255#64)) := by
    simp +decide only [le, initialTemps, CC.PTree.gss, CC.PTree.gso, and_self]
  obtain ⟨written, result, body⟩ := Arm64Mul.Body.execute carried 1 3 4 lhs rhs
    (Arm64Nop.allocation world before).1 le k false
    (unshadowed before _ width_not_local) (unshadowed before _ read_not_local)
    (unshadowed before _ writer_not_local)
    data.1 data.2.1 data.2.2.1 data.2.2.2.2.2.2 data.2.2.2.1 data.2.2.2.2.1 data.2.2.2.2.2.1
    ((cell false 1 .Mint64).trans lhsWord) ((cell true 1 .Mint8unsigned).trans lhsTag)
    ((cell false 3 .Mint64).trans rhsWord) ((cell true 3 .Mint8unsigned).trans rhsTag)
  have registers := result.represents addresses origins native allocatedRegisters
  have owned : ∀ id v, (Arm64Nop.allocation world before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof world.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated_bound world before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation world before).2)
      (fun offset => by simp only [CC.Mem.perm, result.access])).trans live
  obtain ⟨after, freed, freeFrame, contents, next, released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated_bound world before) owned
  let finalStorage := storage_frame result.storage before.nextblock bound freeFrame
  have word : CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 4) 0 =
      some (.Vlong (lhs * rhs)) := by
    change CC.Mem.load .Mint64 after ((storage.tables false).cellBlock 4) 0 = _
    exact (freeFrame.load .Mint64 ((storage.tables false).cellBlock 4) 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables false).cellBinding 4)) bound)).trans result.word
  have tag : CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 4) 0 = some (.Vint 0) := by
    change CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock 4) 0 = _
    exact (freeFrame.load .Mint8unsigned ((storage.tables true).cellBlock 4) 0
      (Nat.lt_of_lt_of_le (local_owned initial _ _ _ ((storage.tables true).cellBinding 4)) bound)).trans result.tag
  have registersLive : Arm64Registers.Represents addresses origins (fun r => r.val)
      written.nextblock written (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate native 4 (lhs * rhs) false) := by
    simpa only [result.nextblock] using registers
  have registersOld := (represents_iff result.storage before.nextblock bound addresses origins
    (Arm64RegisterWrite.nativeUpdate native 4 (lhs * rhs) false)).mpr registersLive
  have finalRegisters := (Arm64Registers.frame freeFrame (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate native 4 (lhs * rhs) false)).mpr registersOld
  have initialBound := Nat.le_trans ((FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1) bound
  have allocationCaller : FrameBelow initial.nextblock before (Arm64Nop.allocation world before).2 :=
    fun block owned => allocationFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have freeCaller : FrameBelow initial.nextblock written after :=
    fun block owned => freeFrame block (Nat.lt_of_lt_of_le owned initialBound)
  have writerKept : Arm64CacheLocalFrame.Kept initial (Arm64Nop.allocation world before).2 written 4 := result.local_load
  have kept := (allocationKept.trans writerKept).trans (Arm64CacheLocalFrame.of_frame before.nextblock 4 bound freeFrame)
  have enter : InternalRun world 1
      (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k (Arm64Nop.allocation world before).1 le
        (Arm64Nop.allocation world before).2) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry.block)) (.refl _)
  have leave : InternalRun world 1
      (.State Arm64Nop.handler .Sskip k (Arm64Nop.allocation world before).1
        (Arm64Mul.Body.finalTemps le false lhs rhs) written)
      (.Returnstate .Vundef k after) :=
    .step trivial (.skip_call _ _ _ _ _ _ valid freed) (.refl _)
  have finalNext := next.trans result.nextblock
  have finalBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat :=
    Eq.mpr (congrArg (fun frontier : CC.Block => (Arm64Producer.allocation initial).2.nextblock.toNat ≤ frontier.toNat)
      finalNext) (Nat.le_trans bound (FrameBelow.allocVariables (Arm64MovImmediate.allocated_bound world before)
        before.nextblock (Nat.le_refl _)).1)
  exact ⟨written, after, finalStorage, word, tag, (enter.trans body).trans leave, finalRegisters,
    (allocationCaller.trans result.caller).trans freeCaller, freed, freeFrame, contents, next, released,
    kept, kept.pointers header pointers, kept.warm before.nextblock header bound pointers false origins.stack warm, finalBound⟩

/-- Every relational execution is a silent prefix of the same real freed-frame
return. All stuck endpoints coincide, and no infinite execution exists. -/
theorem all_behaviors {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 3) 0 = some (.Vint 0)) :
    ∃ after,
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate native 4 (lhs * rhs) false) ∧
      (∀ t other, CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 world other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 world (states j) t (states (j + 1))) := by
  obtain ⟨written, after, finalStorage, word, tag, run, registers, _⟩ :=
    execute storage bound header pointers addresses origins native represented warm lhs rhs
      lhsWord lhsTag rhsWord rhsTag .Kstop rfl
  have stuck : ∀ t next, ¬ CC.Step2 world (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, registers,
    fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64Mul.Call
