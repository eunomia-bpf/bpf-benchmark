import KProgFormal.ClightRefinement.Arm64ProgramEntryCbzExit

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCbzComplete

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

def temps (le : CC.TempEnv) (before raw : BitVec 64) (s : Reference.AArch64.State) : CC.TempEnv :=
  Arm64ProgramEntryCbzExit.temps (Arm64ProgramEntryCbzPrefix.temps le raw) before (Arm64ProgramEntryCbzCall.native s raw)

theorem result_readback (le : CC.TempEnv) (before raw : BitVec 64) (s : Reference.AArch64.State)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) :
    (temps le before raw s).get Arm64ProgramFixture._result =
      some (.Vlong (Arm64ProgramEntryCbzExit.result before (Arm64ProgramEntryCbzCall.native s raw))) := by
  unfold temps Arm64ProgramEntryCbzExit.temps Arm64ProgramEntryCbzExit.result
  split <;> simp +decide [Arm64ProgramEntryCbzExit.choiceTemps,Arm64ProgramEntryCbzCall.temps,
    Arm64ProgramEntryCbzPrefix.temps,CC.PTree.gss,CC.PTree.gso,prior]

theorem ctx_preserved (le : CC.TempEnv) (before raw : BitVec 64) (s : Reference.AArch64.State) :
    (temps le before raw s).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  unfold temps Arm64ProgramEntryCbzExit.temps
  split <;> simp +decide [Arm64ProgramEntryCbzExit.choiceTemps,Arm64ProgramEntryCbzCall.temps,
    Arm64ProgramEntryCbzPrefix.temps,CC.PTree.gso]

/-- The same current helper packet executes the complete original CBZ source:
real X3 reader/caller, unsigned32 cast, full Numeric op0 call/caller and both
original exits. The reached heap and provider maps remain exactly the same. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) (before : BitVec 64)
    (prior : le.get Arm64ProgramFixture._result = some (.Vlong before)) (s : Reference.AArch64.State) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1 (temps le before (gprs 2) s) m) := by
  have read : (Arm64ProgramEntryCbzPrefix.temps le (gprs 2)).get Arm64ProgramFixture.___a64_l_value =
      some (.Vlong (((gprs 2).setWidth 32).setWidth 64)) := by
    simp only [Arm64ProgramEntryCbzPrefix.temps,CC.PTree.gss]
  have currentResult : (Arm64ProgramEntryCbzPrefix.temps le (gprs 2)).get Arm64ProgramFixture._result =
      some (.Vlong before) := by simpa +decide [Arm64ProgramEntryCbzPrefix.temps,CC.PTree.gso] using prior
  have word : (Reference.AArch64.gpr (Arm64ProgramEntryCbzCall.native s (gprs 2)) 3).setWidth 32 =
      (gprs 2).setWidth 32 := by rw [Arm64ProgramEntryCbzCall.native_word]
  obtain ⟨prefixCount,prefixRun⟩ := Arm64ProgramEntryCbzPrefix.execute packet le k
  obtain ⟨callCount,call⟩ := Arm64ProgramEntryCbzCall.invoke (Arm64ProgramEntryCbzPrefix.temps le (gprs 2)) m
    (Arm64ProgramEntryCbzPrefix.branchCont k) ((gprs 2).setWidth 32) read (Arm64ProgramEntryCbzCall.native s (gprs 2)) word
  obtain ⟨exitCount,exit⟩ := Arm64ProgramEntryCbzExit.execute (Arm64ProgramEntryCbzPrefix.temps le (gprs 2)) m k hk
    before (Arm64ProgramEntryCbzCall.native s (gprs 2)) currentResult
  exact ⟨_,(prefixRun.trans call).trans exit⟩

/-- Join the complete current-source JCC and CBZ routes on one memcpy output.
The original caller frame provides mark; the same helper supplies NZCV/X3. -/
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
    ∃ finalLe count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCbzLabels.takenBody
        (.Kseq Arm64ProgramEntryCbzLabels.takenAfter k) (allocation initial).1 finalLe m) ∧
      finalLe.get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx ∧
      finalLe.get Arm64ProgramFixture._result = some (.Vlong
        (Arm64ProgramEntryCbzExit.result
          (Arm64ProgramEntryJccExit.result (before ^^^ (values 63)) mark (Arm64ClobberNativeFlags.native s flags))
          (Arm64ProgramEntryCbzCall.native (Arm64ClobberNativeFlags.native s flags) (gprs 2)))) := by
  let jccLe := Arm64ProgramEntryJccComplete.temps le before (values 63) mark (Arm64ClobberNativeFlags.native s flags)
  let jccResult := Arm64ProgramEntryJccExit.result (before ^^^ (values 63)) mark (Arm64ClobberNativeFlags.native s flags)
  have saved : jccLe.get Arm64ProgramFixture._result = some (.Vlong jccResult) :=
    Arm64ProgramEntryJccComplete.result_readback le before (values 63) mark (Arm64ClobberNativeFlags.native s flags)
  obtain ⟨jccCount,jcc⟩ := Arm64ProgramEntryJccComplete.execute packet frame le k hk ctxBlock ctxOffset mark
    ctxBelow ctx originalMark before prior s
  obtain ⟨cbzCount,cbz⟩ := execute packet jccLe k hk jccResult saved (Arm64ClobberNativeFlags.native s flags)
  refine ⟨temps jccLe jccResult (gprs 2) (Arm64ClobberNativeFlags.native s flags),_,jcc.trans cbz,?_,?_⟩
  · exact (ctx_preserved _ _ _ _).trans (Arm64ProgramEntryJccComplete.ctx_preserved _ _ _ _ _)
  · exact result_readback _ _ _ _ saved

end KProgFormal.ClightRefinement.Arm64ProgramEntryCbzComplete
