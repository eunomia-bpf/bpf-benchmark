import KProgFormal.ClightRefinement.Arm64ProducerRegisters

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

def tableName (tags : Bool) : CC.Ident :=
  if tags then Arm64Entry.___a64_tag_cells else Arm64Entry.___a64_cells

def tableCellType (tags : Bool) : CC.Ty :=
  if tags then CC.tuchar else .Tunion Arm64Entry._arm64_sim_gpr CC.noattr

def tableCellName (tags : Bool) (i : Fin 31) : CC.Ident :=
  if tags then (registerDeclaration i).tag else (registerDeclaration i).word

def tableType (tags : Bool) : CC.Ty := CC.tarray (CC.tptr (tableCellType tags)) 31

/-- Syntactic shape checked against each real exported table assignment. -/
def tableAssignment (tags : Bool) (i : Fin 31) : CC.Stmt :=
  .Sassign
    (.Ederef (.Ebinop .Oadd (.Evar (tableName tags) (tableType tags))
      (.Econst_int (CC.Integers.Int.repr i.val) CC.tint)
      (CC.tptr (CC.tptr (tableCellType tags)))) (CC.tptr (tableCellType tags)))
    (.Eaddrof (.Evar (tableCellName tags i) (tableCellType tags)) (CC.tptr (tableCellType tags)))

private def tableParts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `((registerDeclaration 30).rest)) none
    let mut front : Array Lean.Expr := #[]
    for _ in [:62] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer no longer has the 62 pointer-table assignments"
      let stmt := body.getAppArgs[0]!
      let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt)
      unless exposed.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "producer pointer table contains a non-assignment"
      front := front.push stmt
      body := body.getAppArgs[1]!
    let stmts ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) front.toList
    let result ← Lean.Meta.mkAppM ``Prod.mk #[stmts, body]
    Lean.Elab.Tactic.closeMainGoal `actual_producer_tables result

def afterPointerTables : CC.Stmt := tableParts.2

def tableAssignments (tags : Bool) : List CC.Stmt := List.ofFn (tableAssignment tags)

private theorem word_table_source : tableParts.1.take 31 = tableAssignments false := by rfl
private theorem tag_table_source : tableParts.1.drop 31 = tableAssignments true := by rfl

theorem pointer_tables_source :
    (registerDeclaration 30).rest =
      (tableAssignments false).foldr CC.Stmt.Ssequence
        ((tableAssignments true).foldr CC.Stmt.Ssequence afterPointerTables) := by
  have source : (registerDeclaration 30).rest = tableParts.1.foldr CC.Stmt.Ssequence afterPointerTables := rfl
  rw [← word_table_source, ← tag_table_source, ← List.foldr_append, List.take_append_drop]
  exact source

theorem table_declarations (tags : Bool) :
    (tableName tags, tableType tags) ∈ producer.fn_vars ∧
    CC.sizeof ge.genv_cenv (tableType tags) = 248 := by
  cases tags <;> decide +kernel

theorem table_cell_declaration (tags : Bool) (i : Fin 31) :
    (tableCellName tags i, tableCellType tags) ∈ producer.fn_vars := by
  cases tags
  · exact (register_declarations_source i).2.1
  · exact (register_declarations_source i).2.2.1

/-- The exact pointer arithmetic used by the exported assignments. -/
def tableOffset (i : Fin 31) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Integers.Ptrofs.of_ints (CC.Integers.Int.repr i.val)))

theorem table_offsets : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (tableOffset i) = 8 * (i.val : Int) := by decide +kernel

end KProgFormal.ClightRefinement.Arm64Producer
