import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpOperands
import KProgFormal.ClightRefinement.Arm64CompareCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpStores

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage (Storage)
open Arm64ProgramEntryAllocation (world allocation)
open Arm64Compare.Stores (flagIndex condition value Effect)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_inline_cmp_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))
private def sourceParts : List CC.Stmt := by
  run_tac do
    let mut tail ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryCmpArithmetic.stores)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:3] do
      tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tail)
      unless tail.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual inline CMP local stores changed"
      rows := rows.push tail.getAppArgs[0]!
      tail := tail.getAppArgs[1]!
    rows := rows.push tail
    Lean.Elab.Tactic.closeMainGoal `actual_inline_cmp_stores
      (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList)
private def zCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[0]?).getD .Sskip))
private def nCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[1]?).getD .Sskip))
private def cCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[2]?).getD .Sskip))
private def vCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[3]?).getD .Sskip))
def code (i : Fin 4) : CC.Stmt := [zCode,nCode,cCode,vCode][i]

theorem source : Arm64ProgramEntryCmpArithmetic.stores =
    .Ssequence (code 0) (.Ssequence (code 1) (.Ssequence (code 2) (code 3))) := rfl

def localName (i : Fin 4) : CC.Ident :=
  [Arm64ProgramFixture.___a64_z,Arm64ProgramFixture.___a64_n,
   Arm64ProgramFixture.___a64_c,Arm64ProgramFixture.___a64_v][i]
private theorem four_cases : ∀ i : Fin 4, i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by decide +kernel
private def expression (i : Fin 4) : CC.Expr :=
  match code i with
  | .Sassign _ rhs => rhs
  | _ => .Econst_int 0 CC.tint
private theorem code_source (i : Fin 4) : code i =
    .Sassign (.Evar (localName i) CC.tuchar) (expression i) := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;> rfl
private theorem expression_type (i : Fin 4) : CC.typeof (expression i) = CC.tint := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;> rfl
private def zExpr : CC.Expr := by run_tac cachePart (← `(expression 0))
private def nExpr : CC.Expr := by run_tac cachePart (← `(expression 1))
private def cExpr : CC.Expr := by run_tac cachePart (← `(expression 2))
private def vExpr : CC.Expr := by run_tac cachePart (← `(expression 3))

def operands (le : CC.TempEnv) (lhs rhs result sign : BitVec 64) : Prop :=
  le.get Arm64ProgramFixture.___kprog_a64_sub_lhs = some (.Vlong lhs) ∧
  le.get Arm64ProgramFixture.___kprog_a64_sub_rhs = some (.Vlong rhs) ∧
  le.get Arm64ProgramFixture.___kprog_a64_sub_res = some (.Vlong result) ∧
  le.get Arm64ProgramFixture.___kprog_a64_sub_sign = some (.Vlong sign)

private theorem value_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (lhs rhs result sign : BitVec 64) (i : Fin 4) (inputs : operands le lhs rhs result sign) :
    CC.doEvalExpr world e le m (expression i) = some (value lhs rhs result sign i) := by
  obtain ⟨hl,hr,hs,hn⟩ := inputs
  rcases four_cases i with rfl|rfl|rfl|rfl
  · change CC.doEvalExpr world e le m zExpr = some (value lhs rhs result sign 0)
    simp only [zExpr,CC.doEvalExpr,hl,hr,hs,hn,CC.typeof]
    rfl
  · change CC.doEvalExpr world e le m nExpr = some (value lhs rhs result sign 1)
    simp only [nExpr,CC.doEvalExpr,hl,hr,hs,hn,CC.typeof]
    rfl
  · change CC.doEvalExpr world e le m cExpr = some (value lhs rhs result sign 2)
    simp only [cExpr,CC.doEvalExpr,hl,hr,hs,hn,CC.typeof]
    rfl
  · change CC.doEvalExpr world e le m vExpr = some (value lhs rhs result sign 3)
    simp only [vExpr,CC.doEvalExpr,hl,hr,hs,hn,CC.typeof]
    rfl

/-- The actual original allocation binds each source Evar to its corresponding
allocated byte cell, with source Z,N,C,V order retained. -/
theorem local_binding {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 4) :
    (allocation initial).1.get (localName i) = some ((storage.flags (flagIndex i)).block,CC.tuchar) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ (storage.flags (flagIndex i)).binding
  rcases four_cases i with rfl|rfl|rfl|rfl <;> exact actual

private theorem flag_cast (b : Bool) (m : CC.Mem) :
    CC.Cop.semCast (CC.Val.ofBool b) CC.tint CC.tuchar m = some (CC.Val.ofBool b) := by
  cases b <;> rfl

/-- Execute one true local assignment; no pointer read or temporary write is
inserted in this original source step. -/
theorem single {initial : CC.Mem} (le : CC.TempEnv) (before after : CC.Mem) (k : CC.Cont)
    (lhs rhs result sign : BitVec 64) (i : Fin 4) (block : CC.Block)
    (binding : (allocation initial).1.get (localName i) = some (block,CC.tuchar))
    (inputs : operands le lhs rhs result sign)
    (stored : CC.Mem.store .Mint8unsigned before block 0 (value lhs rhs result sign i) = some after) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile (code i) k (allocation initial).1 le before)
      CC.E0 (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  have evaluated := value_eval (allocation initial).1 le before lhs rhs result sign i inputs
  have cast := flag_cast (condition lhs rhs result sign i) before
  have assigned : CC.doAssignLoc world.genv_cenv CC.tuchar before block 0 .Full
      (value lhs rhs result sign i) = some after := by
    simp only [CC.doAssignLoc,CC.accessMode,CC.tuchar,CC.Mem.storev]
    exact stored
  dsimp only [value] at assigned
  have target_type : CC.typeof (.Evar (localName i) CC.tuchar) = CC.tuchar := rfl
  apply CC.doStep_sound
  rw [code_source]
  simp only [CC.doStep,CC.doEvalLvalue,CC.lvalOfVar,binding,evaluated,expression_type,
    target_type,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero,ite_true,eq_self,value,cast,assigned]

private theorem followed {initial : CC.Mem} {le : CC.TempEnv} {before after : CC.Mem} {k : CC.Cont}
    {s next : CC.Stmt} (inside : InternalState (.State Arm64ProgramFixture.f_arm64_execute_compile s (.Kseq next k) (allocation initial).1 le before))
    (step : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile s (.Kseq next k) (allocation initial).1 le before)
      CC.E0 (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq next k) (allocation initial).1 le after)) :
    InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence s next) k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile next k (allocation initial).1 le after) := by
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step inside step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

/-- Follow all four actual local assignments with the SAME derived four-store
memory effect. Exact original temps, environment and continuation remain. -/
theorem execute_effect {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs result sign : BitVec 64) (inputs : operands le lhs rhs result sign)
    (effect : Effect storage lhs rhs result sign after) :
    InternalRun world 10
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpArithmetic.stores k
        (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  obtain ⟨m1,m2,m3,s0,s1,s2,s3⟩ := effect.stores
  have z := followed (by rw [code_source]; trivial) (single le before m1 (.Kseq (.Ssequence (code 1) (.Ssequence (code 2) (code 3))) k)
    lhs rhs result sign 0 _ (local_binding storage 0) inputs s0)
  have n := followed (by rw [code_source]; trivial) (single le m1 m2 (.Kseq (.Ssequence (code 2) (code 3)) k)
    lhs rhs result sign 1 _ (local_binding storage 1) inputs s1)
  have c := followed (by rw [code_source]; trivial) (single le m2 m3 (.Kseq (code 3) k)
    lhs rhs result sign 2 _ (local_binding storage 2) inputs s2)
  have v : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (code 3) k (allocation initial).1 le m3)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) :=
    .step (by rw [code_source]; trivial) (single le m3 after k lhs rhs result sign 3 _
      (local_binding storage 3) inputs s3) (.refl _)
  rw [source]
  exact ((z.trans n).trans c).trans v

/-- Current allocation-derived permissions supply all store successes, reached
flag bytes and caller/access/frontier frames together with actual execution. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs result sign : BitVec 64) (inputs : operands le lhs rhs result sign) :
    ∃ after, Effect storage lhs rhs result sign after ∧
      InternalRun world 10
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpArithmetic.stores k
          (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 le after) := by
  obtain ⟨after,effect⟩ := Arm64Compare.Stores.write_writable storage lhs rhs result sign
    (Arm64Compare.Stores.writable_of_storage storage)
  exact ⟨after,effect,execute_effect storage le k lhs rhs result sign inputs effect⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpStores
