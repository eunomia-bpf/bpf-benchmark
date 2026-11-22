import KProgFormal.ClightRefinement.X86ShiftLeftCarry

namespace KProgFormal.ClightRefinement.X86RegisterLayout

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  let term ← Lean.instantiateMVars term
  Lean.Elab.Tactic.closeMainGoal `actual_x86_register_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private structure Definitions where
  gprIndex : Nat
  value : CC.CompositeDef
  cellIndex : Nat
  bindings : CC.CompositeDef

private def definitions : Definitions := by
  run_tac do
    let mut rest ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.composites)) none
    let mut index := 0
    let mut value : Option (Nat × Lean.Expr) := none
    let mut bindings : Option (Nat × Lean.Expr) := none
    while value.isNone || bindings.isNone do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless node.isAppOfArity ``List.cons 3 do throwError "expected exported composite definition"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``CC.CompositeDef.Composite 4 do throwError "expected composite constructor"
      if row.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_sim_gpr then
        value := some (index, row)
      if row.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_sim_gpr_cell then
        bindings := some (index, row)
      rest := node.getAppArgs[2]!
      index := index + 1
    let some (vi, vd) := value | throwError "expected inline-value source definition"
    let some (bi, bd) := bindings | throwError "expected binding source definition"
    Lean.Elab.Tactic.closeMainGoal `actual_x86_register_definitions
      (← Lean.Meta.mkAppM ``Definitions.mk #[Lean.mkNatLit vi, vd, Lean.mkNatLit bi, bd])

private def gprDefinition : CC.CompositeDef := by run_tac cachePart (← `(definitions.value))
private def cellDefinition : CC.CompositeDef := by run_tac cachePart (← `(definitions.bindings))

private def members : CC.CompositeDef → List CC.Member
  | .Composite _ _ rows _ => rows

def gprRecord : CC.Composite :=
  { co_su := .Union, co_members := members gprDefinition, co_attr := CC.noattr,
    co_sizeof := 8, co_alignof := 8, co_rank := 1 }

def cellRecord : CC.Composite :=
  { co_su := .Struct, co_members := members cellDefinition, co_attr := CC.noattr,
    co_sizeof := 16, co_alignof := 8, co_rank := 2 }

/-- Source positions, names, members and attributes all come from the real export. -/
theorem definitions_source :
    X86_program_profile_bpf.composites[definitions.gprIndex]? =
      some (.Composite X86_program_profile_bpf._x86_sim_gpr .Union gprRecord.co_members CC.noattr) ∧
    X86_program_profile_bpf.composites[definitions.cellIndex]? =
      some (.Composite X86_program_profile_bpf._x86_sim_gpr_cell .Struct cellRecord.co_members CC.noattr) := by
  constructor <;> rfl


private def buildOne (ce : CC.CompositeEnv) : CC.CompositeDef → CC.Res CC.Composite
  | .Composite name kind rows attr => CC.compositeOfDef ce name kind rows attr

/-- The actual union and cell definitions produce these layouts through the imported C builder. -/
theorem records_source :
    buildOne CC.PTree.empty gprDefinition = .OK gprRecord ∧
    buildOne (CC.PTree.empty.set X86_program_profile_bpf._x86_sim_gpr gprRecord)
      cellDefinition = .OK cellRecord := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected source composite-builder equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

/-- The source-built GPR union is eight bytes and each tagged cell is sixteen bytes,
with their actual eight-byte alignment and composite ranks. -/
theorem layout :
    gprRecord.co_sizeof = 8 ∧ gprRecord.co_alignof = 8 ∧ gprRecord.co_rank = 1 ∧
    cellRecord.co_sizeof = 16 ∧ cellRecord.co_alignof = 8 ∧ cellRecord.co_rank = 2 := by
  exact ⟨rfl, rfl, rfl, rfl, rfl, rfl⟩

private def cellMembers : List CC.Member := by
  run_tac cachePart (← `(cellRecord.co_members))
private def bindingMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

/-- The actual first cell member places its GPR value at byte offset zero. -/
theorem value_offset (ce : CC.CompositeEnv)
    (gprLayout : ce.get X86_program_profile_bpf._x86_sim_gpr = some gprRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._value cellRecord.co_members = .OK (0, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._value cellMembers = .OK (0, .Full)
  simp +decide [cellMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
     CC.bitalignof,  CC.alignof,  CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.noattr, gprLayout, layout.2.1]

/-- The source-built union places the following cell tag at byte offset eight. -/
theorem tag_offset (ce : CC.CompositeEnv)
    (gprLayout : ce.get X86_program_profile_bpf._x86_sim_gpr = some gprRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._tag cellRecord.co_members = .OK (8, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._tag cellMembers = .OK (8, .Full)
  simp +decide [cellMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.noattr, CC.tuchar, gprLayout, layout.1, layout.2.1]

/-- The actual inline binding member list places its cell-table pointer at byte offset zero. -/
theorem cells_offset (ce : CC.CompositeEnv) :
    CC.fieldOffset ce X86_program_profile_bpf._cells
      X86ShiftLeftCarry.bindingsRecord.co_members = .OK (0, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._cells bindingMembers = .OK (0, .Full)
  simp +decide [bindingMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
     CC.bitalignof,  CC.alignof,  CC.alignAttr,
    CC.Ty.attr, CC.align, CC.zdiv, CC.tptr, CC.noattr]

end KProgFormal.ClightRefinement.X86RegisterLayout
