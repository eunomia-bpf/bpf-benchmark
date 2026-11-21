import KProgFormal.ClightRefinement.Arm64AddRegisterOperands

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddRegisterModifier
open Arm64AddRegisterOperands (modify readerCont selectedTemps valueSet registerBody rhsBody)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_modifier_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private structure ModParts where
  kind : CC.Stmt
  shift : CC.Stmt
  mask : CC.Stmt
  amount : CC.Stmt
  switch : CC.Stmt
  output : CC.Stmt

private def modParts : ModParts := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual modifier sequence changed"
      pure actual.getAppArgs
    let kind ← peel (← Lean.Elab.Term.elabTerm (← `(modify)) none) ``CC.Stmt.Ssequence 2
    let shift ← peel kind[1]! ``CC.Stmt.Ssequence 2
    let rest ← peel shift[1]! ``CC.Stmt.Ssequence 2
    let mask ← peel rest[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel rest[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_mod_parts (← Lean.Meta.mkAppM ``ModParts.mk
      #[kind[0]!, shift[0]!, mask[0]!, mask[1]!, tail[0]!, tail[1]!])

private def modKind : CC.Stmt := by run_tac cachePart (← `(modParts.kind))
private def modShift : CC.Stmt := by run_tac cachePart (← `(modParts.shift))
private def modMask : CC.Stmt := by run_tac cachePart (← `(modParts.mask))
private def modAmount : CC.Stmt := by run_tac cachePart (← `(modParts.amount))
private def modSwitch : CC.Stmt := by run_tac cachePart (← `(modParts.switch))
private def modOutput : CC.Stmt := by run_tac cachePart (← `(modParts.output))
private theorem modify_source : modify = .Ssequence modKind (.Ssequence modShift
    (.Ssequence (.Ssequence modMask modAmount) (.Ssequence modSwitch modOutput))) := rfl

private def switchExpr : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modSwitch)) none))
    unless actual.isAppOfArity ``CC.Stmt.Sswitch 2 do throwError "actual modifier switch changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mod_expr actual.getAppArgs[0]!
private def switchCases : CC.LStmts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modSwitch)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_mod_cases actual.getAppArgs[1]!
private theorem switch_source : modSwitch = .Sswitch switchExpr switchCases := rfl

private def caseOne : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(CC.seqOfLabeledStatement (CC.selectSwitch 1 switchCases))) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual case1 changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mod_case actual.getAppArgs[0]!

@[irreducible] private def deadCases : CC.Stmt := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(CC.seqOfLabeledStatement (CC.selectSwitch 1 switchCases))) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual case1 changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mod_dead_cases actual.getAppArgs[1]!
private theorem case_one : CC.seqOfLabeledStatement (CC.selectSwitch 1 switchCases) =
    .Ssequence caseOne deadCases := by
  unfold caseOne deadCases
  rfl

private def valueExpr : CC.Expr := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual LSL0 case changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(caseOne)) none) ``CC.Stmt.Ssequence 2
    let body ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let update ← peel body[1]! ``CC.Stmt.Sset 2
    Lean.Elab.Tactic.closeMainGoal `actual_lsl0_expression update[1]!

private def caseMask : CC.Stmt := by
  run_tac do
    let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(caseOne)) none))
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf outer.getAppArgs[0]!)
    Lean.Elab.Tactic.closeMainGoal `actual_lsl0_mask body.getAppArgs[0]!

private theorem case_shape : caseOne = .Ssequence
    (.Ssequence caseMask (.Sset Arm64Program.___kprog_a64_mod_value valueExpr)) .Sbreak := rfl

private theorem shift_zero (world : CC.CGenv) (m : CC.Mem) (rhs : BitVec 64) :
    CC.Cop.semBinaryOperation world.genv_cenv .Oshl (.Vlong rhs) CC.tulong (.Vint (0#32)) CC.tuchar m =
      some (.Vlong rhs) := by
  change some (CC.Val.Vlong (rhs <<< 0)) = some (CC.Val.Vlong rhs)
  rw [BitVec.shiftLeft_zero]

private theorem mask_all (world : CC.CGenv) (m : CC.Mem) (rhs : BitVec 64) :
    CC.Cop.semBinaryOperation world.genv_cenv .Oand (.Vlong rhs) CC.tulong
      (.Vlong (BitVec.allOnes 64)) CC.tulong m = some (.Vlong rhs) := by
  change some (CC.Val.Vlong (rhs &&& BitVec.allOnes 64)) = some (CC.Val.Vlong rhs)
  rw [BitVec.and_allOnes]

private theorem value_eval (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (rhs : BitVec 64)
    (value : le.get Arm64Program.___kprog_a64_mod_value = some (.Vlong rhs))
    (amount : le.get Arm64Program.___kprog_a64_mod_amount = some (.Vint (0#32)))
    (mask : le.get Arm64Program._t'10 = some (.Vlong (BitVec.allOnes 64))) :
    CC.doEvalExpr world e le m valueExpr = some (.Vlong rhs) := by
  simp only [valueExpr, CC.doEvalExpr, value, amount, mask, CC.typeof, shift_zero, mask_all]

private theorem value_step {world : CC.CGenv} {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem} {k : CC.Cont}
    (rhs : BitVec 64)
    (value : le.get Arm64Program.___kprog_a64_mod_value = some (.Vlong rhs))
    (amount : le.get Arm64Program.___kprog_a64_mod_amount = some (.Vint (0#32)))
    (mask : le.get Arm64Program._t'10 = some (.Vlong (BitVec.allOnes 64))) :
    CC.Step2 world (.State Arm64Nop.handler (.Sset Arm64Program.___kprog_a64_mod_value valueExpr) k e le m)
      CC.E0 (.State Arm64Nop.handler .Sskip k e (le.set Arm64Program.___kprog_a64_mod_value (.Vlong rhs)) m) := by
  apply CC.Step.set
  apply CC.doEvalExpr_sound
  exact value_eval world e le m rhs value amount mask

def prefixTemps (le : CC.TempEnv) (rhs : BitVec 64) : CC.TempEnv :=
  (((((((selectedTemps le).set Arm64Program._t'8 (.Vlong rhs)).set
    Arm64Program.___kprog_a64_mod_value (.Vlong rhs)).set
    Arm64Program.___kprog_a64_mod (.Vint (1#32))).set
    Arm64Program.___kprog_a64_mod_shift (.Vint (0#32))).set
    Arm64Program._t'9 (.Vint (63#32))).set
    Arm64Program.___kprog_a64_mod_amount (.Vint (0#32)))

def finalTemps (le : CC.TempEnv) (rhs : BitVec 64) : CC.TempEnv :=
  (((((prefixTemps le rhs).set Arm64Program._t'10 (.Vlong (BitVec.allOnes 64))).set
    Arm64Program._t'10 (.Vlong (BitVec.allOnes 64))).set
    Arm64Program._t'10 (.Vlong (BitVec.allOnes 64))).set
    Arm64Program.___kprog_a64_mod_value (.Vlong rhs)).set
    Arm64Program.___a64_alu_rhs (.Vlong rhs)


private def modCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 registerBody .Sbreak (.Kloop1 rhsBody Arm64Program.s_kprog_arm64_program_execute_16 k)

private def readTemps (le : CC.TempEnv) (rhs : BitVec 64) : CC.TempEnv :=
  ((selectedTemps le).set Arm64Program._t'8 (.Vlong rhs)).set
    Arm64Program.___kprog_a64_mod_value (.Vlong rhs)

private def maskTemps (le : CC.TempEnv) (rhs : BitVec 64) : CC.TempEnv :=
  ((((prefixTemps le rhs).set Arm64Program._t'10 (.Vlong (BitVec.allOnes 64))).set
    Arm64Program._t'10 (.Vlong (BitVec.allOnes 64))).set
    Arm64Program._t'10 (.Vlong (BitVec.allOnes 64))).set
    Arm64Program.___kprog_a64_mod_value (.Vlong rhs)

private def readyTemps (le : CC.TempEnv) (rhs : BitVec 64) : CC.TempEnv :=
  (((prefixTemps le rhs).set Arm64Program._t'10 (.Vlong (BitVec.ofInt 64 (-1)))).set
    Arm64Program._t'10 (.Vlong (BitVec.ofInt 64 (-1)))).set
    Arm64Program._t'10 (.Vlong (BitVec.ofInt 64 (-1)))

private theorem ready_reads (le : CC.TempEnv) (rhs : BitVec 64) :
    (readyTemps le rhs).get Arm64Program.___kprog_a64_mod_value = some (.Vlong rhs) ∧
    (readyTemps le rhs).get Arm64Program.___kprog_a64_mod_amount = some (.Vint (0#32)) ∧
    (readyTemps le rhs).get Arm64Program._t'10 = some (.Vlong (BitVec.allOnes 64)) := by
  have value_amount : Arm64Program.___kprog_a64_mod_amount ≠ Arm64Program.___kprog_a64_mod_value := by decide +kernel
  have value_t9 : Arm64Program._t'9 ≠ Arm64Program.___kprog_a64_mod_value := by decide
  have value_shift : Arm64Program.___kprog_a64_mod_shift ≠ Arm64Program.___kprog_a64_mod_value := by decide +kernel
  have value_kind : Arm64Program.___kprog_a64_mod ≠ Arm64Program.___kprog_a64_mod_value := by decide
  have value_t10 : Arm64Program._t'10 ≠ Arm64Program.___kprog_a64_mod_value := by decide
  have amount_t10 : Arm64Program._t'10 ≠ Arm64Program.___kprog_a64_mod_amount := by decide
  constructor
  · unfold readyTemps prefixTemps
    rw [CC.PTree.gso _ _ _ _ value_t10, CC.PTree.gso _ _ _ _ value_t10,
      CC.PTree.gso _ _ _ _ value_t10, CC.PTree.gso _ _ _ _ value_amount,
      CC.PTree.gso _ _ _ _ value_t9, CC.PTree.gso _ _ _ _ value_shift,
      CC.PTree.gso _ _ _ _ value_kind, CC.PTree.gss]
  constructor
  · unfold readyTemps prefixTemps
    rw [CC.PTree.gso _ _ _ _ amount_t10, CC.PTree.gso _ _ _ _ amount_t10,
      CC.PTree.gso _ _ _ _ amount_t10, CC.PTree.gss]
  · unfold readyTemps
    rw [CC.PTree.gss]
    rfl

set_option hygiene false in
private theorem after_reader (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64) :
    InternalRun world 4 (.Returnstate (.Vlong rhs) (readerCont k e le) m)
      (.State Arm64Nop.handler modify (modCont k) e (readTemps le rhs) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [modCont, readTemps, maskTemps, CC.doStep, readerCont, prefixTemps, finalTemps,
        selectedTemps, valueSet,         CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof,         Arm64Program.s_kprog_arm64_program_execute_9,
        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
        CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
        CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
        CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.MI.zero, CC.Integers.MI.one,
        BitVec.shiftLeft_zero, BitVec.and_allOnes,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Arm64Program.s_kprog_arm64_program_execute_16] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

set_option hygiene false in
private theorem modifier_prefix (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64)
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32))) :
    InternalRun world 14 (.State Arm64Nop.handler modify (modCont k) e (readTemps le rhs) m)
      (.State Arm64Nop.handler modSwitch (.Kseq modOutput (modCont k)) e (prefixTemps le rhs) m) := by
  run_tac do
    for _ in [:14] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [modCont, readTemps, maskTemps, CC.doStep, readerCont, prefixTemps, finalTemps,
        selectedTemps, valueSet, modify_source, modKind, modShift, modMask, modAmount,
        CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof, aux, width,
        Arm64Program.s_kprog_arm64_program_execute_9,
        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
        CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
        CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
        CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.MI.zero, CC.Integers.MI.one,
        BitVec.shiftLeft_zero, BitVec.and_allOnes,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Arm64Program.s_kprog_arm64_program_execute_16] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem case_enter (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64) :
    CC.Step2 world
      (.State Arm64Nop.handler modSwitch (.Kseq modOutput (modCont k)) e (prefixTemps le rhs) m) CC.E0
      (.State Arm64Nop.handler (.Ssequence caseOne deadCases)
        (.Kswitch (.Kseq modOutput (modCont k))) e (prefixTemps le rhs) m) := by
  rw [switch_source, ← case_one]
  apply CC.Step.switch (v := .Vint (1#32)) (n := 1)
  · apply CC.doEvalExpr_sound
    simp +decide only [switchExpr, CC.doEvalExpr, prefixTemps, selectedTemps, CC.PTree.gss, CC.PTree.gso]
  · rfl

set_option hygiene false in
private theorem case_tail (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64)
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32))) :
    InternalRun world 19 (.State Arm64Nop.handler (.Ssequence caseOne deadCases)
        (.Kswitch (.Kseq modOutput (modCont k))) e (prefixTemps le rhs) m)
      (.State Arm64Nop.handler modOutput (modCont k) e (maskTemps le rhs) m) := by
  run_tac do
    for i in [:19] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      if i == 14 then
        Lean.Elab.Tactic.evalTactic (← `(tactic| exact value_step rhs
          (ready_reads le rhs).1 (ready_reads le rhs).2.1 (ready_reads le rhs).2.2))
      else
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [modCont, readTemps, maskTemps, CC.doStep, readerCont, prefixTemps, finalTemps,
          selectedTemps, valueSet,         case_shape, caseMask, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
          CC.doEvalExpr, CC.typeof, width,         Arm64Program.s_kprog_arm64_program_execute_9,
          CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
          CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
      CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
          CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
          CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
          CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
          CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
          CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
          CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
          CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
          CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
          CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
          CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
          CC.Integers.MI.zero, CC.Integers.MI.one,
          BitVec.shiftLeft_zero, BitVec.and_allOnes,
          CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
          Arm64Program.s_kprog_arm64_program_execute_16] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem modifier_case (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64)
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32))) :
    InternalRun world 20
      (.State Arm64Nop.handler modSwitch (.Kseq modOutput (modCont k)) e (prefixTemps le rhs) m)
      (.State Arm64Nop.handler modOutput (modCont k) e (maskTemps le rhs) m) :=
  .step trivial (case_enter world e le m k rhs) (case_tail world e le m k rhs width)

set_option hygiene false in
private theorem modifier_exit (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64) :
    InternalRun world 5 (.State Arm64Nop.handler modOutput (modCont k) e (maskTemps le rhs) m)
      (.State Arm64Nop.handler .Sskip k e (finalTemps le rhs) m) := by
  run_tac do
    for _ in [:5] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [modCont, readTemps, maskTemps, CC.doStep, readerCont, prefixTemps, finalTemps,
        selectedTemps, valueSet,         modOutput, CC.setOpttemp, CC.PTree.gss, CC.PTree.gso,
        CC.doEvalExpr, CC.typeof,         Arm64Program.s_kprog_arm64_program_execute_9,
        CC.Cop.semSwitchArg, CC.Cop.classifySwitch,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semOr, CC.Cop.semShl,
    CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
        CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Val.shl, CC.Val.shru, CC.Val.and,
        CC.Integers.Int.cmpu, CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.Int.unsigned,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.MI.repr,
        CC.Integers.Int64.shl, CC.Integers.Int64.and, CC.Integers.Int.shru,
        CC.Integers.MI.shl, CC.Integers.MI.shru, CC.Integers.MI.and,
        CC.Integers.MI.unsigned, CC.Integers.MI.cmpu, CC.Integers.MI.eq,
        CC.Integers.MI.zero, CC.Integers.MI.one,
        BitVec.shiftLeft_zero, BitVec.and_allOnes,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Arm64Program.s_kprog_arm64_program_execute_16] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Original AUX256 modifier1/LSL0, retaining all three real mask assignments. -/
theorem finish_lsl_zero (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (rhs : BitVec 64)
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32))) :
    InternalRun world 43 (.Returnstate (.Vlong rhs) (readerCont k e le) m)
      (.State Arm64Nop.handler .Sskip k e (finalTemps le rhs) m) := by
  exact ((after_reader world e le m k rhs).trans
    (modifier_prefix world e le m k rhs aux width)).trans
    ((modifier_case world e le m k rhs width).trans (modifier_exit world e le m k rhs))

end KProgFormal.ClightRefinement.Arm64AddRegisterModifier
