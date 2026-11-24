import KProgFormal.ClightRefinement.X86ProducerGprStore

namespace KProgFormal.ClightRefinement.X86ProducerGprSites

structure Site where
  whole : CC.Stmt
  condition : CC.Expr
  zero : CC.Stmt
  call : CC.Stmt
  saved : CC.Stmt
  destination : CC.Stmt
  tag : CC.Stmt
  following : CC.Stmt
  resultName : CC.Ident
  savedName : CC.Ident

private def sites : List Site := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(X86ProducerGhostSource.beforeProvider)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:16] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original GPR initializer sequence changed"
      let setup ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      let tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[1]!)
      unless setup.isAppOfArity ``CC.Stmt.Ssequence 2 && tail.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original GPR value/tag pair changed"
      let branch ← Lean.Meta.withTransparency .all (Lean.Meta.whnf setup.getAppArgs[0]!)
      unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 do throwError "original GPR source decision changed"
      let route ← Lean.Meta.withTransparency .all (Lean.Meta.whnf branch.getAppArgs[2]!)
      unless route.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original GPR provider route changed"
      let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf route.getAppArgs[0]!)
      let saved ← Lean.Meta.withTransparency .all (Lean.Meta.whnf route.getAppArgs[1]!)
      unless call.isAppOfArity ``CC.Stmt.Scall 3 && saved.isAppOfArity ``CC.Stmt.Sset 2 do
        throwError "original GPR provider return changed"
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
      unless result.isAppOfArity ``Option.some 2 do throwError "original GPR provider result missing"
      rows := rows.push (← Lean.Meta.mkAppM ``Site.mk #[body,branch.getAppArgs[0]!,branch.getAppArgs[1]!,
        route.getAppArgs[0]!,route.getAppArgs[1]!,setup.getAppArgs[1]!,tail.getAppArgs[0]!,tail.getAppArgs[1]!,
        result.getAppArgs[1]!,saved.getAppArgs[0]!])
      body := tail.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `original_x86_gpr_sites
      (← Lean.Meta.mkListLit (Lean.mkConst ``Site) rows.toList)

def site (i : Fin 16) : Site := sites[i.val]'(by have size : sites.length = 16 := rfl; rw [size]; exact i.isLt)
def valueRow (i : Fin 16) : Fin 32 := ⟨2 * i.val, by omega⟩
def tagRow (i : Fin 16) : Fin 32 := ⟨2 * i.val + 1, by omega⟩

private theorem cases16 : ∀ i : Fin 16, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 ∨ i = 12 ∨ i = 13 ∨ i = 14 ∨ i = 15 := by decide +kernel

/-- Every site retains its original condition, both branches, value and tag
assignments and successor. The RSP branch is included, not silently skipped. -/
theorem source_route (i : Fin 16) : (site i).whole =
    .Ssequence (.Ssequence (.Sifthenelse (site i).condition (site i).zero
      (.Ssequence (site i).call (site i).saved)) (site i).destination)
      (.Ssequence (site i).tag (site i).following) := by
  rcases cases16 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

theorem source_stores (i : Fin 16) :
    (site i).destination = X86ProducerGprStore.assignment (valueRow i) (site i).savedName ∧
    (site i).tag = X86ProducerGprStore.assignment (tagRow i) (site i).savedName := by
  rcases cases16 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals constructor <;> rfl

theorem source_call (i : Fin 16) : (site i).call = .Scall (some (site i).resultName)
    (.Evar X86_program_profile_bpf._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint] := by
  rcases cases16 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

theorem source_saved (i : Fin 16) : (site i).saved = .Sset (site i).savedName
    (.Ecast (.Ecast (.Etempvar (site i).resultName CC.tulong) (CC.tptr CC.tvoid)) (CC.tptr CC.tvoid)) := by
  rcases cases16 i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals rfl

theorem source_first : (site 0).whole = X86ProducerGhostSource.beforeProvider ∧
    (site 1).whole = X86ProducerGprAddress.afterRax := by constructor <;> rfl

end KProgFormal.ClightRefinement.X86ProducerGprSites
