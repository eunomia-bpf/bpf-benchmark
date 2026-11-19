import KProgFormal.ClightRefinement.Arm64ProgramEntryRegisters

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterSource

open Arm64Producer (RegisterDeclaration)

/-- Each row carries a kernel-checked equation for an actual declaration.
Only the successor is extracted from the production spine; all scalar metadata
comes from the existing source declaration and temporary-name map. -/
private def parts : List { row : CC.Stmt × RegisterDeclaration // row.1 = row.2.body } × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryInputs.registerStage)) none
    let rowTy ← Lean.Elab.Term.elabTerm (← `(CC.Stmt × RegisterDeclaration)) none
    let predicate ← Lean.Elab.Term.elabTerm
      (← `(fun row : CC.Stmt × RegisterDeclaration => row.1 = row.2.body)) none
    let certificateTy ← Lean.Meta.mkAppM ``Subtype #[predicate]
    let mut rows : Array Lean.Expr := #[]
    for i in [:31] do
      let original := body
      let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual register declaration ended early"
      let tag ← Lean.Meta.withTransparency .all (Lean.Meta.whnf outer.getAppArgs[1]!)
      unless tag.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual register tag/successor changed"
      let next := tag.getAppArgs[1]!
      let number := Lean.Syntax.mkNumLit (toString i)
      let source ← Lean.Elab.Term.elabTerm (← `(Arm64Producer.registerDeclaration $number)) none
      let field := fun (name : Lean.Name) => Lean.Meta.mkAppM name #[source]
      let mapped := fun (name : Lean.Name) => do
        Lean.Meta.mkAppM ``Arm64ProgramEntrySource.temporaryName #[(← field name)]
      let declaration ← Lean.Meta.mkAppM ``RegisterDeclaration.mk
        #[(← field ``RegisterDeclaration.index), (← field ``RegisterDeclaration.word),
          (← field ``RegisterDeclaration.tag), (← mapped ``RegisterDeclaration.resultTemp),
          (← mapped ``RegisterDeclaration.inputTemp), next]
      let row ← Lean.Meta.mkAppM ``Prod.mk #[original, declaration]
      let rhs ← Lean.Meta.mkAppM ``RegisterDeclaration.body #[declaration]
      rows := rows.push (Lean.mkAppN (Lean.mkConst ``Subtype.mk [.succ .zero])
        #[rowTy, predicate, row, (← Lean.Meta.mkEqRefl rhs)])
      body := next
    let data ← Lean.Meta.mkListLit certificateTy rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_register_source
      (← Lean.Meta.mkAppM ``Prod.mk #[data, body])

private theorem count : parts.1.length = 31 := by rfl

def declaration (i : Fin 31) : RegisterDeclaration :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).val.2

def stage (i : Fin 31) : CC.Stmt :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).val.1

def afterRegisters : CC.Stmt := parts.2

theorem source (i : Fin 31) : stage i = (declaration i).body :=
  (parts.1[i.val]'(by rw [count]; exact i.isLt)).property

theorem first_stage : stage 0 = Arm64ProgramEntryInputs.registerStage := by rfl

theorem first_declaration : declaration 0 = Arm64ProgramEntryInputs.firstDeclaration := by
  run_tac do
    let rhs ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryInputs.firstDeclaration)) none
    Lean.Elab.Tactic.closeMainGoal `first_actual_declaration (← Lean.Meta.mkEqRefl rhs)

/-- Metadata keeps the named local cells and maps both temporary names. -/
theorem metadata : ∀ i : Fin 31,
    (declaration i).word = (Arm64Producer.registerDeclaration i).word ∧
    (declaration i).tag = (Arm64Producer.registerDeclaration i).tag ∧
    (declaration i).index = (Arm64Producer.registerDeclaration i).index ∧
    (declaration i).inputTemp = Arm64ProgramEntrySource.temporaryName (Arm64Producer.registerDeclaration i).inputTemp ∧
    (declaration i).resultTemp = Arm64ProgramEntrySource.temporaryName (Arm64Producer.registerDeclaration i).resultTemp := by
  decide +kernel

theorem storage_metadata : ∀ i : Fin 31,
    ((declaration i).word, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∈ Arm64Producer.producer.fn_vars ∧
    ((declaration i).tag, CC.tuchar) ∈ Arm64Producer.producer.fn_vars ∧
    (declaration i).word ≠ (declaration i).tag ∧
    Arm64ProgramEntryAllocation.localName (declaration i).word = (declaration i).word ∧
    Arm64ProgramEntryAllocation.localName (declaration i).tag = (declaration i).tag ∧
    (declaration i).inputTemp ≠ Arm64ProgramFixture._ctx ∧
    (declaration i).resultTemp ≠ Arm64ProgramFixture._ctx := by
  decide +kernel

theorem indices : ∀ i : Fin 31,
    CC.Integers.Int.eq (declaration i).index (30#32) = (i.val == 30) := by decide +kernel

theorem chain : ∀ i : Fin 30,
    (declaration ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩).rest =
      stage ⟨i.val + 1, Nat.add_lt_add_right i.isLt 1⟩ := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

theorem last_rest : (declaration 30).rest = afterRegisters := by rfl

end KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterSource
