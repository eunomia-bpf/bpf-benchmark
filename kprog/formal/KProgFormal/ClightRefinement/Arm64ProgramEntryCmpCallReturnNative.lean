import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBgtNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkReturnFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpCallReturnNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Same actually fetched CMP/B.GT state retains its original native error. -/
theorem error (s : Reference.AArch64.State) (offset : BitVec 19) :
    read_err (Arm64ProgramEntryCmpBgtNative.after s offset).machine = read_err s.machine := by
  have branch : read_err (Arm64ProgramEntryCmpBgtNative.after s offset).machine =
      read_err (Arm64ProgramEntryCmpNative.after s).machine :=
    Arm64ProgramEntryJccNative.field _ (12#4) offset .ERR (by decide)
  exact branch.trans (Arm64ProgramEntryCmpNative.error s)

/-- The actual native compare operands and imported flags discharge the
caller's incoming flag-value contract, using the same source store values. -/
theorem values (s : Reference.AArch64.State) (offset : BitVec 19) (lhs rhs : BitVec 64)
    (left : Reference.AArch64.gpr s 3 = lhs) (right : Reference.AArch64.gpr s 4 = rhs) (i : Fin 4) :
    Arm64ProducerEntryView.flagValues (Arm64ProgramEntryCmpBgtNative.after s offset) i =
      .Vint (Arm64Producer.flagWord (Arm64ProgramEntryCmpFlags.values lhs rhs i)) := by
  have flag (which : PFlag) : read_flag which (Arm64ProgramEntryCmpBgtNative.after s offset).machine =
      read_flag which (Arm64ProgramEntryCmpNative.after s).machine :=
    Arm64ProgramEntryJccNative.field _ (12#4) offset (.FLAG which) (by intro impossible; cases impossible)
  have retained : Arm64ProducerEntryView.flagValues (Arm64ProgramEntryCmpBgtNative.after s offset) i =
      Arm64ProducerEntryView.flagValues (Arm64ProgramEntryCmpNative.after s) i := by
    simp only [Arm64ProducerEntryView.flagValues,flag]
  have actual := Arm64ProgramEntryCmpFlags.native_values (Arm64Nop.atCursor (read_pc s.machine + 4#64) s) lhs rhs i
  rw [←Arm64ProgramEntryCmpNative.source_flags s lhs rhs left right] at actual
  exact retained.trans actual

/-- Original complete CMP/GT and CALL/RET_TO execute on one actual packet:
four CMP flag stores, three CALL stores and the repeated LR store remain.
All four genuine fetched native steps use the same derived intermediate state.
The source false-path XOR8 and actual labels remain in the source run; full
native output-observer/global code-map correspondence continues separately. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (saved : BitVec 64) (savedResult : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (s : Reference.AArch64.State)
    (left : Reference.AArch64.gpr s 3 = gprs 2) (right : Reference.AArch64.gpr s 4 = gprs 3)
    (noError : read_err s.machine = .None)
    (cmpFetched : fetch_inst (read_pc s.machine) s.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
    (branch : Reference.AArch64.Instruction) (conditionOffset : BitVec 19)
    (branchDecoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) conditionOffset)))
    (branchFetched : fetch_inst (read_pc (Arm64ProgramEntryCmpNative.after s).machine)
      (Arm64ProgramEntryCmpNative.after s).machine = some branch.encoding)
    (callOffset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission (Arm64ProgramEntryCmpBgtNative.after s conditionOffset) callOffset) :
    let callState := Arm64ProgramEntryCmpBgtNative.after s conditionOffset
    let finalNative := Arm64ProgramEntryLinkReturnNative.after callState callOffset
    ∃ cmpHeap, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue cmpHeap,
      Arm64Compare.Stores.Effect prior.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) cmpHeap ∧
      ∃ linked, ∃ result : Arm64ProgramEntryLinkComplete.Result updated lr linked,
      ∃ reached, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr linked reached,
      ∃ current : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue reached,
      ∃ count, InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
          (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
          (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1
          (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps
            (Arm64ProgramEntryCmpComplete.temps le saved (gprs 2) (gprs 3) s))) reached) ∧
      Reference.AArch64.step s = ⟨Arm64ProgramEntryCmpNative.after s,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryCmpNative.after s) = ⟨callState,[],none⟩ ∧
      Reference.AArch64.step callState = ⟨Arm64ProgramEntryLinkNative.after callState callOffset,[],none⟩ ∧
      Reference.AArch64.step (Arm64ProgramEntryLinkNative.after callState callOffset) = ⟨finalNative,[],none⟩ ∧
      Arm64ProgramEntryLinkReturnNative.Observation reached (.Vptr entry.block 0) lr.block callState finalNative admitted.continuation ∧
      Arm64Nop.FlagsRepresent reached.nextblock reached (.Vptr entry.block 0) finalNative ∧
      FrameBelow initial.nextblock before reached ∧
      (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps
        (Arm64ProgramEntryCmpComplete.temps le saved (gprs 2) (gprs 3) s))).get Arm64ProgramFixture._result =
          some (.Vlong (if ConditionHolds (12#4) (Arm64ProgramEntryCmpNative.after s).machine then saved else saved ^^^ 8#64)) ∧
      (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps
        (Arm64ProgramEntryCmpComplete.temps le saved (gprs 2) (gprs 3) s))).get Arm64ProgramFixture._ctx =
          le.get Arm64ProgramFixture._ctx := by
  dsimp only
  obtain ⟨cmpHeap,updated,cmpEffect,cmpCount,cmpRun,cmpNative,bgtNative,_,cmpResult,cmpCtx⟩ :=
    Arm64ProgramEntryCmpBgtNative.complete prior le k hk saved savedResult s left right noError cmpFetched
      branch conditionOffset branchDecoded branchFetched
  obtain ⟨linked,result,reached,effect,current,run,callNative,returnNative,observation,represented,caller,resultTemp,ctxTemp⟩ :=
    Arm64ProgramEntryLinkReturnFrame.complete updated lr (Arm64ProgramEntryCmpComplete.temps le saved (gprs 2) (gprs 3) s)
      k hk (Arm64ProgramEntryCmpBgtNative.after s conditionOffset) callOffset admitted
      ((error s conditionOffset).trans noError) (values s conditionOffset (gprs 2) (gprs 3) left right)
  exact ⟨cmpHeap,updated,cmpEffect,linked,result,reached,effect,current,_,cmpRun.trans run,
    cmpNative,bgtNative,callNative,returnNative,observation,represented,cmpEffect.caller.trans caller,
    resultTemp.trans cmpResult,ctxTemp.trans cmpCtx⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpCallReturnNative
