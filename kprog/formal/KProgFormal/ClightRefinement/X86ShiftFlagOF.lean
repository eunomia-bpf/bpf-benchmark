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


private theorem count_bound (rhs : BitVec 64) (size : X86.Size) :
    X86.Flags.shiftCount size (rhs.setWidth 8) < 64 := by
  cases size <;> simp only [X86.Flags.shiftCount] <;> omega

/-- Every positive-count original SHL route passes the exact OF branch and reaches
its original continuation, with the reached heap and temporaries selected by count. -/
theorem route_through_overflow (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (shiftBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._kprog_x86_shl_result = some shiftBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv shiftBlock =
        some (.Internal X86_program_profile_bpf.f_kprog_x86_shl_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs) (old : BitVec 8)
    (heapBinding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (byte : CC.Mem.load .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vint (old.setWidth 32)))
    (effectiveBlock bitsBlock maskBlock : CC.Block)
    (effectiveBinding :
      CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective = some effectiveBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv effectiveBlock =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective))
    (bitsBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_bits = some bitsBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv bitsBlock = some (.Internal X86_program_profile_bpf.f_x86_width_bits))
    (maskBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_mask = some maskBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv maskBlock = some (.Internal X86_program_profile_bpf.f_x86_width_mask))
    (widthsUnshadowed : e.get X86_program_profile_bpf._x86_width_effective = none ∧
      e.get X86_program_profile_bpf._x86_width_bits = none ∧
      e.get X86_program_profile_bpf._x86_width_mask = none)
    (countBlock : CC.Block)
    (countBinding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_shift_count = some countBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv countBlock =
        some (.Internal X86_program_profile_bpf.f_x86_shift_count))
    (countUnshadowed : e.get X86_program_profile_bpf._x86_shift_count = none)
    (nonzero : X86.Flags.shiftCount size (rhs.setWidth 8) ≠ 0)
    (zfBlock : CC.Block) (zfOffset : CC.Integers.Ptrofs) (middle : CC.Mem)
    (zfPointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock zfOffset))
    (zfStored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned zfOffset)
      (X86ShiftFlagZF.bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8)))) = some middle)
    (sfBlock : CC.Block) (sfOffset : CC.Integers.Ptrofs) (sfHeap : CC.Mem)
    (sfPointer : CC.Mem.load CC.Mptr middle bindingBlock 136 = some (.Vptr sfBlock sfOffset))
    (sfStored : CC.Mem.store .Mint8unsigned middle sfBlock (CC.Integers.Ptrofs.unsigned sfOffset)
      (X86ShiftFlagSF.bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) ((1#64) <<< (size.bits - 1))) = some sfHeap)
    (writeBlock : CC.Block) (writeOffset : CC.Integers.Ptrofs) (cfHeap : CC.Mem)
    (cfPointer : CC.Mem.load CC.Mptr sfHeap bindingBlock 120 = some (.Vptr writeBlock writeOffset))
    (cfStored : CC.Mem.store .Mint8unsigned sfHeap writeBlock (CC.Integers.Ptrofs.unsigned writeOffset)
      (X86ShiftFlagCF.byte (X86ShiftFlagCF.payload (X86.Value.trunc size lhs) size.bits (X86.Flags.shiftCount size (rhs.setWidth 8)))) = some cfHeap)
    (ofBlock readSFBlock readCFBlock : CC.Block)
    (ofOffset readSFOffset readCFOffset : CC.Integers.Ptrofs) (sf cf : Bool) (after : CC.Mem)
    (ofPointer : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load CC.Mptr cfHeap bindingBlock 144 = some (.Vptr ofBlock ofOffset))
    (readSFPointer : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load CC.Mptr cfHeap bindingBlock 136 = some (.Vptr readSFBlock readSFOffset))
    (readCFPointer : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load CC.Mptr cfHeap bindingBlock 120 = some (.Vptr readCFBlock readCFOffset))
    (readSFByte : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load .Mint8unsigned cfHeap readSFBlock (CC.Integers.Ptrofs.unsigned readSFOffset) = some (flag sf))
    (readCFByte : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load .Mint8unsigned cfHeap readCFBlock (CC.Integers.Ptrofs.unsigned readCFOffset) = some (flag cf))
    (ofStored : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.store .Mint8unsigned cfHeap ofBlock (CC.Integers.Ptrofs.unsigned ofOffset)
        (xorValue sf cf) = some after) :
    InternalRun ge ((((((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) + X86ShiftFlagWidths.length size) + 25) + 10) + 6) + 11) + (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then 17 else 1))
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function .Sskip (X86ShiftFlagZF.continuation (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))) e
        (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then
          afterTemps (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) sfBlock sfOffset) (X86.Value.trunc size lhs) size
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset) (.Vptr ofBlock ofOffset)
            (.Vptr readSFBlock readSFOffset) (.Vptr readCFBlock readCFOffset) sf cf
        else (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) sfBlock sfOffset) (X86.Value.trunc size lhs) size
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset))
        (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then after else cfHeap)) := by
  have routed := X86ShiftFlagCF.route_to_overflow ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed nonzero zfBlock zfOffset middle zfPointer zfStored
    sfBlock sfOffset sfHeap sfPointer sfStored writeBlock writeOffset cfHeap cfPointer cfStored
  let prepared := X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size
  let reached := X86ShiftFlagSF.afterTemps
    (X86ShiftFlagZF.afterTemps prepared zfBlock zfOffset) sfBlock sfOffset
  let n : Fin 64 := ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩
  have incomingBinding : reached.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    dsimp only [reached]
    rw [(X86ShiftFlagSF.temps _ sfBlock sfOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    dsimp only [prepared]
    rw [X86ShiftFlagInputs.frame _ lhs rhs _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [X86ShiftFlagWidths.frame _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftClassify.temps _).2 _ (by decide +kernel)]
    rw [(X86ShiftLeftCarry.temps _ cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftSite.temps le (X86ShiftLeft.result lhs rhs size)).2.2
      _ (by decide +kernel) (by decide +kernel)]
    exact heapBinding
  have values := X86ShiftFlagInputs.temps
    (X86ShiftFlagWidths.afterTemps
      (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
        (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) cfBlock offset old)) size)
      lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8))) size
  have incomingCount : reached.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (BitVec.ofNat 32 n.val)) := by
    dsimp only [reached]
    rw [(X86ShiftFlagSF.temps _ sfBlock sfOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    simpa only [X86ShiftFlagInputs.native_count, n] using values.2.2.2.1

  let finalTemps := X86ShiftFlagCF.afterTemps
    (X86ShiftFlagCF.calculationTemps reached (X86.Value.trunc size lhs) size n)
    writeBlock writeOffset
  have keptBinding : finalTemps.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    dsimp only [finalTemps]
    rw [(X86ShiftFlagCF.temps _ writeBlock writeOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagCF.calculation_temps _ _ size n).2 _ (by decide +kernel)]
    exact incomingBinding
  have keptCount : finalTemps.get X86_program_profile_bpf.___x86_sh_count =
      some (.Vint (BitVec.ofNat 32 n.val)) := by
    dsimp only [finalTemps]
    rw [(X86ShiftFlagCF.temps _ writeBlock writeOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagCF.calculation_temps _ _ size n).2 _ (by decide +kernel)]
    exact incomingCount
  by_cases one : X86.Flags.shiftCount size (rhs.setWidth 8) = 1
  · simp only [ite_eq_left one]
    have countOne : finalTemps.get X86_program_profile_bpf.___x86_sh_count =
        some (.Vint (1#32)) := by
      have codeOne : BitVec.ofNat 32 n.val = (1#32) := by
        change BitVec.ofNat 32 (X86.Flags.shiftCount size (rhs.setWidth 8)) = (1#32)
        rw [one]
      rw [codeOne] at keptCount
      exact keptCount
    have wrote := one_internal ge bindingsLayout valueLayout function e finalTemps
      (X86ShiftFlagZF.continuation (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))) cfHeap after bindingBlock ofBlock readSFBlock readCFBlock
      ofOffset readSFOffset readCFOffset sf cf keptBinding (ofPointer one)
      (readSFPointer one) (readCFPointer one) (readSFByte one) (readCFByte one)
      (ofStored one) countOne
    exact routed.trans wrote
  · simp only [ite_eq_right one]
    have codeOther : BitVec.ofNat 32 n.val ≠ (1#32) := by
      intro same
      have bounded : n.val < 2 ^ 32 := by have bound := n.isLt; omega
      have values := congrArg BitVec.toNat same
      simp only [BitVec.toNat_ofNat, Nat.mod_eq_of_lt bounded] at values
      exact one values
    have skipped := skip_other ge function e finalTemps
      (X86ShiftFlagZF.continuation (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))) cfHeap
      (BitVec.ofNat 32 n.val) codeOther keptCount
    exact routed.trans skipped

end KProgFormal.ClightRefinement.X86ShiftFlagOF
