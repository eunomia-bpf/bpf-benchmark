import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpExit

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpComplete
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

def temps (le : CC.TempEnv) (before lhs rhs : BitVec 64) (s : Reference.AArch64.State) : CC.TempEnv :=
  Arm64ProgramEntryCmpExit.temps (Arm64ProgramEntryCmpWritten.temps le lhs rhs) before s lhs rhs

theorem result_readback (le : CC.TempEnv) (before lhs rhs : BitVec 64) (s : Reference.AArch64.State)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    (temps le before lhs rhs s).get Arm64ProgramFixture._result =
      some (.Vlong (Arm64ProgramEntryCmpExit.result before s lhs rhs)) := by
  unfold temps Arm64ProgramEntryCmpExit.temps Arm64ProgramEntryCmpExit.result
  split
  · exact (Arm64ProgramEntryCmpWritten.result_readback le lhs rhs).trans prior
  · exact CC.PTree.gss _ _ _

theorem ctx_preserved (le : CC.TempEnv) (before lhs rhs : BitVec 64) (s : Reference.AArch64.State) :
    (temps le before lhs rhs s).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  unfold temps Arm64ProgramEntryCmpExit.temps
  split
  all_goals
    dsimp only [Arm64ProgramEntryCmpWritten.temps,Arm64ProgramEntryCmpArithmetic.temps,
      Arm64ProgramEntryCmpArithmetic.readyTemps,Arm64ProgramEntryCmpOperands.operandTemps,
      Arm64ProgramEntryCmpOperands.returnedTemps,Arm64ProgramEntryCmpBranch.temps,
      Arm64ProgramEntryCmpBranch.widthTemps,Arm64ProgramEntryCmpModifiedCall.temps,Arm64ProgramEntryCmpRhsCall.temps]
    repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- Complete original CMP source: all actual calls, arithmetic, four real flag
writes, signed-GT choice and both actual label routes. Every reached byte and
resource is carried by the SAME updated packet/effect on the reached heap. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State) :
    ∃ after, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue after,
      Arm64Compare.Stores.Effect packet.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) after ∧
      ∃ count, InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
          (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
          (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1
          (temps le before (gprs 2) (gprs 3) s) after) := by
  obtain ⟨after,updated,effect,count,written⟩ := Arm64ProgramEntryCmpWritten.execute packet le k
  have inputs := Arm64ProgramEntryCmpWritten.branch_reads le (gprs 2) (gprs 3)
  have saved := (Arm64ProgramEntryCmpWritten.result_readback le (gprs 2) (gprs 3)).trans prior
  obtain ⟨exitCount,exit⟩ := Arm64ProgramEntryCmpExit.execute
    (Arm64ProgramEntryCmpWritten.temps le (gprs 2) (gprs 3)) after k hk before saved s (gprs 2) (gprs 3)
    inputs.2.2 inputs.1 inputs.2.1
  exact ⟨after,updated,effect,_,written.trans exit⟩

/-- Join complete JCC/CBZ/TBNZ/CMP on the SAME actual memcpy state. Original
caller context, explicit result, new flags, copied bytes and current resources
stay on the one real execution/effect witness. -/
theorem from_memcpy {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (frame : FrameBelow initial.nextblock initial m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (before : BitVec 64) (prior : le.get Arm64ProgramFixture._result = some (.Vlong before))
    (s : Reference.AArch64.State) :
    let flagsState := Arm64ClobberNativeFlags.native s flags
    let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
    let cbzResult := Arm64ProgramEntryCbzExit.result
      (Arm64ProgramEntryJccExit.result (before ^^^ (vectors 63)) mark flagsState) compareState
    let tbnzState := Arm64ProgramEntryTbnzCall.native compareState (gprs 3)
    let tbnzResult := Arm64ProgramEntryTbnzExit.result cbzResult tbnzState
    ∃ after, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue after,
      ∃ finalLe count, Arm64Compare.Stores.Effect packet.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) after ∧
      InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
          (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 finalLe after) ∧
      finalLe.get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx ∧
      finalLe.get Arm64ProgramFixture._result = some (.Vlong
        (Arm64ProgramEntryCmpExit.result tbnzResult tbnzState (gprs 2) (gprs 3))) ∧
      FrameBelow initial.nextblock initial after := by
  dsimp only
  obtain ⟨tbnzLe,tbnzCount,tbnz,ctxEq,resultEq⟩ := Arm64ProgramEntryTbnzComplete.from_memcpy packet frame le k hk
    ctxBlock ctxOffset mark ctxBelow ctx originalMark before prior s
  let flagsState := Arm64ClobberNativeFlags.native s flags
  let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
  let cbzResult := Arm64ProgramEntryCbzExit.result
    (Arm64ProgramEntryJccExit.result (before ^^^ (vectors 63)) mark flagsState) compareState
  let tbnzState := Arm64ProgramEntryTbnzCall.native compareState (gprs 3)
  let tbnzResult := Arm64ProgramEntryTbnzExit.result cbzResult tbnzState
  obtain ⟨after,updated,effect,cmpCount,cmp⟩ := execute packet tbnzLe k hk tbnzResult resultEq tbnzState
  refine ⟨after,updated,temps tbnzLe tbnzResult (gprs 2) (gprs 3) tbnzState,_,effect,tbnz.trans cmp,?_,?_,frame.trans effect.caller⟩
  · exact (ctx_preserved _ _ _ _ _).trans ctxEq
  · exact result_readback _ _ _ _ _ resultEq

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpComplete
