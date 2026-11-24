import KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoves

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMovePath

open Arm64ProgramEntryAllocation (world allocation)
open Arm64MovImmediate

private def markSet : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryPointerWrites.afterFirst)) none
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "ordinary MOV source outer sequence changed"
    let first ← Lean.Meta.withTransparency .all (Lean.Meta.whnf outer.getAppArgs[0]!)
    unless first.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "ordinary MOV mark sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_ordinary_mov_mark first.getAppArgs[0]!

private theorem source : Arm64ProgramEntryPointerWrites.afterFirst =
    .Ssequence (.Ssequence markSet (Arm64ProgramEntryOrdinaryMoves.call 0)) Arm64ProgramEntryOrdinaryMoves.afterFirst := rfl
private theorem mark_source : markSet =
    .Sset Arm64ProgramFixture._t'163 (Arm64ProgramEntryBody.contextExpr 0) := rfl

def callCont (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (mark : BitVec 32) : CC.Cont :=
  .Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1
    (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) (.Kseq Arm64ProgramEntryOrdinaryMoves.afterFirst k)

/-- Execute the genuine ctx.mark field load, full ordinary MOV call and its
original return, retaining every source store and actual local release. -/
theorem first {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ m.nextblock.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (block : CC.Block) (ofs : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr block ofs))
    (read : CC.Mem.loadv .Mint32 m
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark)) :
    ∃ written after, OrdinaryCall.Result storage 1 (mark.setWidth 64) addresses origins s
        (callCont initial le k mark) written after ∧
      InternalRun world 210
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterFirst k
          (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
          (allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) after) := by
  have field := Arm64ProgramEntryBody.context_read (allocation initial).1 le m block ofs 0 mark ctx read
  have assign : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile markSet
        (.Kseq (Arm64ProgramEntryOrdinaryMoves.call 0) (.Kseq Arm64ProgramEntryOrdinaryMoves.afterFirst k))
        (allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip
        (.Kseq (Arm64ProgramEntryOrdinaryMoves.call 0) (.Kseq Arm64ProgramEntryOrdinaryMoves.afterFirst k))
        (allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) m) := by
    rw [mark_source]
    apply CC.doStep_sound
    simp only [CC.doStep,field,Arm64ProgramEntryOrdinaryMoves.markTemps]
  have enter : InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterFirst k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryOrdinaryMoves.call 0)
        (.Kseq Arm64ProgramEntryOrdinaryMoves.afterFirst k) (allocation initial).1
        (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) m) := by
    rw [source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial assign ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  obtain ⟨written,after,result,run⟩ := Arm64ProgramEntryOrdinaryMoves.invoke storage bound 0 addresses origins s represented
    (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) (.Kseq Arm64ProgramEntryOrdinaryMoves.afterFirst k) mark
    (fun _ => CC.PTree.gss _ _ _)
  have leave : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq Arm64ProgramEntryOrdinaryMoves.afterFirst k)
        (allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) after)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterFirst k
        (allocation initial).1 (Arm64ProgramEntryOrdinaryMoves.markTemps le mark) after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨written,after,result,(enter.trans run).trans leave⟩

def constantSite (third : Bool) : Fin 3 := if third then 2 else 1
def beforeConstant (third : Bool) : CC.Stmt :=
  if third then Arm64ProgramEntryPointerWrites.afterThird else Arm64ProgramEntryOrdinaryMoves.afterFirst
def afterConstant (third : Bool) : CC.Stmt :=
  if third then Arm64ProgramEntryOrdinaryMoves.afterThird else Arm64ProgramEntryOrdinaryMoves.afterSecond

private theorem constant_source (third : Bool) : beforeConstant third =
    .Ssequence (Arm64ProgramEntryOrdinaryMoves.call (constantSite third)) (afterConstant third) := by
  cases third
  · exact Arm64ProgramEntryOrdinaryMoves.second_source
  · exact Arm64ProgramEntryOrdinaryMoves.third_source
private theorem constant_destination : ∀ third,
    Arm64ProgramEntryOrdinaryMoves.destination (constantSite third) = 2 := by decide +kernel
private theorem constant_value : ∀ third,
    Arm64ProgramEntryOrdinaryMoves.value (constantSite third) (0#32) = 16#64 := by decide +kernel

/-- Both actual constant16 MOV sites execute independently at their original
positions, retaining the memset/memcpy continuations in the source. -/
theorem constant {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ m.nextblock.toNat)
    (third : Bool) (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written after, OrdinaryCall.Result storage 2 (16#64) addresses origins s
        (.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le
          (.Kseq (afterConstant third) k)) written after ∧
      InternalRun world 207
        (.State Arm64ProgramFixture.f_arm64_execute_compile (beforeConstant third) k (allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (afterConstant third) k (allocation initial).1 le after) := by
  have nonzero : constantSite third ≠ 0 := by cases third <;> decide +kernel
  obtain ⟨written,after,result,run⟩ := Arm64ProgramEntryOrdinaryMoves.invoke storage bound (constantSite third)
    addresses origins s represented le (.Kseq (afterConstant third) k) (0#32) (fun same => False.elim (nonzero same))
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (beforeConstant third) k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryOrdinaryMoves.call (constantSite third))
        (.Kseq (afterConstant third) k) (allocation initial).1 le m) := by
    rw [constant_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have leave : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq (afterConstant third) k) (allocation initial).1 le after)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (afterConstant third) k (allocation initial).1 le after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  refine ⟨written,after,?_,(enter.trans run).trans leave⟩
  simpa only [constant_destination,constant_value] using result

end KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMovePath
