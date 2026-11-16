import KProgFormal.ClightRefinement.Arm64ProducerInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

/-- Names and suffix of one actual exported register declaration. -/
structure RegisterDeclaration where
  index : CC.Integers.Int
  word : CC.Ident
  tag : CC.Ident
  resultTemp : CC.Ident
  inputTemp : CC.Ident
  rest : CC.Stmt

def RegisterDeclaration.setValue (d : RegisterDeclaration) : CC.Stmt :=
  .Sset d.resultTemp (.Ecast (.Etempvar d.inputTemp CC.tulong) CC.tulong)

def RegisterDeclaration.storeValue (d : RegisterDeclaration) : CC.Stmt :=
  .Sassign (.Efield (.Evar d.word (.Tunion Arm64Entry._arm64_sim_gpr CC.noattr))
    Arm64Entry._x CC.tulong) (.Etempvar d.resultTemp CC.tulong)

def RegisterDeclaration.storeTag (d : RegisterDeclaration) : CC.Stmt :=
  .Sassign (.Evar d.tag CC.tuchar) (.Econst_int (0#32) CC.tuint)

/-- A syntactic schema checked against the export, not a new evaluator. -/
def RegisterDeclaration.body (d : RegisterDeclaration) : CC.Stmt :=
  .Ssequence
    (.Ssequence
      (.Sifthenelse (.Ebinop .Oeq (.Econst_int d.index CC.tuint)
        (.Econst_int (30#32) CC.tuint) CC.tint)
        (.Sset d.resultTemp (.Ecast (.Econst_long (0#64) CC.tulong) CC.tulong))
        (.Ssequence (.Scall (some d.inputTemp)
          (.Evar Arm64Entry._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
          [.Econst_int (6#32) CC.tint]) d.setValue)) d.storeValue)
    (.Ssequence d.storeTag d.rest)

private def declarations : List (CC.Stmt × RegisterDeclaration) := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterCacheStage)) none
    for _ in [:3] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer setup no longer has three assignments"
      body := body.getAppArgs[1]!
    let mut rows : Array Lean.Expr := #[]
    for _ in [:31] do
      let original := body
      let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "missing producer register declaration"
      let init ← Lean.Meta.withTransparency .all (Lean.Meta.whnf exposed.getAppArgs[0]!)
      let suffix ← Lean.Meta.withTransparency .all (Lean.Meta.whnf exposed.getAppArgs[1]!)
      unless init.isAppOfArity ``CC.Stmt.Ssequence 2 && suffix.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer register declaration shape changed"
      let branch ← Lean.Meta.withTransparency .all (Lean.Meta.whnf init.getAppArgs[0]!)
      let store ← Lean.Meta.withTransparency .all (Lean.Meta.whnf init.getAppArgs[1]!)
      let tagStore ← Lean.Meta.withTransparency .all (Lean.Meta.whnf suffix.getAppArgs[0]!)
      unless branch.isAppOfArity ``CC.Stmt.Sifthenelse 3 &&
          store.isAppOfArity ``CC.Stmt.Sassign 2 && tagStore.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "producer register stores changed"
      let comparison ← Lean.Meta.withTransparency .all (Lean.Meta.whnf branch.getAppArgs[0]!)
      let indexExpr ← Lean.Meta.withTransparency .all (Lean.Meta.whnf comparison.getAppArgs[1]!)
      let field ← Lean.Meta.withTransparency .all (Lean.Meta.whnf store.getAppArgs[0]!)
      let wordExpr ← Lean.Meta.withTransparency .all (Lean.Meta.whnf field.getAppArgs[0]!)
      let tagExpr ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tagStore.getAppArgs[0]!)
      let zeroSet ← Lean.Meta.withTransparency .all (Lean.Meta.whnf branch.getAppArgs[1]!)
      let inputSeq ← Lean.Meta.withTransparency .all (Lean.Meta.whnf branch.getAppArgs[2]!)
      let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf inputSeq.getAppArgs[0]!)
      let resultOption ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
      unless indexExpr.isAppOfArity ``CC.Expr.Econst_int 2 &&
          wordExpr.isAppOfArity ``CC.Expr.Evar 2 && tagExpr.isAppOfArity ``CC.Expr.Evar 2 &&
          zeroSet.isAppOfArity ``CC.Stmt.Sset 2 && resultOption.isAppOfArity ``Option.some 2 do
        throwError "producer register names changed"
      let row ← Lean.Meta.mkAppM ``RegisterDeclaration.mk #[indexExpr.getAppArgs[0]!,
        wordExpr.getAppArgs[0]!, tagExpr.getAppArgs[0]!, zeroSet.getAppArgs[0]!,
        resultOption.getAppArgs[1]!, suffix.getAppArgs[1]!]
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[original, row])
      body := suffix.getAppArgs[1]!
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt, Lean.mkConst ``RegisterDeclaration]
    let result ← Lean.Meta.mkListLit rowType rows.toList
    Lean.Elab.Tactic.closeMainGoal `producer_register_declarations result

private theorem declaration_count : declarations.length = 31 := by rfl

def registerDeclaration (i : Fin 31) : RegisterDeclaration :=
  (declarations[i.val]'(by rw [declaration_count]; exact i.isLt)).2

def registerDeclarationStage (i : Fin 31) : CC.Stmt :=
  (declarations[i.val]'(by rw [declaration_count]; exact i.isLt)).1

private theorem register_bodies : ∀ i : Fin 31,
    registerDeclarationStage i = (registerDeclaration i).body := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

private theorem register_words : ∀ i : Fin 31,
    ((registerDeclaration i).word, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∈ producer.fn_vars := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals decide +kernel

private theorem register_tags : ∀ i : Fin 31,
    ((registerDeclaration i).tag, CC.tuchar) ∈ producer.fn_vars := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals decide +kernel

private theorem register_indices : ∀ i : Fin 31,
    CC.Integers.Int.eq (registerDeclaration i).index (30#32) = (i.val == 30) := by
  decide +kernel

/-- Every schema is bound to the actual exported source and actual locals. -/
theorem register_declarations_source (i : Fin 31) :
    registerDeclarationStage i = (registerDeclaration i).body ∧
    ((registerDeclaration i).word, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∈ producer.fn_vars ∧
    ((registerDeclaration i).tag, CC.tuchar) ∈ producer.fn_vars ∧
    CC.Integers.Int.eq (registerDeclaration i).index (30#32) = (i.val == 30) :=
  ⟨register_bodies i, register_words i, register_tags i, register_indices i⟩

theorem first_register_stage : registerDeclarationStage 1 = nextRegisterStage := by rfl

theorem register_declarations_chain : ∀ i : Fin 30,
    (registerDeclaration ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩).rest =
      registerDeclarationStage ⟨i.val + 1, Nat.add_lt_add_right i.isLt 1⟩ := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

end KProgFormal.ClightRefinement.Arm64Producer
