import KProgFormal.ClightRefinement.X86LogicFlagWidths
import KProgFormal.ClightRefinement.X86ShiftFlagOF

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

end KProgFormal.ClightRefinement.X86LogicFlagStores
