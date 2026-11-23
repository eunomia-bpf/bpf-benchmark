import KProgFormal.ClightRefinement.X86AluOperandsEntry

namespace KProgFormal.ClightRefinement.X86AluReadSelfXor

private structure Pieces where
  operation : CC.Stmt
  lane : CC.Stmt
  selection : CC.Stmt

private def pieces : Pieces :=
  match X86AluDecode.operandReads with
  | .Ssequence (.Ssequence (.Ssequence operation lane) selection) _ =>
      ⟨operation, lane, selection⟩
  | _ => ⟨.Sskip, .Sskip, .Sskip⟩

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_alu_self_xor_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

def operationGate : CC.Stmt := by run_tac cachePart (← `(pieces.operation))
def laneGate : CC.Stmt := by run_tac cachePart (← `(pieces.lane))
def selection : CC.Stmt := by run_tac cachePart (← `(pieces.selection))

theorem source : X86AluDecode.operandReads =
    .Ssequence (.Ssequence (.Ssequence operationGate laneGate) selection)
      X86ShiftLeftRoute.dispatch := rfl

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'4 (.Vint (1#32))).set X86_program_profile_bpf._t'5 (.Vint (1#32))

/-- The actual XOR/same-register/same-lane shortcut reaches the original
dispatcher without a register-cell load or any memory change. -/
theorem choose (ge : CC.CGenv) (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (reg shift : BitVec 8)
    (op : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)))
    (dst : le.get X86_program_profile_bpf._dst = some (X86Width.argument reg))
    (src : le.get X86_program_profile_bpf._src = some (X86Width.argument reg))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (X86Width.argument shift))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (X86Width.argument shift)) :
    InternalRun ge 11 (.State function X86AluDecode.operandReads k e le m)
      (.State function X86ShiftLeftRoute.dispatch k e (temps le) m) := by
  have opCompare : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (.Vint (2#32)) (.Tint .I8 .Unsigned CC.noattr)
      (.Vint (2#32)) (.Tint .I32 .Unsigned CC.noattr) m = some (.Vint (1#32)) := rfl
  have sameByte (code : BitVec 8) : CC.Cop.semBinaryOperation ge.genv_cenv .Oeq
      (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr)
      (X86Width.argument code) (.Tint .I8 .Unsigned CC.noattr) m = some (.Vint (1#32)) := by
    change some (CC.Val.ofBool (code.setWidth 32 == code.setWidth 32)) = _
    simp only [beq_self_eq_true]
    rfl
  have trueCast : CC.Cop.semCast (.Vint (1#32)) (.Tint .I32 .Signed CC.noattr)
      (.Tint .IBool .Unsigned CC.noattr) m = some (.Vint (1#32)) := rfl
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, operationGate, laneGate,
      selection, temps, CC.doEvalExpr, CC.typeof, op, dst, src, dstShift, srcShift,
      CC.PTree.gss, CC.PTree.gso, opCompare, sameByte, trueCast,
      CC.Cop.semUnaryOperation, CC.Cop.semNotbool, CC.Cop.boolVal, CC.Cop.classifyBool,
      CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]

/-- The shortcut retains both actual zero initializations from aux decoding. -/
theorem zeroes (le : CC.TempEnv) (aux : BitVec 32) :
    (temps (X86AluDecode.temps le aux)).get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong 0) ∧
    (temps (X86AluDecode.temps le aux)).get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong 0) := by
  simp +decide [temps, X86AluDecode.temps, CC.PTree.gss, CC.PTree.gso]

/-- Genuine entry and decoded aux fields reach the shortcut dispatcher in48
transitions. No register-cell pointer, tag or value observation is needed. -/
theorem from_call (ge : CC.CGenv) (caller : CC.Mem) (k : CC.Cont)
    (binding op imm : CC.Val) (reg flags width : BitVec 8) (aux : BitVec 32) (block : CC.Block)
    (xorCode : (aux.setWidth 8).setWidth 32 = (2#32))
    (sameLane : (aux >>> 16).setWidth 8 = (aux >>> 8).setWidth 8)
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_width_effective =
        some block ∧
      CC.Genv.findFunctPtr ge.genv_genv block =
        some (.Internal X86_program_profile_bpf.f_x86_width_effective)) :
    let initial := X86RegisterView.writerInitialTemps binding op
      (X86Width.argument reg) (X86Width.argument reg) (X86Width.argument flags)
      (.Vint aux) imm (X86Width.argument width)
    let ready := X86AluDecode.temps (X86AluEntry.widthTemps
      (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags) aux
    InternalRun ge 48
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG)
        [binding, op, X86Width.argument reg, X86Width.argument reg, X86Width.argument flags,
          .Vint aux, imm, X86Width.argument width] k caller)
      (.State X86_program_profile_bpf.f_x86_sim_inline_arm_ALU_REG X86ShiftLeftRoute.dispatch
        (X86AluEntry.continuation k) (X86RegisterView.writerAllocation ge.genv_cenv caller).1
        (temps ready) (X86RegisterView.writerAllocation ge.genv_cenv caller).2) := by
  dsimp only
  let initial := X86RegisterView.writerInitialTemps binding op
    (X86Width.argument reg) (X86Width.argument reg) (X86Width.argument flags)
    (.Vint aux) imm (X86Width.argument width)
  let afterWidth := X86AluEntry.widthTemps
    (initial.set X86_program_profile_bpf.___x86_l_width (X86Width.argument width)) flags
  let ready := X86AluDecode.temps afterWidth aux
  have opRead : ready.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32)) := by
    simpa only [ready, X86AluDecode.field_byte, BitVec.ushiftRight_zero, xorCode] using
      (X86AluDecode.observations afterWidth aux).1
  have dstShift : ready.get X86_program_profile_bpf.___x86_l_dst_shift =
      some (X86Width.argument ((aux >>> 8).setWidth 8)) := by
    simpa only [ready, X86Width.argument, X86AluDecode.field_byte] using
      (X86AluDecode.observations afterWidth aux).2.1
  have srcShift : ready.get X86_program_profile_bpf.___x86_l_src_shift =
      some (X86Width.argument ((aux >>> 8).setWidth 8)) := by
    simpa only [ready, X86Width.argument, X86AluDecode.field_byte, sameLane] using
      (X86AluDecode.observations afterWidth aux).2.2.1
  have dst : ready.get X86_program_profile_bpf._dst = some (X86Width.argument reg) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  have src : ready.get X86_program_profile_bpf._src = some (X86Width.argument reg) := by
    simp +decide [ready, afterWidth, initial, X86AluDecode.temps, X86AluEntry.widthTemps,
      X86RegisterView.writerInitialTemps, CC.PTree.gss, CC.PTree.gso]
  exact (X86AluDecode.from_call ge caller k binding op (X86Width.argument reg)
    (X86Width.argument reg) imm aux flags width block helper).trans
      (choose ge _ _ ready (X86AluEntry.continuation k) _ reg ((aux >>> 8).setWidth 8)
        opRead dst src dstShift srcShift)

end KProgFormal.ClightRefinement.X86AluReadSelfXor
