import KProgFormal.ClightRefinement.Arm64CntReduction
import KProgFormal.ClightRefinement.Arm64Nop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.ReductionSite

private structure Calls where
  high : CC.Stmt
  low : CC.Stmt

private def calls : Calls := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original CNT call-site constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let body ← peel root[0]! ``CC.Stmt.Ssequence 2
    let mut rest := body[1]!
    let mut branch := rest
    for _ in [:38] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      if node.isAppOfArity ``CC.Stmt.Ssequence 2 then
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original CNT dispatch changed"
      branch := node.getAppArgs[1]!
      rest := node.getAppArgs[2]!
    let selectedBranch ← peel branch ``CC.Stmt.Ssequence 2
    let high ← peel selectedBranch[0]! ``CC.Stmt.Ssequence 2
    let choice ← peel high[0]! ``CC.Stmt.Sifthenelse 3
    let highBody ← peel choice[1]! ``CC.Stmt.Ssequence 2
    let highRead ← peel highBody[0]! ``CC.Stmt.Ssequence 2
    let highCall ← peel highRead[1]! ``CC.Stmt.Ssequence 2
    let low ← peel selectedBranch[1]! ``CC.Stmt.Ssequence 2
    let lowBody ← peel low[0]! ``CC.Stmt.Ssequence 2
    let lowRead ← peel lowBody[0]! ``CC.Stmt.Ssequence 2
    let lowCall ← peel lowRead[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_cnt_call_sites
      (← Lean.Meta.mkAppM ``Calls.mk #[highCall[1]!,lowCall[1]!])

def site (upper : Bool) : CC.Stmt := if upper then calls.high else calls.low
def inputKey (upper : Bool) : CC.Ident := if upper then Arm64Program._t'2837 else Arm64Program._t'2835
def resultKey (upper : Bool) : CC.Ident := if upper then Arm64Program._t'2791 else Arm64Program._t'2792

theorem source (upper : Bool) : site upper =
    .Scall (some (resultKey upper))
      (.Evar Arm64Program._kprog_arm64_reduction (.Tfunction [CC.tulong,CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._op CC.tuint,.Etempvar (inputKey upper) CC.tulong] := by
  cases upper <;> rfl

private theorem binding : ∃ block,
    CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_reduction = some block ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryLinked.ge.genv_genv block = some (.Internal Reduction.handler) := by
  refine ⟨(CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_reduction).get
    (by decide +kernel),?_,?_⟩
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem call_step (world : CC.CGenv) (block : CC.Block)
    (symbol : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_reduction = some block)
    (function : CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Reduction.handler))
    (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (word : le.get (inputKey upper) = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler (site upper) k e le m) CC.E0
      (.Callstate (.Internal Reduction.handler) [.Vlong (36#64),.Vlong value]
        (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k) m) := by
  rw [source]
  apply CC.Step.call (vf := .Vptr block 0) (tyargs := [CC.tulong,CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,global,symbol,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,op,word,CC.Cop.semCast,
      CC.Cop.classifyCast,CC.Cop.castIntLong,CC.typeof,CC.typeconv,
      CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong]
    rfl
  · change CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Reduction.handler)
    exact function
  · rfl

/-- Both original high/low call sites execute the actual linked C reduction
and return its packed word to the original caller temporary. -/
theorem execute (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (value : BitVec 64) (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (word : le.get (inputKey upper) = some (.Vlong value)) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler (site upper) k e le m)
      (.State Arm64Nop.handler .Sskip k e (le.set (resultKey upper) (.Vlong (Reduction.packed value))) m) := by
  obtain ⟨block,symbol,function⟩ := binding
  have enter : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler (site upper) k e le m)
      (.Callstate (.Internal Reduction.handler) [.Vlong (36#64),.Vlong value]
        (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k) m) :=
    .step (by rw [source]; trivial)
      (call_step _ block symbol function upper e le m k value global op word) (.refl _)
  obtain ⟨count,run⟩ := Reduction.execute value (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k) m
  have leave : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate (.Vlong (Reduction.packed value))
        (CC.callCont (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k)) m)
      (.State Arm64Nop.handler .Sskip k e (le.set (resultKey upper) (.Vlong (Reduction.packed value))) m) := by
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    exact .refl _
  exact ⟨_,(enter.trans run).trans leave⟩

theorem retained (upper : Bool) (le : CC.TempEnv) (value : CC.Val) (id : CC.Ident)
    (different : id ≠ resultKey upper) :
    (le.set (resultKey upper) value).get id = le.get id :=
  CC.PTree.gso _ _ _ _ (Ne.symm different)

end KProgFormal.ClightRefinement.Arm64Cnt.ReductionSite
