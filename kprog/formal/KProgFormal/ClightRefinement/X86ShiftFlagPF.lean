import KProgFormal.ClightRefinement.X86ShiftFlagOF

namespace KProgFormal.ClightRefinement.X86ShiftFlagPF

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_pf
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def fold (value : BitVec 64) : BitVec 4 :=
  (value ^^^ (value >>> 4)).setWidth 4

def index (value : BitVec 64) : BitVec 64 :=
  (value ^^^ (value >>> 4)) &&& (15#64)

def bit (value : BitVec 64) : CC.Val :=
  .Vint (((38505#32) >>> (index value).toNat) &&& (1#32))

private theorem index_eq (value : BitVec 64) :
    index value = (fold value).setWidth 64 := by
  apply BitVec.eq_of_getLsbD_eq_iff.mpr
  intro i hi
  by_cases low : i < 4
  · have choices : i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 := by omega
    rcases choices with rfl | rfl | rfl | rfl <;> simp +decide [index, fold]
  · have maskHigh : (15#64).getLsbD i = false := by
      change ((BitVec.allOnes 4).setWidth 64).getLsbD i = false
      have high : (BitVec.allOnes 4).getLsbD i = false :=
        BitVec.getLsbD_of_ge _ _ (by omega)
      simp only [BitVec.getLsbD_setWidth, high, Bool.and_false]
    simp +decide [index, fold, maskHigh, low]

private theorem table :
    ∀ nibble : BitVec 4,
      ((38505#32) >>> nibble.toNat) &&& (1#32) =
        (if !(nibble.getLsbD 0 ^^ nibble.getLsbD 1 ^^
          nibble.getLsbD 2 ^^ nibble.getLsbD 3) then 1 else 0) := by
  decide +kernel

/-- The original nibble-fold/table expression equals the mature ISA low-byte parity. -/
theorem parity (value : BitVec 64) :
    bit value = .Vint (if X86.Value.parity8 value then 1 else 0) := by
  unfold bit
  rw [index_eq]
  simp only [BitVec.toNat_setWidth]
  have bound : (fold value).toNat < 2 ^ 64 := by have b := (fold value).isLt; omega
  rw [Nat.mod_eq_of_lt bound, table]
  congr 2
  simp only [fold, X86.Value.parity8, BitVec.getLsbD_setWidth,
    BitVec.getLsbD_xor, BitVec.getLsbD_ushiftRight]
  simp +decide [Bool.xor_left_comm]


def writer : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 with
    | .Ssequence _ (.Sifthenelse _ active _) => active | _ => .Sskip))

def afterTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'209 (.Vptr block offset)

private theorem index_bound (value : BitVec 64) : (index value).toNat < 16 := by
  rw [index_eq]
  simp only [BitVec.toNat_setWidth]
  have bound := (fold value).isLt
  omega

private def fieldMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

/-- The actual source member list places the PF pointer at byte offset 152. -/
theorem pf_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._pf X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (152, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._pf fieldMembers = .OK (152, .Full)
  have size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
  have align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  simp +decide [fieldMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr,
    CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, size, align]

private def pointerExpr : CC.Expr := by
  run_tac cachePart (← `(match writer with
    | .Ssequence (.Sset _ rhs) _ => rhs
    | _ => .Econst_int (0#32) CC.tint))
private def targetExpr : CC.Expr := by
  run_tac cachePart (← `(match writer with
    | .Ssequence _ (.Sassign target _) => target
    | _ => .Econst_int (0#32) CC.tint))
private def valueExpr : CC.Expr := by
  run_tac cachePart (← `(match writer with
    | .Ssequence _ (.Sassign _ rhs) => rhs
    | _ => .Econst_int (0#32) CC.tint))

private theorem writer_source : writer =
    .Ssequence (.Sset X86_program_profile_bpf._t'209 pointerExpr)
      (.Sassign targetExpr valueExpr) := rfl

/-- The actual PF pointer read and byte store execute with the original current-heap operations. -/
theorem internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock pfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 152 = some (.Vptr pfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m pfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after) :
    InternalRun ge 4 (.State function writer k e le m)
      (.State function .Sskip k e (afterTemps le pfBlock offset) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._pf (.Vptr bindingBlock 0) = some (bindingBlock, 152, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, pf_offset ge.genv_cenv valueLayout]
    rfl
  have unsigned152 : CC.Integers.Ptrofs.unsigned (152 : CC.Integers.Ptrofs) = 152 := rfl
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have pointerRead : CC.doEvalExpr ge e le m pointerExpr = some (.Vptr pfBlock offset) := by
    simp only [pointerExpr, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      structAccess, ptrAccess, CC.Mem.loadv, binding, address, unsigned152, pointer]
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have valueType : CC.typeof valueExpr = CC.tuint := rfl
  have targetLoc : CC.doEvalLvalue ge e (afterTemps le pfBlock offset) m targetExpr =
      some (pfBlock, offset, .Full) := by
    simp only [targetExpr, CC.doEvalLvalue, CC.doEvalExpr, afterTemps, CC.PTree.gss]
  have keptResult : (afterTemps le pfBlock offset).get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong value) := by
    simp +decide [afterTemps, CC.PTree.gso, result]
  have shiftBound : (index value).toNat < 32 := by have bound := index_bound value; omega
  have lowNat : (CC.Integers.Int64.loword (index value)).toNat = (index value).toNat := by
    change ((index value).setWidth 32).toNat = (index value).toNat
    simp only [BitVec.toNat_setWidth]
    exact Nat.mod_eq_of_lt (by have bound := index_bound value; omega)
  dsimp only [index] at shiftBound lowNat
  have shiftNat : (value.toNat ^^^ (value.toNat >>> 4)) &&& 15 < 32 := by
    simpa using shiftBound
  have evaluated : CC.doEvalExpr ge e (afterTemps le pfBlock offset) m valueExpr =
      some (bit value) := by
    simp +decide [valueExpr, CC.doEvalExpr, CC.typeof, keptResult,
      CC.Cop.semBinaryOperation, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
      CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntLong,
      CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semAnd, CC.Cop.semXor,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong, CC.tuint,
      CC.Integers.Int64.shru, CC.Integers.Int.shru, CC.Integers.MI.shru,
      CC.Integers.Int64.xor, CC.Integers.Int64.and, CC.Integers.Int.and,
      CC.Integers.MI.xor, CC.Integers.MI.and, CC.Integers.Int.repr, CC.Integers.Int64.repr,
      CC.Integers.MI.repr, CC.Integers.Int.unsigned,
      CC.Integers.MI.unsigned, CC.Integers.Int64.ltu, CC.Integers.MI.ltu, BitVec.ult,
      bit, index, shiftNat, lowNat]
  have byteCast : CC.Cop.semCast (bit value) CC.tuint CC.tuchar m = some (bit value) := by
    rw [parity]
    cases X86.Value.parity8 value <;> rfl
  have assignment : CC.doAssignLoc ge.genv_cenv CC.tuchar m pfBlock offset .Full (bit value) =
      some after := by
    simp only [CC.doAssignLoc, charAccess, CC.Mem.storev, stored]
  dsimp only [afterTemps] at targetLoc evaluated
  rw [writer_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, pointerRead, targetLoc,
      targetType, valueType, evaluated, byteCast, assignment, afterTemps,
      CC.Eapp, CC.E0, List.nil_append, true_and]




private def choice : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 with
    | .Ssequence first _ => first | _ => .Sskip))
private def gate : CC.Expr := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 with
    | .Ssequence _ (.Sifthenelse test _ _) => test | _ => .Econst_int (0#32) CC.tint))

/-- The real short-circuit selector and byte writer retain their original source identity. -/
theorem source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 =
    .Ssequence choice (.Sifthenelse gate writer .Sskip) := rfl

def selectedTemps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'71 (.Vint (1#32))).set
    X86_program_profile_bpf._t'70 (.Vint (1#32))

/-- Ten source transitions select parity for every positive effective SHL count. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    InternalRun ge 10
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 k e le m)
      (.State function writer k e (selectedTemps le) m) := by
  have different : code ≠ (0#32) := nonzero
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, choice, gate, selectedTemps,
      CC.doStep, CC.doEvalExpr, CC.typeof, count, alu, different,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.cmp, CC.Integers.MI.cmp, CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Integers.Int.zero,
      CC.Integers.Int.one, CC.Integers.MI.zero, CC.Integers.MI.one,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Eapp, CC.E0]

/-- All source pointer and selection temporaries read back their genuine values,
while every other temporary retains its incoming value. -/
theorem temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    (afterTemps (selectedTemps le) block offset).get X86_program_profile_bpf._t'71 = some (.Vint (1#32)) ∧
    (afterTemps (selectedTemps le) block offset).get X86_program_profile_bpf._t'70 = some (.Vint (1#32)) ∧
    (afterTemps (selectedTemps le) block offset).get X86_program_profile_bpf._t'209 = some (.Vptr block offset) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'71 → id ≠ X86_program_profile_bpf._t'70 →
      id ≠ X86_program_profile_bpf._t'209 →
      (afterTemps (selectedTemps le) block offset).get id = le.get id := by
  refine ⟨?_, ?_, ?_, ?_⟩
  · simp +decide [afterTemps, selectedTemps, CC.PTree.gso]
  · simp +decide [afterTemps, selectedTemps, CC.PTree.gso]
  · simp [afterTemps]
  · intro id ne71 ne70 ne209
    simp [afterTemps, selectedTemps, CC.PTree.gso, Ne.symm ne71, Ne.symm ne70, Ne.symm ne209]

/-- The source byte equals the mature SHL parity flag for every oracle choice. -/
theorem native_value (size : X86.Size) (lhs value : BitVec 64) (n : Nat)
    (cfU ofU afU : Bool) (before : X86.Flags) :
    bit value = .Vint (if (X86.Flags.shiftFlags .shl size lhs value n cfU ofU afU before).pf then 1 else 0) := by
  change bit value = .Vint (if X86.Value.parity8 value then 1 else 0)
  exact parity value

/-- The original positive-count SHL parity fragment performs its actual selector
and table-derived byte store in fourteen silent transitions. -/
theorem positive_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock pfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 152 = some (.Vptr pfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m pfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after)
    (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    InternalRun ge 14
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 k e le m)
      (.State function .Sskip k e (afterTemps (selectedTemps le) pfBlock offset) after) := by
  have selected := select ge function e le k m code nonzero count alu
  have keptBinding : (selectedTemps le).get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    simp +decide [selectedTemps, CC.PTree.gso, binding]
  have keptResult : (selectedTemps le).get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong value) := by
    simp +decide [selectedTemps, CC.PTree.gso, result]
  have wrote := internal ge bindingsLayout valueLayout function e (selectedTemps le) k
    m after bindingBlock pfBlock offset value keptBinding keptResult pointer stored
  exact selected.trans wrote

/-- The complete parity fragment has the exact silent Clight relational run. -/
theorem positive_returns (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock pfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 152 = some (.Vptr pfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m pfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after)
    (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    CC.Star (CC.Step2 ge)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 k e le m) CC.E0
      (.State function .Sskip k e (afterTemps (selectedTemps le) pfBlock offset) after) :=
  (positive_internal ge bindingsLayout valueLayout function e le k m after bindingBlock
    pfBlock offset value binding result pointer stored code nonzero count alu).sound


/-- The original flag loop's skip and break transitions reach its parity continuation. -/
theorem resume_parity (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun ge 3 (.State function .Sskip (X86ShiftFlagZF.continuation k) e le m)
      (.State function X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 k e le m) := by
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, X86ShiftFlagZF.continuation,
      CC.doStep, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- Actual loop exit and the original parity fragment compose with their exact heap and temporaries. -/
theorem after_overflow (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock pfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 152 = some (.Vptr pfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m pfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after)
    (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    InternalRun ge 17
      (.State function .Sskip (X86ShiftFlagZF.continuation k) e le m)
      (.State function .Sskip k e (afterTemps (selectedTemps le) pfBlock offset) after) := by
  have resumed := resume_parity ge function e le k m
  have wrote := positive_internal ge bindingsLayout valueLayout function e le k m after
    bindingBlock pfBlock offset value binding result pointer stored code nonzero count alu
  exact resumed.trans wrote

private theorem count_bound (rhs : BitVec 64) (size : X86.Size) :
    X86.Flags.shiftCount size (rhs.setWidth 8) < 64 := by
  cases size <;> simp only [X86.Flags.shiftCount] <;> omega

/-- Every positive-count original SHL dispatch route completes ZF, SF, CF,
the count-selected OF branch, the flag-loop exit and parity byte storage. -/
theorem route_through_parity (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
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
      CC.Mem.load .Mint8unsigned cfHeap readSFBlock (CC.Integers.Ptrofs.unsigned readSFOffset) = some (X86ShiftFlagOF.flag sf))
    (readCFByte : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.load .Mint8unsigned cfHeap readCFBlock (CC.Integers.Ptrofs.unsigned readCFOffset) = some (X86ShiftFlagOF.flag cf))
    (ofStored : X86.Flags.shiftCount size (rhs.setWidth 8) = 1 →
      CC.Mem.store .Mint8unsigned cfHeap ofBlock (CC.Integers.Ptrofs.unsigned ofOffset)
        (X86ShiftFlagOF.xorValue sf cf) = some after)
    (pfBlock : CC.Block) (pfOffset : CC.Integers.Ptrofs) (pfHeap : CC.Mem)
    (pfPointer : CC.Mem.load CC.Mptr (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then after else cfHeap) bindingBlock 152 = some (.Vptr pfBlock pfOffset))
    (pfStored : CC.Mem.store .Mint8unsigned (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then after else cfHeap) pfBlock
      (CC.Integers.Ptrofs.unsigned pfOffset) (bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8)))) = some pfHeap) :
    InternalRun ge (((((((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) + X86ShiftFlagWidths.length size) + 25) + 10) + 6) + 11) + (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then 17 else 1)) + 17)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function .Sskip (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) e
        (afterTemps (selectedTemps (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then
          X86ShiftFlagOF.afterTemps (X86ShiftFlagCF.afterTemps (X86ShiftFlagCF.calculationTemps (X86ShiftFlagSF.afterTemps (X86ShiftFlagZF.afterTemps (X86ShiftFlagInputs.afterTemps
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
          ⟨X86.Flags.shiftCount size (rhs.setWidth 8), count_bound rhs size⟩) writeBlock writeOffset))) pfBlock pfOffset) pfHeap) := by
  have routed := X86ShiftFlagOF.route_through_overflow ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed nonzero zfBlock zfOffset middle zfPointer zfStored
    sfBlock sfOffset sfHeap sfPointer sfStored writeBlock writeOffset cfHeap cfPointer cfStored
    ofBlock readSFBlock readCFBlock ofOffset readSFOffset readCFOffset sf cf after
    ofPointer readSFPointer readCFPointer readSFByte readCFByte ofStored
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
  have keptResult : finalTemps.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8)))) := by
    dsimp only [finalTemps]
    rw [(X86ShiftFlagCF.temps _ writeBlock writeOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagCF.calculation_temps _ _ size n).2 _ (by decide +kernel)]
    dsimp only [reached]
    rw [(X86ShiftFlagSF.temps _ sfBlock sfOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    simpa only [X86.Value.trunc_trunc] using values.2.1
  have keptAlu : finalTemps.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32)) := by
    dsimp only [finalTemps]
    rw [(X86ShiftFlagCF.temps _ writeBlock writeOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagCF.calculation_temps _ _ size n).2 _ (by decide +kernel)]
    dsimp only [reached]
    rw [(X86ShiftFlagSF.temps _ sfBlock sfOffset).2 _ (by decide +kernel)]
    rw [(X86ShiftFlagZF.temps _ zfBlock zfOffset).2 _ (by decide +kernel)]
    exact values.2.2.2.2.2
  let completedTemps := if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then
    X86ShiftFlagOF.afterTemps finalTemps (.Vptr ofBlock ofOffset)
      (.Vptr readSFBlock readSFOffset) (.Vptr readCFBlock readCFOffset) sf cf
    else finalTemps
  have preserved (id : CC.Ident)
      (ne214 : id ≠ X86_program_profile_bpf._t'214)
      (ne215 : id ≠ X86_program_profile_bpf._t'215)
      (ne216 : id ≠ X86_program_profile_bpf._t'216)
      (ne217 : id ≠ X86_program_profile_bpf._t'217)
      (ne218 : id ≠ X86_program_profile_bpf._t'218) :
      completedTemps.get id = finalTemps.get id := by
    dsimp only [completedTemps]
    split
    · exact X86ShiftFlagOF.frame _ _ _ _ sf cf id ne214 ne215 ne216 ne217 ne218
    · rfl
  have finalBinding : completedTemps.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0) := by
    rw [preserved _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)]
    exact keptBinding
  have finalCount : completedTemps.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (BitVec.ofNat 32 n.val)) := by
    rw [preserved _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)]
    exact keptCount
  have finalResult : completedTemps.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8)))) := by
    rw [preserved _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)]
    exact keptResult
  have finalAlu : completedTemps.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32)) := by
    rw [preserved _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel)]
    exact keptAlu
  have codeNonzero : BitVec.ofNat 32 n.val ≠ 0 := by
    intro same
    have bounded : n.val < 2 ^ 32 := by have bound := n.isLt; omega
    have values := congrArg BitVec.toNat same
    simp only [BitVec.toNat_ofNat, Nat.mod_eq_of_lt bounded] at values
    exact nonzero values
  have wrote := after_overflow ge bindingsLayout valueLayout function e completedTemps
    (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) (if X86.Flags.shiftCount size (rhs.setWidth 8) = 1 then after else cfHeap) pfHeap bindingBlock pfBlock pfOffset (X86.Value.trunc size ((X86.Value.trunc size lhs) <<< X86.Flags.shiftCount size (rhs.setWidth 8)))
    finalBinding finalResult pfPointer pfStored
    (BitVec.ofNat 32 n.val) codeNonzero finalCount finalAlu
  exact routed.trans wrote

end KProgFormal.ClightRefinement.X86ShiftFlagPF
