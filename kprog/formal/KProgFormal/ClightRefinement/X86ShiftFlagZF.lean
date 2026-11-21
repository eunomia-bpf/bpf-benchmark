import KProgFormal.ClightRefinement.X86ShiftFlagInputs

namespace KProgFormal.ClightRefinement.X86ShiftFlagZF

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_zf
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Pieces where
  countTest : CC.Expr
  rolTest : CC.Expr
  rol : CC.Stmt
  zf : CC.Stmt
  rest : CC.Stmt

private def pieces : Pieces :=
  match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_87 with
  | .Sifthenelse c (.Sifthenelse r rol (.Ssequence zf rest)) .Sskip =>
    ⟨c, r, rol, zf, rest⟩
  | _ => ⟨.Econst_int (0#32) CC.tint, .Econst_int (0#32) CC.tint, .Sskip, .Sskip, .Sskip⟩

private def countTest : CC.Expr := by run_tac cachePart (← `(pieces.countTest))
private def rolTest : CC.Expr := by run_tac cachePart (← `(pieces.rolTest))
private def rol : CC.Stmt := by run_tac cachePart (← `(pieces.rol))
def zf : CC.Stmt := by run_tac cachePart (← `(pieces.zf))
def rest : CC.Stmt := by run_tac cachePart (← `(pieces.rest))

/-- Both original selection tests, the ZF write and following flag code retain source identity. -/
theorem source : X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_87 =
    .Sifthenelse countTest (.Sifthenelse rolTest rol (.Ssequence zf rest)) .Sskip := rfl

private def fieldMembers : List CC.Member := by
  run_tac cachePart (← `(X86ShiftLeftCarry.bindingsRecord.co_members))

/-- The actual source member list places the ZF pointer immediately after CF. -/
theorem zf_offset (ce : CC.CompositeEnv)
    (valueLayout : ce.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord) :
    CC.fieldOffset ce X86_program_profile_bpf._zf X86ShiftLeftCarry.bindingsRecord.co_members =
      .OK (128, .Full) := by
  change CC.fieldOffset ce X86_program_profile_bpf._zf fieldMembers = .OK (128, .Full)
  have size : X86ShiftLeftCarry.valueRecord.co_sizeof = 16 := rfl
  have align : X86ShiftLeftCarry.valueRecord.co_alignof = 8 := rfl
  simp +decide [fieldMembers, CC.fieldOffset, CC.fieldOffsetRec, CC.layoutField,
    CC.nextField, CC.bitalignof, CC.bitsizeof, CC.alignof, CC.sizeof, CC.alignAttr, CC.Ty.attr,
    CC.align, CC.zdiv, CC.tptr, CC.tarray, CC.noattr, valueLayout, size, align]

def bit (value : BitVec 64) : CC.Val := .Vint (if value = 0 then 1 else 0)

def afterTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'221 (.Vptr block offset)

private def pointerExpr : CC.Expr := by
  run_tac cachePart (← `(match zf with
    | .Ssequence (.Sset _ rhs) _ => rhs
    | _ => .Econst_int (0#32) CC.tint))
private def targetExpr : CC.Expr := by
  run_tac cachePart (← `(match zf with
    | .Ssequence _ (.Sassign target _) => target
    | _ => .Econst_int (0#32) CC.tint))
private def valueExpr : CC.Expr := by
  run_tac cachePart (← `(match zf with
    | .Ssequence _ (.Sassign _ rhs) => rhs
    | _ => .Econst_int (0#32) CC.tint))

private theorem zf_source : zf =
    .Ssequence (.Sset X86_program_profile_bpf._t'221 pointerExpr)
      (.Sassign targetExpr valueExpr) := rfl

/-- The actual ZF pointer read and byte store execute with the original current-heap operations. -/
theorem internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock zfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after) :
    InternalRun ge 4 (.State function zf k e le m)
      (.State function .Sskip k e (afterTemps le zfBlock offset) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._zf (.Vptr bindingBlock 0) = some (bindingBlock, 128, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, zf_offset ge.genv_cenv valueLayout]
    rfl
  have unsigned128 : CC.Integers.Ptrofs.unsigned (128 : CC.Integers.Ptrofs) = 128 := rfl
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have pointerRead : CC.doEvalExpr ge e le m pointerExpr = some (.Vptr zfBlock offset) := by
    simp only [pointerExpr, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      structAccess, ptrAccess, CC.Mem.loadv, binding, address, unsigned128, pointer]
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have valueType : CC.typeof valueExpr = CC.tint := rfl
  have targetLoc : CC.doEvalLvalue ge e (afterTemps le zfBlock offset) m targetExpr =
      some (zfBlock, offset, .Full) := by
    simp only [targetExpr, CC.doEvalLvalue, CC.doEvalExpr, afterTemps, CC.PTree.gss]
  have keptResult : (afterTemps le zfBlock offset).get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong value) := by
    simp +decide [afterTemps, CC.PTree.gso, result]
  have signedZero64 : BitVec.ofInt 64 (CC.Integers.Int.signed (0#32)) =
      (0 : BitVec 64) := rfl
  have evaluated : CC.doEvalExpr ge e (afterTemps le zfBlock offset) m valueExpr =
      some (bit value) := by
    by_cases zero : value = 0
    all_goals
      simp +decide [valueExpr, CC.doEvalExpr, CC.typeof, keptResult,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
         CC.Cop.castIntLong, CC.tulong, CC.tint, CC.typeconv,
        CC.removeAttributes, CC.tattr, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
         CC.Integers.MI.eq, CC.Integers.Int.repr,
        CC.Integers.Int64.repr, CC.Integers.MI.repr, CC.Integers.MI.zero,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.zero,
        CC.Integers.Int.one, CC.Integers.MI.one, signedZero64, bit, zero, apply_ite]
  have byteCast : CC.Cop.semCast (bit value) CC.tint CC.tuchar m = some (bit value) := by
    unfold bit
    split <;> rfl
  have assignment : CC.doAssignLoc ge.genv_cenv CC.tuchar m zfBlock offset .Full (bit value) =
      some after := by
    simp only [CC.doAssignLoc, charAccess, CC.Mem.storev, stored]
  dsimp only [afterTemps] at targetLoc evaluated
  rw [zf_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, pointerRead, targetLoc,
      targetType, valueType, evaluated, byteCast, assignment, afterTemps,
      CC.Eapp, CC.E0, List.nil_append, true_and]


/-- The written zero flag is the existing mature shift flag's ZF for every oracle choice. -/
theorem native_value (size : X86.Size) (lhs value : BitVec 64) (n : Nat)
    (cfU ofU afU : Bool) (before : X86.Flags) :
    bit (X86.Value.trunc size value) =
      .Vint (if (X86.Flags.shiftFlags .shl size lhs value n cfU ofU afU before).zf then 1 else 0) := by
  change bit (X86.Value.trunc size value) =
    .Vint (if X86.Value.isZero size value then 1 else 0)
  by_cases zero : X86.Value.trunc size value = 0
  all_goals simp [bit, X86.Value.isZero, zero]


private def flagBody : CC.Stmt :=
  .Sifthenelse countTest (.Sifthenelse rolTest rol (.Ssequence zf rest)) .Sskip

def continuation (k : CC.Cont) : CC.Cont :=
  .Kloop1 flagBody .Sbreak (.Kseq X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 k)

/-- The actual source loop and parity continuation enclose the original active flag arm. -/
theorem flags_source : X86ShiftFlagInputs.flags =
    .Ssequence (.Sloop flagBody .Sbreak)
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 := rfl

/-- Every nonzero effective SHL count selects the original ZF store and remaining flag suffix. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    InternalRun ge 5 (.State function X86ShiftFlagInputs.flags k e le m)
      (.State function zf (.Kseq rest (continuation k)) e le m) := by
  have evaluated : CC.doEvalExpr ge e le m countTest = some (.Vint (1#32)) ∧
      CC.doEvalExpr ge e le m rolTest = some (.Vint (0#32)) := by
    constructor <;>
      simp +decide [countTest, rolTest, CC.doEvalExpr, CC.typeof, count, alu,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint,
        CC.Integers.Int.cmp, CC.Integers.MI.cmp,  
         CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
        CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.one, CC.Integers.MI.one,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse]
    all_goals exact nonzero
  have countType : CC.typeof countTest = CC.tint := rfl
  have rolType : CC.typeof rolTest = CC.tint := rfl
  have trueInt : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  have falseInt : CC.Cop.boolVal (.Vint (0#32)) CC.tint m = some false := rfl
  rw [flags_source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, flagBody, continuation,
      evaluated.1, evaluated.2, countType, rolType, trueInt, falseInt,  
      CC.Eapp, CC.E0]

/-- The source pointer temporary reads back its actual field value and frames every other temp. -/
theorem temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    (afterTemps le block offset).get X86_program_profile_bpf._t'221 =
      some (.Vptr block offset) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'221 →
      (afterTemps le block offset).get id = le.get id := by
  refine ⟨by simp [afterTemps], ?_⟩
  intro id different
  simp [afterTemps, CC.PTree.gso, Ne.symm different]

/-- The actual nonzero SHL flag path performs its genuine ZF byte write before
continuing to the untouched SF/CF/OF code with the exact new heap. -/
theorem to_remaining_flags (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock zfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after)
    (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    InternalRun ge 10 (.State function X86ShiftFlagInputs.flags k e le m)
      (.State function rest (continuation k) e (afterTemps le zfBlock offset) after) := by
  have selected := select ge function e le k m code nonzero count alu
  have wrote := internal ge bindingsLayout valueLayout function e le (.Kseq rest (continuation k))
    m after bindingBlock zfBlock offset value binding result pointer stored
  have finish : InternalRun ge 1
      (.State function .Sskip (.Kseq rest (continuation k)) e (afterTemps le zfBlock offset) after)
      (.State function rest (continuation k) e (afterTemps le zfBlock offset) after) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (selected.trans wrote).trans finish

/-- Complete source relational execution reaches the remaining flags with the actual updated heap. -/
theorem returns (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock zfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf.___x86_sh_r = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned offset)
      (bit value) = some after)
    (code : BitVec 32) (nonzero : code ≠ 0)
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint code))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftFlagInputs.flags k e le m) CC.E0
      (.State function rest (continuation k) e (afterTemps le zfBlock offset) after) :=
  (to_remaining_flags ge bindingsLayout valueLayout function e le k m after bindingBlock zfBlock
    offset value binding result pointer stored code nonzero count alu).sound


private theorem count_nonzero (rhs : BitVec 64) (size : X86.Size)
    (nonzero : X86.Flags.shiftCount size (rhs.setWidth 8) ≠ 0) :
    (X86ShiftCount.count rhs (BitVec.ofNat 8 size.bytes)).setWidth 32 ≠ (0#32) := by
  intro equal
  have low := congrArg (fun v : BitVec 32 => v.setWidth 8) equal
  have zero : X86ShiftCount.count rhs (BitVec.ofNat 8 size.bytes) = 0 := by simpa using low
  have native := X86ShiftCount.native_count rhs size
  rw [zero] at native
  exact nonzero native.symm

/-- The original nonzero SHL path derives every intermediate observation before
performing the actual ZF byte store and reaching its remaining flag code. -/
theorem route_to_remaining_flags (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
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
    (zfBlock : CC.Block) (zfOffset : CC.Integers.Ptrofs) (after : CC.Mem)
    (zfPointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock zfOffset))
    (zfStored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned zfOffset)
      (bit (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8)))) = some after) :
    InternalRun ge (((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) +
      X86ShiftFlagWidths.length size) + 25) + 10)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function rest (continuation
        (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k)))) e
        (afterTemps (X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size) zfBlock zfOffset) after) := by
  have routed := X86ShiftFlagInputs.route_to_flags ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed
  let prepared := X86ShiftFlagInputs.afterTemps
          (X86ShiftFlagWidths.afterTemps
            (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
              (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
              cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size
  let resultBits := X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))
  have keptBinding : prepared.get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
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
      lhs rhs resultBits size
  have keptResult : prepared.get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong resultBits) := by
    simpa only [resultBits, X86.Value.trunc_trunc] using values.2.1
  have wrote := to_remaining_flags ge bindingsLayout valueLayout function e prepared
    (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) m after
    bindingBlock zfBlock zfOffset resultBits keptBinding keptResult zfPointer zfStored
    ((X86ShiftCount.count rhs (BitVec.ofNat 8 size.bytes)).setWidth 32)
    (count_nonzero rhs size nonzero) values.2.2.2.1 values.2.2.2.2.2
  exact routed.trans wrote

end KProgFormal.ClightRefinement.X86ShiftFlagZF
