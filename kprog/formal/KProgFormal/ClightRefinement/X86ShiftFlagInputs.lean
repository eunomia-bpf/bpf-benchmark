import KProgFormal.ClightRefinement.X86ShiftFlagWidths
import KProgFormal.ClightRefinement.X86ShiftCount

namespace KProgFormal.ClightRefinement.X86ShiftFlagInputs

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_inputs
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Pieces where
  left : CC.Stmt
  result : CC.Stmt
  count : CC.Stmt
  sign : CC.Stmt
  operation : CC.Stmt
  flags : CC.Stmt

private def pieces : Pieces :=
  match X86ShiftFlagWidths.rest with
  | .Ssequence left (.Ssequence result (.Ssequence count
      (.Ssequence sign (.Ssequence operation flags)))) =>
    ⟨left, result, count, sign, operation, flags⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def left : CC.Stmt := by run_tac cachePart (← `(pieces.left))
private def result : CC.Stmt := by run_tac cachePart (← `(pieces.result))
def count : CC.Stmt := by run_tac cachePart (← `(pieces.count))
private def sign : CC.Stmt := by run_tac cachePart (← `(pieces.sign))
private def operation : CC.Stmt := by run_tac cachePart (← `(pieces.operation))
def flags : CC.Stmt := by run_tac cachePart (← `(pieces.flags))

/-- All input preparation statements and the retained flag stage are original source. -/
theorem source : X86ShiftFlagWidths.rest =
    .Ssequence left (.Ssequence result (.Ssequence count
      (.Ssequence sign (.Ssequence operation flags)))) := rfl

def operandTemps (le : CC.TempEnv) (lhs value : BitVec 64) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_sh_a (.Vlong (X86.Value.trunc size lhs))).set
    X86_program_profile_bpf.___x86_sh_r (.Vlong (X86.Value.trunc size value))

def countValue (rhs : BitVec 64) (size : X86.Size) : CC.Val :=
  X86ShiftCount.result rhs (BitVec.ofNat 8 size.bytes)

def countTemps (le : CC.TempEnv) (rhs : BitVec 64) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'66 (countValue rhs size)).set
    X86_program_profile_bpf.___x86_sh_count (countValue rhs size)

def tailTemps (le : CC.TempEnv) (size : X86.Size) : CC.TempEnv :=
  (le.set X86_program_profile_bpf.___x86_sh_sign (.Vlong ((1#64) <<< (size.bits - 1)))).set
    X86_program_profile_bpf.___x86_sh_alu (.Vint (5#32))

def afterTemps (le : CC.TempEnv) (lhs rhs value : BitVec 64) (size : X86.Size) : CC.TempEnv :=
  tailTemps (countTemps (operandTemps le lhs value size) rhs size) size

/-- Original masks narrow both inputs with the mature ISA truncation operation. -/
theorem operands (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (lhs value : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (leftValue : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (resultValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (maskValue : le.get X86_program_profile_bpf.___x86_sh_mask = some (.Vlong size.mask)) :
    InternalRun ge 6 (.State function X86ShiftFlagWidths.rest k e le m)
      (.State function (.Ssequence count (.Ssequence sign (.Ssequence operation flags))) k e
        (operandTemps le lhs value size) m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, left, result, CC.doStep, CC.doEvalExpr,
      CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.classifyBinarith,
      CC.Cop.binarithType, CC.Cop.semBinarith, CC.Cop.semCast, CC.Cop.classifyCast,
       CC.tulong, CC.Integers.Int64.and, CC.Integers.MI.and,
      CC.PTree.gso, leftValue, resultValue, maskValue, operandTemps, X86.Value.trunc, CC.Eapp, CC.E0]


private def countAssign : CC.Stmt := by
  run_tac cachePart (← `(match count with | .Ssequence _ assignment => assignment | _ => .Sskip))

private theorem byteCast (value : BitVec 8) :
    value.setWidth 32 &&& (255#32) = value.setWidth 32 := by
  change value.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = value.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

private theorem count_plumbing (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_shift_count = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_shift_count))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_shift_count = none)
    (rhs : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (width : le.get X86_program_profile_bpf.___x86_sh_width = some (X86ShiftFlagWidths.argument size)) :
    ∃ callK, InternalRun ge 2 (.State function count k e le m)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_shift_count)
        [.Vlong rhs, X86ShiftCount.argument (BitVec.ofNat 8 size.bytes)] callK m) ∧
    InternalRun ge 3 (.Returnstate (countValue rhs size) (CC.callCont callK) m)
      (.State function .Sskip k e (countTemps le rhs size) m) := by
  obtain ⟨symbol, callee⟩ := binding
  have signature : CC.typeOfFundef (.Internal X86_program_profile_bpf.f_x86_shift_count) =
      .Tfunction [CC.tulong, CC.tuchar] CC.tuchar CC.cc_default := rfl
  refine ⟨.Kcall (some X86_program_profile_bpf._t'66) function e le
    (.Kseq countAssign k), ?beforeCall, ?afterCall⟩
  case beforeCall =>
    cases size <;> apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, count, countAssign,
        CC.typeof, CC.tulong,  CC.tuchar, CC.cc_default, CC.doStep, CC.doEvalExpr,
        CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.Cop.classifyFun,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Genv.findFunct,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, unshadowed, right, width,
        symbol, callee,  X86ShiftFlagWidths.argument, X86WidthShape.argument,
        X86ShiftCount.argument, X86.Size.bytes, CC.Eapp, CC.E0]
  case afterCall =>
    apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, countTemps, countAssign, countValue,
        X86ShiftCount.result, CC.doStep, CC.doEvalExpr, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.typeof, CC.tuchar, CC.Integers.Int.zero_ext,
        CC.Integers.MI.zero_ext, byteCast, CC.callCont, CC.setOpttemp, CC.Eapp, CC.E0]

/-- The genuine two-argument count call and its original assignment preserve the heap. -/
theorem count_internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_shift_count = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_shift_count))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_shift_count = none)
    (rhs : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (width : le.get X86_program_profile_bpf.___x86_sh_width = some (X86ShiftFlagWidths.argument size)) :
    InternalRun ge 11 (.State function count k e le m)
      (.State function .Sskip k e (countTemps le rhs size) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ :=
    count_plumbing ge block binding function e le unshadowed rhs size k m right width
  have body := X86ShiftCount.internal ge rhs (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans body).trans afterCall

/-- Source subtraction and shift derive the sign mask; the source cast retains operation five. -/
theorem tail (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (bits : le.get X86_program_profile_bpf.___x86_sh_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 6 (.State function (.Ssequence sign (.Ssequence operation flags)) k e le m)
      (.State function flags k e (tailTemps le size) m) := by
  cases size <;> apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, sign, operation, CC.doStep, CC.doEvalExpr,
      CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semShl, CC.Cop.semShift, CC.Cop.classifyShift,
      CC.Cop.semSub, CC.Cop.classifySub, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semBinarith,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, 
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int.sub, CC.Integers.MI.sub, CC.Integers.Int64.shl, CC.Integers.MI.shl,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.PTree.gso,  
      CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, bits, alu, tailTemps, X86.Size.bits, CC.Eapp, CC.E0]

/-- The actual count value is the mature x86 handler's count. -/
theorem native_count (rhs : BitVec 64) (size : X86.Size) :
    countValue rhs size = .Vint (BitVec.ofNat 32 (X86.Flags.shiftCount size (rhs.setWidth 8))) := by
  unfold countValue X86ShiftCount.result
  congr 1
  apply BitVec.eq_of_toNat_eq
  simp only [BitVec.toNat_setWidth, BitVec.toNat_ofNat]
  rw [X86ShiftCount.native_count]


private theorem sequence {ge : CC.CGenv} {n : Nat} {function : CC.Function}
    {head tail : CC.Stmt} {k : CC.Cont} {e : CC.Env} {le next : CC.TempEnv} {m : CC.Mem}
    (run : InternalRun ge n (.State function head (.Kseq tail k) e le m)
      (.State function .Sskip (.Kseq tail k) e next m)) :
    InternalRun ge (1 + n + 1) (.State function (.Ssequence head tail) k e le m)
      (.State function tail k e next m) := by
  have first : InternalRun ge 1 (.State function (.Ssequence head tail) k e le m)
      (.State function head (.Kseq tail k) e le m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  have last : InternalRun ge 1 (.State function .Sskip (.Kseq tail k) e next m)
      (.State function tail k e next m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (first.trans run).trans last

/-- Original operand masks, real count call and source sign/operation preparation
reach the original flag code for all operands and sizes in the same heap. -/
theorem internal (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_shift_count = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_shift_count))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_shift_count = none)
    (lhs rhs value : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (leftValue : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (resultValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (width : le.get X86_program_profile_bpf.___x86_sh_width = some (X86ShiftFlagWidths.argument size))
    (maskValue : le.get X86_program_profile_bpf.___x86_sh_mask = some (.Vlong size.mask))
    (bits : le.get X86_program_profile_bpf.___x86_sh_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    InternalRun ge 25 (.State function X86ShiftFlagWidths.rest k e le m)
      (.State function flags k e (afterTemps le lhs rhs value size) m) := by
  have start := operands ge function e le lhs value size k m leftValue resultValue maskValue
  have keptRight : (operandTemps le lhs value size).get X86_program_profile_bpf.___x86_l_rhs =
      some (.Vlong rhs) := by simp +decide [operandTemps, CC.PTree.gso, right]
  have keptWidth : (operandTemps le lhs value size).get X86_program_profile_bpf.___x86_sh_width =
      some (X86ShiftFlagWidths.argument size) := by simp +decide [operandTemps, CC.PTree.gso, width]
  have called := sequence (count_internal ge block binding function e (operandTemps le lhs value size)
    unshadowed rhs size (.Kseq (.Ssequence sign (.Ssequence operation flags)) k) m keptRight keptWidth)
  have keptBits : (countTemps (operandTemps le lhs value size) rhs size).get
      X86_program_profile_bpf.___x86_sh_bits = some (.Vint (BitVec.ofNat 32 size.bits)) := by
    simp +decide [countTemps, operandTemps, CC.PTree.gso, bits]
  have keptAlu : (countTemps (operandTemps le lhs value size) rhs size).get
      X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)) := by
    simp +decide [countTemps, operandTemps, CC.PTree.gso, alu]
  have finish := tail ge function e (countTemps (operandTemps le lhs value size) rhs size)
    size k m keptBits keptAlu
  exact (start.trans called).trans finish

/-- The relational execution keeps the entire caller memory at the actual flag entry. -/
theorem returns (ge : CC.CGenv) (block : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_shift_count = some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_shift_count))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_shift_count = none)
    (lhs rhs value : BitVec 64) (size : X86.Size) (k : CC.Cont) (m : CC.Mem)
    (leftValue : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (resultValue : le.get X86_program_profile_bpf.___x86_l_result = some (.Vlong value))
    (width : le.get X86_program_profile_bpf.___x86_sh_width = some (X86ShiftFlagWidths.argument size))
    (maskValue : le.get X86_program_profile_bpf.___x86_sh_mask = some (.Vlong size.mask))
    (bits : le.get X86_program_profile_bpf.___x86_sh_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)))
    (alu : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32))) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftFlagWidths.rest k e le m) CC.E0
      (.State function flags k e (afterTemps le lhs rhs value size) m) :=
  (internal ge block binding function e le unshadowed lhs rhs value size k m
    leftValue right resultValue width maskValue bits alu).sound

/-- Prepared source temporaries read back exactly the values supplied to the real flag code. -/
theorem temps (le : CC.TempEnv) (lhs rhs value : BitVec 64) (size : X86.Size) :
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf.___x86_sh_a =
      some (.Vlong (X86.Value.trunc size lhs)) ∧
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf.___x86_sh_r =
      some (.Vlong (X86.Value.trunc size value)) ∧
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf._t'66 =
      some (countValue rhs size) ∧
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf.___x86_sh_count =
      some (countValue rhs size) ∧
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf.___x86_sh_sign =
      some (.Vlong ((1#64) <<< (size.bits - 1))) ∧
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf.___x86_sh_alu =
      some (.Vint (5#32)) := by
  simp +decide [afterTemps, tailTemps, countTemps, operandTemps, CC.PTree.gso]

/-- Every temporary outside the six original writes retains its input value. -/
theorem frame (le : CC.TempEnv) (lhs rhs value : BitVec 64) (size : X86.Size) (id : CC.Ident)
    (leftNe : id ≠ X86_program_profile_bpf.___x86_sh_a)
    (resultNe : id ≠ X86_program_profile_bpf.___x86_sh_r)
    (countCallNe : id ≠ X86_program_profile_bpf._t'66)
    (countNe : id ≠ X86_program_profile_bpf.___x86_sh_count)
    (signNe : id ≠ X86_program_profile_bpf.___x86_sh_sign)
    (aluNe : id ≠ X86_program_profile_bpf.___x86_sh_alu) :
    (afterTemps le lhs rhs value size).get id = le.get id := by
  simp [afterTemps, tailTemps, countTemps, operandTemps, CC.PTree.gso,
    Ne.symm leftNe, Ne.symm resultNe, Ne.symm countCallNe,
    Ne.symm countNe, Ne.symm signNe, Ne.symm aluNe]


/-- Original arithmetic, old-CF reads, classification, width calls and input preparation
compose to the actual flag code with a derived mature result and unchanged heap. -/
theorem route_to_flags (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
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
    (countUnshadowed : e.get X86_program_profile_bpf._x86_shift_count = none) :
    InternalRun ge ((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) +
      X86ShiftFlagWidths.length size) + 25)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function flags
        (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) e
        (afterTemps (X86ShiftFlagWidths.afterTemps
          (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
            (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
            cfBlock offset old)) size) lhs rhs
          (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size) m) := by
  have routed := X86ShiftFlagWidths.route_to_operands ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
  let incoming := X86ShiftFlagWidths.afterTemps
          (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
            (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
            cfBlock offset old)) size
  let resultBits := X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))
  have keptLeft : incoming.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs) := by
    dsimp only [incoming]
    rw [X86ShiftFlagWidths.frame _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftClassify.temps _).2 _ (by decide +kernel)]
    rw [(X86ShiftLeftCarry.temps _ cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftSite.temps le (X86ShiftLeft.result lhs rhs size)).2.2
      _ (by decide +kernel) (by decide +kernel)]
    exact left
  have keptRight : incoming.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs) := by
    dsimp only [incoming]
    rw [X86ShiftFlagWidths.frame _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftClassify.temps _).2 _ (by decide +kernel)]
    rw [(X86ShiftLeftCarry.temps _ cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftSite.temps le (X86ShiftLeft.result lhs rhs size)).2.2
      _ (by decide +kernel) (by decide +kernel)]
    exact right
  have keptAlu : incoming.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (5#32)) := by
    dsimp only [incoming]
    rw [X86ShiftFlagWidths.frame _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftClassify.temps _).2 _ (by decide +kernel)]
    rw [(X86ShiftLeftCarry.temps _ cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftSite.temps le (X86ShiftLeft.result lhs rhs size)).2.2
      _ (by decide +kernel) (by decide +kernel)]
    exact operation
  have keptResult : incoming.get X86_program_profile_bpf.___x86_l_result = some (.Vlong resultBits) := by
    dsimp only [incoming]
    rw [X86ShiftFlagWidths.frame _ size _ (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    rw [(X86ShiftLeftClassify.temps _).2 _ (by decide +kernel)]
    rw [(X86ShiftLeftCarry.temps _ cfBlock offset old).2.2.2 _
      (by decide +kernel) (by decide +kernel) (by decide +kernel)]
    simpa only [X86ShiftLeft.result, resultBits] using
      (X86ShiftLeftSite.temps le (X86ShiftLeft.result lhs rhs size)).1
  have values := X86ShiftFlagWidths.temps
    (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
      (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size)) cfBlock offset old)) size
  have prepared := internal ge countBlock countBinding function e incoming countUnshadowed
    lhs rhs resultBits size
    (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) m
    keptLeft keptRight keptResult values.2.2.1 values.2.2.2.2.2.2 values.2.2.2.2.1 keptAlu
  exact routed.trans prepared


private def countTest : CC.Expr :=
  .Ebinop .One (.Etempvar X86_program_profile_bpf.___x86_sh_count CC.tuchar)
    (.Econst_int (0#32) CC.tint) CC.tint

private def activeFlags : CC.Stmt := by
  run_tac cachePart (← `(match X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_87 with
    | .Sifthenelse _ active _ => active | _ => .Sskip))

/-- The original flag stage retains its active-count arm and parity continuation. -/
theorem flags_source : flags =
    .Ssequence (.Sloop (.Sifthenelse countTest activeFlags .Sskip) .Sbreak)
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89 := rfl

/-- Zero effective count traverses the original flag loop and parity short circuit,
preserving every byte of the caller heap and recording the real short-circuit write. -/
theorem zero_count_internal (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (zero : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (0#32))) :
    InternalRun ge 11 (.State function flags k e le m)
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'70 (.Vint (0#32))) m) := by
  rw [flags_source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep,
       CC.typeof,
      X86_program_profile_bpf.s_x86_sim_inline_arm_ALU_REG_89,
      CC.doEvalExpr, countTest, zero, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
      CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint,
        CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Val.ofBool, CC.Val.Vfalse,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Eapp, CC.E0]

/-- The actual zero-count flag code is a silent relational execution preserving the full heap. -/
theorem zero_count_returns (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem)
    (zero : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (0#32))) :
    CC.Star (CC.Step2 ge) (.State function flags k e le m) CC.E0
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'70 (.Vint (0#32))) m) :=
  (zero_count_internal ge function e le k m zero).sound

/-- The sole source short-circuit write retains every other temporary. -/
theorem zero_count_temps (le : CC.TempEnv) :
    (le.set X86_program_profile_bpf._t'70 (.Vint (0#32))).get
      X86_program_profile_bpf._t'70 = some (.Vint (0#32)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'70 →
      (le.set X86_program_profile_bpf._t'70 (.Vint (0#32))).get id = le.get id := by
  refine ⟨by simp, ?_⟩
  intro id different
  simp [CC.PTree.gso, Ne.symm different]


private theorem zero_count_readback (le : CC.TempEnv) (lhs rhs value : BitVec 64) (size : X86.Size)
    (zero : X86.Flags.shiftCount size (rhs.setWidth 8) = 0) :
    (afterTemps le lhs rhs value size).get X86_program_profile_bpf.___x86_sh_count =
      some (.Vint (0#32)) := by
  rw [(temps le lhs rhs value size).2.2.2.1, native_count, zero]

/-- The actual SHL route with a zero mature masked count reaches its original
post-flag continuation with the complete incoming heap and exact source temporary map. -/
theorem route_zero_flags (ge : CC.CGenv) (aluBlock shiftBlock : CC.Block)
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
    (zero : X86.Flags.shiftCount size (rhs.setWidth 8) = 0) :
    InternalRun ge (((((3 + X86ShiftLeftSite.length size + 1) + 11 + 37) +
      X86ShiftFlagWidths.length size) + 25) + 11)
      (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function .Sskip
        (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) e
        ((afterTemps (X86ShiftFlagWidths.afterTemps
          (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
            (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
            cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size).set X86_program_profile_bpf._t'70 (.Vint (0#32))) m) := by
  have routed := route_to_flags ge aluBlock shiftBlock binding shiftBinding
    function e le unshadowed lhs rhs size left right operation width k m
    bindingsLayout valueLayout bindingBlock cfBlock offset old heapBinding pointer byte
    effectiveBlock bitsBlock maskBlock effectiveBinding bitsBinding maskBinding widthsUnshadowed
    countBlock countBinding countUnshadowed
  let prepared := afterTemps (X86ShiftFlagWidths.afterTemps
          (X86ShiftLeftClassify.afterTemps (X86ShiftLeftCarry.afterTemps
            (X86ShiftLeftSite.afterTemps le (X86ShiftLeft.result lhs rhs size))
            cfBlock offset old)) size) lhs rhs (X86.Value.trunc size ((X86.Value.trunc size lhs) <<<
          X86.Flags.shiftCount size (rhs.setWidth 8))) size
  have counted : prepared.get X86_program_profile_bpf.___x86_sh_count =
      some (.Vint (0#32)) := by
    exact zero_count_readback _ lhs rhs _ size zero
  exact routed.trans (zero_count_internal ge function e prepared
    (X86ShiftFlagWidths.continuation (.Kswitch (X86ShiftLeftCarry.continuation k))) m counted)

end KProgFormal.ClightRefinement.X86ShiftFlagInputs
