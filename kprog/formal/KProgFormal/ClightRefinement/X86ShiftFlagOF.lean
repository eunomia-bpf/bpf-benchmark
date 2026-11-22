import KProgFormal.ClightRefinement.X86ShiftFlagCF

namespace KProgFormal.ClightRefinement.X86ShiftFlagOF

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_of
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def gate : CC.Expr := by
  run_tac cachePart (← `(match X86ShiftFlagCF.overflow with
    | .Sifthenelse test _ _ => test | _ => .Econst_int (0#32) CC.tint))
def body : CC.Stmt := by
  run_tac cachePart (← `(match X86ShiftFlagCF.overflow with
    | .Sifthenelse _ active _ => active | _ => .Sskip))

/-- The original overflow fragment contains its real count test and original active body. -/
theorem source : X86ShiftFlagCF.overflow = .Sifthenelse gate body .Sskip := rfl

private def fieldMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

/-- The actual source member list places the OF pointer at byte offset 144. -/
theorem of_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._of X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (144, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._of fieldMembers = .OK (144, .Full)
  have size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
  have align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  simp +decide [fieldMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr,
    CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, size, align]

def flag (value : Bool) : CC.Val := .Vint (if value then 1 else 0)

def xorValue (sf cf : Bool) : CC.Val := flag (sf != cf)

def afterTemps (le : CC.TempEnv) (ofPtr sfPtr cfPtr : CC.Val) (sf cf : Bool) : CC.TempEnv :=
  ((((le.set X86_program_profile_bpf._t'214 ofPtr).set
    X86_program_profile_bpf._t'215 sfPtr).set X86_program_profile_bpf._t'216 (flag sf)).set
      X86_program_profile_bpf._t'217 cfPtr).set X86_program_profile_bpf._t'218 (flag cf)

/-- The integer XOR of reloaded flag bytes is exactly the mature count-one OF expression. -/
theorem native_value (size : X86.Size) (lhs value : BitVec 64)
    (cfU ofU afU : Bool) (before : X86.Flags) :
    xorValue (X86.Value.msb size value)
      (X86.Flags.shiftFlags .shl size lhs value 1 cfU ofU afU before).cf =
      .Vint (if (X86.Flags.shiftFlags .shl size lhs value 1 cfU ofU afU before).of then 1 else 0) := by
  rfl

/-- The actual pointer reloads, SF/CF byte reads, integer XOR and OF byte store
retain the exact source temporary map and updated heap. -/
theorem body_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock ofBlock sfBlock cfBlock : CC.Block)
    (ofOffset sfOffset cfOffset : CC.Integers.Ptrofs) (sf cf : Bool)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (ofPointer : CC.Mem.load CC.Mptr m bindingBlock 144 = some (.Vptr ofBlock ofOffset))
    (sfPointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock sfOffset))
    (cfPointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock cfOffset))
    (sfByte : CC.Mem.load .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned sfOffset) = some (flag sf))
    (cfByte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned cfOffset) = some (flag cf))
    (stored : CC.Mem.store .Mint8unsigned m ofBlock (CC.Integers.Ptrofs.unsigned ofOffset)
      (xorValue sf cf) = some after) :
    InternalRun ge 16 (.State function body k e le m)
      (.State function .Sskip k e (afterTemps le
        (.Vptr ofBlock ofOffset) (.Vptr sfBlock sfOffset) (.Vptr cfBlock cfOffset) sf cf) after) := by
  have ofAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._of (.Vptr bindingBlock 0) = some (bindingBlock, 144, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, of_offset ge.genv_cenv valueLayout]
    rfl
  have sfAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._sf (.Vptr bindingBlock 0) = some (bindingBlock, 136, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftFlagSF.sf_offset ge.genv_cenv valueLayout]
    rfl
  have cfAddress : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cf (.Vptr bindingBlock 0) = some (bindingBlock, 120, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftLeftCarry.cf_offset ge.genv_cenv valueLayout]
    rfl
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have unsigned144 : CC.Integers.Ptrofs.unsigned (144 : CC.Integers.Ptrofs) = 144 := rfl
  have unsigned136 : CC.Integers.Ptrofs.unsigned (136 : CC.Integers.Ptrofs) = 136 := rfl
  have unsigned120 : CC.Integers.Ptrofs.unsigned (120 : CC.Integers.Ptrofs) = 120 := rfl
  have xor : CC.Cop.semBinaryOperation ge.genv_cenv .Oxor (flag sf) CC.tuchar
      (flag cf) CC.tuchar m = some (xorValue sf cf) := by cases sf <;> cases cf <;> rfl
  have cast : CC.Cop.semCast (xorValue sf cf) CC.tint CC.tuchar m =
      some (xorValue sf cf) := by cases sf <;> cases cf <;> rfl
  have assignment : CC.doAssignLoc ge.genv_cenv CC.tuchar m ofBlock ofOffset .Full
      (xorValue sf cf) = some after := by
    simp only [CC.doAssignLoc, charAccess, CC.Mem.storev, stored]
  have distinct0 : X86_program_profile_bpf._t'214 ≠ X86_program_profile_bpf.___x86_bind := by decide +kernel
  have distinct1 : X86_program_profile_bpf._t'215 ≠ X86_program_profile_bpf.___x86_bind := by decide +kernel
  have distinct2 : X86_program_profile_bpf._t'216 ≠ X86_program_profile_bpf.___x86_bind := by decide +kernel
  have distinct3 : X86_program_profile_bpf._t'215 ≠ X86_program_profile_bpf._t'214 := by decide +kernel
  have distinct4 : X86_program_profile_bpf._t'216 ≠ X86_program_profile_bpf._t'214 := by decide +kernel
  have distinct5 : X86_program_profile_bpf._t'217 ≠ X86_program_profile_bpf._t'214 := by decide +kernel
  have distinct6 : X86_program_profile_bpf._t'218 ≠ X86_program_profile_bpf._t'214 := by decide +kernel
  have distinct7 : X86_program_profile_bpf._t'217 ≠ X86_program_profile_bpf._t'216 := by decide +kernel
  have distinct8 : X86_program_profile_bpf._t'218 ≠ X86_program_profile_bpf._t'216 := by decide +kernel
  have kept0 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'214 v).get X86_program_profile_bpf.___x86_bind = temps.get X86_program_profile_bpf.___x86_bind :=
    CC.PTree.gso _ _ _ _ distinct0
  have kept1 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'215 v).get X86_program_profile_bpf.___x86_bind = temps.get X86_program_profile_bpf.___x86_bind :=
    CC.PTree.gso _ _ _ _ distinct1
  have kept2 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'216 v).get X86_program_profile_bpf.___x86_bind = temps.get X86_program_profile_bpf.___x86_bind :=
    CC.PTree.gso _ _ _ _ distinct2
  have kept3 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'215 v).get X86_program_profile_bpf._t'214 = temps.get X86_program_profile_bpf._t'214 :=
    CC.PTree.gso _ _ _ _ distinct3
  have kept4 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'216 v).get X86_program_profile_bpf._t'214 = temps.get X86_program_profile_bpf._t'214 :=
    CC.PTree.gso _ _ _ _ distinct4
  have kept5 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'217 v).get X86_program_profile_bpf._t'214 = temps.get X86_program_profile_bpf._t'214 :=
    CC.PTree.gso _ _ _ _ distinct5
  have kept6 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'218 v).get X86_program_profile_bpf._t'214 = temps.get X86_program_profile_bpf._t'214 :=
    CC.PTree.gso _ _ _ _ distinct6
  have kept7 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'217 v).get X86_program_profile_bpf._t'216 = temps.get X86_program_profile_bpf._t'216 :=
    CC.PTree.gso _ _ _ _ distinct7
  have kept8 (v : CC.Val) (temps : CC.TempEnv) :
      (temps.set X86_program_profile_bpf._t'218 v).get X86_program_profile_bpf._t'216 = temps.get X86_program_profile_bpf._t'216 :=
    CC.PTree.gso _ _ _ _ distinct8
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, body, afterTemps, CC.doStep,
      CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.typeof, CC.tptr, CC.PTree.gss,
      structAccess, ptrAccess, charAccess, CC.Mem.loadv, binding,
      ofAddress, sfAddress, cfAddress, unsigned144, unsigned136, unsigned120,
      ofPointer, sfPointer, cfPointer, sfByte, cfByte, xor, cast, assignment,
      kept0, kept1, kept2, kept3, kept4, kept5, kept6, kept7, kept8,
      CC.Eapp, CC.E0, List.nil_append, true_and]


private theorem gate_value (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (code : BitVec 32)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code)) :
    CC.doEvalExpr ge e le m gate = some (CC.Val.ofBool (code == (1#32))) := by
  simp only [gate, CC.doEvalExpr, count]
  try rfl

/-- The original count-one test selects the unchanged active overflow body. -/
theorem select_one (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (1#32))) :
    InternalRun ge 1 (.State function X86ShiftFlagCF.overflow k e le m)
      (.State function body k e le m) := by
  have tested : CC.doEvalExpr ge e le m gate = some (.Vint (1#32)) := by
    simpa +decide [CC.Val.ofBool, CC.Val.Vtrue, CC.Integers.Int.one, CC.Integers.MI.one] using
      gate_value ge e le m (1#32) count
  have type : CC.typeof gate = CC.tint := rfl
  have truth : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  have step : CC.doStep ge (.State function X86ShiftFlagCF.overflow k e le m) =
      some (CC.E0, .State function body k e le m) := by
    rw [source]
    simp only [CC.doStep, tested, type, truth]
    try rfl
  exact .step (by trivial) (CC.doStep_sound ge _ _ _ step) (.refl _)

/-- Every other count follows the actual skip arm and retains all memory, locals and temporaries. -/
theorem skip_other (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (code : BitVec 32)
    (other : code ≠ (1#32))
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code)) :
    InternalRun ge 1 (.State function X86ShiftFlagCF.overflow k e le m)
      (.State function .Sskip k e le m) := by
  have tested : CC.doEvalExpr ge e le m gate = some (.Vint (0#32)) := by
    simpa [other, CC.Val.ofBool, CC.Val.Vfalse, CC.Integers.Int.zero, CC.Integers.MI.zero] using
      gate_value ge e le m code count
  have type : CC.typeof gate = CC.tint := rfl
  have falsity : CC.Cop.boolVal (.Vint (0#32)) CC.tint m = some false := rfl
  have step : CC.doStep ge (.State function X86ShiftFlagCF.overflow k e le m) =
      some (CC.E0, .State function .Sskip k e le m) := by
    rw [source]
    simp only [CC.doStep, tested, type, falsity]
    try rfl
  exact .step (by trivial) (CC.doStep_sound ge _ _ _ step) (.refl _)

/-- Seventeen actual source transitions test count one, reload both flags,
compute integer XOR and perform the original overflow byte store. -/
theorem one_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock ofBlock sfBlock cfBlock : CC.Block)
    (ofOffset sfOffset cfOffset : CC.Integers.Ptrofs) (sf cf : Bool)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (ofPointer : CC.Mem.load CC.Mptr m bindingBlock 144 = some (.Vptr ofBlock ofOffset))
    (sfPointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock sfOffset))
    (cfPointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock cfOffset))
    (sfByte : CC.Mem.load .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned sfOffset) = some (flag sf))
    (cfByte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned cfOffset) = some (flag cf))
    (stored : CC.Mem.store .Mint8unsigned m ofBlock (CC.Integers.Ptrofs.unsigned ofOffset)
      (xorValue sf cf) = some after)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (1#32))) :
    InternalRun ge 17 (.State function X86ShiftFlagCF.overflow k e le m)
      (.State function .Sskip k e (afterTemps le
        (.Vptr ofBlock ofOffset) (.Vptr sfBlock sfOffset) (.Vptr cfBlock cfOffset) sf cf) after) :=
  (select_one ge function e le k m count).trans
    (body_internal ge bindingsLayout valueLayout function e le k m after bindingBlock
      ofBlock sfBlock cfBlock ofOffset sfOffset cfOffset sf cf binding
      ofPointer sfPointer cfPointer sfByte cfByte stored)

/-- The original count-one overflow code has the exact silent relational execution. -/
theorem one_returns (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock ofBlock sfBlock cfBlock : CC.Block)
    (ofOffset sfOffset cfOffset : CC.Integers.Ptrofs) (sf cf : Bool)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (ofPointer : CC.Mem.load CC.Mptr m bindingBlock 144 = some (.Vptr ofBlock ofOffset))
    (sfPointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock sfOffset))
    (cfPointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock cfOffset))
    (sfByte : CC.Mem.load .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned sfOffset) = some (flag sf))
    (cfByte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned cfOffset) = some (flag cf))
    (stored : CC.Mem.store .Mint8unsigned m ofBlock (CC.Integers.Ptrofs.unsigned ofOffset)
      (xorValue sf cf) = some after)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (1#32))) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftFlagCF.overflow k e le m) CC.E0
      (.State function .Sskip k e (afterTemps le
        (.Vptr ofBlock ofOffset) (.Vptr sfBlock sfOffset) (.Vptr cfBlock cfOffset) sf cf) after) :=
  (one_internal ge bindingsLayout valueLayout function e le k m after bindingBlock
    ofBlock sfBlock cfBlock ofOffset sfOffset cfOffset sf cf binding
    ofPointer sfPointer cfPointer sfByte cfByte stored count).sound

/-- Every actual overflow temporary reads back its original pointer or loaded flag byte. -/
theorem temps (le : CC.TempEnv) (ofPtr sfPtr cfPtr : CC.Val) (sf cf : Bool) :
    (afterTemps le ofPtr sfPtr cfPtr sf cf).get X86_program_profile_bpf._t'214 = some ofPtr ∧
    (afterTemps le ofPtr sfPtr cfPtr sf cf).get X86_program_profile_bpf._t'215 = some sfPtr ∧
    (afterTemps le ofPtr sfPtr cfPtr sf cf).get X86_program_profile_bpf._t'216 = some (flag sf) ∧
    (afterTemps le ofPtr sfPtr cfPtr sf cf).get X86_program_profile_bpf._t'217 = some cfPtr ∧
    (afterTemps le ofPtr sfPtr cfPtr sf cf).get X86_program_profile_bpf._t'218 = some (flag cf) := by
  simp +decide [afterTemps, CC.PTree.gso]

/-- The original five writes preserve every other incoming temporary. -/
theorem frame (le : CC.TempEnv) (ofPtr sfPtr cfPtr : CC.Val) (sf cf : Bool) (id : CC.Ident)
    (ofNe : id ≠ X86_program_profile_bpf._t'214) (sfPtrNe : id ≠ X86_program_profile_bpf._t'215)
    (sfNe : id ≠ X86_program_profile_bpf._t'216) (cfPtrNe : id ≠ X86_program_profile_bpf._t'217)
    (cfNe : id ≠ X86_program_profile_bpf._t'218) :
    (afterTemps le ofPtr sfPtr cfPtr sf cf).get id = le.get id := by
  simp [afterTemps, CC.PTree.gso, Ne.symm ofNe, Ne.symm sfPtrNe, Ne.symm sfNe,
    Ne.symm cfPtrNe, Ne.symm cfNe]


/-- For other positive counts, the retained source OF is a valid native oracle choice. -/
theorem native_other_value (size : X86.Size) (lhs value : BitVec 64) (n : Nat)
    (other : n ≠ 1) (cfU ofValue afU : Bool) (before : X86.Flags) :
    (X86.Flags.shiftFlags .shl size lhs value n cfU ofValue afU before).of = ofValue := by
  change (if n = 1 then X86.Value.msb size value !=
    (if size.bits ≤ n then cfU else lhs.getLsbD (size.bits - n)) else ofValue) = ofValue
  simp only [other, ite_false]

end KProgFormal.ClightRefinement.X86ShiftFlagOF
