import KProgFormal.ClightRefinement.Arm64ProgramEntryFmovCall
import KProgFormal.ClightRefinement.Arm64FmovDestination

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Fmov.DestinationSite

private structure Pieces where
  branch : CC.Stmt
  indexPrefix : CC.Stmt
  guard : CC.Expr
  badIndex : CC.Stmt
  body : CC.Stmt
  site : CC.Stmt
  call : CC.Stmt
  choice : CC.Stmt
  vectorStores : CC.Stmt
  scalarStore : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "actual FMOV destination constructor changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Nop.handler.fn_body)) none) ``CC.Stmt.Sloop 2
    let outerBody ← peel root[0]! ``CC.Stmt.Ssequence 2
    let wanted ← Lean.Elab.Term.elabTerm (← `(CC.Expr.Ebinop CC.Binop.Oeq
      (CC.Expr.Etempvar Arm64Program._op CC.tuint) (CC.Expr.Econst_int (35#32) CC.tuint) CC.tint)) none
    let mut rest := outerBody[1]!
    let mut found := false
    for i in [:80] do
      let mut node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      if node.isAppOfArity ``CC.Stmt.Ssequence 2 then
        node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless node.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "actual FMOV dispatch changed at gate {i}"
      let args := node.getAppArgs
      if ← Lean.Meta.withTransparency .all (Lean.Meta.isDefEq args[0]! wanted) then
        let branch ← peel args[1]! ``CC.Stmt.Ssequence 2
        let guard ← peel branch[1]! ``CC.Stmt.Sifthenelse 3
        let middle ← peel guard[2]! ``CC.Stmt.Ssequence 2
        let loop ← peel middle[0]! ``CC.Stmt.Sloop 2
        let site ← peel middle[1]! ``CC.Stmt.Ssequence 2
        let choice ← peel site[1]! ``CC.Stmt.Sifthenelse 3
        Lean.Elab.Tactic.closeMainGoal `actual_fmov_destination
          (← Lean.Meta.mkAppM ``Pieces.mk #[args[1]!,branch[0]!,guard[0]!,guard[1]!,loop[0]!,
            middle[1]!,site[0]!,site[1]!,choice[1]!,choice[2]!])
        found := true
        break
      rest := args[2]!
    unless found do throwError "original FMOV gate absent"

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_fmov_destination_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def branch : CC.Stmt := by run_tac cachePart (← `(pieces.branch))
def body : CC.Stmt := by run_tac cachePart (← `(pieces.body))
private def indexPrefix : CC.Stmt := by run_tac cachePart (← `(pieces.indexPrefix))
private def guard : CC.Expr := by run_tac cachePart (← `(pieces.guard))
private def badIndex : CC.Stmt := by run_tac cachePart (← `(pieces.badIndex))
def site : CC.Stmt := by run_tac cachePart (← `(pieces.site))
private def call : CC.Stmt := by run_tac cachePart (← `(pieces.call))
private def choice : CC.Stmt := by run_tac cachePart (← `(pieces.choice))
def vectorStores : CC.Stmt := by run_tac cachePart (← `(pieces.vectorStores))
private def scalarStore : CC.Stmt := by run_tac cachePart (← `(pieces.scalarStore))

/-- Original index selection/guard, numeric loop and real destination call. -/
theorem branch_source : branch = .Ssequence indexPrefix
    (.Sifthenelse guard badIndex (.Ssequence (.Sloop body .Sbreak) site)) := rfl

theorem site_source : site = .Ssequence call choice := rfl
private theorem call_source : call = .Scall (some Arm64Program._t'2789)
    (.Evar Arm64Program._kprog_arm64_fmov_dest (.Tfunction [CC.tulong] CC.tulong CC.cc_default))
    [.Etempvar Arm64Program._aux CC.tuint] := rfl
private theorem choice_source : choice = .Sifthenelse (.Etempvar Arm64Program._t'2789 CC.tulong)
    vectorStores scalarStore := rfl

private theorem binding : ∃ block,
    CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_fmov_dest = some block ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryLinked.ge.genv_genv block = some (.Internal Destination.handler) := by
  refine ⟨(CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_fmov_dest).get
    (by decide +kernel),?_,?_⟩
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'2789) Arm64Nop.handler e le (.Kseq choice k)

def temps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program._t'2789 (.Vlong 1)

/-- Invoke the linked original Numeric helper with the real uint-to-long cast. -/
theorem enter (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_fmov_dest = none)
    (aux : le.get Arm64Program._aux = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 2 (.State Arm64Nop.handler site k e le m)
      (.Callstate (.Internal Destination.handler) [.Vlong 0] (callCont k e le) m) := by
  obtain ⟨block,symbol,function⟩ := binding
  apply InternalRun.step (mid := .State Arm64Nop.handler call (.Kseq choice k) e le m)
  · trivial
  · exact CC.doStep_sound _ _ _ _ (by simp only [CC.doStep,site_source])
  apply InternalRun.step (mid := .Callstate (.Internal Destination.handler) [.Vlong 0] (callCont k e le) m)
  · trivial
  · rw [call_source]
    apply CC.Step.call (tyargs := [CC.tulong]) (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr block 0)
    · rfl
    · apply CC.doEvalExpr_sound
      simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,CC.doDerefLoc,CC.accessMode,
        CC.typeof,unshadowed,symbol,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero]
    · apply CC.doEvalExprlist_sound
      simp +decide [CC.doEvalExprlist,CC.doEvalExpr,aux,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.Cop.castIntLong,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tuint,CC.tulong,CC.typeof] <;> rfl
    · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
        CC.Integers.MI.eq,CC.Integers.MI.zero] using function
    · rfl
  exact .refl _

/-- The actual helper return and original destination branch select real vector stores. -/
theorem returned (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.Returnstate (.Vlong 1) (callCont k e le) m)
      (.State Arm64Nop.handler vectorStores k e (temps le) m) := by
  apply InternalRun.step (mid := .State Arm64Nop.handler .Sskip (.Kseq choice k) e (temps le) m)
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step (mid := .State Arm64Nop.handler choice k e (temps le) m)
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  apply InternalRun.step (mid := .State Arm64Nop.handler vectorStores k e (temps le) m)
  · trivial
  · apply CC.doStep_sound
    simp +decide [CC.doStep,choice_source,temps,CC.PTree.gss,CC.doEvalExpr,CC.typeof,
      CC.Cop.boolVal,CC.Cop.classifyBool,CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,
      CC.Integers.Int64.eq,CC.Integers.MI.eq,CC.Integers.Int64.zero,CC.Integers.MI.zero]
  exact .refl _

/-- Run the true destination helper and branch without supplying its result. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_fmov_dest = none)
    (aux : le.get Arm64Program._aux = some (.Vint 0)) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count (.State Arm64Nop.handler site k e le m)
      (.State Arm64Nop.handler vectorStores k e (temps le) m) := by
  have first := enter e le m k unshadowed aux
  obtain ⟨count,callee⟩ := Destination.d_from_x Arm64ProgramEntryLinked.ge m (callCont k e le)
  have last := returned Arm64ProgramEntryLinked.ge e le m k
  exact ⟨_,by simpa only [CC.callCont,callCont] using (first.trans callee).trans last⟩

end KProgFormal.ClightRefinement.Arm64Fmov.DestinationSite
