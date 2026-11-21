import KProgFormal.ClightRefinement.X86ShiftLeftRoute

namespace KProgFormal.ClightRefinement.X86ShiftLeftCarry

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  let term ← Lean.instantiateMVars term
  Lean.Elab.Tactic.closeMainGoal `actual_x86_carry_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private structure Definitions where
  valueIndex : Nat
  value : CC.CompositeDef
  bindingsIndex : Nat
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
      if row.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_sim_inline_value then
        value := some (index, row)
      if row.getAppArgs[0]!.isConstOf ``X86_program_profile_bpf._x86_sim_inline_bindings then
        bindings := some (index, row)
      rest := node.getAppArgs[2]!
      index := index + 1
    let some (vi, vd) := value | throwError "expected inline-value source definition"
    let some (bi, bd) := bindings | throwError "expected binding source definition"
    Lean.Elab.Tactic.closeMainGoal `actual_x86_carry_definitions
      (← Lean.Meta.mkAppM ``Definitions.mk #[Lean.mkNatLit vi, vd, Lean.mkNatLit bi, bd])

private def valueDefinition : CC.CompositeDef := by run_tac cachePart (← `(definitions.value))
private def bindingsDefinition : CC.CompositeDef := by run_tac cachePart (← `(definitions.bindings))

private def members : CC.CompositeDef → List CC.Member
  | .Composite _ _ rows _ => rows

def valueRecord : CC.Composite :=
  { co_su := .Struct, co_members := members valueDefinition, co_attr := CC.noattr,
    co_sizeof := 16, co_alignof := 8, co_rank := 0 }

def bindingsRecord : CC.Composite :=
  { co_su := .Struct, co_members := members bindingsDefinition, co_attr := CC.noattr,
    co_sizeof := 224, co_alignof := 8, co_rank := 2 }

/-- Source positions, names, members and attributes all come from the real export. -/
theorem definitions_source :
    X86_program_profile_bpf.composites[definitions.valueIndex]? =
      some (.Composite X86_program_profile_bpf._x86_sim_inline_value .Struct valueRecord.co_members CC.noattr) ∧
    X86_program_profile_bpf.composites[definitions.bindingsIndex]? =
      some (.Composite X86_program_profile_bpf._x86_sim_inline_bindings .Struct bindingsRecord.co_members CC.noattr) := by
  constructor <;> rfl

private def buildOne (ce : CC.CompositeEnv) : CC.CompositeDef → CC.Res CC.Composite
  | .Composite name kind rows attr => CC.compositeOfDef ce name kind rows attr

/-- The standard composite builder derives both layouts from those exact source definitions. -/
theorem records_source :
    buildOne CC.PTree.empty valueDefinition = .OK valueRecord ∧
    buildOne (CC.PTree.empty.set X86_program_profile_bpf._x86_sim_inline_value valueRecord)
      bindingsDefinition = .OK bindingsRecord := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected source composite-builder equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

private theorem value_size : valueRecord.co_sizeof = 16 ∧ valueRecord.co_alignof = 8 := ⟨rfl, rfl⟩

/-- The actual CF field follows the two pointers, six two-pointer values, and
native stack-base pointer; unrelated composite declarations stay arbitrary. -/
theorem cf_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value = some valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._cf bindingsRecord.co_members = .OK (120, .Full) := by
  simp +decide [bindingsRecord, members, bindingsDefinition, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
      CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr,
      CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, value_size.1, value_size.2]

private structure Pieces where
  read : CC.Stmt
  classify : CC.Stmt
  loopExit : CC.Stmt
  writer : CC.Stmt

private def pieces : Pieces :=
  match X86ShiftLeftRoute.flags with
  | .Ssequence (.Sloop (.Ssequence read classify) loopExit) writer =>
      ⟨read, classify, loopExit, writer⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip⟩

private def read : CC.Stmt := by run_tac cachePart (← `(pieces.read))
def classify : CC.Stmt := by run_tac cachePart (← `(pieces.classify))
private def loopExit : CC.Stmt := by run_tac cachePart (← `(pieces.loopExit))
private def writer : CC.Stmt := by run_tac cachePart (← `(pieces.writer))
private def flagBody : CC.Stmt := .Ssequence read classify

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 flagBody loopExit (.Kseq writer k)

/-- The read, classifier, loop exit and writer are the exact original remainder. -/
theorem flags_source : X86ShiftLeftRoute.flags =
    .Ssequence (.Sloop flagBody loopExit) writer := rfl

def afterTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (old : BitVec 8) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf._t'264 (.Vptr block offset)).set
    X86_program_profile_bpf._t'265 (.Vint (old.setWidth 32))).set
      X86_program_profile_bpf.___x86_l_old_cf (.Vint (old.setWidth 32))

private theorem enter (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 3 (.State function X86ShiftLeftRoute.flags k e le m)
      (.State function read (.Kseq classify (continuation k)) e le m) := by
  have first : CC.doStep ge (.State function X86ShiftLeftRoute.flags k e le m) =
      some (CC.E0, .State function (.Sloop flagBody loopExit) (.Kseq writer k) e le m) := by
    rw [flags_source]; rfl
  have second : CC.doStep ge
      (.State function (.Sloop flagBody loopExit) (.Kseq writer k) e le m) =
      some (CC.E0, .State function flagBody (continuation k) e le m) := rfl
  have third : CC.doStep ge (.State function flagBody (continuation k) e le m) =
      some (CC.E0, .State function read (.Kseq classify (continuation k)) e le m) := rfl
  exact .step (by trivial) (CC.doStep_sound ge _ _ _ first)
    (.step (by trivial) (CC.doStep_sound ge _ _ _ second)
      (.step (by trivial) (CC.doStep_sound ge _ _ _ third) (.refl _)))


private theorem read_carry (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs) (old : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (byte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (old.setWidth 32))) :
    InternalRun ge 7 (.State function read k e le m)
      (.State function .Sskip k e (afterTemps le cfBlock offset old) m) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cf (.Vptr bindingBlock 0) = some (bindingBlock, 120, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, cf_offset ge.genv_cenv valueLayout]
    rfl
  have width_arg : old.setWidth 32 &&& (255#32) = old.setWidth 32 := by
    change old.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = old.setWidth 32
    rw [← BitVec.setWidth_and, BitVec.and_allOnes]
  have unsigned120 : CC.Integers.Ptrofs.unsigned (120 : CC.Integers.Ptrofs) = 120 := rfl
  have byteCast : CC.Cop.semCast (.Vint (old.setWidth 32)) CC.tuchar CC.tuchar m =
      some (.Vint (old.setWidth 32)) := by
    simpa [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.tuchar, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext] using
      congrArg (fun v => some (CC.Val.Vint v)) width_arg
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  apply internalRun_of_steps
  all_goals simp only [InternalPath, InternalState, steps, read, afterTemps, CC.doStep, CC.doEvalExpr, CC.doDerefLoc,
      CC.typeof, CC.tptr, structAccess, ptrAccess, charAccess, CC.Mem.loadv, CC.PTree.gss, binding,
      address, unsigned120, pointer, byte, byteCast, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Eleven actual source steps load the old CF byte and reach the untouched
classifier, retaining caller locals, memory and the original writer continuation. -/
theorem enter_classifier (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings = some bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value = some valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs) (old : BitVec 8)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (byte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (old.setWidth 32))) :
    InternalRun ge 11 (.State function X86ShiftLeftRoute.flags k e le m)
      (.State function classify (continuation k) e (afterTemps le cfBlock offset old) m) := by
  have loaded := read_carry ge bindingsLayout valueLayout function e le
    (.Kseq classify (continuation k)) m bindingBlock cfBlock offset old binding pointer byte
  have next : InternalRun ge 1
      (.State function .Sskip (.Kseq classify (continuation k)) e (afterTemps le cfBlock offset old) m)
      (.State function classify (continuation k) e (afterTemps le cfBlock offset old) m) := by
    apply internalRun_of_steps
    · simp [InternalPath, InternalState, CC.doStep]
    · simp [steps, CC.doStep, CC.Eapp, CC.E0]
  exact ((enter ge function e le k m).trans loaded).trans next

/-- Three real source writes affect exactly the pointer, byte and old-CF temporaries. -/
theorem temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) (old : BitVec 8) :
    (afterTemps le block offset old).get X86_program_profile_bpf.___x86_l_old_cf =
      some (.Vint (old.setWidth 32)) ∧
    (afterTemps le block offset old).get X86_program_profile_bpf._t'265 =
      some (.Vint (old.setWidth 32)) ∧
    (afterTemps le block offset old).get X86_program_profile_bpf._t'264 =
      some (.Vptr block offset) ∧
    ∀ id, id ≠ X86_program_profile_bpf.___x86_l_old_cf →
      id ≠ X86_program_profile_bpf._t'265 → id ≠ X86_program_profile_bpf._t'264 →
      (afterTemps le block offset old).get id = le.get id := by
  have oldByte : X86_program_profile_bpf.___x86_l_old_cf ≠ X86_program_profile_bpf._t'265 := by decide +kernel
  have oldPtr : X86_program_profile_bpf.___x86_l_old_cf ≠ X86_program_profile_bpf._t'264 := by decide +kernel
  have bytePtr : X86_program_profile_bpf._t'265 ≠ X86_program_profile_bpf._t'264 := by decide +kernel
  refine ⟨by simp [afterTemps], by simp [afterTemps, CC.PTree.gso, oldByte],
    by simp [afterTemps, CC.PTree.gso, oldPtr, bytePtr], ?_⟩
  intro id old_ne byte_ne ptr_ne
  simp [afterTemps, CC.PTree.gso, Ne.symm old_ne, Ne.symm byte_ne, Ne.symm ptr_ne]

end KProgFormal.ClightRefinement.X86ShiftLeftCarry
