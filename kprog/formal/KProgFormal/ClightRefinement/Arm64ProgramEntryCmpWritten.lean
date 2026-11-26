import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpWritten
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

def temps (le : CC.TempEnv) (lhs rhs : BitVec 64) : CC.TempEnv :=
  Arm64ProgramEntryCmpArithmetic.temps (Arm64ProgramEntryCmpOperands.operandTemps le lhs rhs) lhs rhs false

set_option hygiene false in
/-- True arithmetic-loop exit and original sequence resume reach the signed
choice source; every memory effect was already performed by the real stores. -/
theorem resume {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip
        (Arm64ProgramEntryCmpArithmetic.continuation (Arm64ProgramEntryCmpOperands.arithmeticCont k))
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.choice
        (Arm64ProgramEntryCmpBranch.loopCont k) (allocation initial).1 le m) := by
  run_tac do
    for _ in [:3] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,
        Arm64ProgramEntryCmpArithmetic.continuation,Arm64ProgramEntryCmpOperands.arithmeticCont] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- One real CMP invocation uses the SAME completed memcpy Packet throughout
all original calls, arithmetic, four local writes and loop exit. Its reached
packet has the actual imported subtraction flags on the actual reached heap. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {oldFlags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs oldFlags vectors cell flagValue before)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue after,
      Arm64Compare.Stores.Effect prior.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) after ∧
      ∃ count, InternalRun world count
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
          (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpBranch.choice
          (Arm64ProgramEntryCmpBranch.loopCont k) (allocation initial).1 (temps le (gprs 2) (gprs 3)) after) := by
  obtain ⟨prefixCount,prefixRun⟩ := Arm64ProgramEntryCmpOperands.to_stores prior le k
  have values := Arm64ProgramEntryCmpArithmetic.values
    (Arm64ProgramEntryCmpOperands.operandTemps le (gprs 2) (gprs 3)) (gprs 2) (gprs 3) false
  have inputs : Arm64ProgramEntryCmpStores.operands (temps le (gprs 2) (gprs 3))
      (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
      (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
      (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
      (Arm64ProgramEntryCmpArithmetic.sign false) :=
    ⟨values.2.2.1,values.2.2.2.1,values.2.2.2.2,values.2.1⟩
  obtain ⟨after,effect,stores⟩ := Arm64ProgramEntryCmpStores.execute prior.memory.storage
    (temps le (gprs 2) (gprs 3))
    (Arm64ProgramEntryCmpArithmetic.continuation (Arm64ProgramEntryCmpOperands.arithmeticCont k))
    (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
    (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
    (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
    (Arm64ProgramEntryCmpArithmetic.sign false) inputs
  exact ⟨after,Arm64ProgramEntryCmpFlags.packet prior (gprs 2) (gprs 3) effect,effect,
    _,(prefixRun.trans stores).trans (resume (temps le (gprs 2) (gprs 3)) after k)⟩

/-- All arithmetic/operand temporaries keep the genuine earlier result word. -/
theorem result_readback (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    (temps le lhs rhs).get Arm64ProgramFixture._result = le.get Arm64ProgramFixture._result := by
  dsimp only [temps,Arm64ProgramEntryCmpArithmetic.temps,Arm64ProgramEntryCmpArithmetic.readyTemps,
    Arm64ProgramEntryCmpOperands.operandTemps,Arm64ProgramEntryCmpOperands.returnedTemps,
    Arm64ProgramEntryCmpBranch.temps,Arm64ProgramEntryCmpBranch.widthTemps,
    Arm64ProgramEntryCmpModifiedCall.temps,Arm64ProgramEntryCmpRhsCall.temps]
  repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- The actual width8 signed branch reads the same two current operands. -/
theorem branch_reads (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    (temps le lhs rhs).get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs) ∧
    (temps le lhs rhs).get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs) ∧
    (temps le lhs rhs).get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8) := by
  have prior := Arm64ProgramEntryCmpOperands.observations le lhs rhs
  dsimp only [temps,Arm64ProgramEntryCmpArithmetic.temps,Arm64ProgramEntryCmpArithmetic.readyTemps]
  refine ⟨?_,?_,?_⟩
  all_goals repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
  · exact prior.1
  · exact prior.2.1
  · exact prior.2.2

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpWritten
