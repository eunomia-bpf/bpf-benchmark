import KProgFormal.ClightRefinement.X86ShiftFlagSF

namespace KProgFormal.ClightRefinement.X86ShiftFlagCF

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_shift_cf
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private structure Pieces where
  test : CC.Expr
  calculation : CC.Stmt
  store : CC.Stmt
  overflow : CC.Stmt
  other : CC.Stmt

private def pieces : Pieces :=
  match X86ShiftFlagSF.rest with
  | .Sifthenelse test (.Ssequence (.Ssequence calculation store) overflow) other =>
    ⟨test, calculation, store, overflow, other⟩
  | _ => ⟨.Econst_int (0#32) CC.tint, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def test : CC.Expr := by run_tac cachePart (← `(pieces.test))
def calculation : CC.Stmt := by run_tac cachePart (← `(pieces.calculation))
def cf : CC.Stmt := by run_tac cachePart (← `(pieces.store))
def overflow : CC.Stmt := by run_tac cachePart (← `(pieces.overflow))
private def other : CC.Stmt := by run_tac cachePart (← `(pieces.other))

/-- The actual SHL gate, carry calculation, byte store and overflow continuation are source statements. -/
theorem source : X86ShiftFlagSF.rest =
    .Sifthenelse test (.Ssequence (.Ssequence calculation cf) overflow) other := rfl

def byte (value : BitVec 64) : CC.Val := .Vint (value.setWidth 32 &&& (255#32))

def afterTemps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) : CC.TempEnv :=
  le.set X86_program_profile_bpf._t'219 (.Vptr block offset)

private def pointerExpr : CC.Expr := by
  run_tac cachePart (← `(match cf with
    | .Ssequence (.Sset _ rhs) _ => rhs
    | _ => .Econst_int (0#32) CC.tint))
private def targetExpr : CC.Expr := by
  run_tac cachePart (← `(match cf with
    | .Ssequence _ (.Sassign target _) => target
    | _ => .Econst_int (0#32) CC.tint))
private def valueExpr : CC.Expr := by
  run_tac cachePart (← `(match cf with
    | .Ssequence _ (.Sassign _ rhs) => rhs
    | _ => .Econst_int (0#32) CC.tint))

private theorem cf_source : cf =
    .Ssequence (.Sset X86_program_profile_bpf._t'219 pointerExpr)
      (.Sassign targetExpr valueExpr) := rfl

/-- The actual CF pointer read and byte store execute with the original current-heap operations. -/
theorem internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf._t'67 = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset)
      (byte value) = some after) :
    InternalRun ge 4 (.State function cf k e le m)
      (.State function .Sskip k e (afterTemps le cfBlock offset) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cf (.Vptr bindingBlock 0) = some (bindingBlock, 120, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftLeftCarry.cf_offset ge.genv_cenv valueLayout]
    rfl
  have unsigned120 : CC.Integers.Ptrofs.unsigned (120 : CC.Integers.Ptrofs) = 120 := rfl
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (.Tpointer CC.tuchar CC.noattr) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have pointerRead : CC.doEvalExpr ge e le m pointerExpr = some (.Vptr cfBlock offset) := by
    simp only [pointerExpr, CC.doEvalExpr, CC.doDerefLoc, CC.typeof, CC.tptr,
      structAccess, ptrAccess, CC.Mem.loadv, binding, address, unsigned120, pointer]
  have targetType : CC.typeof targetExpr = CC.tuchar := rfl
  have valueType : CC.typeof valueExpr = CC.tulong := rfl
  have targetLoc : CC.doEvalLvalue ge e (afterTemps le cfBlock offset) m targetExpr =
      some (cfBlock, offset, .Full) := by
    simp only [targetExpr, CC.doEvalLvalue, CC.doEvalExpr, afterTemps, CC.PTree.gss]
  have keptResult : (afterTemps le cfBlock offset).get X86_program_profile_bpf._t'67 =
      some (.Vlong value) := by
    simp +decide [afterTemps, CC.PTree.gso, result]
  have evaluated : CC.doEvalExpr ge e (afterTemps le cfBlock offset) m valueExpr =
      some (.Vlong value) := by
    simp only [valueExpr, CC.doEvalExpr, keptResult]
  have byteCast : CC.Cop.semCast (.Vlong value) CC.tulong CC.tuchar m = some (byte value) := by
    rfl
  have assignment : CC.doAssignLoc ge.genv_cenv CC.tuchar m cfBlock offset .Full (byte value) =
      some after := by
    simp only [CC.doAssignLoc, charAccess, CC.Mem.storev, stored]
  dsimp only [afterTemps] at targetLoc evaluated
  rw [cf_source]
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, CC.doStep, pointerRead, targetLoc,
      targetType, valueType, evaluated, byteCast, assignment, afterTemps,
      CC.Eapp, CC.E0, List.nil_append, true_and]






/-- Operation five follows the original SHL arm and reaches its real carry calculation. -/
theorem select (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem)
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32))) :
    InternalRun ge 3 (.State function X86ShiftFlagSF.rest k e le m)
      (.State function calculation (.Kseq cf (.Kseq overflow k)) e le m) := by
  have evaluated : CC.doEvalExpr ge e le m test = some (.Vint (1#32)) := by
    simp +decide [test, CC.doEvalExpr, CC.typeof, alu, CC.Cop.semBinaryOperation,
      CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
      CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint,

      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Val.ofBool, CC.Val.Vtrue]
  have type : CC.typeof test = CC.tint := rfl
  have truth : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, evaluated, type, truth, CC.Eapp, CC.E0]

/-- Arithmetic shape of the original carry expression, before the byte cast. -/
def payload (value : BitVec 64) (bits n : Nat) : BitVec 64 :=
  if n ≤ bits then (value >>> (bits - n)) &&& (1#64) else 0

def carryBit (size : X86.Size) (lhs : BitVec 64) (n : Nat) : Bool :=
  if n ≤ size.bits then (X86.Value.trunc size lhs).getLsbD (size.bits - n) else false

/-- The source qword-to-byte cast returns its single carry bit exactly. -/
theorem payload_byte (value : BitVec 64) (bits n : Nat) :
    byte (payload value bits n) =
      .Vint (if (if n ≤ bits then value.getLsbD (bits - n) else false) then 1 else 0) := by
  by_cases within : n ≤ bits
  · simp only [payload, within, ite_true]
    rw [BitVec.and_one_eq_setWidth_ofBool_getLsbD]
    simp only [BitVec.getLsbD_ushiftRight, Nat.add_zero]
    cases value.getLsbD (bits - n) <;> rfl
  · simp only [payload, within, ite_false]
    rfl

/-- Defined CF matches the mature ISA bit; in its undefined range the same computed
bit supplies a valid oracle choice, for every value, size and positive count. -/
theorem native_value (size : X86.Size) (lhs value : BitVec 64) (n : Nat) (positive : 0 < n)
    (ofU afU : Bool) (before : X86.Flags) :
    byte (payload (X86.Value.trunc size lhs) size.bits n) =
      .Vint (if (X86.Flags.shiftFlags .shl size lhs value n
        (carryBit size lhs n) ofU afU before).cf then 1 else 0) := by
  rw [payload_byte]
  change CC.Val.Vint (if carryBit size lhs n then 1 else 0) =
    .Vint (if (if size.bits ≤ n then carryBit size lhs n
      else lhs.getLsbD (size.bits - n)) then 1 else 0)
  by_cases beyond : size.bits ≤ n
  · simp only [beyond, ite_true]
  · have within : n ≤ size.bits := by omega
    have index : size.bits - n < size.bits := by omega
    simp only [beyond, ite_false, carryBit, within, ite_true,
      X86.Value.trunc_getLsbD_low size lhs (size.bits - n) index]

/-- The genuine carry storage has a silent relational execution with the exact new heap. -/
theorem returns (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (result : le.get X86_program_profile_bpf._t'67 = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset)
      (byte value) = some after) :
    CC.Star (CC.Step2 ge) (.State function cf k e le m) CC.E0
      (.State function .Sskip k e (afterTemps le cfBlock offset) after) :=
  (internal ge bindingsLayout valueLayout function e le k m after bindingBlock cfBlock
    offset value binding result pointer stored).sound

/-- The sole source pointer write frames every other temporary. -/
theorem temps (le : CC.TempEnv) (block : CC.Block) (offset : CC.Integers.Ptrofs) :
    (afterTemps le block offset).get X86_program_profile_bpf._t'219 = some (.Vptr block offset) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'219 →
      (afterTemps le block offset).get id = le.get id := by
  refine ⟨by simp [afterTemps], ?_⟩
  intro id different
  simp [afterTemps, CC.PTree.gso, Ne.symm different]


def calculationTemps (le : CC.TempEnv) (value : BitVec 64) (size : X86.Size) (n : Fin 64) :
    CC.TempEnv :=
  le.set X86_program_profile_bpf._t'67 (.Vlong (payload value size.bits n.val))

/-- The actual unsigned comparison and source shift derive the carry payload,
including the original zero arm for counts above the operand width. -/
theorem calculation_internal (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) (value : BitVec 64) (size : X86.Size)
    (n : Fin 64) (positive : 0 < n.val)
    (count : le.get X86_program_profile_bpf.___x86_sh_count =
      some (.Vint (BitVec.ofNat 32 n.val)))
    (bits : le.get X86_program_profile_bpf.___x86_sh_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)))
    (left : le.get X86_program_profile_bpf.___x86_sh_a = some (.Vlong value)) :
    InternalRun ge 2 (.State function calculation k e le m)
      (.State function .Sskip k e (calculationTemps le value size n) m) := by
  have count32 : n.val < 4294967296 := by have bound := n.isLt; omega
  have bits32 : size.bits < 4294967296 := by cases size <;> decide
  have bits64 : size.bits ≤ 64 := by cases size <;> decide
  have countNat : (BitVec.ofNat 32 n.val).toNat = n.val := Nat.mod_eq_of_lt count32
  have bitsNat : (BitVec.ofNat 32 size.bits).toNat = size.bits := Nat.mod_eq_of_lt bits32
  have signedZero64 : BitVec.ofInt 64 (CC.Integers.Int.signed (0#32)) = (0#64) := rfl
  have signedOne64 : BitVec.ofInt 64 (CC.Integers.Int.signed (1#32)) = (1#64) := rfl
  by_cases within : n.val ≤ size.bits
  · have difference : BitVec.ofNat 32 size.bits - BitVec.ofNat 32 n.val =
        BitVec.ofNat 32 (size.bits - n.val) :=
      BitVec.ofNat_sub_ofNat_of_le size.bits n.val count32 within
    have shiftBound : size.bits - n.val < 64 := by omega
    have shift32 : size.bits - n.val < 4294967296 := by omega
    have shift64 : size.bits - n.val < 18446744073709551616 := by omega
    have shiftNat : (BitVec.ofNat 32 (size.bits - n.val)).toNat = size.bits - n.val :=
      Nat.mod_eq_of_lt shift32
    apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, calculation, calculationTemps, payload,
        CC.doStep, CC.doEvalExpr, CC.typeof, count, bits, left, within,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.semSub, CC.Cop.classifySub,
        CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semAnd,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
        CC.Integers.Int.cmpu, CC.Integers.MI.cmpu, CC.Integers.Int.ltu, CC.Integers.MI.ltu,
        CC.Integers.Int.sub, CC.Integers.MI.sub, CC.Integers.Int64.shru, CC.Integers.MI.shru,
        CC.Integers.Int64.and, CC.Integers.MI.and, CC.Integers.Int.repr,
        CC.Integers.Int64.repr, CC.Integers.MI.repr, CC.Integers.Int.unsigned,
         CC.Integers.MI.unsigned, CC.Val.ofBool, CC.Val.Vtrue,
         CC.Integers.Int.one, CC.Integers.Int.zero, CC.Integers.MI.one,
        CC.Integers.MI.zero, BitVec.ult, countNat, bitsNat,
        CC.Cop.boolVal, CC.Cop.classifyBool,  signedOne64, CC.Eapp, CC.E0, difference, shiftNat, shiftBound,  Nat.mod_eq_of_lt shift64]
  · apply internalRun_of_steps
    all_goals
      simp +decide [steps, InternalPath, InternalState, calculation, calculationTemps, payload,
        CC.doStep, CC.doEvalExpr, CC.typeof, count, bits,  within,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong,

        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tulong,
        CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,  CC.Integers.MI.ltu,

          CC.Integers.Int.repr,
        CC.Integers.Int64.repr, CC.Integers.MI.repr,
          CC.Val.ofBool,
        CC.Val.Vfalse,  CC.Integers.Int.zero,
        CC.Integers.MI.zero, BitVec.ult, countNat, bitsNat,
        CC.Cop.boolVal, CC.Cop.classifyBool, signedZero64,  CC.Eapp, CC.E0]


/-- The genuine calculation writes its derived payload and retains every other temporary. -/
theorem calculation_temps (le : CC.TempEnv) (value : BitVec 64) (size : X86.Size) (n : Fin 64) :
    (calculationTemps le value size n).get X86_program_profile_bpf._t'67 =
      some (.Vlong (payload value size.bits n.val)) ∧
    ∀ id, id ≠ X86_program_profile_bpf._t'67 →
      (calculationTemps le value size n).get id = le.get id := by
  refine ⟨by simp [calculationTemps], ?_⟩
  intro id different
  simp [calculationTemps, CC.PTree.gso, Ne.symm different]

/-- Original SHL selection, comparison, shift and carry byte storage reach the
actual overflow code, deriving the payload and exact updated heap. -/
theorem to_overflow (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64) (size : X86.Size) (n : Fin 64) (positive : 0 < n.val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (left : le.get X86_program_profile_bpf.___x86_sh_a = some (.Vlong value))
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (BitVec.ofNat 32 n.val)))
    (bits : le.get X86_program_profile_bpf.___x86_sh_bits = some (.Vint (BitVec.ofNat 32 size.bits)))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32)))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset)
      (byte (payload value size.bits n.val)) = some after) :
    InternalRun ge 11 (.State function X86ShiftFlagSF.rest k e le m)
      (.State function overflow k e
        (afterTemps (calculationTemps le value size n) cfBlock offset) after) := by
  have selected := select ge function e le k m alu
  have calculated := calculation_internal ge function e le (.Kseq cf (.Kseq overflow k)) m
    value size n positive count bits left
  have resumed : InternalRun ge 1
      (.State function .Sskip (.Kseq cf (.Kseq overflow k)) e (calculationTemps le value size n) m)
      (.State function cf (.Kseq overflow k) e (calculationTemps le value size n) m) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  have keptBinding : (calculationTemps le value size n).get X86_program_profile_bpf.___x86_bind =
      some (.Vptr bindingBlock 0) := by
    rw [(calculation_temps le value size n).2 _ (by decide +kernel)]
    exact binding
  have wrote := internal ge bindingsLayout valueLayout function e (calculationTemps le value size n)
    (.Kseq overflow k) m after bindingBlock cfBlock offset (payload value size.bits n.val)
    keptBinding (calculation_temps le value size n).1 pointer stored
  have finished : InternalRun ge 1
      (.State function .Sskip (.Kseq overflow k) e
        (afterTemps (calculationTemps le value size n) cfBlock offset) after)
      (.State function overflow k e (afterTemps (calculationTemps le value size n) cfBlock offset) after) :=
    .step (by trivial) (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (((selected.trans calculated).trans resumed).trans wrote).trans finished

/-- The complete source carry stage silently reaches its original overflow continuation. -/
theorem to_overflow_returns (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64) (size : X86.Size) (n : Fin 64) (positive : 0 < n.val)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (left : le.get X86_program_profile_bpf.___x86_sh_a = some (.Vlong value))
    (count : le.get X86_program_profile_bpf.___x86_sh_count = some (.Vint (BitVec.ofNat 32 n.val)))
    (bits : le.get X86_program_profile_bpf.___x86_sh_bits = some (.Vint (BitVec.ofNat 32 size.bits)))
    (alu : le.get X86_program_profile_bpf.___x86_sh_alu = some (.Vint (5#32)))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset)
      (byte (payload value size.bits n.val)) = some after) :
    CC.Star (CC.Step2 ge) (.State function X86ShiftFlagSF.rest k e le m) CC.E0
      (.State function overflow k e
        (afterTemps (calculationTemps le value size n) cfBlock offset) after) :=
  (to_overflow ge bindingsLayout valueLayout function e le k m after bindingBlock cfBlock offset
    value size n positive binding left count bits alu pointer stored).sound

end KProgFormal.ClightRefinement.X86ShiftFlagCF
