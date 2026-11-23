import KProgFormal.ClightRefinement.X86LogicFlagWidths
import KProgFormal.ClightRefinement.X86ShiftFlagPF

namespace KProgFormal.ClightRefinement.X86LogicFlagStores

private structure Pieces where
  cf : CC.Stmt
  zf : CC.Stmt
  sf : CC.Stmt
  ofStmt : CC.Stmt
  loopExit : CC.Stmt
  parity : CC.Stmt

private def pieces : Pieces :=
  match X86LogicFlagWidths.rest with
  | .Ssequence (.Sloop (.Ssequence cf (.Ssequence zf (.Ssequence sf ofStmt))) loopExit) parity =>
    ⟨cf, zf, sf, ofStmt, loopExit, parity⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip, .Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_logical_flag_store
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

def cf : CC.Stmt := by run_tac cachePart (← `(pieces.cf))
def zf : CC.Stmt := by run_tac cachePart (← `(pieces.zf))
def sf : CC.Stmt := by run_tac cachePart (← `(pieces.sf))
def ofStmt : CC.Stmt := by run_tac cachePart (← `(pieces.ofStmt))
def parity : CC.Stmt := by run_tac cachePart (← `(pieces.parity))

theorem source : X86LogicFlagWidths.rest =
    .Ssequence (.Sloop (.Ssequence cf (.Ssequence zf (.Ssequence sf ofStmt))) pieces.loopExit) parity := rfl

private def storeStmt (temp field : CC.Ident) (rhs : CC.Expr) : CC.Stmt :=
  .Ssequence
    (.Sset temp (.Efield
      (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind
        (CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)))
        (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)) field (CC.tptr CC.tuchar)))
    (.Sassign (.Ederef (.Etempvar temp (CC.tptr CC.tuchar)) CC.tuchar) rhs)

theorem cf_source : cf = storeStmt X86_program_profile_bpf._t'206
    X86_program_profile_bpf._cf (.Econst_int (0#32) CC.tint) := rfl

theorem of_source : ofStmt = storeStmt X86_program_profile_bpf._t'203
    X86_program_profile_bpf._of (.Econst_int (0#32) CC.tint) := rfl

/-- A real pointer read and byte assignment execute the original four source
steps. Callers supply the actual expression evaluation and cast equations. -/
private theorem store (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (m after : CC.Mem) (temp field : CC.Ident)
    (rhs : CC.Expr) (raw byte : CC.Val) (bindingBlock targetBlock : CC.Block)
    (headerOffset offset : CC.Integers.Ptrofs)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (address : CC.lvalOfField ge (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      field (.Vptr bindingBlock 0) = some (bindingBlock, headerOffset, .Full))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock (CC.Integers.Ptrofs.unsigned headerOffset) =
      some (.Vptr targetBlock offset))
    (evaluated : CC.doEvalExpr ge e (le.set temp (.Vptr targetBlock offset)) m rhs = some raw)
    (cast : CC.Cop.semCast raw (CC.typeof rhs) CC.tuchar m = some byte)
    (stored : CC.Mem.store .Mint8unsigned m targetBlock (CC.Integers.Ptrofs.unsigned offset)
      byte = some after) :
    InternalRun ge 4 (.State function (storeStmt temp field rhs) k e le m)
      (.State function .Sskip k e (le.set temp (.Vptr targetBlock offset)) after) := by
  have structAccess : CC.accessMode
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) = .By_copy := rfl
  have ptrAccess : CC.accessMode (CC.tptr CC.tuchar) = .By_value CC.Mptr := rfl
  have charAccess : CC.accessMode CC.tuchar = .By_value .Mint8unsigned := rfl
  have pointerRead : CC.doEvalExpr ge e le m
      (.Efield (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind
        (CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)))
        (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)) field (CC.tptr CC.tuchar)) =
      some (.Vptr targetBlock offset) := by
    simp only [CC.doEvalExpr, CC.doDerefLoc, CC.typeof, structAccess, ptrAccess,
      CC.Mem.loadv, binding, address, pointer]
  have targetLoc : CC.doEvalLvalue ge e (le.set temp (.Vptr targetBlock offset)) m
      (.Ederef (.Etempvar temp (CC.tptr CC.tuchar)) CC.tuchar) = some (targetBlock, offset, .Full) := by
    simp only [CC.doEvalLvalue, CC.doEvalExpr, CC.PTree.gss]
  have targetType : CC.typeof (.Ederef (.Etempvar temp (CC.tptr CC.tuchar)) CC.tuchar) =
      CC.tuchar := rfl
  apply internalRun_of_steps
  all_goals
    simp only [steps, InternalPath, InternalState, storeStmt, CC.doStep, pointerRead,
      targetLoc, evaluated, targetType, cast, CC.doAssignLoc, charAccess,
      CC.Mem.storev, stored, CC.Eapp, CC.E0, List.nil_append, true_and]

/-- The actual logical CF body writes byte zero through its original pointer. -/
theorem cf_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock cfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 120 = some (.Vptr cfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m cfBlock (CC.Integers.Ptrofs.unsigned offset)
      (.Vint (0#32)) = some after) :
    InternalRun ge 4 (.State function cf k e le m)
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'206 (.Vptr cfBlock offset)) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cf (.Vptr bindingBlock 0) = some (bindingBlock, 120, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftLeftCarry.cf_offset ge.genv_cenv valueLayout]
    rfl
  rw [cf_source]
  exact store ge function e le k m after X86_program_profile_bpf._t'206 X86_program_profile_bpf._cf
    (.Econst_int (0#32) CC.tint) (.Vint (0#32)) (.Vint (0#32)) bindingBlock cfBlock 120 offset
    binding address pointer rfl rfl stored

/-- The actual logical OF body writes byte zero through its original pointer. -/
theorem of_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock ofBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 144 = some (.Vptr ofBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m ofBlock (CC.Integers.Ptrofs.unsigned offset)
      (.Vint (0#32)) = some after) :
    InternalRun ge 4 (.State function ofStmt k e le m)
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'203 (.Vptr ofBlock offset)) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._of (.Vptr bindingBlock 0) = some (bindingBlock, 144, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftFlagOF.of_offset ge.genv_cenv valueLayout]
    rfl
  rw [of_source]
  exact store ge function e le k m after X86_program_profile_bpf._t'203 X86_program_profile_bpf._of
    (.Econst_int (0#32) CC.tint) (.Vint (0#32)) (.Vint (0#32)) bindingBlock ofBlock 144 offset
    binding address pointer rfl rfl stored

private def zfExpr : CC.Expr := by
  run_tac cachePart (← `(match zf with
    | .Ssequence _ (.Sassign _ rhs) => rhs | _ => .Econst_int (0#32) CC.tint))
private def parityExpr : CC.Expr := by
  run_tac cachePart (← `(match parity with
    | .Ssequence _ (.Sassign _ rhs) => rhs | _ => .Econst_int (0#32) CC.tint))

theorem zf_source : zf = storeStmt X86_program_profile_bpf._t'205
    X86_program_profile_bpf._zf zfExpr := rfl

theorem parity_source : parity = storeStmt X86_program_profile_bpf._t'202
    X86_program_profile_bpf._pf parityExpr := rfl

/-- The original logical ZF comparison and actual byte store produce the
shared checked zero predicate for every input word. -/
theorem zf_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock zfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 128 = some (.Vptr zfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m zfBlock (CC.Integers.Ptrofs.unsigned offset)
      (X86ShiftFlagZF.bit value) = some after) :
    InternalRun ge 4 (.State function zf k e le m)
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'205 (.Vptr zfBlock offset)) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._zf (.Vptr bindingBlock 0) = some (bindingBlock, 128, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftFlagZF.zf_offset ge.genv_cenv valueLayout]
    rfl
  have kept : (le.set X86_program_profile_bpf._t'205 (.Vptr zfBlock offset)).get
      X86_program_profile_bpf.___x86_fl_value = some (.Vlong value) := by
    simp +decide [CC.PTree.gso, word]
  have signedZero64 : BitVec.ofInt 64 (CC.Integers.Int.signed (0#32)) = (0#64) := rfl
  have evaluated : CC.doEvalExpr ge e (le.set X86_program_profile_bpf._t'205 (.Vptr zfBlock offset))
      m zfExpr = some (X86ShiftFlagZF.bit value) := by
    by_cases zero : value = 0
    all_goals
      simp +decide [zfExpr, CC.doEvalExpr, CC.typeof, kept,
        CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntLong, CC.tulong, CC.tint, CC.typeconv,
        CC.removeAttributes, CC.tattr, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
        CC.Integers.MI.eq, CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.MI.zero, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.zero,
        CC.Integers.Int.one, CC.Integers.MI.one, signedZero64, X86ShiftFlagZF.bit, zero, apply_ite]
  have cast : CC.Cop.semCast (X86ShiftFlagZF.bit value) (CC.typeof zfExpr) CC.tuchar m =
      some (X86ShiftFlagZF.bit value) := by
    change CC.Cop.semCast (X86ShiftFlagZF.bit value) CC.tint CC.tuchar m = _
    unfold X86ShiftFlagZF.bit
    split <;> rfl
  rw [zf_source]
  exact store ge function e le k m after X86_program_profile_bpf._t'205 X86_program_profile_bpf._zf
    zfExpr (X86ShiftFlagZF.bit value) (X86ShiftFlagZF.bit value) bindingBlock zfBlock 128 offset
    binding address pointer evaluated cast stored

/-- The original nibble-fold/table expression and actual PF byte store
produce the existing x86lean-corresponding parity value for every word. -/
theorem parity_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock pfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 152 = some (.Vptr pfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m pfBlock (CC.Integers.Ptrofs.unsigned offset)
      (X86ShiftFlagPF.bit value) = some after) :
    InternalRun ge 4 (.State function parity k e le m)
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'202 (.Vptr pfBlock offset)) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._pf (.Vptr bindingBlock 0) = some (bindingBlock, 152, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftFlagPF.pf_offset ge.genv_cenv valueLayout]
    rfl
  have kept : (le.set X86_program_profile_bpf._t'202 (.Vptr pfBlock offset)).get
      X86_program_profile_bpf.___x86_fl_value = some (.Vlong value) := by
    simp +decide [CC.PTree.gso, word]
  have bound : (X86ShiftFlagPF.index value).toNat < 16 := by
    simp only [X86ShiftFlagPF.index, BitVec.toNat_and]
    change (value ^^^ (value >>> 4)).toNat &&& 15 < 16
    have lower : (value ^^^ (value >>> 4)).toNat &&& 15 ≤ 15 := Nat.and_le_right
    omega
  have lowNat : (CC.Integers.Int64.loword (X86ShiftFlagPF.index value)).toNat =
      (X86ShiftFlagPF.index value).toNat := by
    change ((X86ShiftFlagPF.index value).setWidth 32).toNat = _
    simp only [BitVec.toNat_setWidth]
    exact Nat.mod_eq_of_lt (by omega)
  have shiftNat : (value.toNat ^^^ (value.toNat >>> 4)) &&& 15 < 32 := by
    have b : (X86ShiftFlagPF.index value).toNat < 32 := by omega
    simpa [X86ShiftFlagPF.index] using b
  dsimp only [X86ShiftFlagPF.index] at lowNat
  have evaluated : CC.doEvalExpr ge e (le.set X86_program_profile_bpf._t'202 (.Vptr pfBlock offset))
      m parityExpr = some (X86ShiftFlagPF.bit value) := by
    simp +decide [parityExpr, CC.doEvalExpr, CC.typeof, kept,
      CC.Cop.semBinaryOperation, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
      CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntLong,
      CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semAnd, CC.Cop.semXor,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong, CC.tuint,
      CC.Integers.Int64.shru, CC.Integers.Int.shru, CC.Integers.MI.shru,
      CC.Integers.Int64.xor, CC.Integers.Int64.and, CC.Integers.Int.and,
      CC.Integers.MI.xor, CC.Integers.MI.and, CC.Integers.Int.repr, CC.Integers.Int64.repr,
      CC.Integers.MI.repr, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int64.ltu, CC.Integers.MI.ltu, BitVec.ult,
      X86ShiftFlagPF.bit, X86ShiftFlagPF.index, shiftNat, lowNat]
  have cast : CC.Cop.semCast (X86ShiftFlagPF.bit value) (CC.typeof parityExpr) CC.tuchar m =
      some (X86ShiftFlagPF.bit value) := by
    change CC.Cop.semCast (X86ShiftFlagPF.bit value) CC.tuint CC.tuchar m = _
    rw [X86ShiftFlagPF.parity]
    cases X86.Value.parity8 value <;> rfl
  rw [parity_source]
  exact store ge function e le k m after X86_program_profile_bpf._t'202 X86_program_profile_bpf._pf
    parityExpr (X86ShiftFlagPF.bit value) (X86ShiftFlagPF.bit value) bindingBlock pfBlock 152 offset
    binding address pointer evaluated cast stored

private def sfExpr : CC.Expr := by
  run_tac cachePart (← `(match sf with
    | .Ssequence _ (.Sassign _ rhs) => rhs | _ => .Econst_int (0#32) CC.tint))

theorem sf_source : sf = storeStmt X86_program_profile_bpf._t'204
    X86_program_profile_bpf._sf sfExpr := rfl

def signPayload (value : BitVec 64) (size : X86.Size) : BitVec 64 :=
  (value >>> (size.bits - 1)) &&& (1#64)

def signByte (value : BitVec 64) (size : X86.Size) : CC.Val :=
  .Vint (if X86.Value.msb size value then 1 else 0)

/-- The actual shift/AND payload extracts precisely x86lean's sign bit. -/
theorem sign_value (value : BitVec 64) (size : X86.Size) :
    signPayload value size = (BitVec.ofBool (X86.Value.msb size value)).setWidth 64 := by
  rw [signPayload, BitVec.and_one_eq_setWidth_ofBool_getLsbD]
  simp only [BitVec.getLsbD_ushiftRight, Nat.add_zero, X86.Value.msb, X86.Size.signBit_eq]

/-- The original logical SF shift, mask, byte cast and store execute for every
word and native operand width, producing the exact shared native sign flag. -/
theorem sf_internal (ge : CC.CGenv)
    (bindingsLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_bindings =
      some X86ShiftLeftCarry.bindingsRecord)
    (valueLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_inline_value =
      some X86ShiftLeftCarry.valueRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (m after : CC.Mem) (bindingBlock sfBlock : CC.Block) (offset : CC.Integers.Ptrofs)
    (value : BitVec 64) (size : X86.Size)
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock 0))
    (word : le.get X86_program_profile_bpf.___x86_fl_value = some (.Vlong value))
    (bitsRead : le.get X86_program_profile_bpf.___x86_fl_bits =
      some (.Vint (BitVec.ofNat 32 size.bits)))
    (pointer : CC.Mem.load CC.Mptr m bindingBlock 136 = some (.Vptr sfBlock offset))
    (stored : CC.Mem.store .Mint8unsigned m sfBlock (CC.Integers.Ptrofs.unsigned offset)
      (signByte value size) = some after) :
    InternalRun ge 4 (.State function sf k e le m)
      (.State function .Sskip k e (le.set X86_program_profile_bpf._t'204 (.Vptr sfBlock offset)) after) := by
  have address : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._sf (.Vptr bindingBlock 0) = some (bindingBlock, 136, .Full) := by
    simp only [CC.lvalOfField, bindingsLayout, X86ShiftFlagSF.sf_offset ge.genv_cenv valueLayout]
    rfl
  have keptWord : (le.set X86_program_profile_bpf._t'204 (.Vptr sfBlock offset)).get
      X86_program_profile_bpf.___x86_fl_value = some (.Vlong value) := by
    simp +decide [CC.PTree.gso, word]
  have keptBits : (le.set X86_program_profile_bpf._t'204 (.Vptr sfBlock offset)).get
      X86_program_profile_bpf.___x86_fl_bits = some (.Vint (BitVec.ofNat 32 size.bits)) := by
    simp +decide [CC.PTree.gso, bitsRead]
  have evaluated : CC.doEvalExpr ge e (le.set X86_program_profile_bpf._t'204 (.Vptr sfBlock offset))
      m sfExpr = some (.Vlong (signPayload value size)) := by
    cases size
    all_goals
      simp +decide [sfExpr, CC.doEvalExpr, CC.typeof, keptWord, keptBits,
        signPayload, X86.Size.bits, CC.Cop.semBinaryOperation, CC.Cop.semSub, CC.Cop.classifySub,
        CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
        CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semAnd,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong, CC.tuint, CC.tint,
        CC.Integers.Int.sub, CC.Integers.MI.sub,
        CC.Integers.Int64.shru, CC.Integers.MI.shru, CC.Integers.Int64.and, CC.Integers.MI.and,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.signed, CC.Integers.MI.signed,
        CC.Integers.Int.ltu, CC.Integers.Int64.ltu, CC.Integers.MI.ltu]
  have cast : CC.Cop.semCast (.Vlong (signPayload value size)) (CC.typeof sfExpr) CC.tuchar m =
      some (signByte value size) := by
    change CC.Cop.semCast (.Vlong (signPayload value size)) CC.tulong CC.tuchar m = _
    rw [sign_value]
    unfold signByte
    cases X86.Value.msb size value <;> rfl
  rw [sf_source]
  exact store ge function e le k m after X86_program_profile_bpf._t'204 X86_program_profile_bpf._sf
    sfExpr (.Vlong (signPayload value size)) (signByte value size) bindingBlock sfBlock 136 offset
    binding address pointer evaluated cast stored

/-- All five bytes written by the actual logical bodies match the same
external x86lean logical-flags result, for every undefined-AF oracle choice. -/
theorem native_values (value : BitVec 64) (size : X86.Size)
    (af : Bool) (before : X86.Flags) :
    let word := X86.Value.trunc size value
    let next := X86.Flags.logic size word af before
    ((.Vint (0#32) : CC.Val), X86ShiftFlagZF.bit word, signByte word size,
      (.Vint (0#32) : CC.Val), X86ShiftFlagPF.bit word) =
    ((.Vint (if next.cf then 1 else 0) : CC.Val), .Vint (if next.zf then 1 else 0),
      .Vint (if next.sf then 1 else 0), .Vint (if next.of then 1 else 0),
      .Vint (if next.pf then 1 else 0)) := by
  dsimp only
  rw [X86ShiftFlagPF.parity]
  have truncated : X86.Value.trunc size (X86.Value.trunc size value) =
      X86.Value.trunc size value := by
    simp only [X86.Value.trunc, BitVec.and_assoc, BitVec.and_self]
  by_cases zero : X86.Value.trunc size value = 0
  all_goals
    simp [X86.Flags.logic, X86.Flags.fromResult, X86ShiftFlagZF.bit, signByte,
      X86.Value.isZero, truncated, zero]
  all_goals simp [X86.Value.trunc]

end KProgFormal.ClightRefinement.X86LogicFlagStores
