import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnTarget

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryReturnComplete
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

def temps (le : CC.TempEnv) : CC.TempEnv := Arm64ProgramEntryReturnTarget.temps
  (Arm64ProgramEntryReturnTag.temps (Arm64ProgramEntryReturnGuard.temps (Arm64ProgramEntryReturnRaw.temps le)))

theorem result_readback (le : CC.TempEnv) : (temps le).get Arm64ProgramFixture._result = le.get Arm64ProgramFixture._result := by
  simp only [temps,Arm64ProgramEntryReturnTarget.temps,Arm64ProgramEntryReturnTag.temps,
    Arm64ProgramEntryReturnGuard.temps,Arm64ProgramEntryReturnRaw.temps]
  repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

theorem ctx_preserved (le : CC.TempEnv) : (temps le).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  simp only [temps,Arm64ProgramEntryReturnTarget.temps,Arm64ProgramEntryReturnTag.temps,
    Arm64ProgramEntryReturnGuard.temps,Arm64ProgramEntryReturnRaw.temps]
  repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- Complete original callee RET_TO: real raw call/caller, repeated LR store,
nonzero guard, actual tag call/caller and real switch64/goto. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (current : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    ∃ after, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr before after,
      InternalRun world 84
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
          (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1 (temps le) after) ∧
      Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)) ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong 64) := by
  obtain ⟨after,effect,raw⟩ := Arm64ProgramEntryReturnLR.execute current lr le k observed
  have lrRead := Arm64ProgramEntryReturnLR.lr_readback effect
  have link := Arm64ProgramEntryReturnLR.link (prior := current) effect observed
  have guard := Arm64ProgramEntryReturnGuard.execute lr (Arm64ProgramEntryReturnRaw.temps le) after k lrRead
  have tag := Arm64ProgramEntryReturnTag.execute entry
    (Arm64ProgramEntryReturnGuard.temps (Arm64ProgramEntryReturnRaw.temps le)) after (Arm64ProgramEntryReturnGuard.cont k) link
  have target := Arm64ProgramEntryReturnTarget.execute lr
    (Arm64ProgramEntryReturnTag.temps (Arm64ProgramEntryReturnGuard.temps (Arm64ProgramEntryReturnRaw.temps le)))
    after (Arm64ProgramEntryReturnGuard.cont k) lrRead (by exact CC.PTree.gss _ _ _)
  exact ⟨after,effect,by simpa only [temps,Arm64ProgramEntryReturnTarget.targetCont,Arm64ProgramEntryReturnGuard.cont,
    Arm64ProgramEntryReturnRaw.outerCont,CC.callCont] using ((raw.trans guard).trans tag).trans target,link,lrRead⟩

/-- Actual CALL and complete RET_TO share both real LR stores, actual X30
word/tag effects and their final packet; no producer is invoked again. -/
theorem from_call {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ linked, ∃ result : Arm64ProgramEntryLinkComplete.Result prior lr linked,
      ∃ after, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr linked after,
        InternalRun world 152
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
            (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le before)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
            (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1
            (temps (Arm64ProgramEntryLinkCall.temps le)) after) ∧
        FrameBelow initial.nextblock before after := by
  obtain ⟨linked,result,call⟩ := Arm64ProgramEntryLinkComplete.execute prior lr le k hk
  obtain ⟨after,effect,returned,_,_⟩ := execute result.packet lr (Arm64ProgramEntryLinkCall.temps le) k result.link
  exact ⟨linked,result,after,effect,call.trans returned,result.caller.trans effect.caller⟩

/-- Full JCC/CBZ/TBNZ/CMP/CALL/RET_TO from the SAME original memcpy output.
The actual compare, link and repeated-LR effects and saved ctx/result remain. -/
theorem from_memcpy {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (lr : HeaderSourceLocal initial 4) (frame : FrameBelow initial.nextblock initial m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (before : BitVec 64) (saved : le.get Arm64ProgramFixture._result = some (.Vlong before))
    (s : Reference.AArch64.State) :
    let flagsState := Arm64ClobberNativeFlags.native s flags
    let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
    let cbzResult := Arm64ProgramEntryCbzExit.result
      (Arm64ProgramEntryJccExit.result (before ^^^ (vectors 63)) mark flagsState) compareState
    let tbnzState := Arm64ProgramEntryTbnzCall.native compareState (gprs 3)
    let tbnzResult := Arm64ProgramEntryTbnzExit.result cbzResult tbnzState
    ∃ cmpAfter, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue cmpAfter,
      ∃ cmpLe linked, ∃ linkedResult : Arm64ProgramEntryLinkComplete.Result updated lr linked,
      ∃ after, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr linked after, ∃ count,
        Arm64Compare.Stores.Effect prior.memory.storage
          (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
          (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
          (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
          (Arm64ProgramEntryCmpArithmetic.sign false) cmpAfter ∧
        InternalRun world count
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
            (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1
            (temps (Arm64ProgramEntryLinkCall.temps cmpLe)) after) ∧
        (temps (Arm64ProgramEntryLinkCall.temps cmpLe)).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx ∧
        (temps (Arm64ProgramEntryLinkCall.temps cmpLe)).get Arm64ProgramFixture._result =
          some (.Vlong (Arm64ProgramEntryCmpExit.result tbnzResult tbnzState (gprs 2) (gprs 3))) ∧
        FrameBelow initial.nextblock initial after := by
  dsimp only
  obtain ⟨cmpAfter,updated,cmpLe,linked,result,count,cmpEffect,composed,ctxEq,resultEq,caller⟩ :=
    Arm64ProgramEntryLinkComplete.from_memcpy prior lr frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark before saved s
  obtain ⟨after,effect,returned,_,_⟩ := execute result.packet lr (Arm64ProgramEntryLinkCall.temps cmpLe) k result.link
  exact ⟨cmpAfter,updated,cmpLe,linked,result,after,effect,_,cmpEffect,composed.trans returned,
    (ctx_preserved _).trans ctxEq,(result_readback _).trans resultEq,caller.trans effect.caller⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryReturnComplete
