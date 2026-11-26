import KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzExit

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzComplete

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

def temps (le : CC.TempEnv) (before raw : BitVec 64) (s : Reference.AArch64.State) : CC.TempEnv :=
  Arm64ProgramEntryTbnzExit.temps (Arm64ProgramEntryTbnz.temps le raw) before (Arm64ProgramEntryTbnzCall.native s raw)

theorem result_readback (le : CC.TempEnv) (before raw : BitVec 64) (s : Reference.AArch64.State)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    (temps le before raw s).get Arm64ProgramFixture._result =
      some (.Vlong (Arm64ProgramEntryTbnzExit.result before (Arm64ProgramEntryTbnzCall.native s raw))) := by
  unfold temps Arm64ProgramEntryTbnzExit.temps Arm64ProgramEntryTbnzExit.result
  split <;> simp +decide [Arm64ProgramEntryTbnzExit.choiceTemps,Arm64ProgramEntryTbnzCall.temps,
    Arm64ProgramEntryTbnz.temps,CC.PTree.gss,CC.PTree.gso,prior]

theorem ctx_preserved (le : CC.TempEnv) (before raw : BitVec 64) (s : Reference.AArch64.State) :
    (temps le before raw s).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  unfold temps Arm64ProgramEntryTbnzExit.temps
  split <;> simp +decide [Arm64ProgramEntryTbnzExit.choiceTemps,Arm64ProgramEntryTbnzCall.temps,
    Arm64ProgramEntryTbnz.temps,CC.PTree.gso]

/-- The same current helper packet executes the complete original TBNZ source:
real X4 reader/caller, full Numeric op3 call/caller and both
original exits. The reached heap and provider maps remain exactly the same. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
        (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 (temps le before (gprs 3) s) m) := by
  have read : (Arm64ProgramEntryTbnz.temps le (gprs 3)).get Arm64ProgramFixture._t'140 =
      some (.Vlong (gprs 3)) := by simp only [Arm64ProgramEntryTbnz.temps,CC.PTree.gss]
  have currentResult : (Arm64ProgramEntryTbnz.temps le (gprs 3)).get Arm64ProgramFixture._result =
      some (.Vlong before) := by simpa +decide [Arm64ProgramEntryTbnz.temps,CC.PTree.gso] using prior
  have word : Reference.AArch64.gpr (Arm64ProgramEntryTbnzCall.native s (gprs 3)) 4 = gprs 3 :=
    Arm64ProgramEntryTbnzCall.native_word s (gprs 3)
  obtain ⟨prefixCount,prefixRun⟩ := Arm64ProgramEntryTbnz.execute packet le k
  obtain ⟨callCount,call⟩ := Arm64ProgramEntryTbnzCall.invoke (Arm64ProgramEntryTbnz.temps le (gprs 3)) m
    (Arm64ProgramEntryTbnz.branchCont k) (gprs 3) read (Arm64ProgramEntryTbnzCall.native s (gprs 3)) word
  obtain ⟨exitCount,exit⟩ := Arm64ProgramEntryTbnzExit.execute (Arm64ProgramEntryTbnz.temps le (gprs 3)) m k hk
    before (Arm64ProgramEntryTbnzCall.native s (gprs 3)) currentResult

  exact ⟨_,(prefixRun.trans call).trans exit⟩

/-- Join original JCC, CBZ_W and TBNZ on the same completed memcpy heap.
Actual selected flags/X3/X4 and the original caller context frame supply all
condition inputs, and the original saved result/ctx observations remain. -/
theorem from_memcpy {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
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
      (Arm64ProgramEntryJccExit.result (before ^^^ (values 63)) mark flagsState) compareState
    ∃ finalLe count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
        (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 finalLe m) ∧
      finalLe.get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx ∧
      finalLe.get Arm64ProgramFixture._result = some (.Vlong
        (Arm64ProgramEntryTbnzExit.result cbzResult (Arm64ProgramEntryTbnzCall.native compareState (gprs 3)))) := by
  dsimp only
  obtain ⟨cbzLe,cbzCount,cbz,ctxEq,resultEq⟩ := Arm64ProgramEntryCbzComplete.from_memcpy packet frame le k hk
    ctxBlock ctxOffset mark ctxBelow ctx originalMark before prior s
  let compareState := Arm64ProgramEntryCbzCall.native (Arm64ClobberNativeFlags.native s flags) (gprs 2)
  let cbzResult := Arm64ProgramEntryCbzExit.result
    (Arm64ProgramEntryJccExit.result (before ^^^ (values 63)) mark (Arm64ClobberNativeFlags.native s flags)) compareState
  obtain ⟨tbnzCount,tbnz⟩ := execute packet cbzLe k hk cbzResult resultEq compareState
  refine ⟨temps cbzLe cbzResult (gprs 3) compareState,_,cbz.trans tbnz,?_,?_⟩
  · exact (ctx_preserved _ _ _ _).trans ctxEq
  · exact result_readback _ _ _ _ resultEq

end KProgFormal.ClightRefinement.Arm64ProgramEntryTbnzComplete
