import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpModifiedCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpRhsCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpArithmetic

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpOperands
open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryCmpBranch

def rhsCont (k : CC.Cont) : CC.Cont := .Kseq saveRhs (.Kseq afterOperands (loopCont k))
def arithmeticCont (k : CC.Cont) : CC.Cont := .Kseq choice (loopCont k)
def returnedTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  Arm64ProgramEntryCmpRhsCall.temps (Arm64ProgramEntryCmpModifiedCall.temps le value) value
def operandTemps (le : CC.TempEnv) (lhs rhs : BitVec 64) : CC.TempEnv :=
  (returnedTemps (temps le lhs) rhs).set Arm64ProgramFixture.___a64_cmp_rhs (.Vlong rhs)
private theorem saved_rhs_source : saveRhs = .Sset Arm64ProgramFixture.___a64_cmp_rhs
    (.Etempvar Arm64ProgramFixture._t'145 CC.tulong) := rfl

set_option hygiene false in
private theorem resume_modified {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (modifiedCont k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile flagRhsCall (rhsCont k) (allocation initial).1 le m) := by
  apply InternalRun.step
  · trivial
  · apply CC.doStep_sound
    rfl
  · exact .refl _

set_option hygiene false in
private theorem resume_rhs {initial : CC.Mem} (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64) :
    InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (rhsCont k) (allocation initial).1
        (Arm64ProgramEntryCmpRhsCall.temps le value) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile arithmetic (arithmeticCont k) (allocation initial).1
        ((Arm64ProgramEntryCmpRhsCall.temps le value).set Arm64ProgramFixture.___a64_cmp_rhs (.Vlong value)) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [rhsCont,arithmeticCont,after_source,
        saved_rhs_source,CC.doStep,CC.doEvalExpr,Arm64ProgramEntryCmpRhsCall.temps,CC.PTree.gss] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The same completed memcpy Packet supplies actual X3/X4 scalar values to
all original CMP calls and reaches the actual inline arithmetic on the same heap. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
        (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile arithmetic (arithmeticCont k) (allocation initial).1
        (operandTemps le (gprs 2) (gprs 3)) m) := by
  obtain ⟨prefixCount,entered⟩ := Arm64ProgramEntryCmpBranch.execute packet le k
  have width : (temps le (gprs 2)).get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8) := by
    dsimp only [temps,widthTemps]
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
  have observed := packet.registers (3 : Fin 18)
  change Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 4 = some (.Vlong (gprs 3),.Vint 0) at observed
  obtain ⟨modifiedCount,modified⟩ := Arm64ProgramEntryCmpModifiedCall.invoke entry (temps le (gprs 2)) m
    (modifiedCont k) (gprs 3) width packet.memory.storage observed
  have resumed := resume_modified (initial := initial) (Arm64ProgramEntryCmpModifiedCall.temps (temps le (gprs 2)) (gprs 3)) m k
  obtain ⟨rhsCount,rhs⟩ := Arm64ProgramEntryCmpRhsCall.invoke (initial := initial)
    (Arm64ProgramEntryCmpModifiedCall.temps (temps le (gprs 2)) (gprs 3)) m (rhsCont k) (gprs 3)
    (by exact CC.PTree.gss _ _ _)
  have finished := resume_rhs (initial := initial) (Arm64ProgramEntryCmpModifiedCall.temps (temps le (gprs 2)) (gprs 3)) m k (gprs 3)
  exact ⟨_,((((entered.trans modified).trans resumed).trans rhs).trans finished)⟩

/-- Explicit actual source observations at arithmetic entry. -/
theorem observations (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    (operandTemps le lhs rhs).get Arm64ProgramFixture.___a64_cmp_lhs = some (.Vlong lhs) ∧
    (operandTemps le lhs rhs).get Arm64ProgramFixture.___a64_cmp_rhs = some (.Vlong rhs) ∧
    (operandTemps le lhs rhs).get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8) := by
  dsimp only [operandTemps,returnedTemps,temps,widthTemps,
    Arm64ProgramEntryCmpModifiedCall.temps,Arm64ProgramEntryCmpRhsCall.temps]
  refine ⟨?_,?_,?_⟩
  all_goals repeat first
    | rw [CC.PTree.gss]
    | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
  all_goals rfl
/-- Join all original operand calls and inline arithmetic on the same current
memcpy Packet, reaching all four real stores with the imported SUB result. -/
theorem to_stores {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
        (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpArithmetic.stores
        (Arm64ProgramEntryCmpArithmetic.continuation (arithmeticCont k)) (allocation initial).1
        (Arm64ProgramEntryCmpArithmetic.temps (operandTemps le (gprs 2) (gprs 3)) (gprs 2) (gprs 3) false) m) := by
  obtain ⟨count,read⟩ := execute packet le k
  have values := observations le (gprs 2) (gprs 3)
  have math := Arm64ProgramEntryCmpArithmetic.execute world (allocation initial).1
    (operandTemps le (gprs 2) (gprs 3)) m (arithmeticCont k) (gprs 2) (gprs 3) false
    values.2.2 values.1 values.2.1
  exact ⟨_,read.trans math⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpOperands
